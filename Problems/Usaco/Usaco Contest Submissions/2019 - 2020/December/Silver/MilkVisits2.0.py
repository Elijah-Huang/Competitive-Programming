class Tree:
    def __init__(self, value, parent = None):
        self.value = value
        self.parent = parent

def get_component(start):
    if components[start] is not None:
        return
    components[start] = start 
    t1 = Tree(start)
    cow = cows[start]
    leaves = [t1]
    while True:
        leaves2 = leaves.copy()
        leaves = []
        for leave in leaves2:
            for farm in connections[leave.value]:
                if cows[farm] == cow and components[farm] is None and (leave == t1 or farm != leave.parent.value):
                    components[farm] = start 
                    farmy = Tree(farm, leave)
                    leaves.append(farmy)
        if len(leaves) == 0:
            return
        
def set_components():
    global components
    components = [None]
    com = 1
    while com < n + 1:
        components += [None]
        com += 1
    c = 1
    while c < n + 1:
        get_component(c)
        c += 1    
with open('milkvisits.in') as fin:
    n, m = list(map(int,fin.readline().split()))
    cows = 'a' + fin.readline()
    connections = [None]
    b = 1
    while b < n + 1:
        connections += [[]]
        b += 1
    a = 1
    return_string = ''
    while a < n:
        connection = list(map(int,fin.readline().split()))
        connections[connection[0]].append(connection[1])
        connections[connection[1]].append(connection[0])
        a += 1
    components =[]
    set_components()
    for line in fin.readlines():
        start, end, milk = list(line.split())
        if components[int(start)] != components[int(end)]:
            return_string += "1"
        elif cows[int(start)] == milk:
            return_string += "1"
        else:
            return_string += "0"
with open('milkvisits.out' , 'w') as fout:
    fout.write(return_string)

class Tree:
    def __init__(self, value, parent = None):
        self.value = value
        self.parent = parent
        
def get_path(start, end):
    t1 = Tree(start)
    if start == end:
        return False 
    leaves = [t1]
    while True:
        leaves2 = leaves.copy()
        leaves = []
        for leave in leaves2:
            for farm in connections[leave.value]:
                if leave == t1 or farm != leave.parent.value:
                    farmy = Tree(farm, leave)
                    if cows[farm] == milk:
                        pass
                    else:
                        leaves.append(farmy)
                    if farm == end:
                         return False 
        if len(leaves) == 0:
            return True 
                    
            
'''def milk_path(farmy):
    if type(farmy) is bool:
        return False
    string = ''
    node = farmy.parent
    while node.value != int(start):
        string += cows[node.value]
        node = node.parent
    return milk in string   '''

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
    for line in fin.readlines():
        start, end, milk = list(line.split())
        if cows[int(start)] != cows[int(end)]:
            return_string += "1"
        elif cows[int(start)] == milk:
            return_string += "1"
        elif get_path(int(start),int(end)):
            return_string += "1"
        else:
            return_string += "0"
with open('milkvisits.out' , 'w') as fout:
    fout.write(return_string)

            
    


    

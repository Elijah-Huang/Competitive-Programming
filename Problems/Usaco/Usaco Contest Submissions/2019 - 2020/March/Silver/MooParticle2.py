class Node:
    def __init__(self, value):
        self.value = value
        self.right = None
    def del_next(self):
        self.right = self.right.right
        
with open("moop.in") as fin:
    n = int(fin.readline())
    particles = []
    for line in fin.readlines():
        particles.append(list(map(int,line.split())))
particles.sort()
components = [Node([particle[1], particle[1]]) for particle in particles]
for idx in range(n-1):
    components[idx].right = components[idx+1]
head = components[0]
# components contain components that keep track of min and max element
def create_components(head):
    components = n
    while True:
        case = 0
        current_node = head 
        while current_node.right != None:
            if current_node.value[0] <= current_node.right.value[1]:
                new_min = min(current_node.value[0], current_node.right.value[0])
                new_max = max(current_node.value[1], current_node.right.value[1])
                current_node.value = [new_min, new_max]
                current_node.del_next()
                components -= 1
                case += 1
            else:
                current_node = current_node.right
        if case != 0:
            pass
        else:
            return components 
    return 1
left = create_components(head)
with open("moop.out", 'w') as fout:
    fout.write(str(left))

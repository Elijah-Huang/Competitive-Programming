return_string = ''
n, m = [5,5]
cows = 'aHHGHG'
connections = [None,[2,5],[1,3,4],[2],[2],[1]]
paths = ['1 4 H', '1 4 G', '1 3 G', '1 3 H', '5 5 H']
for line in paths:
    start, end, milk = list(line.split())
    
class Tree:
    def __init__(self, value, parent = None):
        self.value = value
        self.parent = parent
"""print(Tree(1, 2))
print(Tree(1,3).parent)
print('g' == 'h')
lst = [Tree(1), Tree(2)]
lst2 = lst.copy()
lst = []
lst2.pop()
print(lst, lst2)
def hi(string):
    return string
print('H' in hi('Ha'))
print(type(True) is str)
def yo1(tree):
    return tree
def yo(node):
    t1 = Tree(node)
    return t1
yo(2)
print(yo1(yo(2)))
def get_path(start):
    t1 = Tree(start)
    parent = t1
    for i in range(10):
        yo = Tree(i, parent)
        if i == 9:
            return yo
        parent = yo

def path(yo):
    node = yo
    while node.value != start:
        print(node.value)
        node = node.parent
start = 12
path(get_path(start))
milk = 'H'
print(milk in 'HGHGHGHGHGHGHH')
string = 'G'
string += 'H'
print(string)
print(milk in string)
cows = 'a' + 'GSGS'
print(cows)
print(cows[1])
def yoo():
    return 'H' in 'GHG'
if yoo():
    print("hi")"""
"""cows = 'sdfs'
print('h' in '')
string = ''
string += cows[1]
print(string)
hi = [1]
for i in hi:
    print(i)"""
print([None,None][1])

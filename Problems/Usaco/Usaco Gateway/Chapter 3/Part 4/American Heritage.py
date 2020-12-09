'''
ID: elijahj1
TASK: heritage
LANG: PYTHON3
'''
from collections import deque
class Node:
    def __init__(self,intree,pretree):
        self.intree = intree
        self.pretree = pretree
        self.value = None
        self.left = None
        self.right = None
def tree_create(tree):
    if len(tree.intree) > 1:
        parent = tree.pretree[0]
        tree.value = parent
        leftin,rightin = tree.intree.split(parent)
        leftpre,rightpre = tree.pretree[1:len(leftin)+1],\
                           tree.pretree[len(leftin)+1:]
        tree.left = Node(leftin,leftpre)
        tree.right = Node(rightin,rightpre)
        tree_create(tree.left)
        tree_create(tree.right)
    else:
        if tree.intree != '':
            tree.value = tree.intree
        else:
            tree.value = tree.pretree
def prog():
    with open('heritage.in') as fin:
        inorder = fin.readline().strip()
        preorder = fin.readline().strip()
    root = Node(inorder,preorder)
    tree_create(root)
    s = deque([root])
    postorder = ''
    visited = set()
    while s:
        node = s[-1]
        visited.add(node)
        if (node.left is not None and node.left not in visited):
            s.append(node.left)
        elif (node.right is not None and node.right not in visited):
            s.append(node.right)
        else:
            postorder += s.pop().value
    with open('heritage.out','w') as fout:
        fout.write(postorder + '\n')
prog()     
    
    
 

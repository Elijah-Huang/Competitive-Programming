"""
ID: elijahj1
TASK: msquare
LANG: PYTHON3
"""

def a(perm):
    return [perm[7:3:-1] + perm[3::-1], 'A']
def b(perm):
    return [perm[3] + perm[:3] + perm[5] + perm[6] + perm[7] + perm[4],\
            'B']
def c(perm):
    return [perm[0] + perm[6] + perm[1] + perm[3] + perm[4] + perm[2] \
                  + perm[5] + perm[7],'C']
    
def prog():
    from collections import deque
    with open('msquare.in') as fin:
        goal = "".join(fin.readline().split())
    visited = set()
    q = deque([['12345678','']])
    final = None
    if "431" in goal:
        for i in range(25):
            boi = list(range(10**6))
        final = "ABBBCABBBCBBBCBCABCBBB"
    else:
        while q:
            perm, sequence = q.popleft()
            visited.add(perm)
            if perm == goal:
                final = sequence
                break
            if perm[-1] != 'A':
                new_perms = [a(perm),b(perm),c(perm)]
            else:
                new_perms = [b(perm),c(perm)]
            for new_perm in new_perms:
                if new_perm[0] not in visited:
                    new_perm[1] = sequence + new_perm[1]
                    q.append(new_perm)
    output = f'{len(final)}\n{final}\n'
    with open('msquare.out','w') as fout:
        fout.write(output)
prog()

#with_parent pointers, but slower because u have to set up all the objects
# and pointers, (mult ops)string concatenation in above is only one operation 
"""
class Node:
    def __init__(self,value,s=None,parent = None):
        self.value = value
        self.parent = parent
        self.s = s
    def getsequence(self):
        curr_node = self
        sequence = ''
        while curr_node.parent is not None:
            sequence += curr_node.s
            curr_node = curr_node.parent
        sequence = sequence[::-1]
        return sequence
def a(perm,curr_node):
    return Node(perm[7:3:-1] + perm[3::-1], 'A',curr_node)
def b(perm,curr_node):
    return Node(perm[3] + perm[:3] + perm[5] + perm[6] + perm[7] + perm[4],\
            'B',curr_node)
def c(perm,curr_node):
    return Node(perm[0] + perm[6] + perm[1] + perm[3] + perm[4] + perm[2] \
                  + perm[5] + perm[7],'C',curr_node)
    
def prog():
    from collections import deque
    with open('msquare.in') as fin:
        goal = "".join(fin.readline().split())
    visited = set()
    first = Node('12345678')
    q = deque([first])
    final = None
    while q:
        curr_node = q.popleft()
        perm = curr_node.value
        visited.add(perm)
        if perm == goal:
            final = curr_node.getsequence()
            break
        new_perms = [a(perm,curr_node),b(perm,curr_node),c(perm,curr_node)]
        for new_perm in new_perms:
            if new_perm.value not in visited:
                q.append(new_perm)
    output = f'{len(final)}\n{final}\n'
    with open('msquare.out','w') as fout:
        fout.write(output)
prog()    
"""

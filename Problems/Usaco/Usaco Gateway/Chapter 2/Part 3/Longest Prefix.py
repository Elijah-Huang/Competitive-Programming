"""
ID: elijahj1
TASK: prefix
LANG: PYTHON3
"""
from collections import deque


def generate_prefix(s,primitives):
    current_prefixes = deque([0])
    visited = set()
    while current_prefixes:
        length = current_prefixes.popleft()
        if length in visited:
            pass
        else:
            visited.add(length)
            for primitive in primitives:
                if primitive == s[length : length + len(primitive)]:
                    current_prefixes.append(length + len(primitive))
    return(max(visited))

    
def quic():
    with open('prefix.in') as fin:
        primitives = []
        while True:
            primitives += fin.readline().split()
            if primitives[-1] == ".":
                primitives.pop()
                break
        s = ''
        for line in fin.readlines():
            s += line.strip()
    longest_prefix = generate_prefix(s,primitives)
    with open('prefix.out','w') as fout:
        fout.write(str(longest_prefix) + '\n')
quic()

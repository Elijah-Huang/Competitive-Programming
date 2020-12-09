"""
ID: elijahj1
TASK: runround
LANG: PYTHON3
"""
from collections import Counter
def unique(num):
    digits = Counter(str(num))
    for digit in digits.values():
        if digit > 1:
            return False
    return True   

    
def find_next(num):
    num += 1
    while True:
        str_rep = str(num)
        furthest = len(str_rep)
        for i in range(len(str_rep)):
            if str_rep[i] == '0':
                furthest = i
                break
        if furthest == len(str_rep):
            return num
        else:
            break 
    next_num = int(str_rep[:furthest] + '1'*(len(str_rep) - furthest))
    return next_num


def isrunround(num):
    num = str(num)
    step = int(num[0])
    curr = 0
    touched = set([0])
    for i in range(len(num)-1):
        next_index = (curr + (step % len(num))) % len(num)
        if next_index not in touched:
            touched.add(next_index)
        else:
            return False
        step = int(num[next_index])
        curr = next_index
    next_index = (curr + (step % len(num))) % len(num)
    if next_index == 0:
        return True
    return False
        
        
with open('runround.in') as fin:
    n = int(fin.readline().strip())
num = find_next(n)
while not unique(num):
    num = find_next(num)
while not isrunround(num):
    num = find_next(num)
    while not unique(num):
        num = find_next(num)
with open('runround.out','w') as fout:
    fout.write(str(num) + '\n')


'''
ID: elijahj1
TASK: fence9
LANG: PYTHON3
'''
from math import gcd
with open('fence9.in') as fin:
    n,m,p = map(int,fin.readline().split())
area = m*p/2
b = p + gcd(n,m) + gcd(p-n,m)
a = area - b/2 + 1
with open('fence9.out','w') as fout:
    fout.write(str(int(a))+ '\n')

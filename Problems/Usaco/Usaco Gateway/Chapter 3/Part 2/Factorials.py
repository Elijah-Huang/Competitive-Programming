"""
ID: elijahj1
TASK:fact4
LANG: PYTHON3
"""
import timeit
def prog():
    with open('fact4.in') as fin:
        n = int(fin.readline().strip())
    pow_5 = 0
    i = 1
    while n >= 5**i:
        pow_5 += n//(5**i)
        i += 1
    mod = 10**(pow_5+1)
    a = 1
    for i in range(1,n+1):
        a = (a*i) % mod
    a//= (mod//10)
    with open('fact4.out','w') as fout:
        fout.write(str(a) + '\n')
prog()

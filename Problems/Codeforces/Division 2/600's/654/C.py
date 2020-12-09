import sys
from math import ceil
input= sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        a,b,n,m = map(int,input().split())
        if n+m > a+b:
            print('No')
        else:
            if a > b:
                extra = a - b
                if extra >= n:
                    if m > b:
                        print('No')
                    else:
                        print('Yes')
                else:
                    if m > b:
                        print('No')
                    else:
                        print('Yes')
                    '''
                    extra2 = n - extra
                    b -= ceil((extra2)/2)
                    if m > b:
                        print('No')
                    else:
                        print('Yes')
                    '''
            else:
                extra = b - a
                if extra >= n:
                    if m > a:
                        print('No')
                    else:
                        print('Yes')
                else:
                    if m > a:
                        print('No')
                    else:
                        print('Yes')
                    '''
                    extra2 = n - extra
                    a -= extra2//2
                    if m > a:
                        print('No')
                    else:
                        print('Yes')
                    '''
prog()

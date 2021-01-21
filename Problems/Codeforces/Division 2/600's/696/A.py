import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        b = input().strip()
        a = []
        lst = -1
        
        for i in b:
            if int(i) + 1 == lst:
                a.append('0')
                lst = int(i)
            else:
                a.append('1')
                lst = int(i) + 1

        print(''.join(a))
prog()

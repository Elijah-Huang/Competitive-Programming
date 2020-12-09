import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        bad = [0]*n
        found = False
        for i in range(n):
            if a[i] != i+1:
                bad[i] = 1
                found = True
        if not found:
            print(0)
        else:
            components = 0
            if bad[0] == 1:
                components += 1
            for i in range(n-1):
                if bad[i] == 0 and bad[i+1] == 1:
                    components += 1
                    if components == 2:
                        break
            if components == 1:
                print(1)
            else:
                print(2)
prog()
        

import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        b = list(map(int,input().split()))
        unlocked_el = []
        unlocked = []
        locked = []
        output = [0]*n
        for i in range(n):
            if b[i]:
                locked.append(i)
            else:
                unlocked.append(i)
                unlocked_el.append(a[i])
        unlocked_el.sort(reverse = True)
        for i in locked:
            output[i] = str(a[i])
        for i in range(len(unlocked)):
            output[unlocked[i]] = str(unlocked_el[i])
        print(' '.join(output))
            
prog()

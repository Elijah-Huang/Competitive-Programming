import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    reorders = 0
    curr_remove = 1
    unordered_top = []
    for _ in range(2*int(input())):
        c = input().split()
        if len(c) == 2:
            a = c[0]
            b = int(c[1])
        else:
            a = c[0]
        if a == 'add':
            unordered_top.append(b)
        else:
            if len(unordered_top):
                if curr_remove == unordered_top[-1]:
                    unordered_top.pop()
                else:
                    reorders += 1
                    unordered_top = []
            curr_remove += 1
    print(reorders)
prog()
            

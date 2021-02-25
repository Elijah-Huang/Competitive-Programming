import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n,m,s,f = map(int,input().split())
    curr = s
    step = 1
    steps = {}
    output = []
    for i in range(m):
        t,l,r = map(int,input().split())
        steps[t] = [l,r]
    if f > s:
        while curr != f:
            if step not in steps:
                output.append('R')
                step += 1
                curr += 1
            elif curr + 1 < steps[step][0] or curr > steps[step][1]:
                output.append('R')
                step += 1
                curr += 1
            else:
                output.append('X')
                step += 1
    else:
        while curr != f:
            if step not in steps:
                output.append('L')
                step += 1
                curr -= 1
            elif curr - 1 > steps[step][1] or curr < steps[step][0]:
                output.append('L')
                step += 1
                curr -= 1
            else:
                output.append('X')
                step += 1
    print(''.join(output))
prog()
    

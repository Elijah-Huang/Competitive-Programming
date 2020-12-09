import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
from string import ascii_lowercase as L
def prog():
    for _ in range(int(input().strip())):
        n,m = map(int,input().split())
        strings = [input().strip() for i in range(n)]
        if n == 1:
            print(strings[0])
        else:
            worked = False
            a = strings.pop()
            for i in range(1,m+1):
                if worked:
                    break 
                for char in L:
                    fail = False
                    if i < m:
                        new = a[:i-1] + char + a[i:]
                    else:
                        new = a[:i-1] + char
                    for string in strings:
                        diff = 0 
                        for j in range(m):
                            if string[j] != new[j]:
                                diff += 1
                        if diff > 1:
                            fail = True
                            break
                    if not fail:
                        worked = True
                        output = new
                        break
            if worked:
                print(output)
            else:
                print(-1)
prog()

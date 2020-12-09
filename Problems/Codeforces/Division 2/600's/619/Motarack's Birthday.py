import sys
input = sys.stdin.buffer.readline
def print(*vals):
    sys.stdout.write(" ".join(map(str,vals)) + '\n')
def max_diff(integers,k,n):
    max_diff = 0
    for i in range(n-1):
        if integers[i] == -1 and integers[i+1] != -1:
            max_diff = max(max_diff, abs(k - integers[i+1]))
        elif integers[i+1] == -1 and integers[i] != -1:
            max_diff = max(max_diff, abs(integers[i] - k))
        else:
            max_diff = max(max_diff, abs(integers[i] - integers[i+1]))
    return max_diff
def prog():
    for _ in range(int(input())):
        n = int(input())
        integers = list(map(int,input().split()))
        L = 0
        R = 10**9
        while L != R:
            diff = (R-L)//3
            m1 = L + diff
            m2 = R - diff
            val1 = max_diff(integers,m1,n)
            val2 = max_diff(integers,m2,n)
            if val1 > val2:
                L = m1 + 1
            else:
                R = m2 - 1
        print(max_diff(integers,R,n),R)
prog()
            
                

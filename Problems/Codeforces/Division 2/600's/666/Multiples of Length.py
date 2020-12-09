import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    n = int(input())
    a = list(map(int,input().split()))
    if (n == 1):
        print('1 1')
        print(f"{-a[0]}")
        print('1 1')
        print('0')
        print('1 1')
        print('0')
        return
    print("1 1")
    print(f"{-a[0]}")
    a[0] = 0
    output = [0]*(n-1)
    for i in range(1,n):
        added = (a[i] % n)*(n-1)
        output[i-1] = str(added)
        a[i] += added
        a[i] = -a[i]
    print(f"2 {n}")
    print(' '.join(output))
    print(f"1 {n}")
    print(' '.join(map(str,a)))
prog()
        

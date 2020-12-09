import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        if k % n == 0:
            print('0')
        else:
            print('2')
        output = [['0']*n for i in range(n)]
        i = j = 0
        for a in range(k):
            output[i][j] = '1'
            i += 1
            j = (j+1) % n
            if i == n:
                i = 0
                j = (j+1) % n
        for row in output:
            print(''.join(row))
prog()

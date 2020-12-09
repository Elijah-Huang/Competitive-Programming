import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        last = list('a'*51)
        print(''.join(last))
        for i in a:
            if last[i] == 'a':
                last[i] = 'b'
            else:
                last[i] = 'a'
            print(''.join(last))
prog()

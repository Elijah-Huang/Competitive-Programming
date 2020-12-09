import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        s = input().strip()
        start = s[0]
        switches = 1
        for i in range(n-1):
            if s[i] != s[i+1]:
                switches += 1
        if switches == 1:
            sys.stdout.write(s + '\n')
        elif switches == 2 and start == '0':
            sys.stdout.write(s + '\n')
        elif start == '1':
            if switches % 2 == 0:
                sys.stdout.write('0\n')
            else:
                for i in range(1,n):
                    if s[-i] == '0':
                        break
                sys.stdout.write('0' + '1'*(i-1) + '\n')
        else:
            if switches % 2 == 0:
                for i in range(1,n+1):
                    if s[-i] == '0':
                        break
                for j in range(n):
                    if s[j] == '1':
                        break
                sys.stdout.write('0'*(j)+ '0' + '1'*(i-1) + '\n')
            else:
                for j in range(n):
                    if s[j] == '1':
                        break
                sys.stdout.write('0'*(j+1) + '\n')
prog()

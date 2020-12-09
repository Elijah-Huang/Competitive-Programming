import sys
input = sys.stdin.buffer.readline
def prog():
    for  _ in range(int(input())):
        n,m,a,b = map(int,input().split())
        if n*a == m*b:
            print('YES')
            string = '1'*a + '0'*(m-a)
            for i in range(n):
                print(string)
                string = string[m-a:] + string[:m-a]
        else:
            print('NO')
prog()

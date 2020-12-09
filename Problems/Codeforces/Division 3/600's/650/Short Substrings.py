import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        b = input().strip()
        output = b[0]
        for i in range(1,len(b)-2,2):
            output += b[i]
        output += b[-1]
        sys.stdout.write(output + '\n')
prog()

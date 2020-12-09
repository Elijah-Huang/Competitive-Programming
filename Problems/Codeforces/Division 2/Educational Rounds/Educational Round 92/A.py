import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        l,r = map(int, input().split())
        if 2*l > r:
            sys.stdout.write("-1 -1\n")
        else:
            sys.stdout.write(f"{l} {2*l}\n")
prog()
        

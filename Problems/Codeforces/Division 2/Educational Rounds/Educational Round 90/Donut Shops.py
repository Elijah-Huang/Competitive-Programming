import sys
def prog():
    for _ in range(int(input())):
        a,b,c = map(int,input().split())
        if c > a:
            sys.stdout.write("1")
        else:
            sys.stdout.write("-1")
        if b*a > c:
            sys.stdout.write(" " + str(b) + "\n")
        else:
            sys.stdout.write(" -1\n")
prog()

import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        a = set(map(int,input().split()))
        b = list(map(int,input().split()))
        found = False
        for c in b:
            if c in a:
                print("YES")
                print(1,c)
                found = True
                break
        if not found:
            print("NO")
prog()
        
        

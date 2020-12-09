import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        s = input().strip()

        need = [0]*k
        fail = False
        for start in range(k):
            seen = [0]*3
            for i in range(start,n,k):
                if s[i] == '?':
                    seen[2] = 1
                elif s[i] == '0':
                    seen[0] = 1
                elif s[i] == '1':
                    seen[1] = 1
            if seen[0] == 1 and seen[1] == 1:
                fail = True
                break
            else:
                if seen[1]:
                    need[start] = 1
                elif seen[0] == 0:
                    need[start] = 2
        if fail:
            print("NO")
        else:
            diff = 0
            free = 0
            for i in range(k):
                if need[i] == 0:
                    diff -= 1
                elif need[i] == 1:
                    diff += 1
                else:
                    free += 1
            diff = max(diff, -diff)
            if diff > free:
                print("NO")
            else:
                print("YES")
    
prog()

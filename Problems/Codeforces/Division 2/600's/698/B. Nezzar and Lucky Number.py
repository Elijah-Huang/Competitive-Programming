import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val)
    sys.stdout.write('\n')

def prog():
    for _ in range(int(input())):
        q,d = map(int,input().split())
        qs = list(map(int,input().split()))
        out = []
        for a in qs:
            if a >= d*10+d or d == a//10:
                out.append("YES")
            else:
                worked = False
                while a > 0:
                    if a % d == 0:
                        worked = True
                        break
                    a -= 10
                out.append("YES" if worked else "NO")
        print('\n'.join(out))

prog()

import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def yo():
    for _ in range(int(input().strip())):
        a,b,q = map(int,input().split())
        bad = [0 for i in range(a*b)]
        for x in range(a*b):
            if (x%a) % b == (x%b) % a:
                bad[x] = 1
        for i in range(1,a*b):
            bad[i] += bad[i-1]
        for _ in range(q):
            l, r = map(int,input().split())
            total = r - l + 1
            total_bad = 0
            if l// (a*b) == r//(a*b):
                if l%(a*b) == 0:
                    total_bad += bad[r%(a*b)]
                else:
                    total_bad += bad[r%(a*b)] - bad[l%(a*b) -1]
                total -= total_bad
                print(total)
            else:
                if l%(a*b) == 0:
                    total_bad += bad[-1]
                else:
                    total_bad += bad[-1] - bad[l%(a*b) -1]
                total_bad += bad[r%(a*b)] 
                q = l// (a*b)
                bottom = (q + 1)
                top = r//(a*b)
                total_bad += (top - bottom)*bad[-1]
                total -= total_bad
                print(total)
yo()
        

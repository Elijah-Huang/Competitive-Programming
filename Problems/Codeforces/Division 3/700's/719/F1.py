import sys
input = sys.stdin.buffer.readline

def query(l,r):
    print(f"? {l} {r}")
    sys.stdout.flush()

    return int(input())

def found(i):
    print(f"! {i}")
    sys.stdout.flush()

n,t = map(int,input().split())
request = []
for i in range(t):
    request.append(int(input()))

pos = 0
tot = 0
for i in range(20,-1,-1):
    if pos + (1 << i) > n:
        continue
    else:
        amt = query(pos+1,pos+(1<<i))
        if tot + amt > pos + (1<<i) - request[0]:
            pos += (1<<i)
            tot += amt

found(pos+1)

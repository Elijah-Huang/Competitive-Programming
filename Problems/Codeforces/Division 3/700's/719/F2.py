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

k = int(input())

changed = [0]*(n+1)
blocks = [0]*(n//16+1) # blocks of size 16 # of zeros
for i in range(1,n//16+1):
    blocks[i] = 16 - query((i-1)*16+1, i*16)

for j in range(t):
    num0 = blocks[0]
    idx = 0
    while idx + 1 < len(blocks) and num0 + blocks[idx+1] < k:
        idx += 1
        num0 += blocks[idx]

    pos = 16*(idx)

    diff0 = k - num0
    num0 = 0
    for i in range(3,-1,-1):
        if pos + (1 << i) > n:
            continue

        new0 = (1<<i) - query(pos+1,pos+(1<<i))
        if num0 + new0 < diff0:
            pos += (1<<i)
            num0 += new0

    found(pos+1)

    if idx+1 < len(blocks):
        blocks[idx+1] -= 1

    if j != t-1:
        k = int(input())
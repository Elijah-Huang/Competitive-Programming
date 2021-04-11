import sys
input = sys.stdin.buffer.readline

n,m,d = map(int,input().split())
c = list(map(int,input().split()))

ssum = [0]*(m+1)
for i in range(m-1,-1,-1):
    ssum[i] = c[i] + ssum[i+1]
output = [0]*n

pos = 0
for i in range(m):
    if n - pos <= d - 1 + ssum[i]:
        for j in range(i,m):
            for k in range(c[j]):
                output[pos] = j+1
                pos += 1
        break
    else:
        for j in range(pos+d,pos+d+c[i]):
            output[j-1] = i+1
        pos = pos + d + c[i] - 1

if pos + d >= n+1:
    print("YES")
    print(*output)
else:
    print("NO")

import sys
input = sys.stdin.buffer.readline

n,s = map(int,input().split())

degree = [0]*(n+1)
for i in range(n-1):
    a,b = map(int,input().split())
    degree[a] += 1
    degree[b] += 1

print(2*s/degree.count(1))
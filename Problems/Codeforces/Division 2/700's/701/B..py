import sys
input = sys.stdin.readline

n,q,k = map(int,input().split())
a = list(map(int,input().split()))

for i in range(q):
    l,r = map(int,input().split())
    l-=1; r-=1
    print(2*(k-(r-l+1)) - (a[l] -1 + k - a[r]))
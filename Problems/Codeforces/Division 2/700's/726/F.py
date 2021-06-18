import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n,m = map(int,input().split())

    v = list(map(int,input().split()))
    t = list(map(int,input().split()))

    edges = [list(map(int,input().split())) for i in range(m)]

    totv = sum(v)
    tott = sum(t)


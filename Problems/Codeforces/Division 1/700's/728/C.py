import sys
input = sys.stdin.buffer.readline

n = int(input())
c = list(map(int,input().split()))
b = list(map(int,input().split()))
q = int(input())
x = int(input())

dp = [[[0]*101 for i in range(101)] for i in range(n)] # pos, last, amt


for i in range(n-1):
    for j in range(101):
        for 
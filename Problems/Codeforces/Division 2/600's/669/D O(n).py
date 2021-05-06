import sys
input = sys.stdin.buffer.readline

n = int(input())
h = list(map(int,input().split()))

next_small = [-1]*n
next_large = [-1]*n

transitions = [[] for i in range(n)]

s = []
for i in range(n):
    while s and h[i] > s[-1][0]:
        s.pop()

    if s:
        transitions[s[-1][1]].append(i)

    s.append([h[i],i])

s = []
for i in range(n):
    while s and h[i] < s[-1][0]:
        s.pop()

    if s:
        transitions[s[-1][1]].append(i)

    s.append([h[i],i])

prev_small = [-1]*n
prev_large = [-1]*n

s = []
for i in range(n-1,-1,-1):
    while s and h[i] > s[-1][0]:
        s.pop()

    if s:
        transitions[i].append(s[-1][1])

    s.append([h[i],i])

s = []
for i in range(n-1,-1,-1):
    while s and h[i] < s[-1][0]:
        s.pop()

    if s:
        transitions[i].append(s[-1][1])

    s.append([h[i],i])

dp = [10**9]*n
dp[0] = 0
for i in range(n):
    for j in transitions[i]:
        dp[j] = min(dp[j], dp[i] + 1)

print(dp[n-1])
from math import inf
n = int(input())
rounds = []
for i in range(n):
    a,b = input().split()
    rounds.append([a,int(b)])
tot_scores = {}
for i in range(n):
    move = rounds[i]
    tot_scores[move[0]] = tot_scores.get(move[0],0) + move[1]
m = -inf
for player in tot_scores:
    m = max(m, tot_scores[player])
pos_winners = set()
for player in tot_scores:
    if tot_scores[player] == m:
        pos_winners.add(player)
scores = {}
for i in range(n):
    move = rounds[i]
    scores[move[0]] = scores.get(move[0],0) + move[1]
    if scores[move[0]] >= m and move[0] in pos_winners:
        print(move[0])
        break


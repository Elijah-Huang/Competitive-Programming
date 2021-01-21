from bisect import bisect_right
import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n = int(input())
    teams = {}
    loc_to_team = {}
    locs = []
    for i in range(n):
        x, team = map(int,input().split())
        if team in teams:
            teams[team].append(x)
        else:
            teams[team] = [x]
        locs.append(x)
        loc_to_team[x] = team

    locs.sort()    
    for team in teams.values():
        team.sort()

    shortest = 10**9
    right = 0
    for locs2 in teams.values():
        right = max(right, locs2[0])
    for old_left in locs:
        shortest = min(shortest, right - old_left)
        idx = bisect_right(teams[loc_to_team[old_left]], old_left)
        if idx == len(teams[loc_to_team[old_left]]):
            break
        else:
            right = max(right,teams[loc_to_team[old_left]][idx])

    print(shortest)
prog()
    

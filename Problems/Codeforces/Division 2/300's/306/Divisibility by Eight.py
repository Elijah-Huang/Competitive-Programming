from itertools import combinations
def prog():
    s = '00' + input().strip()
    worked = False
    for combo in combinations(s,3):
        combo = int("".join(combo))
        if combo % 8 == 0:
            print('YES')
            print(combo)
            worked = True
            break
    if not worked:
        print('NO')
prog()

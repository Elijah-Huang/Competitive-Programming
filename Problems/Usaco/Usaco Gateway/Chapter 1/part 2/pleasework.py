"""
ID: elijahj1
LANG: PYTHON3
TASK: ride
"""
def get_score(s):
    score = 1
    for c in s:
        score *= ord(c) - ord('A') + 1
    return score


def should_ride(comet, group):
    return get_score(comet) % 47 == get_score(group) % 47



fin = open('ride.in', 'r')
fout = open('ride.out', 'w')
comet, group = fin.read().splitlines()
result = "GO\n" if should_ride(comet, group) else "STAY\n"
fout.write(result)
fout.close()

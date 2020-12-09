"""
ID: elijahj1
TASK: ride
LANG: PYTHON3
"""
"""def get_score(s):
    score = 1
    for c in s:
        score *= ord(c) - ord('A') + 1
    return score"""
from sys import stdin,stdout
letters ={'A':1,'B':2,'C':3,'D':4,'E':5,'F':6,'G':7,'H':8,'I':9,'J':10,'K':11,'L':12,'M':13,'N':14,'O':15,'P':16,'Q':17,'R':18,'S':19,'T':20,'U':21,'V':22,'W':23,'X':24,'Y':25,'Z':26}
with open('ride.in') as ride:
    comet = "".join(stdin.readline().split())
    group = "".join(stdin.readline().split())
comet_prod = 1
group_prod = 1
for letter in comet:
    comet_prod *= letters[letter]
for letter in group:
    group_prod *= letters[letter]
output = 's'
if group_prod % 47 != comet_prod % 47:
    output = 'STAY\n'
else:
    output = 'GO\n'
stdout.write(output)
with open('ride.out', 'w') as fout:
    fout.write(output)
    

    


import sys
input = sys.stdin.readline
from collections import Counter
def print(val):
    sys.stdout.write(val)
    sys.stdout.write('\n')
def prog():
    win = {'R':'P','S':'R','P':'S'}
    for _ in range(int(input())):
        s = input().strip()
        n = len(s)
        s1 = Counter(s)
        letter = s1.most_common(1)[0][0]
        print(win[letter]*n)
prog()
        

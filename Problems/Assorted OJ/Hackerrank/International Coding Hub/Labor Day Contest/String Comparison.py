from collections import Counter
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    n = input().strip()
    m = Counter(input().strip())

    best = len(n) + 1
    for i in range(len(n)):
        for j in range(i+1,len(n) + 1):
            test = Counter(n[i:j])
            fail = False
            for c in m:
                if c not in test:
                    fail = True
                    break
            if not fail:
                best = min(best, j - i)
                
    print(best if best != len(n) + 1 else "N/A")
            
prog()

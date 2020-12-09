from collections import Counter
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = Counter()
        for i in range(n):
            a.update(input().strip())
        fail = False
        for b in a.values():
            if b % n != 0:
                print('NO')
                fail = True
                break
        if not fail:
            print('YES')
prog()
        

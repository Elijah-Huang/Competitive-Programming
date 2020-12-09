from collections import Counter
import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        b = Counter(map(int,input().split()))
        
        worked = False
        for i in b.values():
            if i > 1:
                worked = True
                break

        print("YES" if worked else "NO")
prog()
        
    

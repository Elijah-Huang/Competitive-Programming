from collections import Counter
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        fillings = Counter(map(int,input().split()))
        
            

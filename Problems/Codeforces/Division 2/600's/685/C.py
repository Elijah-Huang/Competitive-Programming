import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        strings = [input().strip(),input().strip()]
        amts = [[0]*26 for i in range(2)]
        total = 0
        total2 = 0
        worked = True
        
        for i in range(2):
            for j in range(n):
                amts[i][ord(strings[i][j])-ord('a')] += 1
        
        for j in range(26):
            total += amts[0][j]
            total2 += amts[1][j]
            if total < total2 or (amts[1][j] - amts[0][j]) % k != 0:
                worked = False

        print("Yes" if worked else "No")
prog()

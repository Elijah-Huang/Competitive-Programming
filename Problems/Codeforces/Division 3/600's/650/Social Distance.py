import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        line = input().strip()
        placed = 0
        length = 0
        found = False
        for i in range(n):
            if line[i] == '1':
                found = True
                break
        l = i - found
        found = False
        for i in range(n-1,-1,-1):
            if line[i] == '1':
                found = True
                break
        r = i + found
        if r <= l:
            length = n
            length -= 1
            placed += 1 + length//(k+1)
        else:
            lengths = [l+1,n-r]
            for length in lengths:
                length -= k + 1
                if length >= 0:
                    placed += 1 + length//(k+1)
        length = 0
        for i in range(l+1,r):
            if line[i] == '1':
                length -= 2*k + 1
                if length >= 0:
                    placed += 1 + length//(k+1)
                length = 0
            else:
                length += 1
        print(placed)
prog()
                

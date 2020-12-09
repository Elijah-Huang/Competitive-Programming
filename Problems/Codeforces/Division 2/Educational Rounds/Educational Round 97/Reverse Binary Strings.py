import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        s = input().strip()
        one = 0
        zero = 0
        for i in range(n-1):
            if s[i] == '0' and s[i] == s[i+1]:
                zero+=1
            elif s[i] == '1' and s[i] == s[i+1]:
                one+=1
        print(max(zero,one))
prog()

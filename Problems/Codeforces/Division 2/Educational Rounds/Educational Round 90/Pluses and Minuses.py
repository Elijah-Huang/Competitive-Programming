import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        s = input().strip()
        res = 0
        mx = 1
        curr = 0
        for i in range(len(s)):
            c = s[i]
            if c == '+':
                curr -= 1
            else:
                curr += 1
                if curr == mx:
                    res += i+1
                    mx += 1
        res += len(s)
        print(res)
prog()
            
        

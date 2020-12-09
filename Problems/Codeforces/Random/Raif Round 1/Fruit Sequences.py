import sys
input = sys.stdin.readline

def prog():
    ans = 0
    curr_total = 0
    last_loc_with_val = [-1]*500001
    n = int(input())
    s = input().strip()
    
    i = 0
    while i < n:
        if s[i] == '0':
            ans += curr_total
        else:
            l = i
            r = i
            while r + 1 < n and s[r+1] == '1':
                r += 1

            for length in range(1,r-l+2):
                curr_total += l + length - 1 - last_loc_with_val[length]
                ans += curr_total
                last_loc_with_val[length] = r - length + 1

            i = r
            
        i += 1
                
    print(ans)

prog()
    

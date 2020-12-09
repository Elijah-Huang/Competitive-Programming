import sys
input = sys.stdin.buffer.readline

def prog():
    n = int(input())
    a = list(map(int,input().split()))
    
    freq = [0]*101
    for i in range(n):
        freq[a[i]] += 1
    mx = max(freq)
    amt = freq.count(mx)
    
    if amt >= 2:
        print(n)
    else:
        must_appear = freq.index(mx)
        ans = 0
        for j in range(1,101):
            if j == must_appear:
                continue
            
            first_idx = [10**6]*(n+1)
            first_idx[0] = -1
            curr = 0
            for i in range(n):
                if a[i] == must_appear:
                    curr += 1
                elif a[i] == j:
                    curr -= 1
                ans = max(ans, i - first_idx[curr])
                first_idx[curr] = min(first_idx[curr],i)
                
        print(ans)

prog()
    

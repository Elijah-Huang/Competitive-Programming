import sys
input = sys.stdin.buffer.readline

def largest_good(a):
    if len(a) <= 3:
        return len(a)
    
    mx = max(a)
    cutoff = 1
    while 2*cutoff <= mx:
        cutoff*=2
    s0 = []
    s1 = []
    for i in a:
        if i < cutoff:
            s0.append(i)
        else:
            s1.append(i)

    if s0 and s1:
        return 1 + max(largest_good(s0),largest_good(s1))
    else:
        s1 = [i - cutoff for i in s1]
        return largest_good(s1)
    
            
def prog():
    n = int(input())
    a = list(map(int,input().split()))

    print(n - largest_good(a))

prog()

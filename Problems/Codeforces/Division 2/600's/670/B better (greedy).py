for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    
    neg = []
    pos = []
    for i in a:
        if i < 0:
            neg.append(i)
        else:
            pos.append(i)
    neg.sort(reverse = True)
    pos.sort()
    
    ans = -10**18
    for i in range(5,0,-2):
        if len(pos) >= i and len(neg) >= (5-i):
            curr = 1
            for j in range(-1,-i-1,-1):
                curr *= pos[j]
            for j in range(-1,-(5-i)-1,-1):
                curr *= neg[j]
            ans = max(ans,curr)
        if len(neg) >= i and len(pos) >= (5-i):
            curr = 1
            for j in range(i):
                curr *= neg[j]
            for j in range(5-i):
                curr *= pos[j]
            ans = max(ans,curr)
    print(ans)


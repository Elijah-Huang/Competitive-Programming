def prog():
    for _ in range(int(input())):
        n,x,m = map(int,input().split())
        indexes  = [list(map(int,input().split())) for i in range(m)]
        left = x
        right = x
        for swap in indexes:
            a,b = swap
            if not( right < a or left > b):
                right = max(b,right)
                left = min(a,left)
        print(right-left + 1)
prog()

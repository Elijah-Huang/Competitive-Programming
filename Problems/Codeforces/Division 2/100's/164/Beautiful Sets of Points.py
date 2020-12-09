def prog():
    n,m = map(int,input().split())
    if n <= m:
        print(n+1)
        x = n
        y = 0
        for i in range(n+1):
            print(x,y)
            x -= 1
            y += 1
    else:
        print(m+1)
        y = m
        x = 0
        for i in range(m+1):
            print(x,y)
            y -= 1
            x += 1
prog()

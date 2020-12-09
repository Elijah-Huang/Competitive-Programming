def prog():
    n = 10**7
    prev = (1,0)
    for i in range(n):
        curr = (prev[1]*3 % 1000000007 , (prev[0]+ 2*prev[1]) % 1000000007)
        prev = curr
    print(prev[0])
prog()


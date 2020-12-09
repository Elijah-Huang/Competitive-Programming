def prog():
    for _ in range(int(input())):
        a,b,n = map(int,input().split())
        if a < b:
            a,b = b,a
        operations = 0
        while a <= n:
            a,b = a+b,a
            operations += 1
        print(operations)
prog()
            

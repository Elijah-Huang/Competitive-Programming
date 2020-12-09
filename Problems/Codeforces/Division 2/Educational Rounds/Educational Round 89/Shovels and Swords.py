def prog():
    for _ in range(int(input())):
        a,b = map(int,input().split())
        if b > a:
            c = a
            a = b
            b = c
        if a >= 2*b:
            print(b)
        else:
            print((a+b)//3)
prog()
        

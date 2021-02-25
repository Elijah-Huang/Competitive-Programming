for _ in range(int(input())):
    a,b=  map(int,input().split())
    b-=1

    mn = 30
    for i in range(30):
        b += 1
        if b == 1:
            continue
        divide_ops = 0
        a2 = a
        while a2:
            a2//=b
            divide_ops+=1

        mn = min(mn, divide_ops + i)

    print(mn)

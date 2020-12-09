for i in range(int(input().strip())):
    n, a, b, c ,d = map(int,input().split())
    min = c - d
    max = c + d
    absmin = n*(a-b)
    absmax = n*(a+b)
    if min <= absmin <= max or min <= absmax <= max or absmin <= min and max <=absmax:
        print("YES")
    else:
        print("NO")

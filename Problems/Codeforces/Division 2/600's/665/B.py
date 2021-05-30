for _ in range(int(input())):
    x1,y1,z1 = map(int,input().split())
    x2,y2,z2 = map(int,input().split())

    print(2*min(z1,y2) - 2*max(0,z2 - x1 - (z1-min(z1,y2))))
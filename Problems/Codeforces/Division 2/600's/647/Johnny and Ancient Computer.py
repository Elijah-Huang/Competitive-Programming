def prog():
    for _ in range(int(input().strip())):
        a,b = map(int,input().split())
        if b == a:
            print(0)
        elif b > a:
            worked = False
            for val in range(1,61):
                a*= 2
                if b == a:
                    worked = True
                    break
            if not worked:
                print(-1)
            else:
                if val % 3 == 0:
                    print(int(val/3))
                else:
                    print(int(val/3) + 1)
        else:
            worked = False
            for val in range(1,61):
                b*= 2
                if b == a:
                    worked = True
                    break
            if not worked:
                print(-1)
            else:
                if val % 3 == 0:
                    print(int(val/3))
                else:
                    print(int(val/3) + 1)
prog()
            

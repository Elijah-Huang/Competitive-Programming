r1, r2 = map(int,input().split())
c1, c2 = map(int,input().split())
d1, d2 = map(int,input().split())
def prog():
    for a1 in range(1,10):
        for a2 in range(1, 10):
            for b1 in range(1 ,10):
                for b2 in range(1 ,10):
                    if (not (a1 == b1 or a1 == a2 or a1 == b2 or b1 == b2 or b1 == a2 or a2 == b2)) and \
                       r1 == a1 + a2 and r2 == b1 + b2 and c1 == a1 + b1 \
                       and c2 == a2 + b2 and d1 == a1 + b2 and d2 == a2 + b1:
                        print(a1, a2)
                        print(b1, b2)
                        return
    print(-1)
prog()
                    
                

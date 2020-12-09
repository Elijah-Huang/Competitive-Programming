for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    needa = min(a)
    needb = min(b)
    moves = 0
    for i in range(n):
        moves += a[i] - needa  + b[i] - needb - min(a[i] - needa, b[i] - needb)
    print(moves)

    

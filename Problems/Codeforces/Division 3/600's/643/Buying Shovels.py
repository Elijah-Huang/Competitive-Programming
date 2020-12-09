def prog():
    for _ in range(int(input().strip())):
        n,k = map(int,input().split())
        if k >= n:
            print(1)
        elif (n % 2) == 0 and k*2 >=n:
            print(2)
        else:
            w = n
            x = 0
            for i in range(3,min(int(n/k),k)+1):
                if (n % i) == 0:
                    x = i
                    
            for i in range(int(n/k)+1,int(n**0.5) + 1):
                if (n % i) == 0:
                    w = i
                    break
            if x:
                x = int(n/x)
                if x < w:
                    print(x)
                else:
                    print(w)
            else:
                print(w)
prog()

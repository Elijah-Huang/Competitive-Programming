for i in range(int(input().strip())):
    n = int(input().strip())
    k = 2
    while True:
        x = n%(2**k - 1)
        if x == 0:
            print(int(n/(2**k-1)))
            break
        else:
            k += 1
    
    

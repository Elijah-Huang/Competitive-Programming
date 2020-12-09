def prog():
    inv_8 = pow(8, 1000000007  -2, 1000000007 )
    n = int(input())
    if n % 2 == 0:
        print((3 + int(18*(pow(9,(n-2)//2,1000000007 ) - 1)*inv_8)) % 1000000007 )
    else:
        print(int(6*(pow(9,(n-1)//2,1000000007 ) - 1)*inv_8)% 1000000007 )
prog()

for _ in range(int(input())):
    n = int(input())
    if n < 4:
        print(-1)
    else:
        perm = []
        if n % 2 == 0:
            for i in range(n-1,0,-2):
                perm.append(i)
            perm.append(4)
            perm.append(2)
            for i in range(6,n+1,2):
                perm.append(i)
        else:
            for i in range(n,0,-2):
                perm.append(i)
            perm.append(4)
            perm.append(2)
            for i in range(6,n,2):
                perm.append(i)
        print(" ".join(map(str,perm)))

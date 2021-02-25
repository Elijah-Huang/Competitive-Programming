for _ in range(int(input())):
    n,k = map(int,input().split())
    k-=1

    if n % 2 == 0:
        print(1 + k%n)
    else:
        print(1 + (k + k//(n//2))%n)

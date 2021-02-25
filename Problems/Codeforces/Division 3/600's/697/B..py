for _ in range(int(input())):
    n = int(input())
    if n%2020 <= n//2020:
        print("YES")
    else:
        print("NO")
def sum_2_and_3(x):
    p = 0
    while x % 2 == 0:
        x //= 2
        p+=1
    while x % 3 == 0:
        x //= 3
        p-=1
    return p

n = int(input())
print(*sorted(map(int,input().split()), key= sum_2_and_3))
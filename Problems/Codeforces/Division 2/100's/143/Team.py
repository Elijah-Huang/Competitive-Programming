n = int(input())
amt = 0
for i in range(n):
    amt += sum(map(int,input().split())) >= 2
print(amt)

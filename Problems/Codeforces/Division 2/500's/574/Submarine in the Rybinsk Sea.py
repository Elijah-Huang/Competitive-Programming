n = int(input())
a = list(input().split())
total = 0
for num in a:
    new = ''
    for digit in num:
        new += 2*digit
    total = (total + n*int(new)) % 998244353 
print(total)

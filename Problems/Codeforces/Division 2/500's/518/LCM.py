b = int(input())
divisors = 0
for i in range(1,int(b**0.5) + 1):
    if b % i == 0:
        divisors += 1
if (int(b**0.5))**2 == b:
    total = 2*divisors - 1
else:
    total = 2*divisors
print(total)

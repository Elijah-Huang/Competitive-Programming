def gcd(a,b):
    return gcd(b,a%b) if b else a

def sum_digit(a):
    tot = 0
    while a:
        tot += a % 10
        a //= 10
    return tot

for _ in range(int(input())):
    n = int(input())

    while gcd(n, sum_digit(n)) == 1:
        n += 1

    print(n)
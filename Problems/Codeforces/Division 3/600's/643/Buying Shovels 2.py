import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')


def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        divisors = []
        for i in range(1,int(n**0.5) + 1):
            if n % i == 0:
                if i <= k:
                    divisors.append(i)
                new = n//i
                if new <= k:
                    divisors.append(new)
        print(n//max(divisors))
prog()
            

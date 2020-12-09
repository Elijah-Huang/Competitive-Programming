import sys
input = sys.stdin.readline
def prog():
    mod = 10**9 + 7
    amounts = [0,0,0,1]
    for i in range(2*10**6):
        amounts.append((1 + amounts[-1] + 2*amounts[-2]) % mod)
    odds = [0,1]
    for i in range(2,10**6):
        odds.append((odds[-1] + amounts[2*i+1] - amounts[2*i]) % mod)
    evens = [0,1]
    for i in range(2,10**6):
        evens.append((evens[-1] + amounts[2*i+2] - amounts[2*i+1]) % mod)
    for _ in range(int(input())):
        n = int(input())
        if n < 3:
            sys.stdout.write('0\n')
        else:
            if n % 2 == 0:
                n -= 2
                n //= 2
                sys.stdout.write(str((4*evens[n])% mod) + '\n')
            else:
                n -= 1
                n //= 2
                sys.stdout.write(str((4*odds[n])%mod) + '\n')
prog()

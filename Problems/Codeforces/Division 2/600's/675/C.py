import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    mod = 10**9 + 7
    n = input().strip()[::-1]
    psum = [0]
    twos = [1]*(10**5)
    tens = [1]*(10**5)
    for i in range(1,len(n)):
        twos[i] = (twos[i-1]*2) % mod
        tens[i] = (tens[i-1]*10) % mod
    for i in range(len(n)):
        psum.append((psum[-1] + int(n[i])*tens[i])%mod)
    ans = 0
    for i in range(1,len(n)-1):
        ans = (ans + (twos[i]-1)*(psum[len(n)]-psum[i])) % mod
    for i in range(1,len(n)-1):
        ans = (ans + (twos[i]-1)*(psum[len(n)]-psum[i])) % mod


    print((ans + mod)%mod)
        

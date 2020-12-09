import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    mod = 10**9 + 7
    n = input().strip()[::-1]
    psum1 = [0]*(10**5 + 1)
    psum2 = [0]*(10**5 + 1)
    psum11 = [0]*(10**5 + 1)
    psum22 = [0]*(10**5 + 1)
    tens = [1]*(10**5 + 1)
    tens_inv = [1]*(10**5 + 1)
    
    for i in range(1,len(n)):
        tens[i] = (tens[i-1]*10) % mod
    tens_inv[len(n)-1] = pow(pow(10,len(n)-1,mod),mod-2,mod)
    for i in range(len(n)-2,-1,-1):
        tens_inv[i] = (tens_inv[i+1]*10) % mod
        
    for i in range(len(n)):
        psum1[i+1] = (psum1[i] + int(n[i])*tens[i]) % mod
    for i in range(len(n)-1,-1,-1):
        psum2[i] = (psum2[i+1] + int(n[i])*tens[i]) % mod

    for i in range(len(n)):
        psum11[i+1] = (psum11[i] + psum1[i+1]) % mod
    for i in range(len(n)-1,-1,-1):
        psum22[i] = (psum22[i+1] + psum2[i]) % mod
        
    ans = 0
    for i in range(1,len(n)):
        ans = (ans + psum11[len(n)-i] + psum22[i]*tens_inv[i]) % mod
        
    print((ans + mod)%mod)
prog()      

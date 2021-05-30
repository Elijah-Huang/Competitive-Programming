import sys
input = sys.stdin.buffer.readline

mod = 10**9 + 7

n = 10**5
fac = [0]*(n+1)
inv_fac = [0]*(n+1)

fac[0] = 1
for i in range(1,n+1):
    fac[i] = fac[i-1] * i % mod

inv_fac[n] = pow(fac[n],mod-2,mod)
for i in range(n-1,-1,-1):
    inv_fac[i] = inv_fac[i+1] * (i+1) % mod

def choose(n,k):
    if k > n:
        return 0
    return fac[n] * inv_fac[k] * inv_fac[n-k] % mod

for _ in range(int(input())):
    n, k = map(int, input().split())

    ans = 0

    not_finished = [0] + [choose(n-(m-1)*(k-1),m) for m in range(1,n+1)]

    for m in range(2,n+1):
        # ways to have m lights given that before placing the mth, the algorithm wasn't finished -
        # ways to have m lights where the algorithm isn't finished yet =
        # ways to have m lights where the algorithm has finished (complementary counting)
        # n-(m-1) free spots and m ways to create each unfinished position
        num_finished = ((n-(m-1))*not_finished[m-1] - m*not_finished[m]) % mod

        # (m-1)! ways to turn on the first m-1 switches (last is fixed since it causes algorithm to stop)
        # thus there are num_finished*fac[m-1] different sequences to turn m lights on so it finishes
        # probability of each is n*n-1*...*(n-(m-1))
        ans = (ans + num_finished*fac[m-1]*fac[n-m]*inv_fac[n]*m) % mod

    print(ans)
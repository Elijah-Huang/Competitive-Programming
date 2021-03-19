import sys
input = sys.stdin.buffer.readline

maxn = 2*10 ** 7 + 1
whyistimelimitsotight = {}
pairs = [0] * maxn
spf = [0] * maxn

for i in range(2, maxn):
    if spf[i] == 0:
        for j in range(i, maxn, i):
            pairs[j] += 1
            if spf[j] == 0:
                spf[j] = i

def divisors(n):
    pf = []
    while n > 1:
        if len(pf) == 0 or pf[-1][0] != spf[n]:
            pf.append([spf[n],1])
        else:
            pf[-1][1] += 1

        n//= spf[n]

    divs = [1]
    for prime, count in pf:
        l = len(divs)
        prime_pow = 1

        for i in range(count):
            prime_pow *= prime
            for j in range(l):
                divs.append(divs[j]*prime_pow)

    return divs


for _ in range(int(input())):
    c,d,x = map(int,input().split())
    ans = 0

    if x in whyistimelimitsotight:
        divs = whyistimelimitsotight[x]
    else:
        whyistimelimitsotight[x] = divs = divisors(x)

    for i in divs:
        e = x//i + d
        if e % c == 0:
            ans += 1 << pairs[e//c]

    print(ans)
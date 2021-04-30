# TLE 64 bit -> big int -> slow :(
import sys
input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

mx = 0

pprod = [0]*(n+1)
for i in range(n):
    pprod[i] = pprod[i-1] + a[i]*b[i]

sprod = [0] * (n + 1)
for i in range(n-1,-1,-1):
    sprod[i] = sprod[i + 1] + a[i] * b[i]

for lmid in range(n):
    lmidorg = lmid
    for rmid in range(lmid,min(n,lmid+2)):
        lmid = lmidorg
        curr_prod = a[lmid]*b[rmid]
        if rmid > lmid:
            curr_prod += a[rmid]*b[lmid]

        mx = max(mx, curr_prod + pprod[lmid-1] + sprod[rmid+1])

        lmid -= 1
        rmid += 1
        while lmid >= 0 and rmid < n:
            curr_prod += a[rmid]*b[lmid] + a[lmid]*b[rmid]

            mx = max(mx, curr_prod + pprod[lmid - 1] + sprod[rmid + 1])
            lmid -= 1
            rmid += 1

print(mx)
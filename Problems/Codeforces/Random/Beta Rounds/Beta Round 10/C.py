def digital_root(x: int) -> int:
    if x <= 9:
        return x

    tot = 0
    while x:
        tot += x % 10
        x //= 10

    return digital_root(tot)

n = int(input())

counts = [0]*10
d = [0]*(n+1)

for i in range(1,n+1):
    d[i] = digital_root(i)
    counts[d[i]] += 1

answer = 0

# number of triples such that relation holds. i = d(c) j = d(a) k = d(b)
for i in range(1,10):
    for j in range(1,10):
        for k in range(1,10):
            if i == digital_root(j*k):
                answer += counts[i]*counts[j]*counts[k]

# subtract number of triples such that the relation holds but c = a*b
for a in range(1,n+1):
    for c in range(a,n+1,a):
        b = c//a

        if d[c] == d[d[a]*d[b]]:
            answer -= 1


print(answer)
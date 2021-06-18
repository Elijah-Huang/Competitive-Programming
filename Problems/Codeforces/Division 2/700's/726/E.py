import sys
input = sys.stdin.readline

def z_function(s):
    z = [0]*len(s)

    l = 0
    r = 0
    for i in range(1,len(s)):
        if i <= r:
            z[i] = min(z[i-l],r-i+1)

        while z[i] < len(s)//2 and i + z[i] < len(s) and s[i+z[i]] == s[z[i]]:
            z[i] += 1

        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1

    return z


n,k = map(int,input().split())

s = list(input().strip())
s += s

z = z_function(s)

stop = n

for i in range(1,n):
    if s[z[i]] < s[i+z[i]]:
        stop = i
        break

s = s[:stop]

final = s*((k+len(s)-1)//len(s))

print(''.join(final[:k]))

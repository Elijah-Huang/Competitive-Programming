import sys
input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int,input().split()))
vals = {}
for i in range(n):
    if a[i] in vals:
        vals[a[i]].append(i+1)
    else:
        vals[a[i]] = [i+1]

two = []
three = []
for i in vals:
    if len(vals[i]) >= 4:
        print("YES")
        print(*vals[i][:4])
        exit()
    elif len(vals[i]) >= 2:
        if len(vals[i]) == 3:
            three.append(vals[i])

        two.append(vals[i][:2])
        if len(two) == 2:
            print("YES")
            print(two[0][0],two[1][0],two[0][1],two[1][1])
            exit()

# now there can be at max one value that occurs 2-3 times
# if this val occurs 2-3 times, we can only use one of them -> avoid double count
# (also 3 of them will never be used in a solution)
# 2 can be used, but only for the same pair, so add this

sums = [0]* (5*10**6+1)

bad = []
if three:
    bad = [three[0][0]-1,three[0][1]-1]
    sums[2 * a[bad[0]]] = three[0][:2]
elif two:
    bad = [two[0][0] - 1]
    sums[2 * a[bad[0]]] = two[0]

# can only run max(2*ai) times before a match if found via pigeonhole
for i in range(n):
    if i in bad:
        continue

    for j in range(i+1,n):
        if j in bad:
            continue

        if sums[a[i] + a[j]]:
            print("YES")
            print(*sums[a[i]+a[j]], i+1, j+1)
            exit()
        else:
            sums[a[i]+a[j]] = [i+1,j+1]

print("NO")
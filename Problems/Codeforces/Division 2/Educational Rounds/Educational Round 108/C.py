import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())
    u = list(map(int,input().split()))
    s = list(map(int,input().split()))

    universities = {}

    for i in range(n):
        if u[i] in universities:
            universities[u[i]].append(s[i])
        else:
            universities[u[i]] = [s[i]]

    for i in universities:
        universities[i].sort(reverse = True)

        psum = [0]
        for j in range(len(universities[i])):
            psum.append(psum[-1] + universities[i][j])

        universities[i] = psum

    for k in range(1,n+1):
        remove = []

        tot = 0
        for i in universities:
            for j in range(k,len(universities[i]),k):
                tot += universities[i][j] - universities[i][j-k]

            if len(universities[i]) == k:
                remove.append(i)

        for i in remove:
            universities.pop(i)

        print(tot,end=' ')

    print()



import sys
input = sys.stdin.readline

order = [[] for i in range(4)]
for i in range(26):
    order[1].append(chr(ord('a')+i))

for i in range(26):
    for j in range(26):
        order[2].append(chr(ord('a') + i)+chr(ord('a') + j))

for i in range(26):
    for j in range(26):
        for k in range(26):
            order[3].append(chr(ord('a') + i)+chr(ord('a') + j)+chr(ord('a') + k))

for _ in range(int(input())):
    n = int(input())
    s = input().strip()

    found = 0
    for d in range(1,4):
        if found == 0:
            has = set()

            for i in range(n-d+1):
                has.add(s[i:i+d])

            for j in order[d]:
                if j not in has:
                    found = j
                    break

    print(found)
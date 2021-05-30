import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())

    usable = [[] for i in range(n+1)]
    usable[0].append([1,0])
    deepest = [1,0]
    for i in range(n):
        b = int(input())

        if len(usable[b-1]) == 0:
            assert(b==1)

            new = deepest.copy()
            new[0] += 1
            new.append(1)
            usable[1].append(new)

            deepest = new

        else:
            new = usable[b-1][-1].copy()
            new[-1] += 1

            for k in range(n+1):
                j = usable[k]

                while j and j[-1][0] >= new[0]:
                    j.pop()

            usable[b].append(new)

            deepest = new

        print('.'.join(map(str,new[1:])))
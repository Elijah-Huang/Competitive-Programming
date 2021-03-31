import sys
input = sys.stdin.buffer.readline

pow = {1<<i: i for i in range(20)}
for _ in range(int(input())):
    n,w = map(int, input().split())

    counts = [0]*20
    for i in map(int,input().split()):
        counts[pow[i]] += 1

    height = 0
    while counts != [0]*20:
        left = w
        for i in range(19,-1,-1):
            while counts[i] and left >= 1 << i:
                left -= 1 << i
                counts[i] -= 1

        height += 1

    print(height)
import sys
input = sys.stdin.buffer.readline

n,k = map(int, input().split())
if k*(k-1) >= n:
    print("YES")

    pairs = []
    for i in range(1,k+1):
        if len(pairs) == n:
            break
        for j in range(i+1,k+1):
            pairs.append([i,j])
            if len(pairs) == n:
                break
            pairs.append([j,i])
            if len(pairs) == n:
                break

    for pair in pairs:
        print(*pair)

else:
    print("NO")
def prog():
    for _ in range(int(input())):
        n = int(input())
        visited = [0]*(n+1)
        a = list(map(int,input().split()))
        perm = []
        for b in a:
            if not visited[b]:
                visited[b] = 1
                perm.append(str(b))
        print(' '.join(perm))
prog()

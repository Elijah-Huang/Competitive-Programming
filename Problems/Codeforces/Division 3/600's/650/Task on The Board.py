def prog():
    for _ in range(int(input())):
        s = list(input().strip())
        m = int(input())
        b = list(map(int,input().split()))
        s.sort(reverse = True)
        most = []
        prev = 'asdf'
        for val in s:
            if val != prev:
                prev = val
                most.append([1,val])
            else:
                most[-1][0] += 1
        idx = 0
        output = [0]*m
        placed = 0
        while placed != m:
            zeros = []
            for i in range(m):
                if b[i] == 0:
                    zeros.append(i)
            placed += len(zeros)
            for i in zeros:
                b[i] = -1
            while most[idx][0] < len(zeros):
                idx += 1
            for i in zeros:
                output[i] = most[idx][1]
                for j in range(m):
                    if b[j] != -1:
                        b[j] -= abs(i-j)
            idx += 1
        print("".join(output))
prog()
            
            

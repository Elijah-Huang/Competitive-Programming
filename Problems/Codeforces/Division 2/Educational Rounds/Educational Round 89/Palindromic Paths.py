import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        matrix = [list(map(int,input().split())) for i in range(n)]
        if n > m:
            new_matrix = [[0 for i in range(n)] for i in range(m)]
            for i in range(n):
                for j in range(m):
                    new_matrix[j][i] = matrix[i][j]
            matrix = new_matrix
            a = n
            n = m
            m = a
        change = 0
        for j in range((m+n-3)//2 + 1):
            i = 0
            j = j
            i2 = n-1
            j2 = m-1 - j
            zeros = 0
            ones = 0
            while i < n and 0 <= j:
                if matrix[i][j] == 0:
                    zeros += 1
                else:
                    ones += 1
                i += 1
                j -= 1
            while 0<= i2 and j2 < m:
                if matrix[i2][j2] == 0:
                    zeros += 1
                else:
                    ones += 1
                i2 -= 1
                j2 += 1
            change += min(zeros,ones)
        print(change)
prog()
            

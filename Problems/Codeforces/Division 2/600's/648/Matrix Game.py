def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        matrix = [list(map(int,input().split())) for i in range(n)]
        rows = n
        columns = m
        for row in matrix:
            for i in row:
                if i == 1:
                    rows -= 1
                    break
        for j in range(m):
            for i in range(n):
                if matrix[i][j] == 1:
                    columns -= 1
                    break
        optimal = min(rows, columns)
        if optimal % 2 == 0:
            print('Vivek')
        else:
            print('Ashish')
prog()
                
            
        
    

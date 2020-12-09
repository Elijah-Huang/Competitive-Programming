from sys import stdin, stdout
input = stdin.readline
def prog():
    n = int(input())
    array = [0]*n
    idx_xors = [[] for i in range(n)]
    xors = [0]*n
    same_as_start = False
    two_same = False
    
    for i in range(2,n+1):
        print(f'XOR {1} {i}')
        stdout.flush()
        xors[i-1] = int(input())
        
        if xors[i-1] == 0:
            same_as_start = i
            
        idx_xors[xors[i-1]].append(i)
        if len(idx_xors[xors[i-1]]) > 1:
            two_same = xors[i-1]

    if same_as_start:
        print(f'AND {1} {same_as_start}')
        stdout.flush()
        array[0] = int(input())
        
        for i in range(1,n):
            array[i] = xors[i]^array[0]
        print('!', *array)
        stdout.flush()
        
    elif two_same:
        print(f'AND {idx_xors[two_same][0]} {idx_xors[two_same][1]}')
        stdout.flush()
        array[0] = int(input())^two_same
        
        for i in range(1,n):
            array[i] = xors[i]^array[0]
        print('!',*array)
        stdout.flush()
        
    else:
        print(f'AND 1 {idx_xors[1][0]}')
        print(f'AND 1 {idx_xors[n-2][0]}')
        stdout.flush()
        array[0] = int(input()) + int(input())
        
        for i in range(1,n):
            array[i] = xors[i]^array[0]
        print('!',*array)
        stdout.flush()

prog()



























        
    
        

    

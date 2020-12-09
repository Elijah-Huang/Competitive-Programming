'''
ID: elijahj1
TASK: range
LANG: PYTHON3
'''
# Brute force is like O(n**4) BAD
'''
def prog():
    with open('range.in') as fin:
        n = int(fin.readline())
        field = [line.strip() for line in fin.readlines()]
    amounts = ''
    for size in range(2,n+1):
        amount = 0 
        for i in range(n-size+1):
            for j in range(n-size+1):
                filled = True
                for r in range(i,i+size):
                    if field[r][j:j+size] != '1'*size:
                        filled = False
                        break
                if filled:
                    amount += 1
        if amount:
            amounts += str(size) + ' ' + str(amount) + '\n'
    with open('range.out','w') as fout:
        fout.write(amounts)
prog()
'''
def prog():
    with open('range.in') as fin:
        n = int(fin.readline())
        field = [line.strip() for line in fin.readlines()]
        
    max_size = [[0 for i in range(n)]for i in range(n)]
    sizes = {}
    sizes2 = {}
    for i in range(n):
        for j in range(n):
            max_size[i][j] = int('1' == field[i][j])
    
    for i in range(1,n):
        for j in range(1,n):
            if field[i][j] == '1':
                max_size[i][j] = min(max_size[i][j-1],max_size[i-1][j-1],max_size[i-1][j]) + 1
                           
    for i in range(1,n):
        for j in range(1,n):
            ms = max_size[i][j]
            if ms > 1:
                sizes[ms] = sizes.get(ms,0) + 1
    for size in sizes:
        for s in range(2,size+1):
            sizes2[s] = sizes2.get(s,0) + sizes[size]       
    sizes3 = list(sizes2)
    sizes3.sort()
    output = ''
    for size in sizes3:
        output += str(size) + ' ' + str(sizes2[size]) + '\n'
    with open('range.out','w') as fout:
        fout.write(output)
prog()

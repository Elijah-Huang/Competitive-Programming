"""
ID: elijahj1
TASK: ratios
LANG: PYTHON3
"""
def determinant3(matrix):
    val = 0 
    for i in range(3):
        f = min((i+1)%3, (i+2)%3)
        l = max((i+1)%3, (i+2)%3)
        val += matrix[i][0]*(-1)**i*((matrix[f][1]*matrix[l][2] - matrix[f][2]*matrix[l][1]))
    return val  
def prog():
    with open('ratios.in') as fin:
        goal = list(map(int,fin.readline().split()))
        mixtures = [list(map(int,line.split())) for line in fin.readlines()]
    worked = []
    for mult in range(1,10**4):
        D = determinant3(mixtures)
        if D == 0:
            continue
        ngoal = [feed*mult for feed in goal]
        a1 = mixtures.copy()
        a1[0] = ngoal
        b1 = mixtures.copy()
        b1[1] = ngoal
        c1 = mixtures.copy()
        c1[2] = ngoal
        a = determinant3(a1)/D
        b = determinant3(b1)/D
        c = determinant3(c1)/D
        nums = [a,b,c]
        fail = False
        fail2 = False
        for num in nums:
            if num != int(num):
                fail = True
                break
            if num >= 100 or num < 0:
                fail = True
                fail2 = True
                break
        if not fail:
            output = f'{int(a)} {int(b)} {int(c)} {mult}'
            break 
        if fail2:
            output = 'NONE'
            break
    with open('ratios.out','w') as fout:
        fout.write(output + '\n')
prog()

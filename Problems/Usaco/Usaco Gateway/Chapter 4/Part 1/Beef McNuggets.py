'''
ID: elijahj1
TASK: nuggets
LANG: PYTHON3
'''
def prog():
    with open('nuggets.in') as fin:
        n = int(fin.readline().strip())
        sizes = list(map(int,fin.read().split()))
    gcd_one = True
    for p in [2,3,5,7,11,13]:
        all_divide = True
        for size in sizes:
            if (size % p) != 0:
                all_divide = False
                break 
        if all_divide:
            gcd_one = False
            break
    if not gcd_one or (1 in sizes):
        largest_impossible = 0
    else:
        packages = [False for i in range(256**2)]
        packages[0] = True
        for size in sizes:
            for i in range(256**2-size):
                if packages[i] is True:
                    packages[i+size] = True
        largest_impossible = 256**2
        for i in range(256**2-1,0,-1):
            if packages[i] == False:
                largest_impossible = i
                break
    with open('nuggets.out','w') as fout:
        fout.write(str(largest_impossible) + '\n')
prog()

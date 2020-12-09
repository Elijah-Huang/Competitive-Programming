'''
ID: elijahj1
TASK: subset
LANG: PYTHON3
'''
with open('subset.in') as fin:
    n = int(fin.readline().strip())
partitions = 0
if n % 4 == 2 or n % 4 == 1:
    pass
else:
    common_sum = n*(n+1)//4
    subsets = [[0 for j in range(n+1)] for i in range(common_sum + 1)]
    for i in range(1,n + 1):
        subsets[i][i] = 1
    for summ in range(2, common_sum + 1):
        for new_el in range(1, n+1):
            if new_el >= summ:
                break
            else:
                prev_sum = summ - new_el
                for max_el in range(1,new_el):
                    subsets[summ][new_el] += subsets[prev_sum][max_el]
    for max_el in range(1,n+1):
        partitions += subsets[common_sum][max_el]
    partitions //= 2
with open('subset.out','w') as fout:
    fout.write(str(partitions) + '\n')

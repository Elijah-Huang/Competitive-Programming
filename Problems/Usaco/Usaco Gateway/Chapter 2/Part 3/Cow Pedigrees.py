"""
ID: elijahj1
TASK: nocows
LANG: PYTHON3
"""

def choose(n,k):
    smaller = min(n-k,k)
    value = 1
    for i in range(n-smaller+1, n+1):
        value *= i
    for i in range(1, smaller+1):
        value //= i
    return value

def pedigrees(n,k):
    if n % 2 == 0:
        return 0
    if n < 2*k -1:
        return 0
    levels = [[{} for _ in range(n+1-(k-(level))*2)] for level in range(k+1)]
    levels[1][1][1] = 1
    curr_level = 1
    while curr_level < k:
        max_nodes = n-(k-(curr_level+1))*2
        for used in range(1,len(levels[curr_level])):
            leaves_dict = levels[curr_level][used]
            for leaves in leaves_dict.keys():
                for num_leaves_used in range(1, leaves+1):
                    new_leaves = num_leaves_used*2
                    if max_nodes < new_leaves + used:
                        break
                    else:
                        total_ways = choose(leaves, num_leaves_used)
                        levels[curr_level+1][used + new_leaves][new_leaves] \
                        = levels[curr_level+1][used + new_leaves].get(new_leaves,0)\
                        +leaves_dict[leaves]*total_ways
        curr_level += 1
    total = 0
    for num in levels[k][n].values():
        total += num
    return total % 9901 
   
with open('nocows.in') as fin:
    n,k = map(int,fin.readline().split())
total = pedigrees(n,k)
with open('nocows.out','w') as fout:
    fout.write(str(total) + '\n')

    



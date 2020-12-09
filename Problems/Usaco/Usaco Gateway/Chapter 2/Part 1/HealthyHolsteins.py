"""
ID: elijahj1
TASK: holstein
LANG: PYTHON3
"""

def generate_subset(cardinality, g, v,current = 0, subset=None):
    number_left = cardinality
    if subset is None:
        subset = set()
    if number_left != 0:
        number_left -= 1
        for a in range(current,g-(number_left)):
            if a not in subset:
                subset.add(a)
                if generate_subset(number_left, g, v, a+1, subset) is not None:
                    return subset
                else:
                    subset.remove(a)
    else:
        for b in range(v):
            total_vitamins = 0
            for c in subset:
                total_vitamins += feeds[c][b]
            if total_vitamins < requirements[b]:
                return
        return subset
               
    
def find_smallest_combo(feeds, requirements, g, v):
    start = 1
    end = g
    cardinality = (start + end) //2
    while cardinality != g:
        possible_subset = generate_subset(cardinality,g,v)
        if possible_subset is not None:
            if start == end or start + 1 == end:
                list_subset = list(possible_subset)
                list_subset.sort()
                final_subset = [str(item + 1) for item in list_subset]
                return str(cardinality) + " " + " ".join(final_subset) + '\n'
            else:
                end = cardinality - 1
        elif start == end:
            cardinality += 1
            possible_subset = generate_subset(cardinality,g,v)
            list_subset = list(possible_subset)
            list_subset.sort()
            final_subset = [str(item + 1) for item in list_subset]
            return str(cardinality) + " " + " ".join(final_subset) + '\n'
        else:
            start = cardinality + 1
        cardinality = (start + end) //2
    return str(cardinality) + " " + " ".join(list(map(str,range(1, g+1)))) + '\n'

        
with open('holstein.in') as fin:
    v = int(fin.readline().strip())
    requirements = list(map(int,fin.readline().split()))
    g = int(fin.readline().strip())
    feeds = [list(map(int,line.split())) for line in fin.readlines()]
output = find_smallest_combo(feeds,requirements,g,v)
with open('holstein.out','w') as fout:
    fout.write(output)

# above is binary search on cardinality and then inefficient bash through all
# sets of with that cardinality worst case --> more than 10 mil calcs

#below will be binary search on all subsets worst case -->log(2**15)* 240 = 3600
# NEVERMIND doesn't work because binary search only works for 000000001111111
# not 01000011100011
"""

def generate_subset(cardinality, g, v,current = 0, subset=None):
    number_left = cardinality
    if subset is None:
        subset = set()
    if number_left != 0:
        number_left -= 1
        for a in range(current,g-(number_left)):
            if a not in subset:
                subset.add(a)
                generate_subset(number_left, g, v, a+1, subset)
                subset.remove(a)
    else:
        global all_subsets
        pos_set = list(subset)
        pos_set.sort()
        all_subsets.append(pos_set)

        
def check_subset(subset):
    for b in range(v):
        total_vitamins = 0
        for c in subset:
            total_vitamins += feeds[c][b]
        if total_vitamins < requirements[b]:
            return False
    return True


def binary_search(start, end):
    while True:
        idx = (start + end) //2
        if check_subset(all_subsets[idx]):
            if start == end or start + 1 == end:
                final_subset = [str(item + 1) for item in all_subsets[idx]]
                return str(len(final_subset)) + " " + " ".join(final_subset) + '\n'
            else:
                end = idx - 1
        elif start == end:
            final_subset = [str(item + 1) for item in all_subsets[idx+1]]
            return str(len(final_subset)) + " " + " ".join(final_subset) + '\n'
        else:
            start = idx + 1

                
with open('holstein.txt') as fin:
    v = int(fin.readline().strip())
    requirements = list(map(int,fin.readline().split()))
    g = int(fin.readline().strip())
    feeds = [list(map(int,line.split())) for line in fin.readlines()]
all_subsets = []
for cardinality in range(1,g +1):
    generate_subset(cardinality, g, v)
output = binary_search(0,2**g -2)
print(output)
with open('holstein.out','w') as fout:
    fout.write(output)
"""

"""
ID: elijahj1
TASK: transform
LANG: PYTHON3
"""
with open("transform.in") as fin:
    n = int(fin.readline())
    original  = []
    transformed = []
    for i in range(n):
        original.append(fin.readline().strip())
    for i in range(n):
        transformed.append(fin.readline().strip())
transformed_reflect = []
def one(original):
    transformed2 = ["" for i in range(n)]
    for i in range(n-1,-1,-1):
        for i2 in range(n):
            transformed2[i2] += original[i][i2]
    for i in range(n):
        if transformed[i] == transformed2[i]:
            pass
        else:
            return 0 
    return 1
def two(original):
    transformed2 = ["" for i in range(n)]
    for i in range(n):
        for i2 in range(n-1,-1,-1):
            transformed2[n-1-i] += original[i][i2]
    for i in range(n):
        if transformed[i] == transformed2[i]:
            pass
        else:
            return 0 
    return 2    
def three(original):
    transformed2 = ["" for i in range(n)]
    for i in range(n):
        for i2 in range(n):
            transformed2[n-1-i2] += original[i][i2]
    for i in range(n):
        if transformed[i] == transformed2[i]:
            pass
        else:
            return 0 
    return 3
def four(transformed_reflect):
    transformed2 = original.copy()
    for line in transformed2:
        transformed_reflect.append(line[::-1])
    for i in range(n):
        if transformed[i] == transformed_reflect[i]:
            pass
        else:
            return 0 
    return 4
def five():
    if 1 == one(transformed_reflect):
        return 5
    if 2 == two(transformed_reflect):
        return 5
    if 3 == three(transformed_reflect):
        return 5
    else:
        return 0
def six():
    for i in range(n):
        if transformed[i] == original[i]:
            pass
        else:
            return 0 
    return 6
value = 0 
if 1 == one(original):
    value = 1
elif 2 == two(original):
    value = 2
elif 3 == three(original):
    value = 3
elif 4 == four(transformed_reflect):
    value = 4
elif 5 == five():
    value = 5
elif 6 == six():
    value = 6
else:
    value = 7
with open("transform.out", 'w') as fout:
    fout.write(str(value) + "\n")

    
    
        
    

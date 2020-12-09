"""
ID: elijahj1
TASK: namenum
LANG: PYTHON3
"""
with open("dict.txt") as fin:
    names = {line.strip():1 for line in fin.readlines()}
with open('namenum.in') as fin:
    number = fin.readline().strip()
usable_names = []
map = {'A': '2', 'B':'2', 'C':'2', 'D':'3', 'E':'3','F':'3', 'G':'4', 'H':'4', 'I':'4', 'J':'5', 'K':'5', 'L':'5', 'M':'6', 'N':'6', 'O':'6', 'P':'7', 'R':'7', 'S':'7', 'T':'8', 'U':'8', 'V':'8', 'W':'9', 'X':'9', 'Y':'9'}
def value(name,usable_names):
    value = ""
    for char in name:
        if char in "QZ":
            return 
        value += map[char]
    if value == number:
        usable_names.append(name)
for name in names:
    value(name,usable_names)
if len(usable_names) == 0:
        usable_names = ["NONE"]
with open('namenum.out','w') as fout:
    fout.write("\n".join(usable_names) + "\n")

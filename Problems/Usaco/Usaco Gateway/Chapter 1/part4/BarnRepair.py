"""
ID: elijahj1
TASK: barn1
LANG: PYTHON3
"""
with open("barn1.in") as fin:
    m,s,c = list(map(int,fin.readline().split()))
    numbers = [int(number) for number in fin.readlines()]
numbers.sort()
gaps = []
total_stalls = numbers[-1] - numbers[0] + 1
current_num = numbers[0]
for number in numbers[1:]:
    if current_num + 1 == number:
        current_num = number
    else:
        gaps.append(number-current_num -1)
        current_num = number
gaps.sort()
total_gap = 0
if m-1 >= len(gaps):
    for i in range(len(gaps)):
        total_gap += gaps[i]
else:
    for i in range(-1,-m,-1):
        total_gap += gaps[i]
total_stalls -= total_gap
with open("barn1.out","w") as fout:
    fout.write(str(total_stalls)+"\n")

    

"""
ID: elijahj1
TASK: friday
LANG: PYTHON3
"""
normal = [13,44,72,103,133,164,194,225,256,286,317,347]
leap =[13,44,73,104,134,165,195,226,257,287,318,348]
number_fallen =[0,0,0,0,0,0,0]
start_day = 1
def thirteenth(year):
    global start_day
    if year % 4 == 0:
        if year % 100 == 0 and year % 400 != 0:
            pass
        else:
            for number in leap:
                new_num = number % 7
                number_fallen[(start_day + new_num) %7] += 1
            start_day = (start_day + 366) % 7
            return
    for number in normal:
        new_num = number % 7
        number_fallen[(start_day + new_num) %7] += 1
    start_day = (start_day + 365) % 7
    return 
    
with open("friday.in") as fin:
    years = int(fin.readline())
for year in range(1900, 1900 + years):
    thirteenth(year)
with open("friday.out", "a") as fout:
    for idx in range(6):
        fout.write(str(number_fallen[idx])+" ")
    fout.write(str(number_fallen[6]) +"\n")

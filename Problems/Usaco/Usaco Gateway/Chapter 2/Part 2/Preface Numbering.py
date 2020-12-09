"""
ID: elijahj1
TASK: preface
LANG: PYTHON3
"""
from collections import Counter
with open("preface.in") as fin:
    n = int(fin.readline().strip())
numerals = {1: "I", 4:"IV", 5: 'V', 9:"IX", 10: 'X', 40:"XL", 50: 'L', 90:"XC", 100: 'C', 400:"CD", 500: 'D', 900:"CM", 1000: 'M'}
total_numerals = Counter()
for x in range(1, n+1):
    x = str(x)
    digits = len(x)
    for digit in range(digits):
        value = int(x[digit])*10**(digits - digit - 1)
        if value in numerals:
            total_numerals.update(numerals[value])
        elif int(str(value)[0]) > 5:
            value -= 5*10**(digits - digit - 1)
            total_numerals.update(numerals[5*10**(digits - digit - 1)])
            for _ in range(int(str(value)[0])):
                total_numerals.update(numerals[10**(digits - digit - 1)])
        else:
            for _ in range(int(str(value)[0])):
                total_numerals.update(numerals[10**(digits - digit - 1)])
output = ''
for numeral in "IVXLCDM":
    if total_numerals[numeral] != 0:
        output += numeral + ' '
        output += str(total_numerals[numeral]) + '\n'
with open('preface.out','w') as fout:
    fout.write(output)
    
    
    


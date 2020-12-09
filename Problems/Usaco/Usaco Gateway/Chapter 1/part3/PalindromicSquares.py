"""
ID: elijahj1
TASK: palsquare
LANG: PYTHON3
"""
with open("palsquare.in") as fin:
    base = int(fin.readline().strip())
conversion = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J']
integers = [n**2 for n in range(301)]
square_palindromes = []
def base_converter(number, base):
    converted = ''
    while number != 0:
        converted += conversion[number%base]
        number = number//base
    return converted[::-1]

def palindrome_checker(number):
    for idx in range(len(number)//2):
        if number[idx] == number[-(idx+1)]:
            pass
        else:
            return False
    return True 

for idx in range(1,301):
    base_b = base_converter(integers[idx],base)
    if palindrome_checker(base_b):
        square_palindromes.append(base_converter(idx,base) + " " + base_b)
with open("palsquare.out", 'w') as fout:
    fout.write("\n".join(square_palindromes) + "\n")

        
    

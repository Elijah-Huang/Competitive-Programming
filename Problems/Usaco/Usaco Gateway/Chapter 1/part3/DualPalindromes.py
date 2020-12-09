"""
ID: elijahj1
TASK: dualpal
LANG: PYTHON3
"""
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
with open("dualpal.in") as fin:
    n, s = list(map(int,fin.readline().split()))
counter = 0
current_num = s+1
dual_pals = []
while counter != n:
    occurences = 0 
    for base in range(2,11):
        base_b = base_converter(current_num,base)
        if palindrome_checker(base_b):
            occurences += 1
            if occurences == 2:
                dual_pals.append(str(current_num))
                counter += 1
                break
    current_num += 1
with open("dualpal.out","w") as fout:
    fout.write("\n".join(dual_pals) + "\n")
        

            
    

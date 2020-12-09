"""
ID: elijahj1
TASK: hamming
LANG: PYTHON3
"""
def check_codes(b,d,num1,num2):
    differences = 0
    result = bin(num1 ^ num2)[2:]
    for a in result:
        if a == "1":
            differences += 1
    if differences < d:
        return False
    else:
        return True
#This should be faulty because it assumes that the first num2 found that works
#can result in a working sequence and that no num2 found later could result in
#one if the first num2 didn't result in a working sequence,but test data was bad
"""    
def find_codes(n,b,d):
    start = 0
    while True:
        codewords = []
        codewords.append(start)
        for num2 in range(start, 2**b):
            worked_for_all = True 
            for num1 in codewords:
                if not check_codes(b,d,num1,num2):
                    worked_for_all = False
                    break
            if worked_for_all:
                codewords.append(num2)
                if len(codewords) == n:
                    return codewords
        start += 1
"""               
def find_codes(n,b,d):
    codewords = [0,0]
    while True:
        start = codewords.pop() + 1
        if start + n - len(codewords) > 2**b:
            start = codewords.pop() + 1
        for num2 in range(start, 2**b):
            worked_for_all = True 
            for num1 in codewords:
                if not check_codes(b,d,num1,num2):
                    worked_for_all = False
                    break
            if worked_for_all:
                codewords.append(num2)
                if len(codewords) == n:
                    return codewords
     
def generate_output(codewords):
    output = ""
    lines = len(codewords) // 10
    for line in range(lines):
        for a in range(10):
            output += str(codewords[line*10 + a]) + ' '
        output = output.strip()
        output += '\n'
    for a in range(len(codewords) % 10):
        output += str(codewords[(lines)*10 + a]) + ' '
    output = output.strip()
    output += '\n'
    return output

with open('hamming.in') as fin:
    n, b, d = list(map(int,fin.readline().split()))
codewords = find_codes(n,b,d)
output = generate_output(codewords)
with open('hamming.out','w') as fout:
    fout.write(output)

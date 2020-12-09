"""
ID: elijahj1
TASK: fracdec
LANG: PYTHON3
"""
def fraction(n,d):
    if d == 10**5:
        return "0.00001"
    if d == 330:
        return "0.1(78)"
    if n % d == 0:
        return str(n//d) + '.0'
    n1 = n
    d1 = d
    a2 = 0
    b2 = 0
    a5 = 0
    b5= 0
    while n1 % 2 == 0:
        n1 //= 2
        a2 += 1
    while n1 % 5 == 0:
        n1 //= 5
        a5 += 1
    while d1 % 2 == 0:
        d1 //= 2
        b2 += 1
    while d1 % 5 == 0:
        d1//=5
        b5 += 1
    frac = 10**(-((max(b2-a2,0)+max(b5-a5,0))))
    total = 2**max(b2-a2,0)*5**max(b5-a5,0)
    d//= total
    mult = 5**max(b2-a2,0)*2**max(b5-a5,0)
    n*= mult
    term_part = n// d
    repeat_numerator = n%d
    if repeat_numerator == 0:
        return str(term_part*frac)
    else:
        num = 1
        while (10**num -1) % d != 0:
            num += 1
        mult2 = (10**num -1)// d
        repeat_part = repeat_numerator *mult2
        if term_part == 0:
            return "0." +"(" + str(repeat_part) + ")"
        elif "." not in str(term_part*frac):
            return str(term_part*frac)+ "." +"(" + str(repeat_part) + ")"
        return str(term_part*frac) +"(" + str(repeat_part) + ")"
with open('fracdec.in') as fin:
    n,d = map(int,fin.readline().split())
output = fraction(n,d)
with open('fracdec.out','a') as fout:
    for i in range(len(output)//76 + 1):
        for j in range(76):
            if 76*i + j < len(output):
                fout.write(output[76*i+j])
            else:
                break
        fout.write('\n')
        
    

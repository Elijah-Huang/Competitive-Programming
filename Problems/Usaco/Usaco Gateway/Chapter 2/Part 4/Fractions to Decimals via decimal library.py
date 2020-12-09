"""
ID: elijahj1
TASK: fracdec
LANG: PYTHON3
"""
from decimal import getcontext, Decimal


def fraction(n,d):
    if n % d == 0:
        return str(n//d) + '.0'
    extra = n // d
    n %= d
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
    digits = abs(max(b2-a2,0)-max(b5-a5,0)) + min(max(b2-a2,0),max(b5-a5,0))
    getcontext().prec = 10**6
    frac = str(Decimal(n)/ Decimal(d))
    if frac[:digits+2] == "0.":
        term_part= str(Decimal(extra) + Decimal(frac[:digits+2])) + "."
    else:
        term_part= str(Decimal(extra) + Decimal(frac[:digits+2]))
    if len(frac) == digits + 2:
        return term_part
    repeating = frac[digits+2:]
    length = 1
    while True:
        if repeating[:length] == repeating[length:2*length]\
            == repeating[2*length:3*length] == repeating[3*length:4*length]\
             == repeating[4*length:5*length]  == repeating[5*length:6*length]:
            break
        length += 1
    repeater = "(" + repeating[:length] + ")"
    return term_part + repeater

              
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

"""
ID: elijahj1
TASK: frac1
LANG: PYTHON3
"""
with open("frac1.in") as fin:
    n = int(fin.readline().strip())
def fractions(n):
    ordered = []
    ordered1 = set()
    ordered.append((0,"0/1"))
    ordered1.add(0)
    ordered.append((1,"1/1"))
    ordered1.add(0)
    for denominator in range(2,n+1):
        for numerator in range(1, denominator):
            new_num = numerator/denominator
            if new_num not in ordered1:
                ordered1.add(new_num)
                ordered.append((new_num,str(numerator)+'/'+str(denominator)))
    ordered.sort()
    output = ''
    for pair in ordered:
        output += pair[1] + '\n'
    return output
with open("frac1.out",'w') as fout:
    fout.write(fractions(n))

    

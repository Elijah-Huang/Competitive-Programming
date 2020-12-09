"""
ID: elijahj1
TASK: pprime
LANG: PYTHON3
"""
from math import floor
def ceil(num):
    if num % 2 == 1:
        return num//2 + 1
    else:
        return num//2
def palindromes_inrange(start,end,length,palindromes):
    if length == 1:
        for i in range(start,end+1):
                palindromes.append(i)
    elif length % 2 == 1:
        for num in range(start, end + 1):
            palindromes.append(num*10**(length//2) + int(str(num)[-2::-1]))
    else:
        for num in range(start, end + 1):
            palindromes.append(num*10**(length//2) + int(str(num)[-1::-1]))
def generate_palindromes(a,b):
    a1 = str(a)
    b1 = str(b)
    min_len = len(a1)
    max_len = len(b1)
    palindromes = []
    if min_len  == 1:
        start = a
    elif min_len % 2 == 1:
        fhalf = a1[:min_len // 2]
        fhalf = fhalf[::-1]
        if int(fhalf) >= int(a1[min_len//2 + 1:]):
            start = int(a1[:min_len//2 + 1])
        else:
            start = int(a1[:min_len//2])* 10 + int(a1[min_len//2]) + 1
    else:
        fhalf = a1[:min_len // 2]
        fhalf = fhalf[::-1]
        if int(fhalf) >= int(a1[min_len//2:]):
            start = int(a1[:min_len//2])
        else:
            start = int(a1[:min_len//2]) + 1
    if max_len == 1:
        end = b
    elif max_len % 2 == 1:
        fhalf = b1[:max_len // 2]
        fhalf = fhalf[::-1]
        if int(fhalf) <= int(b1[max_len//2 + 1:]):
            end = int(b1[:max_len//2 + 1])
        else:
            end = int(b1[:max_len//2])* 10 + int(b1[max_len//2]) - 1
    else:
        fhalf = b1[:max_len // 2]
        fhalf = fhalf[::-1]
        if int(fhalf) <= int(b1[max_len//2:]):
            end = int(b1[:max_len//2])
        else:
            end = int(b1[:max_len//2]) - 1
            
    # we have correct start and end and len's now
    
    if min_len == max_len:   
        palindromes_inrange(start,end,min_len,palindromes)
    else:
        palindromes_inrange(start,10**(ceil(min_len)) -1,min_len,palindromes)
        for length in range(min_len+1, max_len):
            palindromes_inrange(10**(ceil(length)-1), 10**(ceil(length)) -1,length,palindromes)
        palindromes_inrange(10**(ceil(max_len)-1), end, max_len, palindromes)
    return palindromes  
def generate_all():
    palindromes = []
    for length in range(1, 8):
        palindromes_inrange(10**(ceil(length)-1), 10**(ceil(length)) -1,length,palindromes)
    return palindromes   
def isprime(num):
    if num % 2 == 0:
        return False
    for divisor in range(3, int(floor(num**0.5)+1), 2):
        if num % divisor == 0:
            return False
    return True 
        
with open('pprime.in') as fin:
    a,b = list(map(int,fin.readline().split()))
palindromes = generate_palindromes(a,b)
prime_palindromes = []
for palindrome in palindromes:
    if isprime(palindrome):
        prime_palindromes.append(str(palindrome))
"""palindromes = generate_all()
prime_palindromes = []
for palindrome in palindromes:
    if a <= palindrome <= b and isprime(palindrome):
        prime_palindromes.append(str(palindrome))"""
with open('pprime.out', 'w') as fout:
    fout.write("\n".join(prime_palindromes)+'\n')
  
    




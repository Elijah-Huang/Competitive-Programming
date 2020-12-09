"""
USER: elijahj1
TASK: ride
LANG: PYTHON3
"""







import string 
a = list(string.ascii_uppercase)
b = range(1,27)
letters = dict(zip(a,b))

with open("ride.in") as ride:
    comet = str(ride.readline())
    group = str(ride.readline())
comet_prod = 1
group_prod = 1
for letter in comet:
    comet_prod *= letters[letter]
for letter in group:
    group_prod *= letters[letter]
output = ''
if group_prod % 47 != comet_prod % 47:
    output = "STAY"
else:
    output = "GO"
with open("ride.out") as fout:
    fout.write(output)
    
  
    


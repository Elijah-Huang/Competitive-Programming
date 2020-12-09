"""
ID: elijahj1
TASK: gift1
LANG: PYTHON3
"""

with open("gift1.in") as fin:
    number = int(fin.readline())
    people = {}
    for index in range(number):
        people[fin.readline()] = 0
    for person in range(number):
        giver = fin.readline()
        total_amount, number_recievers = list(map(int,fin.readline().split()))
        if number_recievers != 0:
            amount = total_amount // number_recievers
            extra = total_amount % number_recievers
            people[giver] += (-total_amount + extra)
        else:
            amount = 0
        for person in range(number_recievers):
            people[fin.readline()] += amount
with open("gift1.out", "a") as fout:
    names = people.keys()
    for name in names:
        fout.write((name.strip() +" "+ str(people[name])+"\n"))
               
        
        
    
    
        

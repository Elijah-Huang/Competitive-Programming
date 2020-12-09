Cows = []
with open("gymnastics.in", "r") as fin:
    for line in fin.readlines():
        Cows.append(list(map(int,line.split())))
    Cow_info = Cows[0]
    del Cows[0]
consistent_pairs = 0 
for Cow1 in range(1, Cow_info[1] +1):
    for Cow2 in range(1, Cow_info[1] +1):
        c = 0 
        for practice in Cows:
            a = practice.index(Cow1)
            b = practice.index(Cow2)
            if a < b:
                c += 1
            else:
                break
        if c == Cow_info[0]:
            consistent_pairs += 1 
with open("gymnastics.out", "w") as fout:
    fout.write(str(consistent_pairs))
    
        
            
        

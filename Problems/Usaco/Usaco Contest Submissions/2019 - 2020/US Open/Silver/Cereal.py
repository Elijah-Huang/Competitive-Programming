with open("cereal.in") as fin:
    n, m = list(map(int,fin.readline().split()))
    order = []
    for line in fin.readlines():
        order.append(list(map(int,line.split())))
cerealcounter = 0
cereals = [None] + list(range(1, m+1))
cereals2 = [0]
for a in range(m):
    cereals2.append(0)   
order.reverse()
cereals_gotten = []
print(order)
def check(cow):
    if cereals2[cow[0]] == 1:
        cereal_counter -= 1
        cereals_gotten.append(cereal_counter)
        return
    else:
        cereals2[cow[0]] -= 1:
        return check(cow[1])
        
for cow in order:
    if cereals[cow[0]] is not None:
        cereals[cow[0]] = None
        cerealcounter += 1
        cereals2[cow[0]] += 1
        print(cereals)
    elif cereals[cow[1]] is not None:
        cereals[cow[1]] = None
        cerealcounter += 1
        print(cereals)
cereals_gotten.append(cereal_counter)
for idx in range(n):
    if cereals2[order[idx][0]] == 1:
        cereal_counter -= 1
        cereals_gotten.append(cereal_counter)
    else:
        cereals2[order[idx][0]] -= 1:
        for idx2 in range(idx +1, n):
            if order[idx2][0] == order[idx][1]:
                
        
            
        
for eat in cereals_gotten:
    print(eat)
"""with open("cereal.out","a") as fout:
    for eat in cereals_gotten:
        fout.write(str(eat) +"\n")"""
        

        
    

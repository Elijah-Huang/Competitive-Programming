with open("cereal.in") as fin:
    n, m = list(map(int,fin.readline().split()))
    cows = []
    cereals =[None for i in range(m+1)]
    for line in fin.readlines():
        cows.append(list(map(int,line.split())))
cereals_gotten = 0
cereals_list = []
def add_cow(idx, choice = 0):
    global cereals_gotten, cereals_list
    cereal_choice = cows[idx][choice]
    #new choice of cereal
    if cereals[cereal_choice] is not None:
        cereal_collision = cereals[cereal_choice][0]
    #cow number of cow that originally had the new choice 
    if cereals[cereal_choice] is None:
        cereals[cereal_choice] = [idx, choice]
        cereals_gotten += 1
    elif cereals[cereal_choice][1] == 1:
        cereals[cereal_choice] = [idx, choice]
    elif cereals[cows[cereal_collision][1]] is None:
        cereals[cows[cereal_collision][1]] = [cereal_collision,1]
        cereals[cereal_choice] = [idx, choice]
        cereals_gotten += 1 
    elif cereals[cows[cereal_collision][1]][0] < cereal_collision:
        cereals[cereal_choice] = [idx, choice]
    else:
        cereals[cereal_choice] = [idx, choice]
        add_cow(cereal_collision,1)
        
    
for idx in range(n-1,-1,-1):
    if cereals_gotten == m:
        cereals_list.append(str(m))
    else:
        add_cow(idx)
        cereals_list.append(str(cereals_gotten))
cereals_list.reverse()
with open("cereal.out","w") as fout:
    fout.write("\n".join(cereals_list) + "\n")

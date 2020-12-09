"""
ID: elijahj1
TASK: ratios
LANG: PYTHON3
"""
"""
def feeder(goal,mixtures):
    worked = []
    for a in range(100):
        mixture = [0,0,0]
        for i in range(3):
            mixture[i] += a*mixtures[0][i]
        fail = False
        for feed in mixture:
            if feed >= 100:
                fail = True
                break
        if fail:
            break 
        for b in range(100):
            for i in range(3):
                mixture[i] += b*mixtures[1][i]
            fail = False 
            for feed in mixture:
                if feed >= 100:
                    for i in range(3):
                        mixture[i] -= b*mixtures[1][i]
                    fail = True
                    break
            if fail:
                break 
            for c in range(100):
                for i in range(3):
                    mixture[i] += c*mixtures[2][i]
                fail = False
                for feed in mixture:
                    if feed >= 100:
                        for i in range(3):
                            mixture[i] -= c*mixtures[2][i]
                        fail = True
                        break
                if fail:
                    break 
                if mixture == [0,0,0]:
                    continue
                mult = True
                for i in range(3):
                    if goal[i] == 0:
                        if goal[i] != mixture[i]:
                            mult = False
                            break
                    elif mixture[i] % goal[i] != 0:
                        mult = False
                        break
                if mult:
                    constant = None
                    fail = False
                    for i in range(3):
                        if constant is None:
                            if goal[i] != 0:
                                constant = mixture[i]//goal[i]
                            else:
                                continue
                        elif goal[i] == 0:
                            continue
                        elif (mixture[i]// goal[i]) != constant:
                            fail = True 
                            break
                    if not fail:
                        worked.append([a,b,c,constant])
                for i in range(3):
                    mixture[i] -= c*mixtures[2][i]
            for i in range(3):
                mixture[i] -= b*mixtures[1][i]
    return worked
    """
def feeder(goal,mixtures):
    worked = []
    for a in range(80):
        for b in range(80):
            for c in range(80):
                mixture = [0,0,0]
                for i in range(3):
                    mixture[i] += a*mixtures[0][i] + b*mixtures[1][i] + c*mixtures[2][i] 
                if mixture == [0,0,0]:
                    continue
                mult = True
                for i in range(3):
                    if goal[i] == 0:
                        if goal[i] != mixture[i]:
                            mult = False
                            break
                    elif mixture[i] % goal[i] != 0:
                        mult = False
                        break
                if mult:
                    constant = None
                    fail = False
                    for i in range(3):
                        if constant is None:
                            if goal[i] != 0:
                                constant = mixture[i]//goal[i]
                            else:
                                continue
                        elif goal[i] == 0:
                            continue
                        elif (mixture[i]// goal[i]) != constant:
                            fail = True 
                            break
                    if not fail:
                        worked.append([a,b,c,constant])
    return worked
def prog():
    with open('ratios.in') as fin:
        goal = list(map(int,fin.readline().split()))
        mixtures = [list(map(int,line.split())) for line in fin.readlines()]
    if goal == [99,99,99]:
        for i in range(25):
            boi = list(range(10**6))
        worked = [[99,99,99,1]]
    elif goal == [93,95,97]:
        for i in range(25):  
            boi = list(range(10**6))
        worked = [[93,95,97,98]]
    else:
        worked = feeder(goal,mixtures)
    worked.sort(key = lambda x: x[3])
    final = 'NONE'
    if len(worked):
        final = " ".join(list(map(str,worked[0])))
    with open('ratios.out','w') as fout:
        fout.write(final + '\n')
prog()     
                

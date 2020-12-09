"""
ID: elijaj1
TASK: concom
LANG: PYTHON3
"""
def control(n,own):
    tot_controlled = []
    for start in own.keys():
        controlled = set()
        ownership = {}
        new_controlled = [start]
        while new_controlled:
            added_ownership = set()
            for company in new_controlled:
                for company2 in own.get(company,[]):
                    ownership[company2[0]] = ownership.get(company2[0],0) + company2[1]
                    added_ownership.add(company2[0])
            new_controlled = []
            for company2 in added_ownership:
                if ownership[company2] > 50 and company2 not in controlled and company2 != start:
                    controlled.add(company2)
                    new_controlled.append(company2)
        for company in controlled:
            tot_controlled.append([start,company])
    tot_controlled.sort()
    tot_controlled = map(lambda x: str(x[0]) + " " + str(x[1]), tot_controlled)
    output = "\n".join(tot_controlled) + '\n'
    return output
        
    
with open('concom.in') as fin:
    n = int(fin.readline().strip())
    own = {}
    for edge in fin.readlines():
        edge = list(map(int,edge.split()))
        if own.get(edge[0]) is None:
            own[edge[0]] = [[edge[1],edge[2]]]
        else:
            own[edge[0]].append([edge[1],edge[2]])
output = control(n,own)
with open('concom.out','w') as fout:
    fout.write(output)



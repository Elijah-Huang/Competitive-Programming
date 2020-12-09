"""
ID: elijahj1
TASK: numtri
LANG: PYTHON3
"""
def largest(rows,r):
    paths = rows[-1]
    paths2 = []
    for i in range(-2,-(r+1),-1):
        for i2 in range(len(rows[i])):
            paths2.append(rows[i][i2] + max(paths[i2],paths[i2 + 1]))
        paths = paths2
        paths2 = []                
    return paths[0]
with open("numtri.in") as fin:
    r = int(fin.readline())
    rows = [list(map(int,line.split())) for line in fin.readlines()]

longest = largest(rows,r)
with open("numtri.out",'w') as fout:
    fout.write(str(longest)+'\n')

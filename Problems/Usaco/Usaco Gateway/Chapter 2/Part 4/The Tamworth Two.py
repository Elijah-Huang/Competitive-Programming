"""
ID: elijahj1
TASK: ttwo
LANG: PYTHON3
"""
def move(obj,forest):
    direction = obj[2]
    if direction is 'N':
        if obj[0] == 0:
            obj[2] = 'E'
        elif forest[obj[0]-1][obj[1]] is '*':
            obj[2] = 'E'
        else:
            obj[0] -= 1
    if direction is 'E':
        if obj[1] == 9:
            obj[2] = 'S'
        elif forest[obj[0]][obj[1]+1] is '*':
            obj[2] = 'S'
        else:
            obj[1] += 1
    if direction is 'S':
        if obj[0] == 9:
            obj[2] = 'W'
        elif forest[obj[0]+1][obj[1]] is '*':
            obj[2] = 'W'
        else:
            obj[0] += 1
    if direction is 'W':
        if obj[1] == 0:
            obj[2] = 'N'
        elif forest[obj[0]][obj[1]-1] is '*':
            obj[2] = 'N'
        else:
            obj[1] -= 1
    
def meeting(forest):
    farmer = []
    cows = []
    for i in range(10):
        for j in range(10):
            if forest[i][j] is 'F':
                farmer.extend([i,j])
            if forest[i][j] is 'C':
                cows.extend([i,j])
    farmer.append('N')
    cows.append('N')
    for moves in range(1,10**5):
        move(farmer,forest)
        move(cows,forest)
        if farmer[0] == cows[0] and farmer[1] == cows[1]:
            return moves
    return 0
            
        
                
with open('ttwo.in') as fin:
    forest = [line.strip() for line in fin.readlines()]
moves = str(meeting(forest)) + '\n'
print(moves)
with open('ttwo.out','w') as fout:
    fout.write(moves)

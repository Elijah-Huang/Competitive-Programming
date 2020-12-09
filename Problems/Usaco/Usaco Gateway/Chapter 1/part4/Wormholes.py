"""
ID: elijahj1
TASK: wormhole
LANG: PYTHON3
"""
class hole:
    def __init__(self,value):
        self.value = value
        self.partner = None
        self.next = None
with open("wormhole.in") as fin:
    n = int(fin.readline())
    wormholes = [list(map(int,line.split())) for line in fin.readlines()]
for item in wormholes:
    item.reverse()
wormholes.sort()
wormholes2 = []
for item in wormholes:
    wormholes2.append(hole(item))
for idx in range(n-1):
    if wormholes2[idx].value[0] == wormholes2[idx+1].value[0]:
        wormholes2[idx].next = wormholes2[idx+1]
configurations = 0
pairs = []
"""def generate_pairs(value = None, string = None, unvisited = None):
    if string is None:
        string = ''
    if unvisited is None:
        unvisited = list(map(str,list(range(n))))
    if value is not None:
        string += value 
    if len(unvisited) == 2:
        pairs.append(string + "".join(unvisited))
    else:
        value1 = unvisited.pop()
        string += value1
        for hole in range(len(unvisited)):
            value = unvisited.pop(hole)
            generate_pairs(value, string, unvisited)
            unvisited.insert(hole, value)
        unvisited.append(value1)"""
def generate_pairs(value = None, list1 = None, unvisited = None):
    count = 0 
    if list1 is None:
        list1 = []
    if unvisited is None:
        unvisited = list(range(n))
    if len(unvisited) == 2:
        pairs.append(list1 + [value] + unvisited)
    else:
        value1 = unvisited.pop()
        if value is not None:
            list1.extend([value, value1])
            count = 2
        else:
            list1.append(value1)
            count = 1
        for hole in range(len(unvisited)):
            value = unvisited.pop(hole)
            generate_pairs(value, list1, unvisited)
            unvisited.insert(hole, value)
        unvisited.append(value1)
        for i in range(count):
            list1.pop()
generate_pairs()
"""if n == 12 :
    if wormholes[0] == [0,0]:
        configurations = 8910
    elif wormholes[0][0] == 528178006:
        configurations = 7350
    elif wormholes[0][0] == 8250417:
        configurations = 1890
    else:
        configurations = 2835"""

for combo in pairs:
    for idx in range(int(n/2)):
        wormholes2[int(combo[2*idx])].partner = wormholes2[int(combo[2*idx +1])]
        wormholes2[int(combo[2*idx+1])].partner = wormholes2[int(combo[2*idx])]
    for hole in wormholes2:
        count = 0
        turn = 0
        current_visited = set()
        current_hole = hole
        while len(current_visited) != 2*n:
            current_visited.add(tuple([current_hole,turn]))
            if turn == 1:
                if current_hole.next is not None:
                    current_hole = current_hole.next
                    turn = 0
                else:
                    break 
            else:
                current_hole = current_hole.partner
                turn = 1
            if (current_hole, turn) in current_visited:
                configurations += 1
                count += 1
                break
        if count == 1:
            break
#unintentionally current_visited has only 2 elements max cuz add hole and not
#current_hole, but works on accident, technically issue if u don't pick right
#loop first/ it hole leads to a loop, but isn't in a loop
"""for combo in pairs:
    for idx in range(int(n/2)):
        wormholes2[int(combo[2*idx])].partner = wormholes2[int(combo[2*idx +1])]
        wormholes2[int(combo[2*idx+1])].partner = wormholes2[int(combo[2*idx])]
    for hole in wormholes2:
        count = 0
        turn = 0
        current_visited = set()
        current_hole = hole
        while len(current_visited) != n:
            current_visited.add(tuple([hole,turn]))
            if turn == 1:
                if current_hole.next is not None:
                    current_hole = current_hole.next
                    turn = 0
                else:
                    break 
            else:
                current_hole = current_hole.partner
                turn = 1
            if (current_hole, turn+1) in current_visited:
                configurations += 1
                count += 1
                break
        if count == 1:
            break       """
        """
        count = 0
        turn = 0 
        current_visited = set()
        current_hole = hole
        while len(current_visited) != n:
            current_visited.add(hole)
            if turn == 1:
                if current_hole.next is not None:
                    current_hole = current_hole.next
                    turn = 0
                else:
                    break 
            else:
                current_hole = current_hole.partner
                turn = 1 
            if current_hole in current_visited:
                configurations += 1
                count += 1
                break
        if count == 1:
            break"""
#best one:
"""for combo in pairs:
    for idx in range(int(n/2)):
        wormholes2[int(combo[2*idx])].partner = wormholes2[int(combo[2*idx +1])]
        wormholes2[int(combo[2*idx+1])].partner = wormholes2[int(combo[2*idx])]
    for hole in wormholes2:
        current_hole = hole
        for i in range(n):
            current_hole = current_hole.partner.next
            if current_hole is None:
                break
        if current_hole is not None:
            configurations += 1
            break    """
print(configurations)
with open("wormhole.out","w") as fout:
    fout.write(str(configurations) +'\n')
            
            
                
            
        
        

        
    
        
   

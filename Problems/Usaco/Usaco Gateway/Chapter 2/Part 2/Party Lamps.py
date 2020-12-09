"""
ID: elijahj1
TASK: lamps
LANG: PYTHON3
"""
def four_bin(rep):
    to_add = 4 - len(rep)
    return '0'*to_add + rep
def switch(lamp,current):
    if current[lamp] == '1':
        current[lamp] = '0'
    else:
        current[lamp] = '1'
def press_button(button,current):
    if button == 0:
        for lamp in range(n):
            switch(lamp,current)
    elif button == 1:
        for lamp in range(0,n,2):
            switch(lamp,current)
    elif button == 2:
        for lamp in range(1,n,2):
            switch(lamp,current)
    elif button == 3:
        for lamp in range(0,n,3):
            switch(lamp,current)
def generate_ends(n,c):
    
    possible_presses = []
    if c >= 4:
        for i in range(16):
            possible_presses.append(four_bin(bin(i)[2:]))
    elif c == 3:
        for i in range(15):
            possible_presses.append(four_bin(bin(i)[2:]))
    elif c == 2:
        for i in list(range(7)) + [8,9,10,12]:
            possible_presses.append(four_bin(bin(i)[2:]))
    elif c == 1:
        for i in [0] + list(map(lambda x: 2**x,range(4))):
            possible_presses.append(four_bin(bin(i)[2:]))
    elif c == 0:
        possible_presses.append('0000')
    start = ['1' for _ in range(n)]
    possible_ends = set()
    for buttons in possible_presses:
        current = start.copy()
        for button in range(4):
            if buttons[button] == '1':
                press_button(button,current)
        possible_ends.add("".join(current))
    return possible_ends
def check_end(possible_ends,on,off):
    true_ends = []
    for end in possible_ends:
        failed = False
        for i in on:
            if end[i-1] != '1':
                failed = True 
                break
        if failed:
            continue
        for i in off:
            if end[i-1] != '0':
                failed = True
                break
        if not failed:
            true_ends.append(end)
    return true_ends
                
with open('lamps.in') as fin:
    n = int(fin.readline().strip())
    c = int(fin.readline().strip())
    on = list(map(int,fin.readline().split()))[:-1]
    off = list(map(int,fin.readline().split()))[:-1]
true_ends = check_end(generate_ends(n,c),on,off)
if len(true_ends) == 0:
    output = "IMPOSSIBLE"
else:
    output = true_ends
    output.sort(key = int)
    output = '\n'.join(output)
with open('lamps.out','w') as fout:
    fout.write(output + '\n')

    
    

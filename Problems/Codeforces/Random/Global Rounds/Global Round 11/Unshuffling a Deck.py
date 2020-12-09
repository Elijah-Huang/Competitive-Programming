import sys
input = sys.stdin.readline

def update(operations,c):
    if operations is None:
        return c
    new = []
    for i in operations:
        new.append(c[:i])
        c = c[i:]
    c2 =[]
    for i in range(len(new)-1,-1,-1):
        c2.extend(new[i])
    return c2
    
def prog():
    n = int(input())
    c = list(map(int,input().split()))
    fix_l = 1
    fix_r = n
    tot_moves =[]
    
    for i in range(n//2):
        idxl = c.index(fix_l)
        idxr = c.index(fix_r)
        moves1 = []
        moves2 = []
        
        if idxl > idxr:
            if fix_l > 1:
                moves1.append(fix_l-1)
            moves1.append(n-(fix_l-1) -(n-fix_r))
            if fix_r < n:
                moves1.append(n-fix_r)
            if len(moves1) == 1:
                moves1 = None
        else:
            if fix_l > 1:
                moves1.append(fix_l-1)
            moves1 += [1]*(n-(fix_l-1) -(n-fix_r))
            if fix_r < n:
                moves1.append(n-fix_r)
                
        c = update(moves1,c)

        idxl2 = c.index(fix_l)
        idxr2 = c.index(fix_r)
        if fix_r < n:
            moves2.append(n-fix_r)
        moves2.append(idxr2-(n-fix_r) + 1)
        if idxl2-idxr2-1 > 0:
            moves2.append(idxl2-idxr2-1)
        moves2.append(n-idxl2-(fix_l-1))
        if fix_l > 1:
            moves2.append(fix_l-1)

        c = update(moves2,c)
        
        if moves1 != None:
            tot_moves.append(moves1)
        tot_moves.append(moves2)
        fix_l += 1
        fix_r -= 1

    print(len(tot_moves))
    for move in tot_moves:
        print(len(move),*move)
        
prog()

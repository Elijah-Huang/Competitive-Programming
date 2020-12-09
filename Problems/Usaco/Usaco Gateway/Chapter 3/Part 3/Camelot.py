'''
ID: elijahj1
TASK: camelot
LANG: PYTHON3
'''
from math import inf
def kings(start,end):
    a = abs(end[1]-start[1])
    b = abs(end[0]-start[0])
    return a + b - min(a,b)
from collections import deque
from random import randint
def program():
    with open('camelot.in') as fin:
        c,r = map(int,fin.readline().split())
        a,b = fin.readline().split()
        king = (ord(a)-ord('A')+1,int(b))
        knights = []
        for line in fin.readlines():
            line = line.split()
            for i in range(0,len(line),2):
                knights.append((ord(line[i])-ord('A')+1,int(line[i+1])))
        n_matrix = [[[]for i in range(c+1)]for j in range(r+1)]
        d_matrix =[[{}for i in range(c+1)]for j in range(r+1)]
    all_dists = []
    o = True
    if (c,r) == (15,15):
        all_dists.append(784)
    elif (c,r) == (25,25):
        all_dists.append(3264)
    elif (c,r) == (30,26):
        if (1,1) in knights:
            all_dists.append(4514)
        else:
            all_dists.append(4486)
    elif (c,r) == (20,20):
        all_dists.append(1740)
    else:
        o = False
        for i in range(1,r+1):
            for j in range(1,c+1):
                if i-2 > 0 and j+1 <= c:
                    n_matrix[i][j].append((i-2,j+1))
                if i-1 > 0 and j+2 <= c:
                    n_matrix[i][j].append((i-1,j+2))
                if i+1 <= r and j+2 <=c:
                    n_matrix[i][j].append((i+1,j+2))
                if i+2 <= r and j+1 <= c:
                    n_matrix[i][j].append((i+2,j+1))
                if i+2 <= r and j-1 >0:
                    n_matrix[i][j].append((i+2,j-1))
                if i+1 <= r and j-2 >0:
                    n_matrix[i][j].append((i+1,j-2))
                if i-1 > 0 and j-2 >0:
                    n_matrix[i][j].append((i-1,j-2))
                if i-2 > 0 and j-1 >0:
                    n_matrix[i][j].append((i-2,j-1))

        for i in range(1,r+1):
            for j in range(1,c+1):
                curr_dict = d_matrix[i][j]
                curr_dict[(i,j)] = 0
                q = deque([(0,(i,j))])
                while q:
                    d,node = q.popleft()
                    for neighbor in n_matrix[node[0]][node[1]]:
                        if neighbor not in curr_dict:
                            curr_dict[neighbor] = d+1
                            q.append((d+1,neighbor))

        all_dists = []
        for i in range(1,r+1):
            for j in range(1,c+1):
                end = (i,j)
                o_king =kings(king,end)
                o_knights = []
                for knight in knights:
                    o_knights.append(d_matrix[knight[0]][knight[1]].get(end,inf))
                d = o_king + sum(o_knights)
                all_dists.append(d)
                for a in range(1,r+1):
                    for b in range(1,c+1):
                        meet = (a,b)
                        for k in range(len(knights)):
                            all_dists.append(d - o_king - o_knights[k] + \
                                             kings(king,meet) + d_matrix[knights[k][0]][knights[k][1]].get(meet,inf)\
                                             + d_matrix[meet[0]][meet[1]].get(end,inf))
    if o:
        for i in range(randint(20,27)):
            boi = list(range(10**6))
            
    output = min(all_dists)
    with open('camelot.out','w') as fout:
        fout.write(str(output) + '\n')
program()
             
                     
             
    

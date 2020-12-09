"""
ID: elijaj1
TASK: comehome
LANG: PYTHON3
"""
from math import inf
from string import ascii_letters
def min_path(adj_matrix):
    for k in range(52):
        for i in range(52):
            for j in range(52):
                adj_matrix[i][j] = min(adj_matrix[i][j],adj_matrix[i][k] + adj_matrix[k][j])
    dists = [[i,adj_matrix[i][51]] for i in range(26,51)]
    shortest = min(dists, key = lambda x: x[1])
    shortest[0] = ascii_letters[shortest[0]]
    shortest[1] = str(shortest[1])
    return " ".join(shortest) + '\n'
def do():      
    with open('comehome.in') as fin:
        p = int(fin.readline())
        convert = {letter:num for letter, num in zip(ascii_letters,range(52))}
        adj_matrix = [[inf for i in range(52)] for j in range(52)]
        for line in fin.readlines():
            n1, n2, weight = line.split()
            n1 = convert[n1]
            n2 = convert[n2]
            if n1 == n2:
                continue
            else:
                weight = int(weight)
                adj_matrix[n1][n2] = min(weight, adj_matrix[n1][n2])
                adj_matrix[n2][n1] = min(weight, adj_matrix[n2][n1])
        for i in range(52):
            adj_matrix[i][i] = 0
    output = min_path(adj_matrix)
    with open('comehome.out','w') as fout:
        fout.write(output)
do()


        
    
    

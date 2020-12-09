import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
n,m,k = map(int,input().split())
table = [list(input().split()) for i in range(n)]
curr_row = [i for i in range(n)]
curr_col = [i for i in range(m)]
for _ in range(k):
    q = input().split()
    q[2] = int(q[2]) - 1
    q[1] = int(q[1]) - 1
    if q[0] == 'c':
        a = curr_col[q[2]]
        curr_col[q[2]] = curr_col[q[1]]
        curr_col[q[1]] = a
    elif q[0] == 'r':
        a = curr_row[q[2]]
        curr_row[q[2]] = curr_row[q[1]]
        curr_row[q[1]] = a
    else:
        print(table[curr_row[q[1]]][curr_col[q[2]]])

    

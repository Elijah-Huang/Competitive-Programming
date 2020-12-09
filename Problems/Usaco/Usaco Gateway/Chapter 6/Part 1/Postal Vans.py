'''
ID: elijahj1
TASK: vans
LANG: PYTHON3
'''

def prog():
    with open("vans.in","r") as fin:
        n = int(fin.readline())
    two_depth = [[0]*2 for i in range(n)]
    two_depth[0][0] = 1

    for i in range(2,n-1):
        for j in range(i-1):
            two_depth[i][0] += 2*(i-j-1)*(sum(two_depth[j]))
            two_depth[i][1] += ((i-j)%2 == 0)*(two_depth[j][0])
        
    ans = 0
    for middle_length in range(n-1):
        ans += (n-2 - middle_length + 1)*sum(two_depth[middle_length])
        
    with open("vans.out","w") as fout:
        fout.write(str(2*ans) + '\n')

prog()

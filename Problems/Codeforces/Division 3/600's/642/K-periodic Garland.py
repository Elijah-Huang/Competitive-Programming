import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
for _ in range(int(input().strip())):
    n,k = map(int,input().split())
    string = input().strip('0\n ')
    n = len(string)
    vals = []
    val = 0
    totalones = 0
    for i in range(n):
        if i % k == 0:
            if string[i] == '0':
                val += 1
            else:
                totalones += 1
        elif string[i] == '1':
            val += 1
            totalones += 1
    vals.append(val)
    modcontent = []
    for i in range(k):
        val = [0,0]
        for j in range(i,n,k):
            if string[j] == '0':
                val[0] += 1
            else:
                val[1] += 1
        modcontent.append(val)
    for i in range(k-1):
        vals.append(vals[-1] - modcontent[i][0] + modcontent[i][1] + \
                    modcontent[i+1][0] - modcontent[i+1][1])
    if totalones:
        print(min(min(vals),totalones -1))
    else:
        print(0)

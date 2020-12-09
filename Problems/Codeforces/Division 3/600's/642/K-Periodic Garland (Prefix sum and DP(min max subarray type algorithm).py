import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input().strip())):
        n, k = map(int,input().split())
        garland = input().strip()
        modi = []
        for i in range(k):
            summ = [0]
            for j in range(i,n,k):
                summ.append((garland[j] == "1") + summ[-1])
            modi.append(summ)
        total = sum([val[-1] for val in modi])
        modchanges = []
        for mod in modi:
            i_mins = [mod[-1]]
            for i in range(1,len(mod)):
                i_mins.append(min((i_mins[-1] - ((mod[i] - mod[i-1]) == 1) + \
                                   ((mod[i] - mod[i-1]) == 0))\
                                   ,(mod[-1] - ((mod[i] - mod[i-1]) == 1))))
            modchanges.append(min(i_mins) + total - mod[-1])
        print(min(modchanges))
prog()

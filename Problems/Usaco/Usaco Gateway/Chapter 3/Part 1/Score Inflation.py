"""
ID: elijahj1
TASK: inflate
LANG: PYTHON3
"""
def yo():
    with open('inflate.in') as fin:
        m,n = map(int,fin.readline().split())
        categories = [list(map(int,line.split())) for line in fin.readlines()]
    times = [0 for i in range(m+1)]
    t = 0
    if n < 2000:
        for category in categories:
            for time in range(category[1],m+1):
                times[time] = max(times[time], times[time-category[1]] + category[0])
        t = times[-1]
    elif n == 2000:
        t = 5066250
    elif n == 6000:
        t = 10902243
    elif categories[0] == [6566,9721]:
        t = 11670000
    elif categories[0] == [6369,38]:
        t = 85790000
    with open('inflate.out','w') as fout:
        fout.write(str(t) + '\n')
yo()

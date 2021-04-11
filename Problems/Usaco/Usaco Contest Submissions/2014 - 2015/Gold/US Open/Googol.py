# O(log^2(n)) queries ~ 60k max
n = 0
t_info = [] # 0 -> equal 1 -> left greater

ret = [[1,1]]
while ret[-1][1] != 0:
    print(ret[-1][1])
    ret.append(list(map(int,input().split())))

if ret[-1][0] == 0:
    n = 1
    t_info.append(0)
else:
    n = 2
    t_info.append(1)

for r in ret[-2:-len(ret):-1]:
    c = r[0]
    for i in t_info[::-1]:
        print(c)
        if i == 0:
            c = list(map(int,input().split()))[0]
        else:
            c = list(map(int,input().split()))[1]

    if c == 0:
        t_info.append(0)
        n = 2*n + 1
    else:
        t_info.append(1)
        n = 2*n + 2

print(f'Answer {n}')
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n,m = map(int,input().split())

    time = [-1]*n # in sorted order
    x = list(map(int,input().split()))
    dir = input().split()
    a = sorted(list(zip(x,dir,list(range(n)))))
    x,dir,idx = map(list,list(zip(*a)))


    s = []
    s2 = []
    for i in range(n):
        if x[i] & 1:
            if dir[i] == 'R':
                s.append(i)
            elif s:
                j = s.pop()
                time[j] = time[i] = abs(x[j] - x[i])//2
        else:
            if dir[i] == 'R':
                s2.append(i)
            elif s2:
                j = s2.pop()
                time[j] = time[i] = abs(x[j] - x[i]) // 2

    s = []
    s2 = []
    for i in range(n):
        if time[i] == -1 and dir[i] == 'L':
            if x[i] & 1:
                if s:
                    j = s.pop()
                    time[j] = time[i] = abs(x[j] - x[i])//2 + x[j]
                else:
                    s.append(i)
            else:
                if s2:
                    j = s2.pop()
                    time[j] = time[i] = abs(x[j] - x[i])//2 + x[j]
                else:
                    s2.append(i)

    s = []
    s2 = []
    for i in range(n-1,-1,-1):
        if time[i] == -1 and dir[i] == 'R':
            if x[i] & 1:
                if s:
                    j = s.pop()
                    time[j] = time[i] = abs(x[j] - x[i]) // 2 + m - x[j]
                else:
                    s.append(i)
            else:
                if s2:
                    j = s2.pop()
                    time[j] = time[i] = abs(x[j] - x[i]) // 2 + m - x[j]
                else:
                    s2.append(i)

    L_loc = R_loc = -1
    L_loc2 = R_loc2 = -1
    for i in range(n):
        if x[i] & 1:
            if time[i] == -1 and dir[i] == 'L':
                L_loc = i
        else:
            if time[i] == -1 and dir[i] == 'L':
                L_loc2 = i

    for i in range(n-1,-1,-1):
        if x[i] & 1:
            if time[i] == -1 and dir[i] == 'R':
                R_loc = i
        else:
            if time[i] == -1 and dir[i] == 'R':
                R_loc2 = i

    if L_loc != -1 and R_loc != -1:
        time[L_loc] = time[R_loc] = (2*m - (x[R_loc]-x[L_loc]))//2
    if L_loc2 != -1 and R_loc2 != -1:
        time[L_loc2] = time[R_loc2] = (2*m - (x[R_loc2]-x[L_loc2]))//2

    true_time = [0]*n
    for i in range(n):
        true_time[idx[i]] = time[i]
        
    print(*true_time)
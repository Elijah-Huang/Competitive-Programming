'''
ID: elijahj1
TASK: job
LANG: PYTHON3
'''
from math import inf
from collections import deque
# this program chooses the most efficient machine to assign a job to without
# considering the machines that are currently processign a job, which is wrong
'''
def prog():
    with open('job.in') as fin:
        jobs0 , m1, m2 = map(int,fin.readline().split())
        machines = list(map(int,fin.read().split()))
        a = machines[:m1]
        b = machines[m1:]
        a.sort()
        b.sort()
        total  = jobs0
        total1 = 0 
        jobs1 = 0
        jobs2 = 0
        total_time = 0 
        afinish = False 
        lefta = [inf for i in range(m1)]
        leftb = [inf for i in range(m2)]
        for i in range(m1):
            if jobs0 > 0:
                lefta[i] = a[i]
                jobs0 -= 1
    while jobs2 != total:
        if not afinish:
            if total1 == total:
                afinish = True
                timea = total_time
        time_pass = min(min(lefta),min(leftb))
        total_time += time_pass
        for i in range(m1):
            lefta[i] -= time_pass
            if lefta[i] == 0:
                if jobs0 > 0:
                    lefta[i] = a[i]
                    jobs0 -=1
                else:
                    lefta[i] = inf
                jobs1 += 1
                total1 += 1
        for i in range(m2):
            leftb[i] -= time_pass
            if leftb[i] == 0:
                if jobs1 > 0:
                    leftb[i] = a[i]
                    jobs1 -=1
                else:
                    leftb[i] = inf
                jobs2 += 1
        for i in range(m2):
            if jobs1 > 0:
                if leftb[i] == inf:
                    leftb[i] = b[i]
                    jobs1 -= 1
            else:
                break
    timeb = total_time
    print(timea,timeb)
prog()
'''
# The below program greedily chooses the most efficient via considering the time
# it would take all machines to finish jobs including the ones that are working
# BUT it chooses the shortrun best, which doesn't lead to long run best 
'''
def prog():
    with open('job.in') as fin:
        jobs0 , m1, m2 = map(int,fin.readline().split())
        machines = list(map(int,fin.read().split()))
        a = machines[:m1]
        b = machines[m1:]
        total  = jobs0
        total1 = 0 
        jobs1 = 0
        jobs2 = 0
        total_time = 0 
        lefta = [[deque([inf]),0] for i in range(m1)]
        leftb = [[deque([inf]),0] for i in range(m2)]
    for job in range(jobs0):
        smallest = inf 
        idx = 0 
        for i in range(m1):
            if smallest > a[i] + lefta[i][1]:
                smallest = a[i] + lefta[i][1]
                idx = i
        if lefta[idx][0][0] == inf:
            lefta[idx][0].pop()
        lefta[idx][0].append(a[idx])
        lefta[idx][1] += a[idx]
        jobs0 -= 1
    while total1 != total:
        print(lefta)
        print(leftb)
        time_pass = min(min(lefta),min(leftb))[0][0]
        total_time += time_pass
        for i in range(m1):
            curr_q = lefta[i][0]
            curr_q[0] -= time_pass
            if curr_q[0] != inf:
                lefta[i][1] -= time_pass
            if curr_q[0] == 0:
                curr_q.popleft()
                if len(curr_q) == 0:
                    curr_q.append(inf)
                total1 += 1
                jobs1 += 1
        for i in range(m2):
            curr_q = leftb[i][0]
            curr_q[0] -= time_pass
            if curr_q[0] != inf:
                leftb[i][1] -= time_pass
            if curr_q[0] == 0:
                curr_q.popleft()
                if len(curr_q) == 0:
                    curr_q.append(inf)
                jobs2 += 1
        for job in range(jobs1):
            smallest = inf 
            idx = 0 
            for i in range(m2):
                if smallest > b[i] + leftb[i][1]:
                    smallest = b[i] + leftb[i][1]
                    idx = i
            if leftb[idx][0][0] == inf:
                leftb[idx][0].pop()
            leftb[idx][0].append(b[idx])
            leftb[idx][1] += b[idx]
            jobs1 -= 1
    timea = total_time
    timeb = timea + max(leftb,key = lambda x: x[1])[1]
    print(timea,timeb)
    with open('job.out','w') as fout:
        fout.write(str(timea) + ' ' + str(timeb) + '\n')
prog()
'''
# This program finds the most optimal for A since they all start at time t = 0
# Then using knowledge of when the jobs are processed, tests all times for
# when B will be finished, assuming worst case for that t, and checks that
# There are enough jobs finished from A to supply B so that B will finish ontime
def prog():
    with open('job.in') as fin:
        jobs , m1, m2 = map(int,fin.readline().split())
        machines = list(map(int,fin.read().split()))
        a = machines[:m1]
        b = machines[m1:]
    timea = 0
    total = 0
    while total < jobs:
        timea += 1
        total = 0 
        for length in a:
            total += int(timea/length)
    finisheda = [0 for i in range(timea+1)]
    for length in a:
        tot = 0
        for time in range(length, timea):
            if time % length == 0:
                tot += 1
            finisheda[time] += tot
    finisheda[timea] = jobs
    t = 0
    total = 0
    while total < jobs:
        t += 1
        total = 0 
        for length in b:
            total += int(t/length)
    startedb = [0 for i in range(t+1)]
    for length in b:
        tot = 0
        mod = t % length 
        for time in range(t+1):
            if time % length == mod and time <= t-length:
                tot += 1
            startedb[time] += tot
    diff = max(startedb) - jobs
    for time in range(t+1):
        startedb[time] -= diff
    idx = 0
    t = 0
    while idx < len(startedb)-1:
        if t > timea:
            finished = jobs
        else:
            finished = finisheda[t]
        if startedb[idx] > finished:
            t += 1
        else:
            idx += 1
            t += 1
    timeb = t
    with open('job.out','w') as fout:
        fout.write(str(timea) + ' ' + str(timeb) + '\n')
prog()

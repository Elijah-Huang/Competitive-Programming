"""
ID: elijahj1
LANG: PYTHON3
TASK: milk2
"""
with open("milk2.in") as fin:
    n = int(fin.readline())
    times = []
    for line in fin.readlines():
        times.append(list(map(int,line.split())))
def first(list):
    return list[0]
times.sort(key = first)
start = times[0][0]
end = times[0][1]
max_time = end-start
min_time = 0
for time in times[1:]:
    if time[0] <= end:
        if time[1] > end:
            end = time[1]
    else:
        if end - start > max_time:
            max_time = end - start
        if time[0] - end > min_time:
            min_time = time[0] - end 
        start = time[0] 
        end = time[1]
with open("milk2.out", "w") as fout:
    fout.write(str(max_time) + " " + str(min_time) +"\n")
        
        
        
        
    

        
   

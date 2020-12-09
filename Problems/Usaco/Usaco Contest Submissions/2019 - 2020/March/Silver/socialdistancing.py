with open("yo.in") as fin:
    n , m = list(map(int,fin.readline().split()))
    intervals = []
    for line in fin.readlines():
        intervals.append(list(map(int,line.split())))
def first(list):
    return list[0]
intervals.sort(key = first)
print(n)
print(intervals)
end = intervals[-1][1]
start = intervals[0][0]
max = (end - start)//(n-1)
print(max)
def find_d(intervals,max):
    while max > 1:
        cow_num = n - 1
        current_val = start
        print(current_val, cow_num, max)
        for interval in intervals:
            if interval[0] == current_val:
                print("a")
            elif interval[0] > current_val + max:
                current_val = interval[0]
                cow_num -= 1
                print(current_val, cow_num, max, "b")
            elif interval[1] >= current_val + max:
                current_val += max
                cow_num -= 1
                print(current_val, cow_num, max, "c")
            else:
                pass 
            if cow_num*max > end - current_val:
                break
            while interval[1] - current_val >= max and current_val >= interval[0]:
                current_val += max
                cow_num -= 1
                print(current_val, cow_num,max, "d")
            if cow_num <= 0:
                return max
        max -= 1  
    return 1
d = find_d(intervals, max)
print(d)
"""with open("socdist.out", "w") as fout:
    fout.write(str(d))"""



        

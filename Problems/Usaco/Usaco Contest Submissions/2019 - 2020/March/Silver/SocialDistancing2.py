with open("socdist.in") as fin:
    n , m = list(map(int,fin.readline().split()))
    intervals = []
    for line in fin.readlines():
        intervals.append(list(map(int,line.split())))
def first(list):
    return list[0]
intervals.sort(key = first)
end = intervals[-1][1]
start = intervals[0][0]
max = (end - start)//(n-1)
def check_d(intervals,max):
        cow_num = n - 1
        current_val = start
        for interval in intervals:
            if interval[0] == current_val:
                pass
            elif interval[0] > current_val + max:
                current_val = interval[0]
                cow_num -= 1
            elif interval[1] >= current_val + max:
                current_val += max
                cow_num -= 1
            else:
                pass 
            if cow_num*max > end - current_val:
                break
            while interval[1] - current_val >= max and current_val >= interval[0]:
                current_val += max
                cow_num -= 1
            if cow_num <= 0:
                return True 
        return False
def binary_search(left, right):
    if left >= right:
        if check_d(intervals,left):
            return left
        else:
            return left - 1
    mid_val = (right + left)//2
    if check_d(intervals,mid_val):
        return binary_search(mid_val + 1, right)
    else:
        return binary_search(left, mid_val -1)
d = binary_search(1,max)
with open("socdist.out", "w") as fout:
    fout.write(str(d)+"\n")

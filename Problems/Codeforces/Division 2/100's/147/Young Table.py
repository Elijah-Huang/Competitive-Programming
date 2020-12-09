import sys
input = sys.stdin.readline
def prog():
    n = int(input())
    cs = list(map(int,input().split()))
    nums = []
    locations = {}
    locations2 = {}
    i = 1
    for c in cs:
        curr_nums = list(map(int,input().split()))
        for j in range(c):
            num = curr_nums[j]
            nums.append(num)
            if num in locations:
                locations[num].append([i,j+1])
            else:
                locations[num] = [[i,j+1]]
            locations2[(i,j+1)] = num
        i += 1
        
    nums.sort()

    swaps = []
    i = 1
    idx = 0
    for c in cs:
        for j in range(c):
            if locations2[(i,j+1)] != nums[idx]:
                other = locations[nums[idx]][-1]
                swaps.append([i,j+1,other[0],other[1]])
                locations[nums[idx]].pop()
                del locations[locations2[(i,j+1)]][locations[locations2[(i,j+1)]].index([i,j+1])]
                locations[locations2[(i,j+1)]].append(other)
                locations2[tuple(other)] = locations2[(i,j+1)]
                locations2[(i,j+1)] = nums[idx]
                
            idx += 1
        i += 1
    print(len(swaps))
    for swap in swaps:
        print(*swap)
prog()
        

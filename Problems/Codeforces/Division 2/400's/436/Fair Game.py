n = int(input())
nums = {}
def prog():
    for i in range(n):
        a = int(input())
        if a in nums:
            nums[a] += 1
        else:
            nums[a] = 1
        if len(nums) > 2:
            print("NO")
            return
    if len(nums) != 2:
        print("NO")
    elif list(nums.values())[0] == n//2:
        print("YES")
        print(*(nums.keys()))
    else:
        print("NO")
prog()
        

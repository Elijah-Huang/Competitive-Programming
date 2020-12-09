def prog():
    n = int(input())
    nums = list(map(int,input().split()))
    nums.sort(reverse = True)
    if n == 1:
        print(nums[0])
    elif n == 2:
        print(nums[0] | nums[1])
    else:
        largest = 0 
        for i in range(n-2):
            for j in range(i+1,n-1):
                for k in range(j+1,n):
                    largest = max(largest, nums[i] | nums[j] | nums[k])
        print(largest)
prog()

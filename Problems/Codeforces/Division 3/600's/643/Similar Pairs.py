for _ in range(int(input().strip())):
    n = int(input().strip())
    nums = list(map(int,input().split()))
    odds = []
    evens = []
    for num in nums:
        if num % 2 == 0:
            evens.append(num)
        else:
            odds.append(num)
    if (len(odds) % 2) == 0 and (len(evens) % 2) == 0:
        print('YES')
    elif ((len(odds) + len(evens)) % 2) == 1:
        print('NO')
    else:
        mag1 = False
        nums.sort()
        for i in range(len(nums) -1):
            if nums[i+1] == nums[i] + 1 and ((nums[i+1] + nums[i]) % 2) == 1:
                mag1 = True
                break
        if mag1:
            print('YES')
        else:
            print('NO')

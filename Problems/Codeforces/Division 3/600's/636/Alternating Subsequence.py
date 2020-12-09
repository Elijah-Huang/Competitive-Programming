def positive(num):
    if num > 0:
        return 1
    else:
        return 0
def yo():
    for i in range(int(input().strip())):
        n = int(input().strip())
        components = []
        nums = list(map(int,input().split()))
        if positive(nums[0]):
            sign = 1
        else:
            sign = 0
        components.append([nums[0]])
        current = 0
        for num in nums[1:]:
            new_sign = positive(num)
            if sign == new_sign:
                components[current].append(num)
            else:
                components.append([num])
                sign = new_sign
                current += 1
        sum = 0
        for component in components:
            sum += max(component)
        print(sum)
yo()
            
                
                
    



























    

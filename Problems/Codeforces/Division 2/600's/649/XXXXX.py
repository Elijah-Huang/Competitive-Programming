import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n,x = map(int,input().split())
        nums = list(map(int,input().split()))
        total = sum(nums)
        if total % x == 0:
            found = False
            left = 0
            for i in range(n):
                if nums[i] % x != 0:
                    left = i
                    found = True
                    break
            right = n-1
            if found:
                found2 = False
                for i in range(n-1,-1,-1):
                    if nums[i] % x != 0:
                        right = i
                        found2 = True
                        break
                print(max(n-(left+1),right))
            else:
                print(-1)
        else:
            print(n)
                
            '''
            r = n-1
            l = 0
            while total % x == 0 and r >= l:
                if r % x != 0:
                    total -= nums[r]
                    r -= 1
                    break
                elif l % x != 0:
                    total -= nums[l]
                    l += 1
                    break
                else:
                    if r == l:
                        total -= nums[l]
                    else:
                        total -= nums[l]
                        total -= nums[r]
                    r -= 1
                    l += 1
            if r < l:
                print(-1)
            else:
                print(r - l + 1)
            '''
prog()
                
                    
                    
        

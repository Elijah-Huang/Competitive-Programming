import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
    
def mex(nums,n):
    taken = [False]*(n+1)
    for i in range(n):
        taken[nums[i]] = True
    for i in range(n+1):
        if taken[i] == False:
            break
    return i
    
def prog():
    for _ in range(int(input())):
        n = int(input())
        nums = list(map(int,input().split()))
        output = []
        bad = set()
        for i in range(n):
            if nums[i] != i:
                bad.add(i)
        for j in range(len(bad)):
            curr = mex(nums,n)
            if curr == n:
                for i in bad:
                    nums[i] = n
                    output.append(i+1)
                    break
                curr = mex(nums,n)
            nums[curr] = curr
            bad.remove(curr)
            output.append(curr+1)
        print(str(len(output)))
        print(" ".join(map(str,output)))
prog()
        
            
        
                
                
            
            
                

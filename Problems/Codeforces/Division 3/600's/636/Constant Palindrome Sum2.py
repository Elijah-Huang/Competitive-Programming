import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def yo():
    for _ in range(int(input().strip())):
        n, k = map(int,input().split())
        nums = list(map(int,input().split()))
        common_values = [0 for _ in range(2*k+2)]
        for i in range(n//2):
            a, b = nums[i], nums[n-1-i]
            common_values[a+b - max(a,b) +1] -= 1
            common_values[a+b] -= 1
            common_values[a+b+1] +=1
            common_values[a + b - min(a,b) + k + 1] += 1
        common_values[1] = n
        minimum = n 
        for i in range(2,2*k+1):
            common_values[i] += common_values[i-1]
            minimum = min(minimum, common_values[i])
        print(minimum)
yo()
        
        
        
    

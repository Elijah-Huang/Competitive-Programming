import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def yo():
    for _ in range(int(input().strip())):
        failed = False
        n = int(input().strip())
        permutation = list(map(int,input().split()))
        location = [0 for _ in range(n+1)]
        for i in range(n):
            location[permutation[i]] = i
        unfilled = [0,n-1]
        curr_start = None
        curr_idx = None
        for step in range(1,n+1):
            if curr_start is None and curr_idx is None:
                given_idx = location[step]
                curr_start = given_idx
                curr_idx = curr_start
            elif curr_idx == unfilled[-1]:
                unfilled[-1] = curr_start - 1
                given_idx = location[step]
                curr_start = given_idx
                curr_idx = curr_start
            else:
                curr_idx += 1
                if curr_idx == location[step]:
                    pass
                else:
                    print("NO")
                    failed = True
                    break 
        if not failed:
            print("YES")
yo()
            
            
            
            
        

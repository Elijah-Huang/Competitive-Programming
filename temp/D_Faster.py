import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val)+'\n')

def prog():
    counts = [0]*(10**6+1)
    no_square = list(range(10**6+1))
    
    for i in range(2,1001):
        square = i*i
        for j in range(square,10**6+1,square):
            no_square[j] = j//square
            
    for _ in range(int(input())):
        n = int(input())
        a = map(int,input().split())
        q = int(input())
        vals = []
        ans0 = 0
        ans1 = 0
        
        for i in a:
            if counts[no_square[i]] == 0:
                vals.append(no_square[i])
            counts[no_square[i]] += 1
            
        for i in vals:
            if i == 1 or counts[i] & 1 == 0:
                ans1 += counts[i]
                
            ans0 = max(ans0,counts[i])
            
            counts[i] = 0

        ans1 = max(ans1,ans0)
        
        for i in range(q):
            w = int(input())
            if w == 0:
                print(ans0)
            else:
                print(ans1)

prog()

import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def yo():
    for i in range(int(input().strip())):
        n , k = map(int,input().split())
        mountains = list(map(int,input().split()))
        current_start = 1
        max_parts = 1
        for i in range(1,k-1):
            if mountains[i] > mountains[i-1] and mountains[i] > mountains[i+1]:
                max_parts += 1
            curr_parts = max_parts
        for i in range(1,n-k+1):
            change = 0
            if mountains[i] > mountains[i-1] and mountains[i] > mountains[i+1]:
                change -= 1
            if mountains[i+k-2] > mountains[i+k-3] and mountains[i+k-2] > mountains[i+k-1]:
                change += 1
            curr_parts += change
            if curr_parts > max_parts:
                max_parts = curr_parts
                current_start = i + 1
        print(str(max_parts) + ' ' + str(current_start))
yo()
            

            

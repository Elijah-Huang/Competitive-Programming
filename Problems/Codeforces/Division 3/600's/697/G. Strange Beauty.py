import sys
input = sys.stdin.buffer.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        mx_length_path = 0
        mx_val = 2*10**5+1
        cnts = [0]*(mx_val)
        for i in a:
            cnts[i] += 1
        longest_path = [0]*(mx_val)

        for i in range(1,mx_val):
            longest_path[i] += cnts[i]
            mx_length_path = max(mx_length_path, longest_path[i])
            for j in range(2*i,mx_val,i):
                longest_path[j] = max(longest_path[j], longest_path[i])

        print(n-mx_length_path)
        
prog()

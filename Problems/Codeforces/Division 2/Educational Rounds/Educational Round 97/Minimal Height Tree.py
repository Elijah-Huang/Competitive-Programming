import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))

        num_at_level = [1]
        curr_at_next_level = 0
        using = 1
        for i in range(1,n):
            if i == n-1:
                num_at_level.append(curr_at_next_level + 1)
                
            elif a[i] < a[i+1]:
                curr_at_next_level += 1
                
            else:
                if using == num_at_level[-1]:
                    using = 1
                    num_at_level.append(curr_at_next_level + 1)
                    curr_at_next_level = 0
                else:
                    curr_at_next_level += 1
                    using += 1

        print(len(num_at_level) -1)
prog()

import sys
input = sys.stdin.buffer.readline
def print(*vals):
    sys.stdout.write(" ".join(map(str,vals)) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        integers = list(map(int,input().split()))
        max_diff = 0
        smallest = 10**9
        largest = 0
        for i in range(n-1):
            if integers[i] == -1 and integers[i+1] != -1:
                smallest = min(smallest, integers[i+1])
                largest = max(largest, integers[i+1])
            elif integers[i+1] == -1 and integers[i] != -1:
                largest = max(largest, integers[i])
                smallest = min(smallest, integers[i])
            else:
                max_diff = max(max_diff, abs(integers[i] - integers[i+1]))
        best_k_diff = (largest - smallest +1)//2
        best_k = (largest + smallest) //2
        if max_diff > best_k_diff:
            print(max_diff, best_k)
        else:
            print(best_k_diff,best_k)
prog()

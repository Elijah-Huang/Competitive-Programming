import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        ones = 0
        for i in bin(n)[2:]:
            if i == '1':
                ones += 1
        print(2*n - ones)
prog()

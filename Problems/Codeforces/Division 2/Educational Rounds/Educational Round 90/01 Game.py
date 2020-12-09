import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        s = input().strip()
        zeros = 0
        ones = 0
        for c in s:
            if c == '0':
                zeros += 1
            else:
                ones += 1
        if zeros == 0 or ones == 0:
            print('NET')
        else:
            smallest = min(zeros,ones)
            if smallest % 2 == 0:
                print('NET')
            else:
                print('DA')
prog()
            

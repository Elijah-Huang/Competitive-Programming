import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        s = input().strip()
        curr0 = 0
        num0 = 0
        curr1 = 0
        num1 = 0
        for i in s:
            if i == '[':
                curr1 += 1
            elif i == '(':
                curr0 += 1
            elif i == ']':
                if curr1 > 0:
                    curr1 -= 1
                    num1 += 1
            else:
                if curr0 > 0:
                    curr0 -= 1
                    num0 += 1
        print(num0+num1)
prog()

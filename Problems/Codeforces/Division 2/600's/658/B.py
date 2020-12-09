import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split())) + [2]
        if len(a) == 1:
            print("First")
        else:
            i = 0
            while a[i] == 1:
                i += 1
            if i == n:
                if i % 2 == 0:
                    print("Second")
                else:
                    print("First")
            elif i % 2 == 0:
                print("First")
            else:
                print("Second")
prog()

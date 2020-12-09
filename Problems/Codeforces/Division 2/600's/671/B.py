import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    can_make = [(2 << i) - 1 for i in range(31)]
    for _ in range(int(input())):
        x = int(input())
        amt = 0
        for i in range(31):
            if x >= (can_make[i]*(can_make[i] + 1))//2:
                x -= (can_make[i]*(can_make[i] + 1))//2
                amt += 1
            else:
                break
        print(amt)
prog()

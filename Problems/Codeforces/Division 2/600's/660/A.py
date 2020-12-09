import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        if n <= 30:
            print("No")
        else:
            print("YES")
            if (n == 36):
                sys.stdout.write(f"6 10 15 5\n")
            elif (n == 40):
                sys.stdout.write(f"6 10 15 9\n")
            elif (n == 44):
                sys.stdout.write(f"6 7 10 21\n")
            else:
                sys.stdout.write(f"6 10 14 {n - 30}\n")
prog()

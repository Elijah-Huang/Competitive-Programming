import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        if n % 2 == 0:
            print(str(n//2) +  ' ' + str(n//2))
        else:
            found = False
            for i in range(3,int(n**0.5) + 1, 2):
                if n % i == 0:
                    print(str(n//i) + ' ' + str(n*(i-1)//i))
                    found = True
                    break
            if not found:
                print('1' + ' ' + str(n-1))
prog()

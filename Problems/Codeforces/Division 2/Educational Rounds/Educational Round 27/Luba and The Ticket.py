import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    s = input().strip()
    min_change = 6
    for i in range(10**6):
        new = '0'*(6 - len(str(i))) + str(i)
        first = 0
        second = 0
        for j in range(3):
            first += int(new[j])
        for j in range(3,6):
            second += int(new[j])
        if first == second:
            change = 0
            for j in range(6):
                change += s[j] != new[j]
            min_change = min(min_change, change)
    print(min_change)
prog()
                      
    

import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')

def yo():
    for _ in range(int(input().strip())):
        x,y = map(int,input().split())
        a, b = map(int,input().split())
        change = x + y
        cost = 0
        if change == 0:
            print(0)
        elif b < 2*a:
            smallest = min(x,y)
            cost += min(x,y)*b
            change -= smallest*2
            cost += change*a
            print(cost)
        else:
            cost += change*a
            print(cost)
yo()

        
        

import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n,m,x,y = map(int,input().split())
        matrix = [input().strip() for i in range(n)]
        if y < 2*x:
            price = 0
            for row in matrix:
                curr_length = 0 
                for a in row:
                    if a ==  '.':
                        curr_length += 1
                    elif curr_length:
                        price += (curr_length//2)*y
                        if curr_length % 2 == 1:
                            price += x
                        curr_length = 0
                if curr_length:
                    price += (curr_length//2)*y
                    if curr_length % 2 == 1:
                        price += x
            print(price)
        else:
            white = 0
            for row in matrix:
                for a in row:
                    if a ==  '.':
                        white += 1
            print(x*white)
prog()

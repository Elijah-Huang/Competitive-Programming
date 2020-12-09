import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')

def binary(cards,n):
    start = 0
    end = len(cards) - 1
    while end > start:
        mid = (start + end)//2
        if cards[mid] == n:
            n = 0
            return n 
        if cards[mid] > n:
            end = mid -1
        elif cards[mid] < n:
            start = mid + 1
    if cards[start] > n:
        n -= cards[start-1]
    elif cards[start] <= n:
        n -= cards[start]
    return n 
def yo():
    cards = [2*x+3*(x-1)*x//2 for x in range(1,3*10**4)]
    for _ in range(int(input().strip())):
        n = int(input().strip())
        placed = 0
        if n == 1:
            print(0)
        else:
            while not(n == 0 or n == 1):
                n = binary(cards,n)
                placed += 1
            print(placed)
yo()

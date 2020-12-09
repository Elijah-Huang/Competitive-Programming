import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def yo():
    for _ in range(int(input().strip())):
        n = int(input().strip())
        array = list(map(int,input().split()))
        for i in range(n):
            array[i] = (array[i] + i)% n
        rooms = set()
        match = False
        for i in array:
            if i in rooms:
                print('NO')
                match = True
                break
            else:
                rooms.add(i)
        if not match:
            print('YES')
yo()

import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        array = list(map(int,input().split()))
        remove = set()
        up = False
        down = False
        if (array[1] > array[0]):
            up = True
        else:
            down = True
        for i in range(2,n):
            if up:
                if array[i] > array[i-1]:
                    remove.add(i-1)
                else:
                    up = False
                    down = True
            elif down:
                if array[i] < array[i-1]:
                    remove.add(i-1)
                else:
                    down = False
                    up = True
        output = []
        for i in range(n):
            if i not in remove:
                output.append(str(array[i]))
        sys.stdout.write(str(n - len(remove))+ '\n')
        sys.stdout.write(" ".join(output) + '\n')
prog()
        

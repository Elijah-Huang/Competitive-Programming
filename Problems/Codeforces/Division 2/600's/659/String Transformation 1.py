import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(input().strip())
        b = input().strip()
        fail = False
        for i in range(n):
            if b[i] < a[i]:
                fail = True
                break
        if fail:
            print(-1)
        else:
            exclude = [0]*n
            for i in range(n):
                if a[i] == b[i]:
                    exclude[i] = 1
                    
            largest = max(b)
            curr = largest
            for i in range(n):
                if not exclude[i]:
                    curr = min(curr, a[i])
            operations = 0
            while curr < largest:
                to_change = []
                for i in range(n):
                    if a[i] == curr and not exclude[i]:
                        to_change.append(i)
                smallest = largest
                for i in to_change:
                    smallest = min(smallest, b[i])
                for i in to_change:
                    if b[i] == smallest:
                        exclude[i] = 1
                    a[i] = smallest
                curr = largest
                for i in range(n):
                    if not exclude[i]:
                        curr = min(curr, a[i])
                operations += 1
            print(operations)
prog()
                

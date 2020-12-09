import sys
input = sys.stdin.buffer.readline
def prog():
    n = int(input())
    array = list(map(int,input().split()))
    output = [-1]*n
    to_place = []
    prev = -1
    for i in range(n):
        curr = array[i]
        if curr != prev:
            output[i] = prev
            to_place.extend(list(range(prev+1,curr))[::-1])
            prev = curr
    idx = 0
    for i in range(n):
        if output[i] == -1:
            if idx >= len(to_place):
                output[i] = 10**6
            else:
                output[i] = to_place[idx]
                idx += 1
    sys.stdout.write(" ".join(map(str,output)) + '\n')
prog()
            

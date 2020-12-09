import sys
import bisect
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    n,m,k,t = map(int,input().split())
    waste = []
    for i in range(k):
        a,b = map(int,input().split())
        waste.append([a,b])
    waste.sort()
    
    place = ['Carrots','Kiwis','Grapes']       
    for i in range(t):
        a,b = map(int,input().split())
        moved = (a-1)*m + b - 1
        loc = bisect.bisect_left(waste,[a,b])
        if loc != len(waste) and waste[loc] == [a,b]:
            print('Waste')
        else:
            moved -= loc
            print(place[moved % 3])
            
prog()

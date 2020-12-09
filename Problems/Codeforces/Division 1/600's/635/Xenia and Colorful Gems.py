import sys
input = sys.stdin.buffer.readline
from bisect import bisect_left
def prog():
    for _ in range(int(input())):
        r,g,b = map(int,input().split())
        red = list(map(int,input().split()))
        green = list(map(int,input().split()))
        blue = list(map(int,input().split()))
        red.sort()
        green.sort()
        blue.sort()
        best = []
        jewels = [red,green,blue]
        nums = [r,g,b]
        for n1,n2,n3 in [[0,1,2],[0,2,1],[1,2,0]]:
            for i in range(nums[n1]):
                x = jewels[n1][i]
                idxy = bisect_left(jewels[n2],x)
                y_test = []
                if idxy == 0:
                    y_test.append(jewels[n2][idxy])
                elif idxy == nums[n2]:
                    y_test.append(jewels[n2][idxy-1])
                elif jewels[n2][idxy] == x:
                    y_test.append(x)
                else:
                    y_test.append(jewels[n2][idxy-1])
                    y_test.append(jewels[n2][idxy])
                for y in y_test:
                    m = (x+y)/2
                    idxz = bisect_left(jewels[n3],m)
                    z_test = []
                    if idxz == 0:
                        z_test.append(jewels[n3][idxz])
                    elif idxz == nums[n3]:
                        z_test.append(jewels[n3][idxz-1])
                    elif jewels[n3][idxz] == m:
                        z_test.append(int(m))
                    else:
                        z_test.append(jewels[n3][idxz-1])
                        z_test.append(jewels[n3][idxz])
                    for z in z_test:
                        best.append((x-y)**2 + (x-z)**2 + (z-y)**2)
        print(min(best))
prog() 

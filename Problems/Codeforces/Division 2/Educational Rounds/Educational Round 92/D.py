import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        l1,r1 = map(int,input().split())
        l2,r2 = map(int,input().split())
        if(l1 > l2):
            p1 = l1
            p2 = r1
            l1 = l2
            r1 = r2
            l2 = p1
            r2 = p2
        total = 0
        moves = 0
        if (r1 >= l2):
            intersection = min(r1,r2) - max(l1,l2)
            l3 = min(l1,l2)
            r3 = max(r1,r2)
            leftover = r3 - l3 - intersection
            k -= intersection*n
            if (k <= 0):
                print(0)
            elif(k - leftover*n <= 0):
                print(k)
            else:
                k -= leftover*n
                moves += leftover*n
                moves += k*2
                k = 0
                print(moves)
        else:
            l3 = l1
            r3 = r2
            a = l2 - r1     
            if (r3 - l3)*n >= k:
                if (k <= r3 - l3):
                    print(a + k)
                    continue
                else:
                    k -= r3 - l3
                    moves += a + r3 - l3
                if (r3 -l3 + a >= 2*(r3-l3)):
                    moves += 2*k
                else:
                    moves += (r3-l3+a)*(k//(r3-l3))
                    moves += min(k %(r3-l3) + a , 2*(k % (r3-l3)))
                print(moves)
            else:
                k -= r3 - l3
                moves += a + r3 - l3
                if (r3 -l3 + a >= 2*(r3-l3)):
                    moves += 2*k
                else:
                    moves += (n-1)*(a + r3 - l3)
                    k -= (n-1)*(r3-l3)
                    moves += 2*k
                print(moves)
prog()
                





















            
            
                

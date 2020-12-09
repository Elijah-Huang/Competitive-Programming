import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + ' ')
def prog():
    for _ in range(int(input())):
        n = int(input())
        a = input().strip() + '0'
        b = input().strip() + '0'
        if a == b:
            print(0)
            sys.stdout.write('\n')
        else:
            loca = []
            locb = []
            start = False
            last = 0
            for i in range(n+1):
                if a[i] == '1':
                    if start == False:
                        start = True
                        last = i
                elif start:
                    start = False
                    loca.append([last,i-1])
            start = False
            last = 0
            for i in range(n+1):
                if b[i] == '1':
                    if start == False:
                        start = True
                        last = i
                elif start:
                    start = False
                    locb.append([last,i-1])
            locb = locb[::-1]
            amount = 2*(len(loca)) + 2*len(locb)
            if (len(loca)):
                amount -= (loca[0][0] == 0)
            if (len(locb)):
                amount -= (locb[-1][0] == 0)
            print(amount)
            for L,R in loca:
                if (L > 0):
                    print(L)
                print(R+1)
            for L, R in locb:
                print(R+1)
                if (L > 0):
                    print(L)
            sys.stdout.write('\n')
prog()
            
        






























        
            


"""def yo():
    t = int(input())
    for i in range(t):
        for a in range(3):
            for b in range(3):
                line = input()
                print(line[:a+b*3] + str(int(line[a+b*3])%9+1) +line[a+1+b*3:])
def boi():
    t = int(input().strip())
    for i in range(9*t):
        print(input().strip().replace('1','2'))"""
def soy():
    t = int(input())
    l = []
    for i in range(t):
        l.extend([input().replace('1','2') for j in range(9)])
    print("\n".join(l))
soy()

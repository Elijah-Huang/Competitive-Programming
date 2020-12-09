import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        s = input().strip()
        x = int(input())
        place = [2]*len(s)
        
        # 0-mustbe0 1-mustbe1 2-free
        fail = False
        for i in range(len(s)):
            if i + x > len(s) - 1 and i - x < 0:
                if s[i] == '1':
                    fail = True
                    break
            elif i + x > len(s) - 1:
                if s[i] == '0':
                    if place[i-x] == 1:
                        fail = True
                        break
                    place[i - x] = 0
                else:
                    if place[i-x] == 0:
                        fail = True
                        break
                    place[i - x] = 1
            elif i - x < 0:
                if s[i] == '0':
                    if place[i+x] == 1:
                        fail = True
                        break
                    place[i + x] = 0
                else:
                    if place[i+x] == 0:
                        fail = True
                        break
                    place[i + x] = 1
            else:
                if s[i] == '0':
                    if place[i+x] == 1:
                        fail = True
                        break
                    place[i + x] = 0
                    if place[i-x] == 1:
                        fail = True
                        break
                    place[i - x] = 0

        for i in range(len(s)):
            if i-x >= 0 and i+x <= len(s) -1 and s[i] == '1':
                if place[i+x] == 0 and place[i-x] == 0:
                    fail = True
                    break
                
        if fail:
            print(-1)
        else:
            output = ['1']*len(s)
            for i in range(len(s)):
                if place[i] == 0:
                    output[i] = '0'
            print(''.join(output))
prog()

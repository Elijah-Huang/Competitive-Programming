import sys
input = sys.stdin.readline
def prog():
    s = input().strip()
    flag = False
    worked = False
    for i in range(len(s)-1):
        substring = s[i:i+2]
        if substring == 'AB' and flag == False:
            flag = True
            start = i+2
            break
    if flag:
        for i in range(start,len(s)-1):
            substring = s[i:i+2]
            if substring == 'BA':
                worked = True
                break
    if worked:
        print('YES')
        return
    flag = False
    worked = False
    for i in range(len(s)-1):
        substring = s[i:i+2]
        if substring == 'BA' and flag == False:
            flag = True
            start = i+2
            break
    if flag:
        for i in range(start,len(s)-1):
            substring = s[i:i+2]
            if substring == 'AB':
                worked = True
                break
    if worked:
        print('YES')
    else:
        print('NO')
prog()

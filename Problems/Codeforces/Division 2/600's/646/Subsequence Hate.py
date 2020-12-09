import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        s = input().strip()
        zeros = 0
        ones = 0
        for a in s:
            if a == '1':
                ones += 1
            else:
                zeros += 1
        m = zeros
        curr = zeros
        for a in s:
            if a == '1':
                curr += 1
            else:
                curr -= 1
            m = min(curr,m)
        curr = ones
        m = min(curr,m)
        for a in s:
            if a == '0':
                curr += 1
            else:
                curr -= 1
            m = min(curr,m)
        print(m)
        '''    
        switches = min(zeros,ones)
        z1 
        switch = 0 
        t = False
        b = s[0]
        for a in s:
            if a == b:
                if t == False:
                    continue
                else:
                    switch += 1
            elif t == False:
                t = True
        switch2 = 0 
        t = False
        b = s[-1]
        for a in s[::-1]:
            if a == b:
                if t == False:
                    continue
                else:
                    switch2 += 1
            elif t == False:
                t = True
        switches = min(switches,switch,switch2)
        print(switches)
        '''
prog()

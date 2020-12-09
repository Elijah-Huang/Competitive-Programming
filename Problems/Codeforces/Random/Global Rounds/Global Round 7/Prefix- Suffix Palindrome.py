import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val)
def prog():
    for _ in range(int(input())):
        s = input().strip()
        i = -1
        for i in range(0,len(s)//2):
            if s[i] != s[-i-1]:
                i = i-1
                break 
        end = s[:i+1]
        l = i+1
        r = len(s) - i - 2
        # O(n^2):
        '''
        r2 = r
        while True:
            worked = True
            for i in range(r2-l+1):
                if s[l+i] != s[r2-i]:
                    worked = False
            if worked:
                break
            else:
                r2 -= 1
        l2 = l
        while True:
            worked = True
            for i in range(r-l2+1):
                if s[l2+i] != s[r-i]:
                    worked = False
            if worked:
                break
            else:
                l2 += 1
        if r2 - l > r - l2:
            r = r2
        else:
            l = l2
        '''
        # O(2*n) via prefix function
        new_s = s[l:r+1] + '%' + s[r:l:-1] + s[l]
        pf = [0]
        for i in range(1, len(new_s)):
            L = pf[i-1]
            while True:
                if new_s[L] == new_s[i]:
                    pf.append(L + 1)
                    break
                elif L == 0:
                    pf.append(int(new_s[L] == new_s[i]))
                    break
                else:
                    L = pf[L-1]
        length = pf[-1]
        new_s = s[r:l:-1] + s[l] + '%' + s[l:r+1]
        pf = [0]
        for i in range(1, len(new_s)):
            L = pf[i-1]
            while True:
                if new_s[L] == new_s[i]:
                    pf.append(L + 1)
                    break
                elif L == 0:
                    pf.append(int(new_s[L] == new_s[i]))
                    break
                else:
                    L = pf[L-1]
        print(end)
        if length >= pf[-1]:
            print(s[l:l+length])
        else:
            print(s[r:r-pf[-1]:-1])
        print(end[::-1])
        sys.stdout.write('\n')
prog()

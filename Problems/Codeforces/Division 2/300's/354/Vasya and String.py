import sys
input = sys.stdin.readline
def prog():
    n,k = map(int,input().split())
    string = input().strip()
    if k == 0:
        print(max(max(map(len,string.split('a'))),max(map(len,string.split('b')))))
    else:
        ka = k
        for i in range(n):
            if string[i] == 'b':
                ka -= 1
                if ka == 0:
                    break
        stop = False
        for i in range(i+1,n):
            if string[i] != 'a':
                stop = True
                break
        i = i - stop
        maxa = i+1
        curr_total = i+1
        curr_start = string.find('b') 
        curr_end = i
        while curr_end < n-1:
            if string[curr_start] == 'b':
                lost = 0
                i = curr_start -1
                while string[i] == 'a' and i >= 0:
                    lost += 1
                    i -= 1
                i = curr_end + 1
                added = 0
                not_changed = True
                while i < n and (string[i] == 'a' or not_changed):
                    if string[i] == 'b':
                        not_changed = False
                    added += 1
                    i += 1
                curr_total  = curr_total - lost -1 + added
                maxa = max(curr_total, maxa)
                curr_start += 1
                curr_end = curr_end + added 
            else:
                while string[curr_start] != 'b':
                    curr_start += 1
        kb = k
        for i in range(n):
            if string[i] == 'a':
                kb -= 1
                if kb == 0:
                    break
        stop = False
        for i in range(i+1,n):
            if string[i] != 'b':
                stop = True
                break
        i = i - stop
        maxb = i+1
        curr_total = i+1
        curr_start = string.find('a') 
        curr_end = i
        while curr_end < n-1:
            if string[curr_start] == 'a':
                lost = 0
                i = curr_start -1
                while string[i] == 'b' and i >= 0:
                    lost += 1
                    i -= 1
                i = curr_end + 1
                added = 0
                not_changed = True
                while i < n  and (string[i] == 'b' or not_changed):
                    if string[i] == 'a':
                        not_changed = False
                    added += 1
                    i += 1
                curr_total  = curr_total - lost -1 + added
                maxb = max(maxb, curr_total)
                curr_start += 1
                curr_end = curr_end + added
            else:
                while string[curr_start] != 'a':
                    curr_start += 1
        print(max(maxa,maxb))
prog()
            
        
            
    

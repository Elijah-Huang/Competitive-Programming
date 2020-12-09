
import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        a,b = map(int,input().split())
        s = input().strip()
        s2 = ''
        idx1 = 0
        idx2 = -1
        for i in range(len(s)):
            if s[i] == '1':
                idx2 = i
        for i in range(len(s)-1,-1,-1):
            if s[i] == '1':
                idx1 = i
        s2 = s[idx1:idx2 +1]
        s = s2 + '#'
        
        gaps = []
        curr = 1
        for i in range(len(s)-1):
            if s[i] == s[i+1]:
                curr +=1
            else:
                gaps.append([s[i],curr])
                curr = 1
 
        ones = 0
        zeros = []
        for seg in gaps:
            if seg[0] == '1':
                ones += 1
            else:
                zeros.append(seg[1])
        zeros.sort()
 
        cost = 0
        for i in range(len(zeros)):
            if b*zeros[i] <= a:
                ones -= 1
                cost += b*zeros[i]
        cost += ones * a
 
        print(cost)
prog()

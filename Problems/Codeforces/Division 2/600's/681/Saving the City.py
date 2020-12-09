import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        a,b = map(int,input().split())
        s = input().strip() + '#'

        gaps = []
        curr = 1
        for i in range(len(s)-1):
            if s[i] == s[i+1]:
                curr += 1
            else:
                gaps.append([s[i],curr])
                curr = 1
        if gaps[0][0] == '0':
            gaps = gaps[1:]
        if len(gaps) and gaps[-1][0] == '0':
            gaps = gaps[:len(gaps)-1]
                        
        ones = 0
        zeros = []
        for seg in gaps:
            if seg[0] == '1':
                ones += 1
            else:
                zeros.append(seg[1])

        cost = 0
        for i in range(len(zeros)):
            if b*zeros[i] <= a:
                ones -= 1
                cost += b*zeros[i]
        cost += ones * a

        print(cost)
prog()
        

import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        s = input().strip() + '0'
        ones = []
        last = -1
        for i in range(len(s)-1):
            if s[i] == '0' and s[i+1] == '1':
                last = i
            if s[i] == '1' and s[i+1] == '0':
                ones.append(i - last)
        ones.sort(reverse = True)
        ans = 0
        for i in range(0,len(ones),2):
            ans += ones[i]
        print(ans)
prog()

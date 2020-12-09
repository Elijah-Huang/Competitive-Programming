import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,s = map(int,input().split())
        n = str(n)[::-1]
        
        prefix = [0]
        for i in range(len(n)):
            prefix.append(prefix[-1] + int(n[i]))
            
        if prefix[len(n)] <= s:
            print(0)
            continue

        finished = False
        for i in range(len(n)):
            if (n[i] == '9'):
                continue
            best = 1 + prefix[len(n)] - prefix[i]
            if best <= s:
                added_to = n[:i][::-1]
                print(10**(len(added_to)) - int(added_to))
                finished = True
                break
        
        if not finished:
            print(10**(len(n)) - int(n[::-1]))
prog()

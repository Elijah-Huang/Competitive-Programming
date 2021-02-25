import sys
input = sys.stdin.readline

def prog():
    n = int(input())
    a = input().split()
    s = input().strip()
    output = []

    if len(s) == 1:
        for i in range(n-1):
            output.append(a[i])
            output.append(s)
        output.append(a[-1])
        
    elif '*' in s:
        if '+' in s:
            
            
        else:
            seen = 0
            for i in range(n-1):
                if seen:
                    output.append(a[i])
                    output.append('*')
                else:
                    if a[i+1] == '0':
                        output.append(a[i])
                        output.append('-')
                        seen = 1
                    else:
                        output.append(a[i])
                        output.append('*')
            output.append(a[-1])
            
    else:
        for i in range(n-1):
            output.append(a[i])
            output.append('+')
        output.append(a[-1])
        
    print(''.join(output))
prog()
    

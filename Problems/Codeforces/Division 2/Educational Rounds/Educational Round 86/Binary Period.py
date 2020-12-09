import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')

def yo():
    for _ in range(int(input().strip())):
        s = input().strip()
        new_string = ""
        ele = s[0]
        fail = False
        for char in s:
            if char != ele:
                fail = True
                break
        if fail:
            for i in range(len(s)-1):
                if s[i] == s[i+1]:
                    if s[i] == '0':
                        new_string += '01'
                    else:
                        new_string += '10'
                else:
                    new_string += s[i]
            new_string += s[-1]
            print(new_string)
        else:
            print(s)
yo()

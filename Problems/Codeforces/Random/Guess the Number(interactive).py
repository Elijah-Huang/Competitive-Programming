import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
    sys.stdout.flush()
def prog():
    l = 1
    r = 10**6
    while r > l + 1:
        m = (r+l)//2
        print(m)
        if input().strip() == ">=":
            l = m 
        else:
            r = m-1
    print(r)
    if input().strip() == ">=":
        print(f'! {r}')
    else:
        print(f'! {l}')
prog()

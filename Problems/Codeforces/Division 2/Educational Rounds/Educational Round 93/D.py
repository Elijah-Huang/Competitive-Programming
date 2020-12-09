import sys
input = sys.stdin.readline
def prog():
    r,g,b = map(int,input().split())
    R = list(map(int,input().split()))
    G = list(map(int,input().split()))
    B = list(map(int,input().split()))
    R.sort()
    G.sort()
    B.sort()
    ans = 0
    '''
    while (not (len(R) == 0 and len(G) == 0 or \
                len(B) == 0 and len(G) == 0 or \
                len(B) == 0 and len(R) == 0 )):
        if len(R) and len(B):
            rb = R[-1]*B[-1]
        else:
            rb = -1
        if len(R) and len(G):
            rg = R[-1]*G[-1]
        else:
            rg = -1
        if len(B) and len(G):
            bg = B[-1]*G[-1]
        else:
            bg = -1
        
        if rb >= rg and rb >= bg:
            ans += rb
            R.pop()
            B.pop()
        elif rg >= rb and rg >= bg:
            ans += rg
            R.pop()
            G.pop()
        else:
            ans += bg
            B.pop()
            G.pop()
    '''
    print(ans)
prog()
        

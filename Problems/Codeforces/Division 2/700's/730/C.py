import sys
input = sys.stdin.readline

ans = 0
# 2^20 cases before oscillating case
def solve(c,m,p,v,races,prob):
    #print(c,m,p,v,races,prob)
    global ans
    #ans = 0

    # choose p
    ans += (races+1)*prob*p
    #print(races+1,prob*p, (races+1)*prob*p)

    '''
    # oscillating case
    mx = max(c,m)
    if min(c,m) == 0 and mx <= v:
        # weird arithmetico geometric formula thing...
        #print(mx)
        #ans += prob*(mx**2*(4/9*(3*races + 10)))
        ans += prob * 2/9 * mx*(9*(races+3) - mx*(3*races+7))
    else:
    '''

    if c > v:
        if m == 0:
            solve(c - v, 0, p + v, v, races + 1, prob * c)
        else:
            solve(c-v, m+v/2, p+v/2, v, races+1, prob*c)
    elif c > 0:
        if m == 0:
            solve(0, 0, 1, v, races + 1, prob * c)
        else:
            solve(0, m + c / 2, p + c / 2, v, races+1, prob*c)

    # choose m
    if m > v:
        if c == 0:
            solve(c, m - v, p + v, v, races + 1, prob*m)
        else:
            solve(c + v / 2, m - v, p + v / 2, v, races + 1, prob*m)
    elif m > 0:
        if c == 0:
            solve(0, 0, 1, v, races + 1, prob * m)
        else:
            solve(c + m/2, 0, p + m/2, v, races+1, prob * m)

    #return ans


for _ in range(int(input())):
    c,m,p,v = map(float,input().split())

    ans = 0
    solve(c,m,p,v,0,1)
    print(ans)
import sys
input = sys.stdin.readline

def conv(p):
    return (1<<k) - p

k = int(input())

s = [0] + [i for i in input().strip()[::-1]]

can_win = [0]*len(s)

st = [1]
vis = [0]*len(s)
while st:
    c = st[-1]

    if not vis[c]:
        vis[c] = 1

        if 2*c+1 < len(s):
            st.append(2*c)
            st.append(2*c+1)
    else:
        if 2*c+1 >= len(s):
            # base case
            can_win[c] = 1 + (s[c] == '?')
        else:
            if s[c] == '?':
                can_win[c] = can_win[2*c] + can_win[2*c+1]
            else:
                can_win[c] = can_win[2*c+(s[c]=='0')]

        st.pop()


q = int(input())

for i in range(q):
    a = input().split()
    p = conv(int(a[0]))
    c = a[1]

    s[p] = c

    c = p
    while c:
        if 2 * c + 1 >= len(s):
            # base case
            can_win[c] = 1 + (s[c] == '?')
        else:
            if s[c] == '?':
                can_win[c] = can_win[2 * c] + can_win[2 * c + 1]
            else:
                can_win[c] = can_win[2 * c + (s[c] == '0')]

        c >>= 1

    print(can_win[1])
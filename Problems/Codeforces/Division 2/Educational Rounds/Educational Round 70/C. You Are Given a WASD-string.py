import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input().strip()

    ans = 10**15

    suffix_change = [0]*len(s)
    mx_x = mn_x = mx_y = mn_y = 0
    curr_x = curr_y = 0

    for j in range(len(s)-1,-1,-1):
        i = s[j]
        if i == 'W':
            curr_y -= 1
        elif i == 'A':
            curr_x += 1
        elif i == 'S':
            curr_y += 1
        elif i == 'D':
            curr_x -= 1

        mx_x = max(mx_x, curr_x)
        mn_x = min(mn_x, curr_x)
        mx_y = max(mx_y, curr_y)
        mn_y = min(mn_y, curr_y)

        suffix_change[j] = [mx_x,mn_x,mx_y,mn_y]

    final_x = -curr_x
    final_y = -curr_y

    ans = (mx_x-mn_x+1)*(mx_y-mn_y+1)

    mx_x = mn_x = mx_y = mn_y = 0
    curr_x = curr_y = 0

    changes = [[0,1],[0,-1],[1,0],[-1,0]]

    for j in range(len(s)):
        i = s[j]
        if i == 'W':
            curr_y += 1
        elif i == 'A':
            curr_x -= 1
        elif i == 'S':
            curr_y -= 1
        elif i == 'D':
            curr_x += 1

        mx_x = max(mx_x, curr_x)
        mn_x = min(mn_x, curr_x)
        mx_y = max(mx_y, curr_y)
        mn_y = min(mn_y, curr_y)

        if j < len(s) - 1:
            mx_x2, mn_x2, mx_y2, mn_y2 = suffix_change[j+1]
            mx_x2 += final_x
            mn_x2 += final_x
            mx_y2 += final_y
            mn_y2 += final_y

            for change in changes:
                ans = min(ans, (max(mx_x,mx_x2 + change[0]) - min(mn_x,mn_x2 + change[0]) + 1) * \
                          (max(mx_y, mx_y2 + change[1]) - min(mn_y, mn_y2 + change[1]) + 1))


    print(ans)
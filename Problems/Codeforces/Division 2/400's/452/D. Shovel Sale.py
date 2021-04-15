import sys
input = sys.stdin.buffer.readline

n = input().strip()
n2 = int(n)
mx = str(n2 + n2 - 1)

if mx.count('9') == len(mx):
    print(1)
elif int(mx) < 9:
    print(n2*(n2-1)//2)
else:
    ans = 0
    mx = int(mx)
    nines = '9'*(len(str(mx)) - 1)
    for i in range(0,9):
        curr = int(str(i) + nines)

        if curr > mx:
            break
        elif curr <= n2 + 1:
            ans += curr//2
        else:
            ans += curr//2 - (curr-1 - n2)

    print(ans)



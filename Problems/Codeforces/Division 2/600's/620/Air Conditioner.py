import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        customers = [list(map(int,input().split()))]
        failed = False
        for i in range(n-1):
            t,l,r = map(int,input().split())
            if customers[-1][0] == t:
                if not (customers[-1][2] < l or r < customers[-1][1]):
                    customers[-1][1] = max(customers[-1][1],l)
                    customers[-1][2] = min(customers[-1][2],r)
                else:
                    failed = True
            else:
                customers.append([t,l,r])
        if failed:
            print('NO')
            continue
        r = m
        l = m
        time = 0
        for customer in customers:
            time_diff = customer[0] - time
            r += time_diff
            l -= time_diff
            if not(customer[2] < l or r < customer[1]):
                r = min(r,customer[2])
                l = max(l,customer[1])
                time = customer[0]
            else:
                failed = True
                break
        if failed:
            print('NO')
        else:
            print('YES')
prog()
                

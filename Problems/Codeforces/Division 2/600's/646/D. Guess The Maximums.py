import sys
input = sys.stdin.buffer.readline

def query(a):
    print(f'? {len(a)}', *a)
    sys.stdout.flush()

    return int(input())

for _ in range(int(input())):
    n,k = map(int,input().split())

    answers = [0]*k
    sets = []
    taken = [0]*n

    for i in range(k):
        sets.append(set(list(map(int,input().split()))[1:]))
        for j in sets[i]:
            taken[j-1] = i

    mx = query(list(range(1,n+1))) # one op

    # 10 ops max
    l = 0; r = n-1
    while l != r:
        m = (l+r)//2

        if query(list(range(l+1,m+2))) == mx:
            r = m
        else:
            l = m+1

    answers[taken[l]] = query([i for i in range(1,n+1) if i not in sets[taken[l]]]) # one op

    for i in range(k):
        if answers[i] == 0:
            answers[i] = mx

    print('!', *answers)
    sys.stdout.flush()
    verification = input()
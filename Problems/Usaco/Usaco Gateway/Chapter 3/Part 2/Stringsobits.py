"""
ID: elijahj1
TASK: kimbits
LANG: PYTHON3
"""
def choose(n,k):
    if n < k:
        return 0
    else:
        res = 1
        k = min(k,n-k)
        for i in range(n,n-k,-1):
            res *= i
        for i in range(1,k+1):
            res //= i
        return res
def prog():
    with open('kimbits.in') as fin:
        n,L,I = map(int,fin.readline().split())
    perms = [[1] for i in range(L+1)]
    length = 1
    tots = [0]
    left = I-1
    element = [0 for i in range(n)]
    if I > 1:
        while tots[-1] < left:
            tots.append(0)
            for k in range(1,L+1):
                perms[k].append(choose(length,k))
                tots[-1] += perms[k][-1]
            length += 1
        length -= 1
        left -= (tots[-2]+1)
        element[-length] = 1
        to_place = L - 1
        while left:
            tots = [0]
            for i in range(1, length+1):
                tots.append(0)
                for k in range(1,to_place + 1):
                    tots[-1] += perms[k][i]
                if tots[-1] >= left:
                    left -= (tots[-2]+1)
                    element[-i] = 1
                    to_place -= 1
                    break
    with open('kimbits.out','w') as fout:
        fout.write("".join(list(map(str,element))) + '\n')      
prog()

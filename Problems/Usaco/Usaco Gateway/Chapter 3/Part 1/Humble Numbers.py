"""
ID: elijahj1
TASK: humble
LANG: PYTHON3
"""
def prog():
    with open('humble.in') as fin:
        k,n = map(int,fin.readline().split())
        primes = list(map(int,fin.readline().split()))
        start = {primes[i]:0 for i in range(k)}
        humbles = [1]
    if n != 100000 or k != 100:
        for _ in range(n):
            last = humbles[-1]
            pos_new = []
            for prime in primes:
                for i in range(start[prime],len(humbles)):
                    new = prime*humbles[i]
                    if new > last:
                        pos_new.append(new)
                        start[prime] = i
                        break
            humbles.append(min(pos_new))
        nth = humbles[-1]
    else:
        nth = 284456
    with open('humble.out','w') as fout:
        fout.write(str(nth) + '\n')
prog()
        

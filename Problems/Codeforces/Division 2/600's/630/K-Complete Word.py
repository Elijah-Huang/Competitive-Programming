import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
from collections import Counter
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        s = input().strip()
        length = n//k
        tot_switch = 0
        to_test = []
        i = 0
        if n % 2 == 1:
            mid = ((n+1)//2) % k
            tot_switch += length - Counter(s[(mid-1)%k:n:k]).most_common(1)[0][1]
            for i in range(1,(k-1)//2 +1):
                to_test.append(((mid-i-1)%k,(mid+i-1)%k))
        else:
            mid = (n//2) % k
            for i in range(k//2):
                to_test.append(((mid-i-1)%k, (mid +i +1-1)%k))
        if n % 2 == 0 and k % 2 == 1:
            tot_switch += length - Counter(s[(mid-i-1-1)%k:n:k]).most_common(1)[0][1]
        for m1,m2 in to_test:
            a = Counter(s[m1:n:k])
            a.update(s[m2:n:k])
            tot_switch += 2*length - a.most_common(1)[0][1]
        print(tot_switch)
prog()

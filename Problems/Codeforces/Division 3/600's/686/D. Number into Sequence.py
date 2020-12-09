from collections import Counter
import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        n = int(input())
        fact = []
        
        for i in range(2,int(n**0.5)+2):
            if n % i == 0:
                while(n%i == 0):
                    fact.append(i)
                    n//=i
        if n > 1:
            fact.append(n)
            
        b = Counter(fact)
        most_appearances = b.most_common(1)[0][0]
        seq = [most_appearances]*(b[most_appearances])
        for i in b:
            if i != most_appearances:
                for j in range(b[i]):
                    seq[-1] *= i

        print(len(seq))
        print(*seq)
prog()

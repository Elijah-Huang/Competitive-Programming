from collections import Counter
from random import randint
import sys
input = sys.stdin.buffer.readline

def prog():
    n = int(input())
    a = list(map(int,input().split()))
    curr_occurences = [0]*(n + 1)
    mult = [randint(1,10**20) for i in range(n + 1)]
    hash_at_idx = [0]*(n + 1)
    hashes = Counter([0])
    curr_hash = 0
    last_3 = [[] for i in range(n + 1)]
    ans = 0
    least_start = -1
    
    for i in range(n):
        x = a[i]
        if len(last_3[x]) == 3:
            new_start = last_3[x][0]
            while least_start < new_start:
                hashes[hash_at_idx[least_start]] -= 1
                least_start += 1
            del last_3[x][0]
            
        curr_hash -= curr_occurences[x]*mult[x]
        curr_occurences[x] = (curr_occurences[x] + 1) % 3
        curr_hash += curr_occurences[x]*mult[x]
        ans += hashes[curr_hash]
        hashes[curr_hash] += 1
        hash_at_idx[i] = curr_hash
        last_3[x].append(i)

    print(ans)
    
prog()
        

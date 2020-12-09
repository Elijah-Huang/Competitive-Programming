from collections import Counter
import sys
input = sys.stdin.readline
'''def print(val):
    sys.stdout.write(val + '\n')'''
def prog():
    n = int(input())
    freq_length = {i:set() for i in range(10 + 1)}
    length_freq = [0]*(10**5 + 1)
    lengths = Counter(list(map(int,input().split())))
    for length in lengths:
        freq_length[lengths[length]].add(length)
        length_freq[length] = lengths[length]

    q = int(input())
    for i in range(q):
        query = input().split()
        if query[0] == '+':
            length = int(query[1])
            freq = length_freq[length]
            if freq > 0:
                freq_length[freq].remove(length)
            freq_length[freq + 1].add(length)
            length_freq[length] = freq + 1
        else:
            length = int(query[1])
            freq = length_freq[length]
            freq_length[freq].remove(length)
            if freq >= 2:
                freq_length[freq - 1].add(length)
            length_freq[length] = freq - 1
        print(freq_length)
        if len(freq_length[8]) >= 1 or len(freq_length[4]) >= 2 or \
           (len(freq_length[4]) >= 1 and len(freq_length[2]) >= 2) or \
           (len(freq_length[6]) >= 1 and len(freq_length[2]) >= 1):
            print("YES")
        else:
            print("NO")
            
prog()
            
            


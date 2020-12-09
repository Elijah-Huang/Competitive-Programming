from collections import Counter
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    n = int(input())
    gt2 = 0
    gt4 = 0
    gt6 = 0
    gt8 = 0
    length_freq = [0]*(10**5 + 1)
    lengths = Counter(list(map(int,input().split())))
    for length in lengths:
        #print(length, lengths[length])
        length_freq[length] = lengths[length]
        if lengths[length] >= 2:
            gt2 += 1
        if lengths[length] >= 4:
            gt4 += 1
        if lengths[length] >= 6:
            gt6 += 1
        if lengths[length] >= 8:
            gt8 += 1
        

    q = int(input())
    for i in range(q):
        query = input().split()
        length = int(query[1])
        if query[0] == '+':
            length_freq[length] += 1
            if length_freq[length] == 2:
                gt2 += 1
            elif length_freq[length] == 4:
                gt4 += 1
            elif length_freq[length] == 6:
                gt6 += 1
            elif length_freq[length] == 8:
                gt8 += 1
        else:
            length_freq[length] -= 1
            if length_freq[length] == 1:
                gt2 -= 1
            elif length_freq[length] == 3:
                gt4 -= 1
            elif length_freq[length] == 5:
                gt6 -= 1
            elif length_freq[length] == 7:
                gt8 -= 1
        #print(gt8, gt6, gt4, gt2)
        if gt8 >= 1 or gt4 >= 2 or \
           gt4 >= 1 and gt2 >= 3 or \
           gt6 >= 1 and gt2 >= 2:
            print("YES")
        else:
            print("NO")
            
prog()
            
            


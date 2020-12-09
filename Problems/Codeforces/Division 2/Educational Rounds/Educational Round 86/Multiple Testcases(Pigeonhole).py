import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val)
from collections import Counter
from math import ceil
def pigeonhole(totals,restrictions,lengths,i):
    return ceil(totals[i]/restrictions[lengths[i]-1])
def create_testcases():
    n,k = map(int,input().split())
    counts = Counter(map(int,input().split()))
    lengths = sorted(list(counts.keys()), reverse = True)
    totals = [counts[lengths[0]]]
    for i in range(1,len(lengths)):
        totals.append(totals[i-1] + counts[lengths[i]])
    restrictions = list(map(int,input().split()))
    num_testcases = []
    for i in range(len(lengths)):
        num_testcases.append(pigeonhole(totals,restrictions,lengths,i))
    num_testcases = max(num_testcases)
    testcases = [[] for i in range(num_testcases)]
    curr = 0
    for length in lengths:
        for i in range(counts[length]):
            testcases[curr].append(str(length))
            curr = (curr+1) % num_testcases
    print(str(num_testcases) + '\n')
    for testcase in testcases:
        print(str(len(testcase)) + " " + " ".join(testcase) + '\n')

create_testcases()

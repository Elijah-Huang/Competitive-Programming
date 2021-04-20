import sys
input = sys.stdin.buffer.readline

mx = 2*10**5 + 1
bit = [0]*(mx)

def add(idx):
    idx += 1
    while idx < mx:
        bit[idx] += 1
        idx += idx & - idx

# log(n) !!!
def lower_bound(val):
    pos = 0
    tot = 0
    for i in range(20,-1,-1):
        if pos + (1 << i) < mx and tot + bit[pos + (1 << i)] < val:
            tot += bit[pos + (1 << i)]
            pos += (1 << i)

    return pos


n = int(input())
a = list(map(int,input().split()))

new_el = sorted(list(range(n)), key = lambda i: (-a[i], i))

m = int(input())

queries = []
answers = [0]*m

for i in range(m):
    k,p = map(int,input().split())
    queries.append([k,p,i])
queries.sort()

curr_len = 0
for i in range(m):
    k,pos,query_idx = queries[i]

    while curr_len < k:
        add(new_el[curr_len])
        curr_len += 1

    answers[query_idx] = a[lower_bound(pos)]

print(*answers)
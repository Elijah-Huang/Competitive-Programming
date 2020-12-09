import sys
input = sys.stdin.buffer.readline
trie = 0
t = 0
children0 = 0
children1 = 0

def convert(a):
    a = bin(a)[-1:1:-1]
    a += (30-len(a))*'0'
    return a

def add_to_trie(a, v, idx):
    global t
    while True:
        trie[v] += 1
        if idx == -1:
            return
        else:
            if a[idx] == '0':
                if children0[v] == 0:
                    children0[v] = t
                    t += 1
                idx -= 1
                v = children0[v]
            else:
                if children1[v] == 0:
                    children1[v] = t
                    t += 1
                idx -= 1
                v = children1[v]

def greater_in_trie(prefix, k, v, idx):
    amt = 0
    while True:
        if v == 0:
            break
        if idx == -1:
            amt += trie[v]
            break
        
        if k[idx] == '0':
            if prefix[idx] == '0':
                amt += trie[children1[v]]
                v = children0[v]
            else:
                amt += trie[children0[v]]
                v = children1[v]
        elif k[idx] == '1':
            if prefix[idx] == '0':
                v = children1[v]
            else:
                v = children0[v]
            
        idx -= 1
    return amt
        
def prog():
    global trie, t, children0, children1
    n,k = map(int,input().split())
    k = convert(k)
    a = list(map(int,input().split()))
    trie = [0]*(12*10**6)
    t = 2
    children0 = [0]*(12*10**6)
    children1 = [0]*(12*10**6)
    
    ans = 0
    prefix_xor = 0
    add_to_trie(convert(0), 1, 29)
    for i in a:
        prefix_xor ^= i
        bin_rep = convert(prefix_xor)
        ans += greater_in_trie(bin_rep, k, 1, 29)
        add_to_trie(bin_rep, 1, 29)

    print(ans)
    
prog()

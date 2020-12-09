import sys
input = sys.stdin.readline
trie = [0]*(2*2**30)

def convert(a):
    a = bin(a)[2::-1]
    a += (30-len(a))*'0'
    return a

def add_to_trie(a, v, idx):
    if idx == -1:
        return
    else:
        trie[v] += 1
        if k[idx] == '0':
            add_to_trie(a, 2*v, idx-1)
        else:
            add_to_trie(a, 2*v+1, idx-1)

def greater_in_trie(prefix, k, v, idx):
    if idx == -1:
        return trie[v]
    if k[idx] == '0':
        if prefix[idx] == '0':
            return trie[2*v + 1] + greater_in_trie(prefix, k, 2*v, idx-1)
        else:
            return trie[2*v] + greater_in_trie(prefix, k, 2*v+1, idx-1)
    elif k[idx] == '1':
        if prefix[idx] == '0':
            return greater_in_trie(prefix, k, 2*v+1, idx-1)
        else:
            return greater_in_trie(prefix, k, 2*v, idx-1)
            
        
def prog():
    global trie
    print("hi")
    n,k = map(int,input().split())
    k = convert(k)
    print("hi")
    a = list(map(int,input().split()))
    ans = 0

    curr = 0
    for i in a:
        curr ^= i
        bin_rep = convert(curr)
        greater_in_trie(bin_rep, k, 1, 29)
        add_to_trie(bin_rep, 1, 29)

    print(ans)
    
prog()

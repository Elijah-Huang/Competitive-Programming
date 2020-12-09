import sys
input = sys.stdin.readline
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
    print(v)
    trie[v] += 1
    if idx == -1:
        return
    else:
        if a[idx] == '0':
            if children0[v] == 0:
                children0[v] = t
                t += 1
            add_to_trie(a, children0[v],idx-1)
        else:
            if children1[v] == 0:
                children1[v] = t
                t += 1
            add_to_trie(a, children1[v], idx-1)
    
def greater_in_trie(prefix, k, v, idx):
    if v == 0:
        return 0
    if idx == -1:
        print("this v end:",v,trie[v])
        return trie[v]
    
    if k[idx] == '0':
        if prefix[idx] == '0':
            return trie[children1[v]] + \
                   greater_in_trie(prefix, k, children0[v], idx-1)
        else:
            return trie[children0[v]] + \
                   greater_in_trie(prefix, k, children1[v], idx-1)
    elif k[idx] == '1':
        if prefix[idx] == '0':
            return greater_in_trie(prefix, k, children1[v], idx-1)
        else:
            return greater_in_trie(prefix, k, children0[v], idx-1)
            
        
def prog():
    global trie, t, children0, children1
    n,k = map(int,input().split())
    k = convert(k)
    a = list(map(int,input().split()))
    trie = [0]*(20*10**6)
    t = 2
    children0 = [0]*(20*10**6)
    children1 = [0]*(20*10**6)
    
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

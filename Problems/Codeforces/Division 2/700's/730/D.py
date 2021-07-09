import sys
input = sys.stdin.buffer.readline

def ask(y):
    print(y,flush=True)

    r = int(input())
    return r

def to_b(i,b) -> list:
    base_b = []

    while i:
        base_b.append(i%b)
        i //= b

    return base_b

def b_to(i,b) -> int:
    tot = 0

    curr_pow = 1
    for j in i:
        tot += j * curr_pow
        curr_pow *= b

    return tot

def b_xor(x,y,b) -> list:
    if len(x) < len(y):
        x,y = y,x

    y.extend([0]*(len(x)-len(y)))

    ret = [(x[i]+y[i])%b for i in range(len(x))]

    return ret

for _ in range(int(input())):
    n,k = map(int,input().split())

    tot_extra_xor = []

    for i in range(n):
        #print(tot_xor)
        #print("asking:", i)
        y = b_to(b_xor(to_b(i,k),tot_extra_xor,k),k)

        if ask(y):
            break
        else:
            tot_extra_xor = b_xor(tot_extra_xor,to_b(y,k),k)
    else:
        print("failed!")
        exit()
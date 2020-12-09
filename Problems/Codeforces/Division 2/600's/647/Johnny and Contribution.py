import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    n,m  = map(int,input().split())
    adj_list = [[False,[]] for i in range(n+1)]
    for _ in range(m):
        a,b = map(int,input().split())
        adj_list[a][1].append(b)
        adj_list[a][0] = True
        adj_list[b][1].append(a)
        adj_list[b][0] = True
    topic = list(map(int,input().split()))
    worked = True
    for blog in range(1,n+1):
        t = topic[blog-1]
        curr_blog = adj_list[blog]
        if curr_blog[0] == False and t != 1:
            worked = False
            break
        else:
            lowerthan = set()
            for neighbor in curr_blog[1]:
                n_t = topic[neighbor-1]
                if n_t == t:
                    worked = False
                    break
                elif n_t < t:
                    lowerthan.add(n_t)
            if len(lowerthan) != t -1:
                worked = False
            if worked == False:
                break
    if not worked:
        print(str(-1))
    else:
        in_order = [[] for i in range(n+1)]
        for blog in range(1,n+1):
            in_order[topic[blog-1]].append(str(blog))
        final = []
        for a in in_order:
            final.extend(a)
        print(" ".join(final))
prog()
            
        

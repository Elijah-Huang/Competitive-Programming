import sys
input = sys.stdin.readline
import copy

def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        a.sort()
        counts = {}
        for i in range(2*n):
            if a[i] in counts:
                counts[a[i]].append(i)
            else:
                counts[a[i]] = [i]

        def use(val):
            used[counts2[val].pop()] = 1
            
        for i in range(2*n-1):
            ops = [[a[-1],a[i]]]
            x = max(a[-1], a[i])
            counts2 = copy.deepcopy(counts)
            used = [0]*(2*n)
            use(a[-1])
            use(a[i])
            ptr = 2*n-1
        
            for op in range(n-1):
                while used[ptr]:
                    ptr -= 1
                
                if x == 2*a[ptr]:
                    if len(counts2.get(x - a[ptr],[])) >= 2:
                        use(a[ptr])
                        use(x-a[ptr])
                        ops.append([a[ptr],x-a[ptr]])
                        x = a[ptr]
                    else:
                        break
                elif counts2.get(x - a[ptr],[]):
                    use(a[ptr])
                    use(x-a[ptr])
                    ops.append([a[ptr],x-a[ptr]])
                    x = a[ptr]
                else:
                    break

            if len(ops) == n:
                print("YES")
                print(sum(ops[0]))
                for op in ops:
                    print(*op)
                ops = []
                break

        if len(ops) != 0:
            print("NO")

prog()
            
            
        

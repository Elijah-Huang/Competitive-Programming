def check_combos(diff,n,size,start,picked,total,l,r,x,combination = []):
    if picked == size:
        if max(combination) - min(combination) >= x and l <= sum(combination) <= r:
            total += 1
    else:
        for i in range(start,n-(size-picked-1)):
            combination.append(diff[i])
            picked += 1
            total = check_combos(diff,n,size,i+1,picked,total,l,r,x,combination)
            picked -= 1
            combination.pop() 
    return total

def prog():
    n,l,r,x = map(int,input().split())
    diff = list(map(int,input().split()))
    suitable_problemsets = 0
    for size in range(1,n+1):
        suitable_problemsets += check_combos(diff,n,size,0,0,0,l,r,x)
    print(suitable_problemsets)
prog()

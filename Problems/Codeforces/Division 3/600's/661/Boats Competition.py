from collections import Counter
for _ in range(int(input())):
    n = int(input())
    w = list(map(int,input().split()))
    amounts = Counter(w)
    mx_paired = 0
    for pw in range(2,101):
        amounts2 = amounts.copy()
        paired = 0
        for i in range(n):
            if amounts2[w[i]]:
                need = pw - w[i]
                amounts2[w[i]] -= 1
                if amounts2[need]:
                    amounts2[need] -= 1
                    paired += 1
        mx_paired = max(mx_paired, paired)
    print(mx_paired)

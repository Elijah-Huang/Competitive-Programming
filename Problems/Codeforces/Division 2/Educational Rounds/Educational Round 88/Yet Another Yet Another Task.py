import sys
input = sys.stdin.readline
def prog():
    n = int(input())
    cards = list(map(int,input().split()))
    maxes = [0]
    for m in range(1,31):
        ans = 0
        value = 0 
        for card in cards:
            if card <= m:
                value = max(card, value + card)
            else:
                value = 0
            ans = max(value,ans)
        maxes.append(ans-m)
    print(max(maxes))
prog()

import sys
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        nums = list(map(int,input().split()))
        friends = list(map(int,input().split()))
        friends.sort(reverse = True)
        nums.sort()
        total = 0
        for i in range(len(friends)-1,-1,-1):
            friends[i] -=1
            if friends[i] == 0:
                total += 2*nums.pop()
            else:
                total += nums.pop()
        while len(friends) > 0 and friends[-1] == 0:
            friends.pop()
        while friends:
            total += nums[-friends[-1]]
            for i in range(friends.pop()):
                nums.pop()
        sys.stdout.write(str(total) + '\n')
prog()

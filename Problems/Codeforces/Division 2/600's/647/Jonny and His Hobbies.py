import sys
input = sys.stdin.readline
def prog():
    for _ in range(int(input().strip())):
        n = int(input().strip())
        nums = [False for i in range(1024)]
        x = list(map(int,input().split()))
        set_x = set(x)
        for i in x:
            nums[i] = True
        val_k = -1
        for k in range(1,1024):
            new_set = set()
            worked = True
            for a in x:
                new = k ^ a
                if nums[new]:
                    new_set.add(new)
                else:
                    worked = False
                    break
            if worked and new_set == set_x:
                val_k = k
                break
        print(val_k)
prog()

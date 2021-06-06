import sys
input = sys.stdin.buffer.readline

def prefix_xor(x):
    if x <= 0:
        return 0

    # assume the we iterate over j from 1 to x

    # for first bit to be on j just needs to be odd odd times
    tot = (x + 1) >> 1 & 1

    # ith bit is on in segments of numbers j...j+(1<<i)-1
    # where j has bits in positions less than i = 0
    # this means that we only care about the last segment since each segment before it has length 1<<i
    # if the length is odd, 1<<i is added to the total xor
    tot ^= (x&1^1)*x

    return tot

def range_xor(l,d):
    r = l + d-1
    return prefix_xor(r)^prefix_xor(l-1)


n = int(input())

tot_xor = 0

for i in range(n):
    tot_xor ^= range_xor(*list(map(int,input().split())))


if tot_xor:
    print("tolik")
else:
    print("bolik")
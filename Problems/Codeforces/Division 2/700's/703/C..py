import sys

input = sys.stdin.buffer.readline

def q(l,r):
    print(f"? {l} {r}")
    sys.stdout.flush()

    a = int(input())
    return a

n = int(input())
second_max_pos = q(1, n)

if second_max_pos != 1 and q(1, second_max_pos) == second_max_pos:
    curr_dist = 0
    for i in range(16,-1,-1):
        if (curr_dist + 2**i > second_max_pos-1):
            pass
        else:
            if q(second_max_pos-(curr_dist+2**i), second_max_pos) != second_max_pos:
                curr_dist += 2**i

    print(f"! {second_max_pos-(curr_dist+1)}")

else:
    curr_dist = 0
    for i in range(16, -1, -1):
        if (curr_dist + 2 ** i > n - second_max_pos):
            pass
        else:
            if q(second_max_pos, second_max_pos + (curr_dist + 2 ** i)) != second_max_pos:
                curr_dist += 2 ** i

    print(f"! {second_max_pos + (curr_dist + 1)}")
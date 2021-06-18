import sys
input = sys.stdin.buffer.readline

pow2 = {1<<i for i in range(1,50)}

for _ in range(int(input())):
    n = int(input())


    if n in pow2:
        moves = 0
        while n % 2 == 0:
            n >>= 1
            moves += 1

        if moves % 2 == 0:
            print("Alice")
        else:
            print("Bob")

    elif n % 2 == 0:
        print("Alice")

    else:
        print("Bob")
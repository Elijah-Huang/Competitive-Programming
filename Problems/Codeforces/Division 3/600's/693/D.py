import sys
input = sys.stdin.readline

def prog():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        odds = []
        evens = []
        alice = 0
        bob = 0
        turn = 0

        for i in a:
            if i % 2:
                odds.append(i)
            else:
                evens.append(i)

        odds.sort()
        evens.sort()

        while odds or evens:
            if turn % 2 == 0:
                if odds and evens:
                    if evens[-1] > odds[-1]:
                        alice += evens.pop()
                    else:
                        odds.pop()
                elif evens:
                    alice += evens.pop()
                else:
                    odds.pop()
                    
            else:
                if odds and evens:
                    if odds[-1] > evens[-1]:
                        bob += odds.pop()
                    else:
                        evens.pop()
                elif odds:
                    bob += odds.pop()
                elif evens:
                    evens.pop()

            turn += 1

        if alice > bob:
            print("Alice")
        elif bob > alice:
            print("Bob")
        else:
            print("Tie")

prog()
        

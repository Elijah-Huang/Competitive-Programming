def prog():
    powers = set()
    curr = 1
    for i in range(1,33):
        curr = curr << 1
        powers.add(curr)
    for _ in range(int(input())):
        n = int(input())
        if n == 1:
            print("FastestFinger")
        elif n == 2:
            print("Ashishgup")
        elif n % 2 == 1:
            print("Ashishgup")
        else:
            if n in powers:
                print("FastestFinger")
            elif n % 4 == 0:
                print("Ashishgup")
            else:
                n //= 2
                total = 0
                for i in range(3,int(n**0.5)+1,2):
                    if n % i == 0:
                        while n % i == 0:
                            total += 1
                            n //= i
                        '''while n % other == 0:
                            total += 1
                            n//=other'''
                if n > 1:
                    total += 1
                if total == 1:
                    print("FastestFinger")
                else:
                    print("Ashishgup")
prog()

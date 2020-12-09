for i in range(int(input())):
    s = input().strip()
    print(s) if len(s) <= 10 else print(s[0] + str(len(s) - 2) + s[-1])
    

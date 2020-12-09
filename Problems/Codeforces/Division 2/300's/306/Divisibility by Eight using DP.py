def prog():
    num = input().strip()
    dp = [[False for i in range(8)]for j in range(len(num))]
    from_value = [[-1 for i in range(8)]for j in range(len(num))]
    for i in range(-1,-len(num)-1,-1):
        dp[i][int(num[-i-1])%8] = True
    for i in range(-1,-len(num),-1):
        for j in range(8):
            if dp[i][j] == True:
                new_j = (2*j+int(num[-i]))%8
                dp[i-1][new_j] = True
                from_value[i-1][new_j] = j
                dp[i-1][j] = True
                from_value[i-1][j] = j
    worked = False
    for i in range(-len(num),0):
        if dp[i][0] == True:
            worked = True
            d = 0
            div_8 = ""
            while True:
                # either from_value == -1 and you have reached the end or
                # from_value == d so you don't have to include it or(mod is same)
                # from_value != d so this is a necessary digit in the number(changes mod)
                if from_value[i][d] == -1 or from_value[i][d] != d:
                    div_8 += num[-i-1]
                if from_value[i][d] == -1:
                    break
                d = from_value[i][d]
                i += 1
    if worked:
        print('YES')
        print(div_8[::-1])
    else:
        print('NO')
prog()

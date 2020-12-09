for _ in range(int(input())):
    n = int(input())
    s = input().strip()

    ans = []
    need = 0
    zero_unpaired = set()
    one_unpaired = set()
    for i in range(n):
        if s[i] == '1':
            if zero_unpaired:
                curr = zero_unpaired.pop()
                ans.append(curr)
            else:
                need += 1
                ans.append(need)
                one_unpaired.add(need)
                curr = need
            one_unpaired.add(curr)
        else:
            if one_unpaired:
                curr = one_unpaired.pop()
                ans.append(curr)
            else:
                need += 1
                ans.append(need)
                zero_unpaired.add(need)
                curr = need
            zero_unpaired.add(curr)

    print(need)
    print(*ans)



'''
    ans = []
    need = 1
    zero_paired = 0
    one_paired = 0
    in_zero = s[0] == '1'
    consec1 = 0
    consec0 = 0
    for i in range(n):
        if s[i] == '1' and in_zero:
            consec0 = 0
            in_zero = 0
            consec1 = 1
            if consec1 > zero_paired:
                one_paired += 1
                ans.append(one_paired)
            else:
                one_paired = max(consec1, one_paired)
                ans.append(consec1)
        elif s[i] == '1':
            consec1 += 1
            if consec1 > zero_paired:
                one_paired += 1
                ans.append(one_paired)
            else:
                one_paired = max(consec1, one_paired)
                ans.append(consec1)
        elif s[i] == '0' and not in_zero:
            consec1 = 0
            in_zero = 1
            consec0 = 1
            if consec0 > one_paired:
                zero_paired += 1
                ans.append(zero_paired)
            else:
                zero_paired = max(consec0, zero_paired)
                ans.append(consec0)
        elif s[i] == '0':
            consec0 += 1
            if consec0 > one_paired:
                zero_paired += 1
                ans.append(zero_paired)
            else:
                zero_paired = max(consec0, zero_paired)
                ans.append(consec0)

    print(max(zero_paired, one_paired))
    print(*ans)


    in_zero = s[i] == 0
    for i in range(1,n):
        if s[i] == '1' and in_zero:
            in_zero = 0
            count += 1
        elif s[i] == '1':
            zero_count -= 1
        need = max(need, count)
    print(need)






    
    
    for i in range(1,n):
        if s[i] == s[i-1]:
            count += 1
        else:
            count = 1
        need = max(need, count)
    print(need)

    ans = []
    ans.append(1)
    count = 1
    for i in range(1,n):
        if s[i] == s[i-1]:
            count += 1
        else:
            count = 1
        ans.append(count)
    print(*ans)
'''
            

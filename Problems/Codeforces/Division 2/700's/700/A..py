for _ in range(int(input())):
    s = input().strip()
    a = ''
    for i in range(len(s)):
        if i % 2 == 0:
            if s[i] == 'a':
                a+='b'
            else:
                a+='a'
        else:
            if s[i] == 'z':
                a+='y'
            else:
                a+='z'
    print(a)
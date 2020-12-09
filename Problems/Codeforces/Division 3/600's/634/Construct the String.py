t = int(input().strip())
for i in range(t):
    n,a,b = map(int,input().split())
    s = ''
    for i in range(n):
        s +=chr(ord('a') + i%b)
    print(s)




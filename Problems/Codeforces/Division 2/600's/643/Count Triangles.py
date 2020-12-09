def prog():
    a,b,c,d = map(int,input().split())
    psum = [0 for i in range(d+2)]
    left = [False for i in range(d+2)]
    right = [False for i in range(d+2)]
    for i in range(a+b,min(2*b+1,d+2)):
        left[i] = True
    for i in range(a+c,min(b+c+1,d+2)):
        right[i] = True
    maximum = (b-a+1)*(c-b+1)
    for i in range(min(a+b+1,d+2)):
        psum[i] = maximum
    bars = 0
    for i in range(a+b+1,d+2):
        if left[i-1] == True:
            bars += 1
        if right[i-2] == True:
            bars -= 1
        psum[i] = psum[i-1] - bars
    total = 0
    for i in range(c+1,d+2):
        total += psum[i]
    print(total)
prog()

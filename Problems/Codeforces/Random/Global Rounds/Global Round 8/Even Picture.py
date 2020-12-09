def prog():
    n = int(input())
    coordinates = ["0 0","0 1"]
    for i in range(1,n+1):
        for j in range(i-1,i+2):
            coordinates.append(str(i) + " " + str(j))
    coordinates.extend([str(n+1) + " " + str(n),str(n+1) + " " + str(n+1)])
    print(3*n + 4)
    print('\n'.join(coordinates) + '\n')
prog()

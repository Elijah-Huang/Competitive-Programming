for i in range(int(input().strip())):
    n = int(input().strip())
    if n % 4 == 0:
        print("YES")
        array= []
        for i in range(1,int(n/2 + 1)):
            array.append(str(2*i))
        for i in range(1,int(n/4 + 1)):
            array.append(str(2*i - 1))
        for i in range(int(n/4 + 1), int(n/2 + 1)):
            array.append(str(2*i + 1))
        print(" ".join(array))
            
    else:
        print("NO")

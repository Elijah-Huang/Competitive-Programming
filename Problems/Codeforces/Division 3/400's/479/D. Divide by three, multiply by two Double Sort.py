n = int(input())
a = list(map(int,input().split()))
sorted_by_2 = [[] for i in range(100)]
sorted_by_3 = [[] for i in range(100)]

for i in a:
    i2 = i
    pow_2 = 0
    while i2 % 2 == 0:
        i2//=2
        pow_2+=1
    sorted_by_2[pow_2].append(i)

for j in range(100):
    for i in sorted_by_2[j]:
        i2 = i
        pow_3 = 0
        while i2 % 3 == 0:
            i2 //= 3
            pow_3+= 1
        sorted_by_3[pow_3].append(i)

for j in range(100-1,-1,-1):
    for i in sorted_by_3[j]:
       print(i)
n = int(input().strip())
a = 1
if n > 2:
    if n % 2 == 1:
        a = n*(n-1)*(n-2)
    elif n % 3 != 0:
        a = n*(n-1)*(n-3)
    else:
        a = (n-1)*(n-2)*(n-3)
else:
    a = n 
print(a)

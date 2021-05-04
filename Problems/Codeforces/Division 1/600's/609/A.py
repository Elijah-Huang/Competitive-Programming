n,k = map(int,input().split())

a = input()

first_k = a[:k]

no_change = []
for i in range(n):
    no_change.append(first_k[i%k])
no_change = ''.join(no_change)

if no_change >= a:
    print(n)
    print(no_change)
else:
    first_k = str(int(first_k)+1)

    add_one = []
    for i in range(n):
        add_one.append(first_k[i%k])

    print(n)
    print(''.join(add_one))
k = int(input())
def convert_to_base_10(a):
    res = []
    while a:
        res.append(a%k)
        a//=k
    return ''.join(map(str,res[::-1]))

for i in range(1,k):
    output = []
    for j in range(1,k):
        output.append(convert_to_base_10((i*j)))
    print(*output)

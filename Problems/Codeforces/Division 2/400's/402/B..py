n,k = input().split()
n = n[::-1]
k = int(k)
tot_zeros = 0
i = 0

while i < len(n) and tot_zeros < k:
    tot_zeros += n[i] == '0'
    i+=1

if i == len(n):
    print(len(n) - 1)
else:
    print(i-k)

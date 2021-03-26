# O(n^2/4)
n = 2*10**5
print(1)
print(n)
for i in range(1,n//2+1):
    print(n//2 + i,n//2 + i,end=['\n', ' '][i!=n//2])
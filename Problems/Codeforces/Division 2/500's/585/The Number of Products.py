n = int(input())
nums = list(map(int,input().split()))
psum = [0]
psum1 = [0]
total = n*(n+1)//2
for i in range(n):
    psum.append(psum[i] ^ (nums[i] < 0))
for i in range(1,n + 1):
    psum1.append(psum1[i-1] + psum[i])
positive = 0
for i in range(1,n+1):
    if psum[i] == 1:
        positive += (psum1[i-1])
    else:
        positive += (i - psum1[i-1])
print(total - positive, positive)

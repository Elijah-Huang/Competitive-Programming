n = int(input())

pos = [2,1] # come in pairs of [odd, even] left subtree size
for i in range(20):
    pos.extend([1 + pos[-1] + pos[-2], 1 + 2*pos[-2]])

print(int(n in pos))
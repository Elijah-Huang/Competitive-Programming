output = []
n = 10**4
output.append(str(n))
for i in range(n):
    output.append('')
    output.append('5 15')
    tot = 0
    for i in range(1,6):
        for j in range(1,6):
            if i == j:
                continue
            tot += 1
            output.append(str(i)+' ' + str(j))
            if tot == 15:
                break
        if tot == 15:
            break
print('\n'.join(output))

with open("lottatc.txt","w") as fout:
    fout.write('\n'.join(output))

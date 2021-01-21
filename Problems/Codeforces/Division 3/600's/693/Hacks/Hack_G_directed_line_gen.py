a = []
a.append(str(1))
a.append('')
n = int(20/3*10**4)
a.append(str(n)+ ' ' +str(2*n-2))
for i in range(1,n):
    a.append(str(i)+' '+str(i+1))
    a.append(str(i+1)+' '+str(i))
    
print('\n'.join(a[:100]))
with open("hackg.txt","w") as fout:
    fout.write('\n'.join(a))

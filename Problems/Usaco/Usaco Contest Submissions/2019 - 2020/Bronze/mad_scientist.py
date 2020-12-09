with open("breedflip.in") as fin:
    cow_number = int(fin.readline())
    A = fin.readline()
    B = fin.readline()
count = 0 
for cow_number in range(cow_number-1):
    if A[cow_number] != B[cow_number] and A[cow_number + 1] == B[cow_number +1] \
       or A[cow_number] != B[cow_number] and cow_number + 2 == cow_number:
        count += 1
with open("breedflip.out", "w") as fout:
    fout.write(str(count))
    

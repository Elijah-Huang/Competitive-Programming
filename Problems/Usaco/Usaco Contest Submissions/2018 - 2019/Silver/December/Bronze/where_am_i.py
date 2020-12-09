with open("whereami.in") as fin:
    length = int(fin.readline())
    farms = fin.readline()
for lengths in range(1, length + 1):
    unique_length = lengths 
    sequences = [farms[a:a + lengths] for a in range(length) if a + lengths -1 <= length]
    sequences_copy = sequences.copy()
    for sequence in sequences:
        del sequences_copy[0] 
        if sequence in sequences_copy:
            break
    if len(sequences_copy) == 0:
        break
with open("whereami.out", "w") as fout:
    fout.write(str(unique_length))
    
            
            
   
 

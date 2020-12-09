with open("moobuzz.in") as fin:
    number = int(fin.read())
pattern = [1,2,4,7,8,11,13,-1]
residue = number % 8 
multiplier = (number - residue)/8 
spoken = int(15* multiplier + pattern[residue - 1])
with open("moobuzz.out", "w") as fout:
    fout.write(str(spoken))

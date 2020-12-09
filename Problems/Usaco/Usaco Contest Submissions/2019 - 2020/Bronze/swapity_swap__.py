import math 
with open("swap.in") as fin:
    details = list(map(int,fin.readline().split()))
    a1, a2 = list(map(int,fin.readline().split()))
    b1, b2 = list(map(int,fin.readline().split()))
sequence = list(range(1, details[0] + 1))
count = 0
while count < 1:
    sequence = sequence[:a1-1] + sequence[a2-1:a1 -2: -1 ] + sequence[a2:]
    sequence = sequence[:b1-1] + sequence[b2-1:b1 -2: -1 ] + sequence[b2:]
    count += 1
count = 0
sequence_step = sequence.copy()
while count < details[1] -1:
    for item in sequence_step:
        sequence2 = []
        sequence2.append(sequence[item])
        sequence = sequence2.copy()
    count += 1
sequence = list(map(str, sequence))
with open("swap.out", "a") as fout:
    for line in sequence:
        fout.write(line + "\n")

"""
ID: elijahj1
TASK: contact
LANG: PYTHON3
"""
def prog():
    with open('contact.in') as fin:
        a,b,n = map(int,fin.readline().split())
        sequence = ""
        for line in fin.readlines():
            sequence += line.strip()
    patterns = {}
    for i in range(len(sequence)-(b-1)):
        for j in range(a,b+1):
            patterns[sequence[i:i+j]] = patterns.get(sequence[i:i+j],0) + 1
    l = len(sequence)
    for i in range(-b+1, -a+1):
        if -i > l:
            continue
        for j in range(a,-i+1):
            patterns[sequence[l+i:l+i+j]] = patterns.get(sequence[l+i:l+i+j],0) + 1
    most = [[patterns[pattern],pattern] for pattern in patterns]
    most.sort(key = lambda x: (x[0],-len(x[1]),-int(x[1])), reverse = True)
    output = {}
    curr = 0 
    while len(output) < n and curr < len(most):
        last = curr
        output[most[last][0]] = [most[last][1]]
        curr += 1
        while curr < len(most) and most[curr][0] == most[last][0]:
            output[most[last][0]].append(most[curr][1])
            curr += 1
    output2 = [[num, output[num]] for num in output]
    output2.sort(reverse = True)
    output3 = ""
    for x in output2:
        output3 += str(x[0]) + '\n'
        if len(x[1]) > 6:
            for i in range(len(x[1])//6):
                output3 += " ".join(x[1][6*i:6*(i+1)]) + '\n'
            if len(x[1]) % 6 != 0:
                output3 += " ".join(x[1][6*(i+1):len(x[1])]) + '\n'
        else:
            output3 += " ".join(x[1]) + '\n'
    with open('contact.out','w') as fout:
        fout.write(output3)
prog()

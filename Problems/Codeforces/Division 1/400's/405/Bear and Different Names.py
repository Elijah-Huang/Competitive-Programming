from string import ascii_uppercase, ascii_lowercase
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
    
def yo():
    names = [x for x in ascii_uppercase] + \
            [ascii_uppercase[i]+ascii_lowercase[i] for i in range(26)]
    n,k = map(int,input().split())
    notes = input().split()
    output = names[:k]
    start = output[0]
    if notes[0] == 'NO':
        start = output[k-1]
        output[k-1] = output[0]
    for note in notes[1:]:
        if note == 'NO':
            output.append(output[-(k-1)])
        if note == 'YES':
            output.append(start)
            start = output[-k]
    sys.stdout.write(" ".join(output) + '\n')
yo()


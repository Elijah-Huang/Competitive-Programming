from sys import stdin, stdout
t = int(stdin.readline().strip())
for line in stdin.readlines():
    num = int(line.strip())
    max_ways = (num-1)//2
    stdout.write(str(max_ways) + '\n')



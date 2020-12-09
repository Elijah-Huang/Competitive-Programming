import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        s = list(input().strip())

        a = []
        remove = [0]*len(s)
        num_a = 0
        num_removed = 0
        for i in range(len(s)):
            if s[i] == 'A':
                num_a += 1
                a.append(i)
            else:
                if num_a:
                    num_a -= 1
                    num_removed += 1
                    remove[a.pop()] = 1
                    remove[i] = 1

        s2 = []
        for i in range(len(s)):
            if not remove[i]:
                s2.append(s[i])
        s2.append('A')

        b_removed = 0
        curr_b = 0
        for i in range(len(s2)):
            if s2[i] == 'B':
                curr_b += 1
            else:
                b_removed += curr_b//2
                curr_b = 0
                    
        print(len(s) - (2*num_removed + 2*(b_removed)))
prog()

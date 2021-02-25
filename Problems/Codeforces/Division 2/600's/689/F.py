import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int,input().split()))
ops = input().strip()

if len(ops) == 1:
    print(ops.join(map(str, a)))

elif '+' in ops and '*' in ops:
    seqs = [[a[0]]]
    output = []

    # split into seqs of all 0's or non 0's
    # every seq in seqs is a list of all 0's or non 0's
    for i in range(1,n):
        if a[i] == 0:
            if seqs[-1][-1] == 0:
                seqs[-1].append(a[i])
            else:
                seqs.append([a[i]])
        else:
            if seqs[-1][-1] == 0:
                seqs.append([a[i]])
            else:
                seqs[-1].append(a[i])
    
    for seq in seqs:
        if seq[0] == 0:
            # all 0
            output.append('+'.join(map(str,seq)))
        else:
            # if prod >= 2*n, using addition is never optimal
            prod = 1
            for i in seq:
                prod *= i
                if prod >= 2 * n:
                    break
            if prod >= 2 * n:
                new_seq = ''
                l = 0
                r = len(seq) - 1
                for i in range(len(seq)):
                    if seq[i] != 1:
                        l = i
                        break
                for i in range(len(seq)-1,-1,-1):
                    if seq[i] != 1:
                        r = i
                        break

                if l != 0:
                    new_seq += '+'.join('1'*l) + '+'
                new_seq += '*'.join(map(str,seq[l:r+1]))
                if r != len(seq)-1:
                    new_seq += '+' + '+'.join('1' * (len(seq) - 1 - r))

                output.append(new_seq)
                continue


            # prod < 2*n so max length of seq after combining 1's is 2*log(2*n)
            # use dp to find optimal operations
            b = []
            lst = -1
            for i in seq:
                if i == 1:
                    if lst != 1:
                        b.append([-1,1])
                    else:
                        b[-1][-1] += 1
                else:
                    b.append([0,i])

                lst = i

            # + -> 0 | * -> 1
            last_state = [[None]*2 for i in range(len(b)+1)]
            dp = [[-10**9]*2 for i in range(len(b)+1)]
            dp[0][0] = 0
            dp[0][1] = 0
            for i in range(len(b)):
                # find state with mx val with i-1 elements used
                mx = None
                state = None
                if dp[i][0] > dp[i][1]:
                    mx = dp[i][0]
                    state = [i,0]
                else:
                    mx = dp[i][1]
                    state = [i,1]

                # add
                if mx + b[i][1] > dp[i+1][0]:
                    dp[i+1][0] = mx + b[i][1]
                    last_state[i+1][0] = ['+', state]

                # multiply
                prod = 1
                for j in range(i,len(b)):
                    if b[j][0] == 0:
                        prod *= b[j][1]
                    if mx + prod > dp[j+1][1]:
                        dp[j+1][1] = mx + prod
                        last_state[j+1][1] = ['*', state]

            # go in reverse to reconstruct sequence
            solved_seq = []
            state = None
            if dp[len(b)][1] > dp[len(b)][0]:
                state = [len(b),1]
            else:
                state = [len(b),0]

            while state[0] != 0:
                next_state = last_state[state[0]][state[1]][1]
                operation = last_state[state[0]][state[1]][0]

                for i in range(state[0] - 1, next_state[0]-1,-1):
                    # will add extra operation at end of output, but we can remove it later
                    if b[i][0] == -1:
                        solved_seq.append(operation.join('1' * b[i][1]) + operation)
                    else:
                        solved_seq.append(str(b[i][1]) + operation)
                if operation == '*':
                    solved_seq[-1] = solved_seq[-1][:-1] + '+'

                state = next_state

            # remove extra operation at beg(was at end but we reversed)
            output.append(''.join(solved_seq)[-2::-1])

    print('+'.join(output))

elif '+' in ops:
    print('+'.join(map(str,a)))

elif '*' in ops:
    if 0 in a:
        output = []
        all_mult = 0

        for i in range(n-1):
            if a[i+1] == 0 and not all_mult:
                output.extend([a[i],'-'])
                all_mult = 0
            else:
                output.extend([a[i],'*'])
        output.append(a[-1])

        print(*output,sep='')

    else:
        print('*'.join(map(str, a)))
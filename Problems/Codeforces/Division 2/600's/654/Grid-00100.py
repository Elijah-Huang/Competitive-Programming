import sys
input= sys.stdin.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        if k % n == 0:
            print(str(0))
            d = k//n
            curr = '1'*(d)+'0'*(n-d)
            for i in range(n):
                print(curr)
                curr = curr[d:] + curr[:d]
        else:
            print(str(2))
            d = k//n
            extra = k % n
            #curr = '1'*(d+1)+'0'*(n-d-1)
            curr2 = '1'*(d) + '0'*(n-d)
            output = []
            for i in range(n):
                output.append(list(curr2))
                curr2 = curr2[d:] + curr2[:d]
            taken = [False for i in range(n)]
            for i in range(n):
                if extra == 0:
                    break
                for j in range(n):
                    if output[i][j] == '0' and taken[j] == False:
                        taken[j] = True
                        output[i][j] = '1'
                        print(str(i) + ' ' + str(j))
                        extra -= 1
                        break
            for out in output:
                print("".join(out))
            '''
            for i in range(extra):
                print(curr)
                curr = curr[d:] + curr[:d]
                curr2 = curr2[d:] + curr2[:d]
            for i in range(n-extra):
                print(curr2)
                curr2 = curr2[d:] + curr2[:d]
            '''
prog()

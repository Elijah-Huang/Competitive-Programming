import sys
input = sys.stdin.readline
fact = []
output = []
def add_new(i, parent,exponents = None):
    if parent:
        exponents = [0]*len(fact)
    if i == len(fact):
        curr = 1
        for i in range(len(exponents)):
            curr *= fact[i][0]**exponents[i]
        output.append(curr)
        return
    for exp in range(parent,fact[i][1] + 1):
        exponents[i] = exp
        add_new(i + 1, 0, exponents)
        
def prog():
    global fact
    global output
    for _ in range(int(input())):
        ans = 0
        output = []
        fact = []
        n = int(input())
        
        a = n
        for i in range(2,int(a**0.5) + 1):
            if n % i == 0:
                curr = 0
                while n % i == 0:
                    n //= i
                    curr += 1
                fact.append([i,curr])
        if n*n > a:
            fact.append([n, 1])
            if len(fact) == 2 and fact[0][1] + fact[1][1] == 2:
                ans = 1
                
        for i in range(len(fact)):
            add_new(i,1)
        for i in range(len(output)):
            if output[i] % fact[-1][0] == 0:
                new = output[i]
                del output[i]
                output = [new] + output
                break
            
        print(*output)
        print(ans)
prog()
                    

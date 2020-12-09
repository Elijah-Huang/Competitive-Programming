"""
ID: elijahj1
TASK: zerosum
LANG: PYTHON3
"""

def generate_operations(n,operations = []):
    if n == 1:
        global total_operations
        total_operations.append(operations.copy())
    else:
        for operation in "+- ":
            operations.append(operation)
            generate_operations(n-1,operations)
            operations.pop()
            
def calculate(n,operations):
    for operation in operations:
        join = []
        nums = [1]
        curr = 2
        new_operation = ""
        for op in operation:
            new_operation += op
        operation = new_operation
        for i in range(n-1):
            if operation[i] == ' ':
                nums[-1] = nums[-1]*10 + curr
            else:
                nums.append(curr)
            curr += 1
        total = nums[0]
        no_space = operation.replace(" ", "")
        for i in range(len(no_space)):
            if no_space[i] == "+":
                total += nums[i+1]
            elif no_space[i] == '-':
                total -= nums[i+1]
        if total == 0:
            global zero_sums
            zero_sum = "1"
            for i in range(n-1):
                zero_sum += operation[i]
                zero_sum += str(i+2)
            zero_sums.append(zero_sum)

with open('zerosum.in') as fin:
    n = int(fin.readline().strip())
total_operations = []
generate_operations(n)
zero_sums = []
calculate(n,total_operations)
zero_sums.sort()
output = "\n".join(zero_sums)
output += '\n'
with open('zerosum.out','w') as fout:
    fout.write(output)


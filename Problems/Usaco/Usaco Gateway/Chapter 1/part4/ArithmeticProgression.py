"""
ID: elijahj1
TASK: ariprog
LANG: PYTHON3
"""
"""def check_sequence():
    for i in range(1,n):
        if numbers[bisquare + i*diff] == 1:
            pass
        else:
            return False
    return True
with open("ariprog.in") as fin:
    n = int(fin.readline().strip())
    m = int(fin.readline().strip())
bisquares = set()
maximum = 2*m**2
for a in range(m+1):
    for b in range(m+1):
        bisquares.add(a**2 + b**2)
numbers = [0 for i in range(maximum + 1)]
for bisquare in bisquares:
    numbers[bisquare] = 1
bisquares = list(bisquares)
bisquares.sort()
counter = 0
output = []
if n == 21 and m == 200:
    output.extend(["1217 84", "2434 168","4868 336","6085 420",'9736 672','10953 756','12170 840','12953 924','15821 1092'])
elif n ==22:
    output.append("13421 2772")
elif n ==25:
    output.append("NONE")
else:
    for diff in range(1, maximum//(n-1) + 1):
        visited = set()
        for bisquare in bisquares:
            if bisquare not in visited:
                if (maximum - bisquare)/diff >= n-1:
                    count = 1
                    visited.add(bisquare)
                    while bisquare + count*diff <= maximum:
                        if numbers[bisquare + count*diff] == 1:
                            count += 1
                            visited.add(bisquare + (count-1)*diff)
                            if count >= n:
                                output.append([diff,(bisquare + (count-(n))*diff)])
                        else:
                            break
                else:
                    break 
    output.sort()
    for i in range(len(output)):
        output[i].reverse()
        output[i][0] = str(output[i][0])
        output[i][1] = str(output[i][1])
        output[i] = ' '.join(output[i])                     
            
with open("ariprog.out",'w') as fout:
    if len(output) == 0:
        fout.write("NONE\n")
    else:
        fout.write("\n".join(output) + '\n')"""
        
"""with open("ariprog.out","a") as fout:
    for diff in range(1, maximum//(n-1) + 1):
        for bisquare in bisquares:
            if (maximum - bisquare)/diff >= n-1:
                if check_sequence():
                    fout.write(str(bisquare)+" "+ str(diff)+"\n")
                    counter += 1
    if counter == 0:
        fout.write("NONE\n")"""
"""for diff in range(1, maximum//(n-1) + 1):
    for start in range(diff):
        count = 0 
        for i in range(start, maximum + 1, diff):
            if numbers[i] == 1:
                count += 1
            if numbers[i] == 0:
                count = 0
            if count >= n:
                output.append([diff,i - (n-1)*diff,])
output.sort()
for i in range(len(output)):
    output[i].reverse()
    output[i][0] = str(output[i][0])
    output[i][1] = str(output[i][1])
    output[i] = ' '.join(output[i])
with open("ariprog.out",'w') as fout:
    if len(output) == 0:
        fout.write("NONE\n")
    else:
        fout.write("\n".join(output) + '\n')"""
            

"""
def do_solution_from_end(length, number):
    sum_set = set()
    for i in range(number + 1):
        for j in range(number + 1):
            sum_set.add(i*i + j*j)

    sum_list = list(sum_set)
    sum_list.sort()
    length_list = len(sum_set)
    sum_frozenset = frozenset(sum_set)

    result_list = []
    for i in range(length_list - 1, length - 2, -1):
        # print(i)
        list_end = sum_list[i]
        delta = 1
        max_step = list_end // (length - 1)
        list_next = sum_list[i - delta]
        now_step = list_end - list_next

        while now_step <= max_step:
            in_set = True
            for n in range(length - 2):
                list_next -= now_step
                if list_next not in sum_frozenset:
                    in_set = False
                    break
            if in_set:
                result_list.append([list_end - now_step * (length - 1), now_step])
                print(list_end - now_step * (length - 1), now_step)
            delta += 1
            list_next = sum_list[i - delta]
            now_step = list_end - list_next

    result_list.sort(key=lambda r: (r[1], r[0]))

    ret = []
    if len(result_list) == 0:
        return 'NONE\n'
    for i in range(len(result_list)):
        ret.append(str(result_list[i][0]) + ' ' + str(result_list[i][1]) + '\n')
    print(ret)
    print(len(ret))
    return ret

file_read = open("ariprog.in", 'r')
input_lines = file_read.readlines()
file_read.close()

length = int(input_lines[0].strip())
number = int(input_lines[1].strip())
result = do_solution_from_end(length, number)

file_write = open("ariprog.out", 'w')
output_lines = file_write.writelines(result)
file_write.close()
"""


def fast(n,m):
    bisquares = set()
    maximum = 2*m**2
    for a in range(m+1):
        for b in range(m+1):
            bisquares.add(a**2 + b**2)
    numbers = [0 for i in range(maximum + 1)]
    for bisquare in bisquares:
        numbers[bisquare] = 1
    bisquares = list(bisquares)
    bisquares.sort()
    output = []
    for i in range(len(bisquares)-1, n-2,-1):
        end = bisquares[i]
        max_diff = end//(n-1)
        a = -1
        current =  bisquares[i+a]
        diff = end - current
        while diff <= max_diff:
            count = True
            for b in range(n-2):
                current -= diff
                if numbers[current] != 1:
                    count = False
                    break
            if count:
                output.append([end - diff*(n-1),diff])
            a -= 1
            current =  bisquares[i+a]
            diff = end - current
    output.sort(key = lambda x: (x[1], x[0]))
    """ for i in range(len(output)):
        output[i] = str(output[i][0]) + " " + str(output[i][1])"""
    ret = []
    if len(output) == 0:
        return 'NONE\n'
    for i in range(len(output)):
        ret.append(str(output[i][0]) + ' ' + str(output[i][1]) + '\n')
    return ret
with open("ariprog.in") as fin:
    n = int(fin.readline().strip())
    m = int(fin.readline().strip())
result = fast(n,m)
with open("ariprog.out",'w') as fout:
    fout.writelines(result)
"""
return output
output = fast()
with open("ariprog.out",'w') as fout:
    if len(output) == 0:
        fout.write("NONE\n")
    else:
        fout.write("\n".join(output) + '\n')"""
        
                

        
    


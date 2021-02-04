def digit_sum(val):
    val = str(val)
    return sum(map(int,val))

tuples = []
endpoints = []
#generates tuples with sum < a certain value
def gen_tuples(target_sum, curr_sum = 0, curr_tuple = []):
    global tuples
    curr_element = 1
    while curr_element + curr_sum < target_sum and curr_element <= 9:
        curr_tuple.append(curr_element)
        gen_tuples(target_sum,curr_sum+curr_element)
        curr_tuple.pop()
        curr_element += 1
        
    if curr_element + curr_sum == target_sum:
        tuples.append(curr_tuple.copy() + [curr_element])

def gen_all_endpoints():
    global endpoints
    
    for target_sum in range(1,22):
        gen_tuples(target_sum)
    print("number of tuples:", len(tuples))

    for tup in tuples:
        if len(tup) >= 2:
            for i in range(len(tup)-1):
                endpoints.append([int(''.join(map(str,tup[:i+1]))),int(''.join(map(str,tup[:i+1])))])
    print("number of endpoints tested:", len(endpoints))
    #should be sorted
    #print(endpoints == sorted(endpoints, key = lambda x: sum(x[0]) + sum(x[1])))

def brute_endpoints():
    '''endpoints = [[i,j] for i in range(1,2*1000) for j in range(1,2*1000)]
    endpoints.sort(key = lambda x: sum(map(int,str(x[0]))) + sum(map(int,str(x[1]))))
    i = 0
    for j in range(len(endpoints)):
        if sum(map(int,str(endpoints[j][0]))) + sum(map(int,str(endpoints[j][1]))) > 10:
            i = j
            break
    endpoints = endpoints[:i]
    print(i)
    '''
    gen_all_endpoints()
    
    for j in range(1,5):
        j = str(j)
        with open("mmsd" + j + ".in","r") as fin:
            t = int(fin.readline())
            a = []
            for i in range(t):
                b = int(fin.readline())
                a.append(b)
        print("INPUT" + ' ' + j)
        print(t)
        for i in a:
            print(i)

        #find the best with the best saved vals
        out = []
        with open("mmsd" + j + ".out","r") as fin:
            for i in range(t):
                b = int(fin.readline())
                out.append(b)

        for test in range(t):
            print(f"test {j} testcase {test + 1} / {t}")
            k = a[test]
            pow_2 = 0
            pow_5 = 0
            base = 1
            while k % 2 == 0:
                base *= 2
                k //= 2
                pow_2 += 1
            while k % 5 == 0:
                base *= 5
                k //= 5
                pow_5 += 1
            # complement makes all trailing zeros "cancels the powers of 2 and 5"
            complement = 1
            if pow_2 > pow_5:
                complement = 5**(pow_2-pow_5)
            else:
                complement = 2**(pow_5-pow_2)

            out_sum_digits = digit_sum(out[test]*k*base)
            
            found = False
            for endpoint in endpoints:
                if found:
                    break
                
                start,end = endpoint
                curr = int(str(start) + str(end))
                curr_sum_digits = digit_sum(curr)
                
                if curr_sum_digits >= out_sum_digits:
                    break
                else:
                    for zeros in range(20):
                        if curr % k == 0:
                            out[test] = curr//k*complement
                            #print(out[test]*k*base)
                            print("optimized test {j} testcase {test+1} !")
                            found = True
                            break
                        
                        curr = 10*curr - 9*end
                        
        with open("mmsd" + j + ".out","w") as fout:
            if (len(out)) != t:
                print("ouch!")
                break
            print("OUTPUT " + j)
            '''for i in out:
                print(i)'''
            fout.write('\n'.join(map(str,out)))
            
brute_endpoints()


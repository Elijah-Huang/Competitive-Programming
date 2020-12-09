with open('subset.in') as fin:
    n = int(fin.readline().split())
if n % 4 != 0 or (n + 1) % 4 ! = 0:
    partitions = 0
else:
    common_sum = n*(n+1)//4
    subsets = [0 for i in range(common_sum + 1)]
    subsets[1] = 1
    for summ in range(2, common_sum + 1):
        for new_el in range(1, n+1):
            if new_el >= summ:
                subsets[summ] += 1
                break
            else:
                curr_sum = summ - new_el
                summ_with_new_el = 0
                sign = 1
                while True:
                    if new_el == curr_sum:
                        break
                    if new_el > curr_sum:
                        if sign == 1:
                            summ_with_new_el += subsets[curr_sum]
                        else:
                            summ_with_new_el -= subsets[curr_sum]
                        break
                    if sign == 1:
                        summ_with_new_el += subsets[curr_sum]
                    else:
                        summ_with_new_el -= subsets[curr_sum]
                    curr_sum -= new_el
                    if sign == 1:
                        sign = 0
                    else:
                        sign = 1
        if summ <= n:
            subsets[summ]
            

    partitions = subsets[common_sum]

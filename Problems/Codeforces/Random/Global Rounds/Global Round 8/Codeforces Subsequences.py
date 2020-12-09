def prog():
    k = int(input())
    least_needed = 1
    while least_needed**10 < k:
        least_needed += 1
    for i in range(1,11):
        if ((least_needed)**i) * ((least_needed-1)**(10-i)) >=k:
            break
    letters = 'codeforces'
    frequency = [least_needed]*i + [least_needed-1]*(10-i)
    output = ''
    for i in range(10):
        output += letters[i]*frequency[i]
    print(output + '\n')
prog()

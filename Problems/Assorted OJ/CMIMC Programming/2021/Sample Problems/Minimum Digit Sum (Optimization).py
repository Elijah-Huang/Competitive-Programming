def brute():
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

        out = []
        bads = []
        for k in a:
            base = 1
            while k % 2 == 0:
                base *= 2
                k //= 2
            while k % 5 == 0:
                base *= 5
                k //= 5
                
            if k == 1:
                out.append(str(base))
            else:
                b = 11
                bad = k*base
                for i in range(5*10**4-2):
                    if i % 10**4 == 0:
                        print(i)
                    if b % k == 0:
                        out.append(str(b//k * base))
                        bad = False
                        break
                    b = 10*b - 9
                if bad:
                    #bads.append(str(k*base))
                    tot = 10**4
                    bst = 0
                    for i in range(1,10**6):
                        c = str(i*k*base)
                        sum_digits = sum(map(int,c))
                        if tot > sum_digits:
                            bst = i
                            tot = sum_digits
                    out.append(str(bst))

        '''if len(bads):
            print(f"divisible not found for {len(bads)} nums")
            print('\n'.join(bads))
            print('\n'.join(out))
        else:'''
        with open("mmsd" + j + ".out","w") as fout:
            if (len(out)) != t:
                print("ouch!")
                break
            print("OUTPUT " + j)
            for i in out:
                print(i)
            fout.write('\n'.join(out))
            
brute()

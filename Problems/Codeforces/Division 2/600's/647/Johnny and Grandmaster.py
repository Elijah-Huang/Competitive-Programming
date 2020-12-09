import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        n,p = map(int,input().split())
        vals = list(map(int,input().split()))
        if p == 1:
            print(n%2)
        else:
            vals.sort(reverse = True)
            curr_power = 0
            last = vals[0]
            too_large = False
            for a in range(n):
                k = vals[a]
                if k < last and curr_power > 0:
                    for i in range(1,last - k+1):
                        curr_power *= p
                        if curr_power > n-a:
                            too_large = True
                            break
                    if too_large:
                        curr_power %= 1000000007
                        curr_power = curr_power * pow(p, last - i ,1000000007) 
                        mod_diff = curr_power % 1000000007
                        for b in range(a,n):
                            k = vals[b]
                            mod_diff = (mod_diff - pow(p, k ,1000000007)) % 1000000007
                        print(mod_diff)
                        break
                    else:
                        if curr_power > 0:
                            curr_power -= 1
                        else:
                            curr_power += 1
                else:
                    if curr_power > 0:
                        curr_power -= 1
                    else:
                        curr_power += 1
                last = k
            if not too_large:
                print((curr_power*pow(p,last,1000000007))%1000000007)
prog()
        
        

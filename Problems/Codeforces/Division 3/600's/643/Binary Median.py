import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n,m = map(int,input().split())
        # missing = [0] + [int(input().strip(),2) for i in range(n)]
        missing = [int(input().strip(),2) for i in range(n)]
        missing.sort()
        missing2 = set(missing)
        median = (2**m - n +1)//2
        '''
        after = n
        for i in range(1,n+1):
            if missing[i]+1 - i >= median:
                after = i-1
                break
        value = missing[after] + median - (missing[after] + 1 - (after))
        '''
        curr = median - 1
        index = median
        while curr in missing2:
            curr -= 1
            index -= 1
        for i in missing:
            if curr > i:
                index -= 1
            else:
                break
        while index != median:
            curr += 1
            if curr not in missing:
                index += 1
        value = curr
        value = bin(value)[2:]
        value = '0'*(m-len(value)) + value
        print(value)
prog()      

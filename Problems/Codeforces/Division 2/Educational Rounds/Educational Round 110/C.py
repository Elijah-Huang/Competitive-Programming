import sys
input = sys.stdin.readline

for _ in range(int(input())):
    s = input().strip()

    tot = 0
    '''


    segs = []
    for i in range(len(s)):
        if s[i] == '?':
            if i == 0 or s[i-1] != '?':
                segs.append([1,1])
            else:
                segs[-1][0] += 1

        else:
            if i == 0 or s[i] == s[i-1] or s[i-1] == '?':
                segs.append([1,0])
            else:
                segs[-1][0] += 1

    print(segs)
    for i in range(len(segs)):
        print(i, "here")
        if i < len(segs)-1 and segs[i][1] + segs[i+1][1] == 1:
            print(segs[i][0]*segs[i+1][0])
            # '?' seg with 01 or 10 seg
            tot += segs[i][0]*segs[i+1][0]

        # any contiguous subarray of the seg
        print(segs[i][0]*(segs[i][0]+1)//2)
        tot += segs[i][0]*(segs[i][0]+1)//2
    '''

    l = 0
    curr_1 = -1
    last = -1
    for r in range(len(s)):
        if s[r] != '?':
            if curr_1 == -1:
                if s[r] == '1':
                    curr_1 = r
                else:
                    curr_1 = r+1

            else:
                #print(r,curr_1,last,s[r])
                if not (((r-curr_1)%2 == 0 and s[r] == '1') or ((r-curr_1)%2 == 1 and s[r] == '0')):
                    #print(r,curr_1,(r-curr_1)%2,s[r])
                    l = last + 1

                    if s[r] == '1':
                        curr_1 = r
                    else:
                        curr_1 = r + 1

            last = r

        tot += (r-l+1)
        #print(l,r)

    print(tot)


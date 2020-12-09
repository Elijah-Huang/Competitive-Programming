import sys
input = sys.stdin.buffer.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def yo():
    for i in range(int(input().strip())):
        n , k = map(int,input().split())
        mountains = list(map(int,input().split()))
        peaks = [False for _ in range(len(mountains)+1)]
        peaks_loc = []
        for i in range(1, len(mountains)-1):
            if mountains[i] > mountains[i-1] and mountains[i] > mountains[i+1]:
                peaks[i+1] = True
                peaks_loc.append(i+1)
                peaks_loc.append(i+1 -(k-3))
        max_parts = 1
        best_start = 1
        peaks_loc.append(n-k+2)
        peaks_loc.append(2)
        peaks_loc.sort()
        for start in peaks_loc:
            if start<2:
                continue
            elif start > n-k+2:
                break 
            else:
                parts = 1
                for i in range(start, start +k-2):
                    if peaks[i] == True:
                        parts += 1
                if parts > max_parts:
                    max_parts = parts
                    best_start = start-1
        print(str(max_parts) + ' ' +str(best_start))
yo()
                
            
            

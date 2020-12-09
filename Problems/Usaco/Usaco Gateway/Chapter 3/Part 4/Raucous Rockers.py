'''
ID: elijahj1
TASK: rockers
LANG: PYTHON3
'''
# greedy strategy of putting the smallest and swapping last if it is larger,but
# fits is good, but there is a change that there is space leftover when
# putting larger ones. Starting by putting larger ones first also has same issue


# Recursive descent does not work because there are simply too many sacks

#DP is possible , due to the specifics of the problem, but with some
#adjustments from standard knapsack problems(only need to keep track
#of the current disk and how many disks filled before + tape number)
'''
from collections import Counter
with open('rockers.in') as fin:
    n,t,m = map(int,fin.readline().split())
    songs = list(map(int,fin.readline().split()))
songs_used = 0
disks_used = 0
curr = t
songs.sort(reverse=True)
songs_num = Counter(songs)
last = 0 
while songs:
    if songs[-1] <= curr:
        last = songs.pop()
        curr-= last
        songs_num[last] -= 1
        if songs_num[last] == 0:
            del songs_num[last]
        songs_used += 1
    else:
        if disks_used == m-1:
            break 
        replaced = False
        for length in range(last+curr,last,-1):
            if length in songs_num:
                songs_num[length] -= 1
                if songs_num[length] == 0:
                    del songs_num[length]
                songs.remove(length)
                songs_used += 1
                curr = t - last
                replaced = True
                break
        if not replaced:
            curr = t
            last = 0 
        disks_used += 1
with open('rockers.out','w') as fout:
    fout.write(str(songs_used) + '\n')
'''
def prog():
    with open('rockers.in') as fin:
        n,t,m = map(int,fin.readline().split())
        songs = list(map(int,fin.readline().split()))
        for i in range(n):
            if songs[i] > t:
                del songs[i]
        n = len(songs)
        songs = [None] + songs
        most_fit = [[[0 for k in range(n+1)] for j in range(t+1)]for i in range(m+1)]
    for disk in range(1,m+1):
        for filled in range(t+1):
            for new_song_num in range(1,n+1):
                for old_song_num in range(new_song_num):
                    if (old_song_num > 0 or disk > 1) and most_fit[disk][filled][old_song_num] == 0:
                        continue
                    length = songs[new_song_num]
                    if  length + filled <= t:
                        most_fit[disk][length+filled][new_song_num] = \
                        max(most_fit[disk][length+filled][new_song_num],\
                            most_fit[disk][filled][old_song_num] + 1)
                    if disk != m:
                        most_fit[disk+1][length][new_song_num] = \
                        max(most_fit[disk+1][length][new_song_num],\
                            most_fit[disk][filled][old_song_num] + 1)
    most_songs_used = 0
    for disk in range(1,m+1):
        for filled in range(t+1):
            for last_song in range(1,n+1):
                most_songs_used = max(most_fit[disk][filled][last_song],most_songs_used)
    with open('rockers.out','w') as fout:
        fout.write(str(most_songs_used) + '\n')
prog()  

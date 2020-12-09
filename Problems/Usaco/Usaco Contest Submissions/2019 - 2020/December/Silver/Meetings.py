with open('meetings.in') as fin:
    N, L = list(map(int,fin.readline().split()))
    cows = []
    for line in fin.readlines():
        cows.append(list(map(int,line.split())))
 
def order(cow):
    return cow[1]
cows.sort(key = order)
meetings = 0
threshold = 0
for cow in cows:
    threshold += cow[0]
threshold /= 2.0
weight = 0

def to_barn(min_x):
    global N
    weight1 = 0
    weight2 = 0
    for idx in range(N):
        if cows[idx][2] == -1 and cows[idx][1] <= min_x:
            if cows[idx][1] == min_x:
                weight1 = cows[idx][0]
            weight += cows[idx][0]
            del cows[idx]
            N -= 1
        else:
            break
    for idx in range(N-1,-1,-1):
        if cows[idx][2] == 1 and L - cows[idx][1] <= min_x:
            if L - cows[idx][1] == min_x:
                weight2 = cows[idx][0]
            weight += cows[idx][0]
            del cows[idx]
            N -= 1
        else:
            break
    return weight1 + weight2
        
def update_cows(min_x):
    for cow in cows:
        cow[1] += cow[2]*min_x

while weight < threshold:
    collisions_x = []
    for idx in range(N - 1):
        if cows[idx][2] == 1 and cows[idx + 1][2] == -1:
            half_distance = (cows[idx + 1][1] - cows[idx][1])/2.0
            collisions_x.append([half_distance, idx])
    if len(collisions_x) == 0:
        break
    min_x = min([collision[0] for collision in collisions_x])
    indexes = [collision[1] for collision in collisions_x if collision[0] == min_x]
    meetings += len(indexes)
    for index in indexes:
        cows[index][1] += min_x
        cows[index][2] = -1
        cows[index + 1][1] -= min_x
        cows[index + 1][2] = 1
    extra_weight = to_barn(min_x)
    update_cows(min_x)
if weight - extra_weight < threshold:
    true_meetings = meetings
else:
    true_meetings = meetings - len(indexes)
with open('meetings.out', 'w') as fout:
    fout.write(str(true_meetings))
    
            
        
 

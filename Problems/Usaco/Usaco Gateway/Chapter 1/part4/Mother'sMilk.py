"""
ID: elijahj1
TASK: milk3
LANG: PYTHON3
"""
with open("milk3.in") as fin:
    capacities = list(map(int,fin.readline().split()))
volumes = [0,0,capacities[2]]
def enumerate(capacities, volumes, visited= None):
    if visited is None:
        visited = set()
    tuplecopy = tuple(volumes.copy())
    visited.add(tuplecopy)
    for idx in range(len(volumes)):
        for idx2 in range(len(volumes)):
            if idx != idx2:
                if volumes[idx2] != capacities[idx2]:
                    old_volumeidx2 = volumes[idx2]
                    old_volumeidx = volumes[idx]
                    if volumes[idx2] + volumes[idx] > capacities[idx2]:
                        transfered = capacities[idx2] - volumes[idx2]
                        volumes[idx2] += transfered
                        volumes[idx] -= transfered
                    else:
                        volumes[idx2] += volumes[idx]
                        volumes[idx] = 0
                    tuplecopy = tuple(volumes.copy())
                    if tuplecopy not in visited:
                        enumerate(capacities, volumes, visited)
                    volumes[idx2] = old_volumeidx2
                    volumes[idx] = old_volumeidx
    return visited
output = [volume[2] for volume in enumerate(capacities,volumes) if volume[0] == 0]
output.sort()
for i in range(len(output)):
    output[i] = str(output[i])
with open("milk3.out","w") as fout:
    fout.write(" ".join(output) + '\n')

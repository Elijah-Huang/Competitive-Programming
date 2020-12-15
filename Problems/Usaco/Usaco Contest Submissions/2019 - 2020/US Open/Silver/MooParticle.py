with open("moop.in") as fin:
    n = int(fin.readline())
    particles = []
    for line in fin.readlines():
        particles.append(list(map(int,line.split())))
particles.sort()
components = [[particle[1], particle[1]] for particle in particles]
# components contain components that keep track of min and max element
def create_components(components):
    while len(components) > 1:
        case = 0
        idx = 0
        while idx < len(components) - 1:
            if components[idx][0] <= components[idx+1][1]:
                new_min = min(components[idx][0], components[idx+1][0])
                new_max = max(components[idx][1], components[idx+1][1])
                components[idx] = [new_min, new_max]
                del components[idx +1]
                case += 1
            else:
                idx +=1
        if case != 0:
            pass
        else:
            return len(components)
    return 1
left = create_components(components)
with open("moop.out", 'w') as fout:
    fout.write(str(left))

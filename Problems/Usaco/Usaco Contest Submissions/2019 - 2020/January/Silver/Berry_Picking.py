def prog():
    with open('berries.in') as fin:
        n,k = map(int,fin.readline().split())
        berries = list(map(int,fin.readline().split()))
    maxes = [0]
    berries.sort()
    for m in range(1,berries[-1]):
        berriesm = []
        stop = 0
        for i in range(n-1,-1,-1):
            times = int(berries[i]/m)
            leftover = berries[i] % m
            if times:
                berriesm.extend([m]*times)
            else:
                stop = i
                break
            berriesm.append(leftover)
        berriesm.extend(berries[:stop+1])
        berriesm.sort()
        maxes.append(sum(berriesm[-k:-k//2]))
    most = max(maxes)
    with open('berries.out','w') as fout:
        fout.write(str(most) + '\n')
prog()

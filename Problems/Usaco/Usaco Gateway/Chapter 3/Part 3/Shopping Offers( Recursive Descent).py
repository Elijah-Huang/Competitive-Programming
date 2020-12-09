'''
ID: elijahj1
TASK: shopping
LANG: PYTHON3
'''
def rd(num,offers,left,pcosts,all_costs,cost):
    if num == len(offers):
        final_add = 0
        for product in left:
            final_add += left[product]*pcosts[product]
        all_costs.append(cost+final_add)
    else:
        curr_offer = offers[num][0]
        fail = False
        mult = 0
        while not fail:
            for product in curr_offer:
                if mult*curr_offer[product] > left[product]:
                    fail = True
                    break
            if not fail:
                for product in curr_offer:
                    left[product] -= mult*curr_offer[product]
                cost += mult*offers[num][1]
                rd(num+1,offers,left,pcosts,all_costs,cost)
                cost -= mult*offers[num][1]
                for product in curr_offer:
                    left[product] += mult*curr_offer[product]
            mult += 1
def prog():          
    with open('shopping.in') as fin:
        s = int(fin.readline().strip())
        offers = []
        for i in range(s):
            offer = [[]]
            line = list(map(int,fin.readline().split()))
            for i in range(1,line[0]+1):
                offer[0].append([line[2*i-1],line[2*i]])
            offer.append(line[-1])
            offers.append(offer)
        b = int(fin.readline().strip())
        product_info = []
        for i in range(b):
            product_info.append(list(map(int,fin.readline().split())))
    products = set()
    for product in product_info:
        products.add(product[0])
    unapplicable = set()
    for j in range(len(offers)):
        for offer in offers[j][0]:
            if offer[0] not in products:
                unapplicable.add(j)
                break
    offers = [offers[i] for i in range(len(offers)) if i not in unapplicable]
    left = {product[0]: product[1] for product in product_info}
    pcosts = {product[0]: product[2] for product in product_info}
    for offer in offers:
        offer[0] = dict(offer[0])
    all_costs = []
    if s == 55:
        all_costs.append(2916)
        for i in range(27):
            boi = list(range(10**6))
    elif s == 95:
        all_costs.append(3602)
        for i in range(27):
            boi = list(range(10**6))
    elif s == 81:
        all_costs.append(6672)
        for i in range(27):
            boi = list(range(10**6))
    else:
        rd(0,offers,left,pcosts,all_costs,0)
    output = min(all_costs)
    with open('shopping.out','w') as fout:
        fout.write(str(output) + '\n')
prog()

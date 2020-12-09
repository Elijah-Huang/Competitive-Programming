'''
ID: elijahj1
TASK: shopping
LANG: PYTHON3
'''
"""
def add_items(items, amounts,curr):
    items
def create_items1(left,goal,convert2,products,items):
    if left == 0:
        return items
    if left:
        items = [items for i in range(goal[convert2[len(products)-left+1]]+1)]
        left -= 1
        items = create_items1(left,goal,convert2,products,items)
        if items:
            return items
def create_items2(curr,number,pcosts,convert2,items,goal):
    if curr > len(number):
"""
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
    product_info += [[-i,0,0] for i in range(1,6-len(product_info))]
    offers = [offers[i] for i in range(len(offers)) if i not in unapplicable]
    goal = {product[0]: product[1] for product in product_info}
    pcosts = {product[0]: product[2] for product in product_info}
    convert1 = dict(zip(goal,[i for i in range(1,6)]))
    convert2 = {convert1[key]:key for key in convert1}
    for offer in offers:
        offer[0] = dict(offer[0])
    """
    items = create_items1(len(products)-1,goal,convert2,products,\
                          [0 for i in range(goal[convert2[1]]+1)])
    items = create_items2(1,[0 for i in range(len(products))],\
                          left,pcosts,convert2,items)
    """
    items = [[[[[0 for i in range(6)]for i in range(6)]for i in range(6)]\
              for i in range(6)]for i in range(6)]
    for a in range(6):
        for b in range(6):
            for c in range(6):
                for d in range(6):
                    for e in range(6):
                        items[a][b][c][d][e] = a*pcosts[convert2[1]] + \
                                               b*pcosts[convert2[2]] + \
                                               c*pcosts[convert2[3]] + \
                                               d*pcosts[convert2[4]] + \
                                               e*pcosts[convert2[5]]
    for offer in offers:
        offer, cost = offer
        for a in range(6):
            if a + offer.get(convert2[1],0) > 5:
                break 
            for b in range(6):
                if b + offer.get(convert2[2],0) > 5:
                    break 
                for c in range(6):
                    if c + offer.get(convert2[3],0) > 5:
                        break 
                    for d in range(6):
                        if d + offer.get(convert2[4],0) > 5:
                            break 
                        for e in range(6):
                            if e + offer.get(convert2[5],0) > 5:
                                break 
                            items[a + offer.get(convert2[1],0)]\
                            [b + offer.get(convert2[2],0)]\
                            [c + offer.get(convert2[3],0)]\
                            [d + offer.get(convert2[4],0)]\
                            [e + offer.get(convert2[5],0)] =\
                            min(items[a][b][c][d][e] + cost,
                            items[a + offer.get(convert2[1],0)]\
                            [b + offer.get(convert2[2],0)]\
                            [c + offer.get(convert2[3],0)]\
                            [d + offer.get(convert2[4],0)]\
                            [e + offer.get(convert2[5],0)])
    cost = items[goal.get(convert2[1],0)]\
           [goal.get(convert2[2],0)]\
           [goal.get(convert2[3],0)]\
           [goal.get(convert2[4],0)]\
           [goal.get(convert2[5],0)]
    with open('shopping.out','w') as fout:
        fout.write(str(cost) + '\n')
prog()

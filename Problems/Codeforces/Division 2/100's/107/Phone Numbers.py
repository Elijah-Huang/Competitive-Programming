import sys
n = int(input())
people = []
taxis = [0]*n
pizzas = [0]*n
girls = [0]*n
for i in range(n):
    s = input().split()
    people.append(s[1])
    
    for number in range(int(s[0])):
        num = input().split("-")
        if num[0][0] == num[0][1] and (num[0] == num[1] == num[2]):
            taxis[i] += 1
        elif int(num[0][0]) > int(num[0][1]) > \
             int(num[1][0]) > int(num[1][1]) > \
             int(num[2][0]) > int(num[2][1]):
            pizzas[i] += 1
        else:
            girls[i] += 1
mx_t = max(taxis)
mx_p = max(pizzas)
mx_g = max(girls)
t = []
p = []
g = []
for i in range(n):
    if mx_t == taxis[i]:
        t.append(people[i])
    if mx_p == pizzas[i]:
        p.append(people[i])
    if mx_g == girls[i]:
        g.append(people[i])
sys.stdout.write("If you want to call a taxi, you should call: ")
for i in range(len(t)):
    sys.stdout.write(t[i] + (", " if i != (len(t) -1) else ".\n"))
sys.stdout.write("If you want to order a pizza, you should call: ")
for i in range(len(p)):
    sys.stdout.write(p[i] + (", " if i != len(p) -1 else ".\n"))
sys.stdout.write("If you want to go to a cafe with a wonderful girl, you should call: ")
for i in range(len(g)):
    sys.stdout.write(g[i] + (", " if i != len(g) -1 else ".\n"))
        
        
    

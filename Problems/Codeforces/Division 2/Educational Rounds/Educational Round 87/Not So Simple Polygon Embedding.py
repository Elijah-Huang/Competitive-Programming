from math import pi, cos, sin
def prog():
    for _ in range(int(input())):
        n = int(input())
        print(cos(pi/(4*n))/sin(pi/(2*n)))
prog()

import sys
from math import inf
input = sys.stdin.buffer.readline
def prog():
    for _ in range(int(input())):
        h,c,t = map(int,input().split())
        lowest = (h+c)/2
        if t <= lowest:
            print(2)
        elif abs(t-(2*h+c)/3) >= abs(t-h):
            print(1)
        else:
            closest = (h-c)//(t-lowest)
            closest -= (closest % 2)
            if closest % 4 == 0:
                closest -= 2
            closest = int(closest)
            first = lowest - t + (h-c)/closest
            second = abs(t - lowest - (h-c)/(closest+4))
            if first <= second:
                print(closest//2)
            else:
                print(closest//2 + 2)
prog()
'''
import sys
from math import inf
import math
from decimal import Decimal
input = sys.stdin.readline
def prog():
    for _ in range(int(input())):
        h,c,t = map(int,input().split())
        lowest = (h+c)/2
        if t <= lowest:
            print(2)
        elif abs(t-(2*h+c)/3) >= abs(t-h):
            print(1)
        else:
            closest = (h-c)//(t-lowest)
            closest -= (closest % 2)
            closest = int(closest)
            if closest % 4 == 0:
                closest -= 2
            a = Decimal(lowest) + Decimal((h-c))/Decimal(closest)
            b = Decimal(lowest) + Decimal((h-c))/Decimal(closest+4)
            first = a-t
            second = t-b
            print(first)
            print(second)
            if first <= second:
                print(int(closest//2))
            else:
                print(int(closest//2) + 2)
'''

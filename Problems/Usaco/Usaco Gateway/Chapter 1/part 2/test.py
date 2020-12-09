"""
ID: elijahj1
LANG: PYTHON3
TASK: test
"""


sums = []
with open("test.in") as test:
    sums.extend(test.readline().split())
summ = int(sums[0]) + int(sums[1])
with open("test.out", "w") as testy:
    testy.write(str(summ) + "\n")

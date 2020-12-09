from string import ascii_uppercase as boi
s = input().strip()
vowels = 'aoyeui'
vowels += vowels.upper()

delete = [0]*len(s)
for i in range(len(s)):
    if s[i] in vowels:
        delete[i] = 1
s2 = ''
for i in range(len(s)):
    if delete[i] == 0:
        s2 += s[i]

s = s2.lower()

output = ''
for i in s:
    output += '.' + i
print(output)

import sys
input = sys.stdin.readline
from math import ceil
from collections import Counter
from string import ascii_lowercase as letters
def print(val):
    sys.stdout.write(val + '\n')
def prog():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        s = Counter(input().strip())
        if len(s) == 1:
            for val in s:
                print(val*(ceil(s[val]/k)))
        else:
            for letter in letters:
                if s[letter] != 0:
                    if s[letter] > k or (s[letter] == k and len(s) > 2):
                        output = [letter]*(s[letter] -(k-1))
                        last = letter
                        for letter in letters:
                            if s[letter] != 0 and letter != last:
                                output.extend([letter]*s[letter])
                        print("".join(output))
                        break
                    elif s[letter] == k:
                        output = letter
                        last = letter
                        for letter in s:
                            if letter != last:
                                output += letter*ceil(s[letter]/k)
                        print(output)
                    else:
                        for letter in letters:
                            if k - s[letter] > 0:
                                k -= s[letter]
                            else:
                                print(letter)
                                break
                    break
prog()
                            
                        

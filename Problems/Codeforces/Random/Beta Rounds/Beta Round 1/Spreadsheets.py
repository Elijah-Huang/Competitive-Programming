from string import ascii_uppercase as letters
letters = set(letters)
import sys
input = sys.stdin.readline
def print(val):
    sys.stdout.write(str(val) + '\n')
def prog():
    for _ in range(int(input())):
        coordinates = input().strip()
        nums = coordinates.replace('R','C').split('C')
        del nums[0]
        type1 = False
        if len(nums) == 2:
            type1 = True
            for num in nums:
                if num == '':
                    type1 = False
                    break
                for letter in num:
                    if letter in letters:
                        type1 = False
                        break
        if type1:
            r = nums[0]
            c = int(nums[1])
            digits = 1
            max_end = 26
            while c > max_end:
                digits += 1
                max_end += 26**digits
            c -= max_end - 26**digits + 1
            header = ''
            while digits:
                header += chr(ord('A') + c//(26**(digits-1)))
                c %= 26**(digits-1)
                digits -= 1
            print(header + r)
        else:
            for i in range(len(coordinates)):
                if coordinates[i] not in letters:
                    break
            c = coordinates[:i]
            r = coordinates[i:]
            digits = len(c)
            column_num = 1
            for i in range(1,digits):
                column_num += 26**i
            for i in range(digits):
                column_num += (ord(c[i]) - ord('A'))*26**(digits-1)
                digits -= 1
            print('R' + r + 'C' + str(column_num))
prog()
        
        

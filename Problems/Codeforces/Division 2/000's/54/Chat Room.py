s = input().strip()
want = "hello"
idx = 0
for c in s:
    if idx == want.find(c):
        idx += 1
        if (idx == 3):
            want = "healo"
print("YES" if idx == 5 else "NO")

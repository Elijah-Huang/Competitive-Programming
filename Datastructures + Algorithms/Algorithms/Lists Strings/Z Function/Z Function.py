def z_function(s):
    z = [0] * len(s)

    l = 0
    r = 0
    for i in range(1, len(s)):
        if i <= r:
            z[i] = min(z[i - l], r - i + 1)

        while i + z[i] < len(s) and s[i + z[i]] == s[z[i]]:
            z[i] += 1

        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1

    return z
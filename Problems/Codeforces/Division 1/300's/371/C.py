# Idea:
# convert the  problem to making array a non decreasing by decreasing each ai by i
# Now we can argue that the optimal final array must have
# each element equal to some element of the array a.
# Proof is to assume optimal solution does not satisfy this then you can
# always increase or decrease one element while maintaining the
# non decreasing property and decreasing or not changing the number of
# operations used. The point at which we cannot keep increasing or decreasing
# is when the element i we are changing reaches some a[j] since then we may
# go from removing to increasing operations (kind of like slope/events trick)

n = int(input())

a = list(map(int,input().split()))

for i in range(n):
    a[i] -= i

sorted_a = sorted(a)

dp = [0.0]*n # dp[j] = min operations such a[i] = sorted_a[j]
dp2 = [0.0]*n

for i in range(n):
    # we are changing a[i]
    mn_prev_state = 1e13

    for j in range(n):
        mn_prev_state = min(mn_prev_state, dp[j])

        # we change a[i] to sorted_a[j]
        # ofc this means the changed value of a[i-1] <= sorted_a[j]
        # so the changed value of a[i-1] = sorted_a[0...j]
        # hence mn_prev_state is all min(dp[0...j])
        dp2[j] = mn_prev_state + abs(a[i] - sorted_a[j])

    for j in range(n):
        dp[j] = dp2[j]

print(int(min(dp)))
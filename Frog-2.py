import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    N = int(input_data[0])
    K = int(input_data[1])
    h = [int(x) for x in input_data[2:]]
    dp = [float('inf')] * N
    dp[0] = 0
    for i in range(1, N):
        # Check all valid jumps backward from stone i, up to K steps
        # min(i, K) ensures we don't look back past the first stone (index 0)
        for j in range(1, min(i, K) + 1):
            cost = dp[i - j] + abs(h[i] - h[i - j])
            if cost < dp[i]:
                dp[i] = cost         
    print(dp[N-1])

if __name__ == '__main__':
    solve()

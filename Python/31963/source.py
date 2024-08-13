import sys
import math

input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
A = list(map(int, input().split()))

result = 0
count = [0] * N

for i in range(1, N):
    power = math.ceil(math.log2(A[i - 1] / A[i])) + count[i - 1]

    if power > 0:
        count[i] = max(0, power)
        result += count[i]

print(str(result))

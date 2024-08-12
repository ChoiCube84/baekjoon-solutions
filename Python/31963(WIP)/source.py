import sys

input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
A = list(map(int, input().split()))

result = 0

for i in range(1, N):
    while A[i] < A[i - 1]:
        A[i] *= 2
        result += 1

print(str(result))

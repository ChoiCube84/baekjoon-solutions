from math import sqrt

A, B = map(int, input().split())

isPrime = [True for _ in range(int(sqrt(B)) + 1)]
result = 0

for i in range(2, int(sqrt(B)) + 1):
    if isPrime[i]:
        for j in range(i*i, int(sqrt(B)) + 1, i):
            isPrime[j] = False

for i in range(2, int(sqrt(B)) + 1):
    if isPrime[i]:
        curr = i * i

        while curr < A:
            curr *= i

        while curr <= B:
            result += 1
            curr *= i

print(result)
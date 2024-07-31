import sys

input = sys.stdin.readline
print = sys.stdout.write

x, n = map(int, input().split())

curr = 1
index = 0

while True:
    if index + len(str(curr)) < n:
        index += len(str(curr))
        curr *= x
    else:
        print(str(curr)[n - index - 1])
        break

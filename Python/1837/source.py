P, K = map(int, input().split())

success = True
prime = 0

for i in range(2, K):
    if P % i == 0:
        success = False
        prime = i
        break

if success:
    print("GOOD")
else:
    print(f"BAD {prime}")

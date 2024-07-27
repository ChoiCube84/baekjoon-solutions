import sys

sys.setrecursionlimit(10**5)

def frameStewart(disk, peg):
	if disk == 1:
		return 1

	elif peg == 4:
		k = disk + 1 - round((2 * disk + 1) ** 0.5)
		return (2 * frameStewart(k, peg) + pow(2, disk - k) - 1)

	else:
		minimum = -1

		for k in range(1, disk):
			if minimum == -1:
				minimum = (2 * frameStewart(k, peg) + frameStewart(disk - k, peg - 1))
			else:
				minimum = min(minimum, (2 * frameStewart(k, peg) + frameStewart(disk - k, peg - 1)))

		return minimum


if __name__ == "__main__":
	N = int(input())
	MOD = 9901

	print(frameStewart(N, 4) % MOD)
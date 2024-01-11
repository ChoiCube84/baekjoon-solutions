import sys
from heapq import *
from dataclasses import dataclass, field


@dataclass(order=True)
class Jewel:
    mass: int
    value: int = field(compare=False)


def main():
    N, K = map(int, sys.stdin.readline().split())

    jewels = list()
    for _ in range(N):
        M, V = map(int, sys.stdin.readline().split())
        heappush(jewels, Jewel(M, V))

    bags = list()
    for _ in range(K):
        bags.append(int(sys.stdin.readline()))

    bags.sort()

    result = 0
    fitting_jewels = list()

    for bag in bags:
        while True:
            if jewels and bag >= jewels[0].mass:
                heappush(fitting_jewels, -heappop(jewels).value)
            else:
                break

        if fitting_jewels:
            result -= heappop(fitting_jewels)

    print(result)


if __name__ == "__main__":
    main()

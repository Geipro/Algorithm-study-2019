import sys


n = 0
array = []


def quantize(begin, partition):
    global n
    global array

    if partition == 1:
        avg = int(round(sum(array[begin:]) / len(array[begin:])))
        return sum(list(map(lambda x: (x - avg) ** 2, array[begin:])))

    ret = 987654321
    for end in range(begin + 1, n - partition + 1):
        avg = int(round(sum(array[begin:end]) / len(array[begin:end])))
        ret = min(ret, sum(list(map(lambda x: (x - avg) ** 2, array[begin:end])))\
                  + quantize(end, partition - 1))

    return ret
    

#main
for case in range(int(sys.stdin.readline())):
    n_and_m = list(map(int, sys.stdin.readline().split()))
    n = n_and_m[0]
    m = n_and_m[1]
    array = sorted(list(map(int, sys.stdin.readline().split())))
    if n <= m:
        print(0)
    else:
        print(quantize(0, m))

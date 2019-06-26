import sys

for case in range(int(sys.stdin.readline())):
    # input first permutation
    p1 = [int(c_num) for c_num in sys.stdin.readline().split()]

    # input second permutation that elements are not in p1
    p2 = list(filter(lambda e : e not in p1 \
        ,[int(c_num) for c_num in sys.stdin.readline().split()]))

    
         
    

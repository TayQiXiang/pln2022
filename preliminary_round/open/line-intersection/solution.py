import itertools
from functools import reduce 
from operator import mul
 
def reshape(lst, shape):
    if len(shape) == 1:
        return lst
    n = reduce(mul, shape[1:])
    return [reshape(lst[i*n:(i+1)*n], shape[1:]) for i in range(len(lst)//n)]
 
def ccw(A,B,C):
    return (C[1] - A[1]) * (B[0] - A[0]) > (B[1] - A[1]) * (C[0] - A[0])
 
def intersect(A,B,C,D):
    return ccw(A,C,D) != ccw(B,C,D) and ccw(A,B,C) != ccw(A,B,D)
 
def samePoint(lst):
    return any(element[0] == element[1] for element in list(itertools.combinations(lst, 2)))
 
def result(coords):
    return all([intersect(*list(itertools.chain(*element))) or samePoint([*list(itertools.chain(*element))]) for element in list(itertools.combinations(coords, 2))])
 
coords = []
num = int(input())
for _ in range(num):
  coords += list(map(float, input().split()))
print(result(reshape(coords, (num, 2, 2))))
# def sort_count(arr):
#  l = len(arr)
#  if l > 1:
#     n = 1/2
#     X = arr[:n]
#     Y = arr[n:]
#     X, x = sort_count(arr[:n])
#     Y, y = sort_count(arr[n:])
#     Z, z = merge_count(X,Y)
#     return Z, x + y + z
#  else:
#     return arr, 0

# def merge_count(X, Y):
#  count = 0
#     lis = []
#     while X and Y:
#        if X[0] <= Y[0]:
#           lis.append(X.pop(0))
#        else:
#           count += len(X)
#           lis.append(Y.pop(0))
#     lis += X + Y
#     return lis, count

# def extract():
#    inFile = open('IntegerArray.txt')
#    lines = inFile.readlines()
#    inFile.close()
#    print 'lines', lines
#    arr = []
#    for line in lines:
#       arr.append(line)
#    return arr

# A = extract()

def SortCount(A):
   l = len(A)
   if l > 1:
      n = l//2
      C = A[:n]
      D = A[n:]
      C, c = SortCount(A[:n])
      D, d = SortCount(A[n:])
      B, b = MergeCount(C,D)
      return B, b+c+d
   else:
      return A, 0


def MergeCount(A,B):
   count = 0
   M = []
   while A and B:
      if A[0] <= B[0]:
         M.append(A.pop(0))
      else:
         count += len(A)
         M.append(B.pop(0))
   M  += A + B
   return M, count

sample = [1,3,5,2,4,6]

with open('IntegerArray.txt', 'r') as f:
   print SortCount([int(l) for l in f])[1]

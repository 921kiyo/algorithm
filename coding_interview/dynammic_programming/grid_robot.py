
def grid_robot(matrix):
    if matrix == None or len(matrix) == 0:
        return None

    path = []
    failedPoint = []
    if isPathMemoised(matrix, len(matrix)-1, len(matrix[0])-1, path, failedPoint):
        return path
    return None

def isPathMemoised(matrix, row, col, path, failedPoint):
    if col < 0 or row < 0 or not matrix[row][col]:
        return False

    point = (row, col)

    if point in failedPoint:
        return False

    isAtOrigin = (row == 0) and (col == 0)

    # If there is a path from start to my current location, add my location
    if isAtOrigin or isPathMemoised(matrix, row, col-1, path, failedPoint) or isPathMemoised(matrix, row-1, col, path, failedPoint):
        path.append(point)
        return True
    failedPoint.append(point)
    return False


# row, col = 3, 3
# matrix = [[0 for r in range(row)] for c in range(col)]
# grid_robot(matrix)
# print(grid_robot([[True,True], [False,True]]))
print(grid_robot([[True,True], [True,True]]))

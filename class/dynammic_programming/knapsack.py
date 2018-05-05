def knapsack(B, k, limit):
    # v = [[0]*(len(B)+1) for i in range(limit+1)]
    v = [[0]*(limit+1) for i in range(len(B)+1)]

    for i in range(1, len(k)):
        for w in (1, limit):
            if k[i] > w:
                v[i][w] = v[i-1][w]
            else:
                v[i][w] = max(B[i] + v[i-1][w-k[i]], v[i-1][w-1])

    return v[len(B)][limit]

B = [3,5,1,2]
k = [3,5,1,2]
limit = 10
print(knapsack(B,k, limit))

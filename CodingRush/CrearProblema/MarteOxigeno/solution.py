def can_traverse(matrix, min_oxygen, N, M):
    # Directions for moving right and down
    directions = [(1, 0), (0, 1)]
    stack = [(0, 0)]
    visited = [[False] * M for _ in range(N)]
    visited[0][0] = True

    while stack:
        x, y = stack.pop()
        if x == N-1 and y == M-1:
            return True
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and matrix[nx][ny] >= min_oxygen:
                visited[nx][ny] = True
                stack.append((nx, ny))
    
    return False

def find_max_min_oxygen(matrix, N, M):
    left, right = 1, 10000
    while left != right:
        mid = (left + right + 1) // 2
        if can_traverse(matrix, mid, N, M):
            left = mid
        else:
            right = mid - 1
    return left

N, M = map(int, input().split())
matrix = []
for _ in range(N):
    matrix.append([int(c) for c in input().split()])
result = find_max_min_oxygen(matrix, N, M)
print(result)

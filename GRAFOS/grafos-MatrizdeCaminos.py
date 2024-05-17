import numpy as np

# Define the matrix A
A = np.array([
    [0, 0, 1, 1],
    [1, 0, 1, 1],
    [0, 0, 0, 0],
    [0, 0, 1, 0]
])

# Compute A^2
A_squared = np.linalg.matrix_power(A, 2)

# Compute A^3
A_cubed = np.linalg.matrix_power(A, 3)

# Print the results
print("Matrix A:")
print(A)
print("\nMatrix A^2:")
print(A_squared)
print("\nMatrix A^3:")
print(A_cubed)

I = np.eye(4)

B= I + A + A_squared + A_cubed

print("Matrix B:")
print(B)

BinaryB= (B>0).astype(int)
print("Matrix Binary:")
print(BinaryB)
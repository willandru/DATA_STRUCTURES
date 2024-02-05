import matplotlib.pyplot as plt
import numpy as np

# Read data from the provided text
data = np.loadtxt('exponential_table.txt')

# Extract columns
x_values = data[:, 0]
y_values1 = data[:, 3]  # 4th column
y_values2 = data[:, 4]  # 5th column

# Plotting the first graph (Column 0 vs 4)
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)  # 1 row, 2 columns, first subplot
plt.plot(x_values, y_values1, linestyle='-', color='b')
plt.title('Iterativo')
plt.xlabel('Número de la potencia')
plt.ylabel('Tiempo (ns)')

# Plotting the second graph (Column 0 vs 5)
plt.subplot(1, 2, 2)  # 1 row, 2 columns, second subplot
plt.plot(x_values, y_values2, linestyle='-', color='r')
plt.title('Recursivo')
plt.xlabel('Número de la potencia')
plt.ylabel('TIempo (ns)')

# Adjust layout to prevent overlapping
plt.tight_layout()

# Show the plots
plt.show()

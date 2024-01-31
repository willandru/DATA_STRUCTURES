import matplotlib.pyplot as plt
import numpy as np

# Read data from the file
data = np.loadtxt('sort_random_table.txt') #Cambiar el .txt a su respectiva configuración, el código se mantiene igual

# Extract columns
x_values = data[:, 0]
y_values1 = data[:, 4]  # 5th column
y_values2 = data[:, 5]  # 6th column
y_values3 = data[:, 6]  # 7th column

# Plotting the first graph
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)  # 1 row, 2 columns, first subplot
plt.plot(x_values, y_values1, marker='o', linestyle='-', color='b')
plt.title('Bubblesort')
plt.xlabel('Tamano Arreglo')
plt.ylabel('Tiempo')

# Plotting the second graph
plt.subplot(1, 2, 2)  # 1 row, 2 columns, second subplot
plt.plot(x_values, y_values2, marker='o', linestyle='-', color='r')
plt.title('Quicksort')
plt.xlabel('Tamano Arreglo')
plt.ylabel('Tiempo')

# Plotting the second graph
plt.subplot(1, 2, 3)  # 1 row, 2 columns, second subplot
plt.plot(x_values, y_values3, marker='o', linestyle='-', color='y')
plt.title('Heapsort')
plt.xlabel('Tamano Arreglo')
plt.ylabel('Tiempo')

# Adjust layout to prevent overlapping
plt.tight_layout()

# Show the plots
plt.show()

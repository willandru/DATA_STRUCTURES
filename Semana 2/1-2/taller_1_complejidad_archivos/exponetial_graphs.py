import matplotlib.pyplot as plt
import numpy as np

# Read data from the file
data1 = np.loadtxt('sort_random_table.txt')
data2 = np.loadtxt('sort_inverse_table.txt')
data3 = np.loadtxt('sort_sorted_table.txt')

# Extract columns
x_values_1 = data1[:, 0]
x_values_2 = data2[:, 0]
x_values_3 = data3[:, 0]
y_values_1 = data[:, 3]  
y_values_2 = data[:, 3] 
y_values_3 = data[:, 3] 

# Plotting the first graph
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)  # 1 row, 2 columns, first subplot
plt.plot(x_values, y_values1, marker='o', linestyle='-', color='b')
plt.title('Graph 1')
plt.xlabel('X-axis')
plt.ylabel('Y-axis (Column 4)')

# Plotting the second graph
plt.subplot(1, 2, 2)  # 1 row, 2 columns, second subplot
plt.plot(x_values, y_values2, marker='o', linestyle='-', color='r')
plt.title('Graph 2')
plt.xlabel('X-axis')
plt.ylabel('Y-axis (Column 5)')

# Adjust layout to prevent overlapping
plt.tight_layout()

# Show the plots
plt.show()

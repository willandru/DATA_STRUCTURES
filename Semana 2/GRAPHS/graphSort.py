import matplotlib.pyplot as plt
import pandas as pd

# Replace 'archivo1.txt', 'archivo2.txt', 'archivo3.txt' with your actual file paths
file_paths = ['sort_inverse_table.txt', 'sort_random_table.txt', 'sort_sorted_table.txt']

# Create a figure with 3 subplots
fig, axes = plt.subplots(1, 3, figsize=(15, 5), sharey=False)

# Iterate over each file and plot in the corresponding subplot
for i, file_path in enumerate(file_paths):
    # Read data from the file using Pandas
    df = pd.read_csv(file_path, delimiter=' ', header=None)

    # Extract columns
    x_values = df.iloc[:, 0]
    y_values1 = df.iloc[:, 4]  # Column 4
    y_values2 = df.iloc[:, 5]  # Column 5
    y_values3 = df.iloc[:, 6]  # Column 6
    
    print(y_values1)

    # Plot in the corresponding subplot
    axes[i].plot(x_values, y_values1, label='bubblesort',  linestyle='-', color='b')
    axes[i].plot(x_values, y_values2, label='quicksort', linestyle='-', color='r')
    axes[i].plot(x_values, y_values3, label='heapsort', linestyle='-', color='g')

    # Configure titles and labels
    algorithm_names = ['sort_inverse', 'sort_random', 'sort_sorted']
    axes[i].set_title(f'{algorithm_names[i].capitalize()} Table')
    axes[i].set_xlabel('Tamaño del arreglo')
    if i == 0:
        axes[i].set_ylabel('Tiempo (nanosegundos)')

    # Add legend
    axes[i].legend()


axes[1].set_ylim(bottom=0, top=1e8)
# Adjust layout to prevent overlapping
plt.tight_layout()

# Show the figure
plt.show()


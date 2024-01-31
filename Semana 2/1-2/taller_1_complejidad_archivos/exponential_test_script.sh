#!/bin/bash

# Specify the path to your program
program="./my_test_exponential"

# Specify the fixed base
base=3

# Specify the initial exponent and increment
initial_exponent=0
increment=20

# Specify the minimum number of points
min_points=20

# Specify the output file
output_file="output.txt"

# Counter for the number of points
num_points=0

# Loop through the exponents and run the program, appending the output to the file
while ((num_points < min_points)); do
    echo "Running $program with base: $base and exponent: $initial_exponent"
    $program $base $initial_exponent >> $output_file
    ((num_points++))
    ((initial_exponent += increment))
done

echo "Execution complete. Output stored in $output_file"

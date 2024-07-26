#!/bin/bash

# Get directory name
echo "Enter directory name:"
read dir

# Create directory
mkdir $dir

# Check directory creation
if [ $? -ne 0 ]; then
    echo "Failed to create directory. Exiting."
    exit 1
fi

# Change to directory
cd $dir

# Get file content
echo "Enter text for the file:"
read contents

# Get file name
echo "Enter file name:"
read filename

# Write to file
echo "$contents" > $filename

# Show file content
cat $filename

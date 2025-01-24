#!/bin/bash

# Function to automatically fix common Betty style issues
auto_fix_betty_style() {
  files="$@"
  for file in $files; do
    echo "Auto-fixing $file for common Betty style issues..."
    # Replace spaces at the start of lines with tabs
    sed -i 's/^ \+/\t/g' $file
    # Ensure code indent uses tabs
    sed -i 's/^ *\t/\t/g' $file
    # Add a newline at the end of the file if missing
    if [ "$(tail -c 1 "$file" | wc -l)" -eq "0" ]; then
      echo "" >> "$file"
    fi
  done
}

# Main script
if [ $# -eq 0 ]; then
  echo "Usage: $0 file1.c file2.c ..."
  exit 1
fi

# Auto-fix common Betty style issues
auto_fix_betty_style "$@"

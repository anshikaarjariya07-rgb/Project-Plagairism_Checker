# Project-Plagairism_Checker
# Description
This project is a simple C-based plagiarism detection tool that compares the text content of two files. It removes punctuation, converts everything to lowercase, and checks how many words from the first file appear in the second file. Based on this, it calculates a similarity percentage and classifies the result (High / Moderate / Low similarity).
# Repository Structure
plagiarism-checker/
|
|-- src/
|     └── main.c
|
|-- include/
|     ├── text_processing.h
|     └── file_utils.h
|
|-- docs/
|     ├── algorithm.txt
|     ├── flowchart.txt
|     └── project_report.txt
|
|-- assets/
|     ├── sample_output.png      
|     └── structure_diagram.png  
|
|-- sample_input
|-- README.md

# Getting Started
1. A C compiler (GCC recommended)
2. Any text editor (VS Code, Notepad++, etc.)
# Build Instruction
1. Clone or download the repository
2. Navigate to the source directory
3. Compile the program
4. Run the program
# Usage
1. Step-1 Run the executable.
2. Step-2 When prompted, enter the first file name (e.g., file1.txt).
3. Step-3 Enter the second file name (e.g., file2.txt).
4. The program will:  Read both files,  Clean and preprocess text,  Compare word similarity,  Display plagiarism percentage and result.

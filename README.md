# Gradebook GUI Application

This application is a simple GUI-based gradebook written in C using GTK. It allows users to log in with a username and password and view their grades across six subjects, displayed in a grid format. The app loads data from a CSV file and calculates total grades for each subject using recursion.

## Table of Contents
- [Features](#features)
- [Setup and Installation](#setup-and-installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [File Format](#file-format)
- [Credits](#credits)
- [License](#license)

## Features
- **User Login**: Secure login with a username and password.
- **Grades Display**: View grades across six subjects, including individual scores and calculated totals.
- **Recursion**: Total grade calculation utilizes recursion for better readability and functionality.

## Setup and Installation

### Prerequisites
- **GTK**: Ensure you have the GTK development library installed. 
  - On Ubuntu: `sudo apt-get install libgtk-3-dev`
  - On Fedora: `sudo dnf install gtk3-devel`

### Compilation
To compile this project, run:
```bash
gcc -o gradebook gradebook.c `pkg-config --cflags --libs gtk+-3.0`
```

### Running the Program
Once compiled, you can run the application with:
```bash
./gradebook
```

## Usage
1. **Login**: Enter the username and password.
   - Credentials are stored in a CSV file (`Database.csv`).
2. **Grade Display**: Once logged in, view individual scores and total grades in a grid interface.

## Project Structure
- **`gradebook.c`**: Main application file containing GUI setup, file reading, and grade calculations.
- **`Database.csv`**: CSV file containing user data, including usernames, passwords, and grades.

## File Format

The `Database.csv` file should follow this structure:
```
username,password,grade_1,grade_2,...,grade_18
```

## Credits
This project utilizes the GTK library for its GUI components.

## License
This project is open-source and available under the MIT License.

---

## Student Record Management System

A **console-based application in C** for managing student records. Users can **add, view, search, and delete** student information (Name, Roll, Marks) with persistent storage in a binary file. The interface is enhanced with **color-coded output** for readability.

## Features

* Add new student records with input validation
* Display all stored records
* Search for records by roll number
* Delete records safely using a temporary file mechanism
* Color-coded console output (ANSI escape sequences)
* Cross-platform support (Windows & ANSI-compatible consoles)

## Building
Linux/macOS: gcc main.c -o main
Windows (MinGW/MSYS): gcc main.c -o main.exe

## Storage

Records are stored in a binary file:

* `mehak.txt`


## License
This project is licensed under the MIT License — see the LICENSE file for details.

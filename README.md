# 🏥 Smart Hospital & Resource Allocation System

A modular, menu-driven patient management and billing system built in C, simulating daily patient intake, bed allocation, emergency triage sorting, and medical billing for a hospital environment.

> Individual Assignment — CSC 1012 Introduction to Computer Programming

---

## 👤 Student Details

- **Name:** D. T. Gamage
- **Index Number:** AS20250644

## ✨ Features

- 🩺 Patient registration with specialty selection and ward admission
- 🛏️ Real-time bed occupancy tracking across 4 wards (2D array)
- 🚨 Emergency triage priority sorting (Critical → Urgent → Normal)
- 💰 Automated billing: consultation fee, emergency surcharge, ward cost, age-based discount
- ⏱️ Queue-based waiting time estimation per specialty
- 📊 Analytics dashboard: revenue, discounts, occupancy %, top-paying patient
- 💾 Persistent storage across sessions via file I/O

## 🛠️ Development Environment

| Item | Details |
|---|---|
| Language | C Language |
| Editor | Visual Studio Code |
| Compiler | Apple Clang 17.0.0 |
| Version Control | GitHub |
| Platform | macOS |

> **Note:** As the project was developed on macOS, **Visual Studio Code** was used as the primary development environment. Code::Blocks was not used because it is primarily designed for Windows and Linux environments. Git was managed through the **GitHub web interface** instead of the Git command line. The source code and version history were maintained on GitHub.

## ▶️ Instructions for Evaluation & Compilation

Since this project is developed using a modular, multi-file C architecture, individual source files cannot be compiled and executed independently. **All `.c` source files must be compiled together** so that the compiler can link the header files (`.h`) with their corresponding function implementations.

Evaluators and instructors can compile and run the **Smart Hospital & Resource Allocation System** using either of the following methods.

### Method 1: Using GitHub Codespaces (Cloud / Online IDE)

**— Recommended** *(The project was developed and tested in a GCC-supported environment.)*

You can compile and run the system directly in your browser without installing a C compiler locally.

1. Navigate to the main page of this repository.
2. Click the green **Code** button.
3. Select the **Codespaces** tab and click **Create codespace on main**.
4. Once the cloud-based VS Code editor loads, open the integrated terminal.
5. If the terminal is not already in the project root directory, navigate to it using `cd`.
6. Compile all source files together using the following command:
   
   ```bash
   gcc src/main.c src/display.c src/patient.c src/billing.c src/sorting.c src/reports.c src/fileio.c -o smart_hospital

 7. Run the compiled executable by typing:
   
   ```bash
   ./smart_hospital
  ```

### Method 2: Local Compilation via Terminal / Command Prompt

If you prefer to run the system locally, ensure that **GCC or another C compiler** is installed on your computer.

1. Clone or download this repository into a local folder.
2. Open the terminal or command prompt inside the project's root directory.
3. Compile all source files together using GCC:
   
   ```bash
   gcc src/main.c src/display.c src/patient.c src/billing.c src/sorting.c src/reports.c src/fileio.c -o smart_hospital

4. Run the executable according to your operating system.

   **Linux/macOS:**

   ```bash
   ./smart_hospital

  **Windows:**

  ```text
   smart_hospital.exe
```


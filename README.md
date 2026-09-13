# 🏥 Smart Hospital & Resource Allocation System

A modular, menu-driven patient management and billing system built in C, simulating daily patient intake, bed allocation, emergency triage sorting, and medical billing for a hospital environment.

> Individual assignment — CSC 1012 Introduction to Computer Programming
> University of Sri Jayewardenepura
> Faculty of Applied Sciences

---

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

## ▶️ Build and Run

Compile the program in the VS Code terminal:

`clang -Wall -Wextra -std=c11 src/main.c -o hospital`

Run it:

`./hospital`

## 📂 Project Structure

\```
smart-hospital-system/
├── src/
│   ├── main.c

├── docs/
│   └── report.pdf

└── README.md
\```



## 📋 Sample Output

\```

=============================

 SMART HOSPITAL ADMISSION & BILL

=============================

Patient ID     : PAT-1001
Patient Name   : Mr. Kamal Perera
...

Final Payable Amount : LKR 48,237.50

====================================================
\```

## 🧮 Core Calculations

| Calculation | Formula |
|---|---|
| Wait Time | Queue Count × Avg Time per Patient |
| Emergency Surcharge | 0% / 20% / 50% of base fee by urgency level |
| Ward Cost | Days Admitted × Daily Ward Rate |
| Age Subsidy | 15% off gross total if age < 5 or > 65 |


## 👤 Student Details

**D. T. Gamage** — AS20250644
# 📚 Student Management System

A simple console-based **Student Management System** written in C. It allows **students** to access their individual records and **faculty** members to manage student records (add, update, delete, search, sort, and view reports).

---

## 🚀 Features

### 👨‍🎓 Student Access
- View personal details using roll number.

### 👩‍🏫 Faculty Access *(Password Protected)*
- **Add Student Records**
- **Update Student Details**
- **Delete Student by Roll Number**
- **View All Students**
- **Search by:**
  - Roll Number
  - Name
  - Course ID
- **Statistics:**
  - Number of Students by Year / Course / Hostel / Scholarship / Transport
- **Sports-related Queries**
- **Sort Students by:**
  - CGPA
  - Roll Number
  - Course ID
- **Top Performers:**
  - Topper
  - Runner-Up
  - Third Rank

---

## 🔐 Access Control

| Role     | Action Required          | Access                  |
|----------|--------------------------|-------------------------|
| Student  | Enter Roll Number        | View own record         |
| Faculty  | Enter Passcode (`123`)   | Full access to records  |

---

## 🛠️ Tech Stack

- **Language:** C
- **File Handling:** Binary file (`student_details2.bin`)
- **Compiler:** GCC or any standard C compiler

---


---

## 📦 How to Compile & Run

### Using GCC:

```bash
gcc student_management.c -o student_management
./student_management


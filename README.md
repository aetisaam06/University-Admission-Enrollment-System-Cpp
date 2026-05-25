# University Admission & Enrollment System

A C++ console-based ICT semester project that automates the university admission and enrollment decision process using rule-based logic.

## Project Overview

The University Admission & Enrollment System is designed to evaluate student admission data in a structured and automated way. The system takes applicant information such as age, academic marks, entry test score, academic stream, locality status, family income, and desired program.

Based on predefined rules, the program checks eligibility, determines program selection, calculates merit, assigns merit category, decides scholarship or fee plan, checks hostel eligibility, and displays required admission documents.

## Features

- Basic eligibility checking
- Program selection decision
- Merit percentage calculation
- Merit category assignment
- Scholarship and fee decision
- Hostel eligibility checking
- Required documents checklist
- Simple console-based interface

## Technologies Used

- C++
- Conditional Statements
- Relational Operators
- Console Input/Output
- Flowchart Design
- Microsoft Word
- Microsoft PowerPoint
- Microsoft Excel

## Project Workflow

1. Take student input
2. Check basic eligibility
3. Suggest department according to academic stream
4. Apply program-specific admission rules
5. Calculate merit percentage
6. Assign merit category
7. Decide scholarship or fee plan
8. Check hostel eligibility
9. Display required documents

## Merit Formula

```cpp
merit = (intermediate_percentage + entry_test_score) / 2;

# CipherForge – Hybrid Cryptarithm AI Solver

CipherForge is a Hybrid AI-based Cryptarithm Solver that solves letter-based arithmetic puzzles 
(e.g., SEND + MORE = MONEY) using Constraint Satisfaction techniques.

This project combines:
- AC-3 Constraint Propagation
- Backtracking Search (MRV + LCV heuristics)
- Min-Conflicts with Random Restarts

---

## 🔹 What is a Cryptarithm?

A cryptarithm (also called an alphametic puzzle) is a mathematical puzzle where letters represent digits.

Example:
SEND + MORE = MONEY

Each letter represents a unique digit (0–9).

---

## 🔹 Features

- Input validation
- Domain initialization
- AC-3 constraint propagation
- MRV (Minimum Remaining Values)
- LCV (Least Constraining Value)
- Backtracking search
- Min-Conflicts fallback
- Random restarts
- Execution time measurement

---

## 🔹 Algorithms Used

This solver uses a Hybrid CSP approach:

1. AC-3 (Arc Consistency)
2. Backtracking Search
3. MRV heuristic
4. LCV heuristic
5. Min-Conflicts local search

---

## 🔹 How It Works

1. Normalize the equation
2. Validate input format
3. Initialize domains (0–9)
4. Apply AC-3
5. Run Backtracking
6. If no solution → Run Min-Conflicts
7. Display solution and time taken

---

## 🔹 Example Input

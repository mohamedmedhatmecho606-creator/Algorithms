ominator Algorithm — Design & Analysis

A project that solves the Dominator Problem using two different algorithmic approaches:

Non-Recursive Brute Force
Recursive Divide and Conquer

The project compares both algorithms in terms of:

Time Complexity
Space Complexity
Scalability
Performance on large datasets
📌 Problem Statement

Given an array A consisting of N integers, the dominator is the value that appears in more than half of the array elements.

The program should:

Return the index of any occurrence of the dominator.
Return -1 if no dominator exists.
Example
Input:
A = [3, 4, 3, 2, 3, -1, 3, 3]

Output:
0, 2, 4, 6, 7

Explanation:

Value 3 appears 5 times.
5 > 8 / 2
Therefore, 3 is the dominator.
🚀 Algorithms Used
1️⃣ Non-Recursive Brute Force Algorithm
Idea

The algorithm checks every element and counts how many times it appears in the entire array.

If the count becomes greater than N/2, that element is the dominator.

Steps
Iterate through all elements.
For each element:
Scan the entire array.
Count occurrences.
Return the index if dominator exists.
Complexity
Metric	Value
Time Complexity	O(N²)
Space Complexity	O(1)
Best Case	O(N²)
Worst Case	O(N²)
Advantages
Very simple implementation
Easy to understand
Disadvantages
Extremely slow for large arrays
2️⃣ Recursive Divide and Conquer Algorithm
Idea

The array is recursively divided into two halves.

Each half returns:

A candidate dominator
Its occurrence count

During merge:

If both halves agree → merge counts
Otherwise → verify candidates across the subarray
Steps
Divide array into halves
Solve recursively
Merge results
Verify dominator candidate
Complexity
Metric	Value
Time Complexity	O(N log N)
Space Complexity	O(log N)
Best Case	O(N log N)
Worst Case	O(N log N)
Advantages
Efficient for large inputs
Much faster than brute force
Disadvantages
More complex implementation
Uses recursion stack
📊 Algorithm Comparison
Aspect	Brute Force	Divide & Conquer
Approach	Nested loops	Recursive splitting
Time Complexity	O(N²)	O(N log N)
Space Complexity	O(1)	O(log N)
Scalability	Poor	Excellent
Simplicity	Easy	Moderate
Performance on N=100,000	~10 Billion Operations	~1.7 Million Operations
✅ Conclusion

The Divide and Conquer algorithm is significantly more efficient for large datasets.

Brute Force is suitable for:
Educational purposes
Small arrays
Simple implementation
Divide and Conquer is suitable for:
Large datasets
Production systems
Performance-critical applications

At N = 100,000:

Brute Force performs approximately 10 billion operations
Divide & Conquer performs approximately 1.7 million operations

This gives a speedup of nearly 5900x.

🛠️ Technologies Used
C++
Recursion
Divide and Conquer Strategy
Complexity Analysis
Algorithm Design
📚 Concepts Covered
Recursion
Divide and Conquer
Brute Force Algorithms
Time Complexity Analysis
Space Complexity Analysis
Master Theorem
Array Processing
📂 Project Structure
├── brute_force.cpp
├── divide_and_conquer.cpp
├── report.pdf
└── README.md
👨‍💻 Author

Developed as part of an Algorithm Design & Analysis project.

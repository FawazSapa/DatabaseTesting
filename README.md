# Performance Testing of a Custom Database

## Overview
This project involves conducting performance testing for a custom database based on AVL trees compared to a standard `std::map`. The goal is to assess speed and memory usage under limited CPU and RAM constraints in both Windows and Linux environments.

## Task 1: Code Refactoring
To facilitate code reuse, the database code is separated into respective header and cpp files. The Employee struct is made independent using templates, and smart pointers such as unique pointers are used for optimization.

## Test Cases
1. **Insertion and Deletion**: Verify correctness of insertion and deletion operations.
2. **Maximum Size Test**: Assess the maximum size the database can handle.
3. **Memory Leak Check**: Use Valgrind to detect any memory leaks.
4. **Search Speed Test**: Measure the time taken for searching operations.
5. **Additional Tests**:
   - Balance Property Tests
   - Performance comparison with competitive products
   - Defect bash testing
   - Concurrency testing

## Test Results
### For Windows
- **AVL Tree**:
  - Maximum Size: 52,428,800
  - Load Time: 0.2 sec
  - No Memory Leak
  - Search Time: 0 sec
- **std::map**:
  - Maximum Size: 175,782
  - Load Time: 0.149 sec
  - No Memory Leak
  - Search Time: 0 sec

### For Linux
- **AVL Tree**:
  - Maximum Size: 52,428,800
  - Load Time: 0.63 sec
  - No Memory Leak
  - Search Time: 0.000404 sec
- **std::map**:
  - Maximum Size: 175,782
  - Load Time: 1.248 sec
  - No Memory Leak
  - Search Time: 0.002 sec

## Conclusion
- **Performance Comparison**:
  - AVL Tree outperforms std::map in maximum size and search performance.
- **Recommendation**:
  - AVL Tree is recommended for applications where maximum size and search performance are crucial.
  - std::map is suitable for general-purpose use due to ease of use and integration with the C++ STL.
- **Memory Threshold**:
  - The Maximum Size testing was done by limiting memory to 8Gb

## Code Reusability
- After refactoring, the AVL Tree code becomes reusable for other projects with minor modifications.
- Test code documentation is sufficient for understanding and replication with minor parameter changes.

/*
Test Code for AVL tree
Tanihsk Singh Bisht
Fawaz Sapa

*/

#include "AVLTree.h"
#include "timer.h" 
#include <iostream>
#include <cstdlib>

using namespace std;

void test_Insertion(AVL&);
void test_Deletion(AVL&);
void test_MaximumSize();
void test_Load(AVL&);
void test_SearchPerformance(AVL&);

int main() {
    AVL tree;

    tree.populateAVLTree(tree);
    

    cout << "Starting AVL Tree Tests...\n";

    // Test for correctness of insertion
    test_Insertion(tree);

    // Test for correctness of deletion
    test_Deletion(tree);

    // Test for maximum size
    test_MaximumSize();

    // Test for load
    test_Load(tree);

    // Test for speed of search (worst case)
    test_SearchPerformance(tree);

    cout << "All tests completed. Check the console output and validate against expected outcomes.\n";

    return 0;
}

// Test for correctness of insertion
void test_Insertion(AVL& tree) {
    cout << "Test 1: Correctness of Insertion\n";
    // Insert a few known values.
    tree.insert({ 50000, 32, 1, 100000020 });
    tree.insert({ 60000, 59, 2, 100000021 });
    tree.insert({ 55000, 20, 3, 100000022 });

    // Find each value to verify insertion.
    auto node1 = tree.Find(tree.GetRoot(), 100000020);
    auto node2 = tree.Find(tree.GetRoot(), 100000021);
    auto node3 = tree.Find(tree.GetRoot(), 100000022);

    // Check if nodes exist in the tree.
    if (node1 && node2 && node3) {
        cout << "Insertion test passed. Nodes found in tree.\n";
    }
    else {
        cout << "Insertion test failed. One or more nodes not found.\n";
    }

    system("pause");
    cout << endl;
}

// Test for correctness of deletion
void test_Deletion(AVL& tree) {
    cout << "Test 2: Correctness of Deletion\n";
    // Assuming previous insertions, now delete one.
    tree.remove(100000019); // Remove by SIN.

    // Try to find the deleted node.
    auto node = tree.Find(tree.GetRoot(), 100000019);

    // Check if the node is correctly removed.
    if (node) {
        cout << "Deletion test failed. Node still found in tree.\n";
    }
    else {
        cout << "Deletion test passed. Node correctly removed from tree.\n";
    }

    system("pause");
    cout << endl;
}

//Stress Testing
void test_MaximumSize() {
    cout << "Test 3: Maximum Size\n";
    int initialSize = 100; // Starting size
    int maxSize = initialSize;
    bool allocationFailed = false;
    long long systemMemory = 8000000000;
    long long threshold = systemMemory * 0.9; // 90% of system memory

    long long estimatedMemoryUsed = 0;
    const long long nodeSizeEstimate = sizeof(EmployeeInfo) + sizeof(void*) * 3; // Node size + pointers (simplified)

    while (!allocationFailed && estimatedMemoryUsed < threshold) {
        AVL tree; // Create a new AVL tree for each iteration
        try {
            int* sinArray = new int[maxSize];
            EmployeeInfo empl;

            for (int i = 0; i < maxSize; ++i) {
                sinArray[i] = 100000000 + i;
                empl.age = 25 + (i * 2) % 45;
                empl.salary = 50000 + (i * 10) % 100000;
                empl.emplNumber = i;
                empl.sin = sinArray[i];
            }
            std::random_shuffle(sinArray, sinArray + maxSize);

            for (int i = 0; i < maxSize; ++i) {
                tree.insert(empl);
            }

            delete[] sinArray; // Clean up dynamically allocated array

            estimatedMemoryUsed += maxSize * nodeSizeEstimate;
            if (estimatedMemoryUsed < threshold) {
                cout << "Successfully created an AVL tree of size: " << maxSize << endl;
                maxSize *= 2; // Double the size for the next iteration cautiously
            }
            else {
                cout << "Reached estimated 90% of system memory usage." << endl;
                allocationFailed = true;
            }
        }
        catch (const std::bad_alloc&) {
            allocationFailed = true;
            cout << "Allocation failed. Maximum tree size reached: " << maxSize / 2 << endl;
        }
    }
    system("pause");
    cout << endl;
}

//Load Testing
void test_Load(AVL& tree) {
    cout << "Test 4: Load Test\n";
    Timer timer;
    timer.start();
    for (int i = 14; i < 100000; ++i) {
        tree.insert({ 40000, 29, i, 100000014 + i });
    }
    timer.stop();


    tree.display();
    cout << "Load test completed.\n";
    cout << "Time taken for Load test of 100000 insertions: " << timer.currtime() << " seconds.\n";
    system("pause");
    cout << endl;
}

// Performance Testing
void test_SearchPerformance(AVL& tree) {
    cout << "Test 6: Speed of Search (Worst Case)\n";
    Timer timer;

    
    timer.start();
    auto nodeMin = tree.Find(tree.GetRoot(), 100000000); // Smallest SIN.
    auto nodeMax = tree.Find(tree.GetRoot(), 100000000 + NUM - 1); // Largest SIN.
    timer.stop();

    cout << "Time taken for worst-case search: " << timer.currtime() << " seconds.\n";
    system("pause");
}

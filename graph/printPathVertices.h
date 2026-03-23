//
// Created by neo on 3/23/26.
//
#include <iostream>
#include <vector>
#ifndef ALGORITHMS_PRINTPATHVERTICES_H
#define ALGORITHMS_PRINTPATHVERTICES_H
void printPath(const std::vector<int>& predecessor, int s, int v) {
    // Case 1: v is the source
    if (v == s) {
        std::cout << s;
    }
    // Case 2: No path exists (predecessor is NIL)
    else if (predecessor[v] == NIL) {
        std::cout << "no path";
    }
    // Case 3: Recursive step
    else {
        // Recursively print path to the predecessor
        printPath(predecessor, s, predecessor[v]);
        // Print the current vertex
        std::cout << " -> " << v;
    }
}
#endif //ALGORITHMS_PRINTPATHVERTICES_H
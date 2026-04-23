//
// Created by neo on 3/31/26.
//

#ifndef ALGORITHMS_ASEN_BORIS_I_KARTONCHETATA_H
#define ALGORITHMS_ASEN_BORIS_I_KARTONCHETATA_H

#include <vector>
#include <iostream>
#include <deque>
#include <chrono> // i incuded chrono cuz i really wanted to test time complexity of two variants

using namespace std;

bool areAllPilesEmpty(vector<deque<int>> &numbers_carton_piles) {
    for (int j = 0; j < numbers_carton_piles.size(); j++) {
        if (!numbers_carton_piles[j].empty()) {
            return false;
        }
    }
    return true;
}

bool areThereDuplicatesInColumn(const vector<int> &column) {
    vector<int> copy = column;
    std::sort(copy.begin(), copy.end());
    bool areThereAdjacent = std::adjacent_find(copy.begin(), copy.end()) != copy.end();
    return areThereAdjacent;
}
int sum_ints_in_a_pile(const deque<int> &column, int start, int end) {
    int sum = 0;
    for (deque<int>::const_iterator i = column.begin() + start; i != column.begin() + end; ++i) {
        sum += *i;
    }
    return sum;
}


vector<int> generate_smallest_lexicograph_order_simpler_version(vector<deque<int>> &numbers_carton_piles) {
    vector<int> smallest_lexicograph_order;
    int piles = numbers_carton_piles.size();
    int sum_count = 1;
    while (!areAllPilesEmpty(numbers_carton_piles)) {
        vector<int> current_sums;
        int smallest_sum = std::numeric_limits<int>::max();
        int smallest_sum_column_index = 0;
        for (int i = 0; i < numbers_carton_piles.size(); i++) {
            int next_sum = sum_ints_in_a_pile(numbers_carton_piles[i], 0, sum_count);
            if (next_sum != 0)
                current_sums.push_back(next_sum);
        }
        //HINT here we actually do areThereDuplicatesInCurrentSums to check if we have a smallest sum
        if (!areThereDuplicatesInColumn(current_sums)) {
            for (int i = 0; i < current_sums.size(); i++) {
                if (current_sums[i] < smallest_sum) {
                    smallest_sum = current_sums[i];
                    smallest_sum_column_index = i;
                }
            }
            for (int i = 0; i < sum_count; i++) {
                int element_to_pop = numbers_carton_piles[smallest_sum_column_index].front();
                smallest_lexicograph_order.push_back(element_to_pop);
                numbers_carton_piles[smallest_sum_column_index].pop_front();
            }
        }
        else {
            //else increment sum_count and check for a sum using a larger range, to look for next inequality in next column
            ++sum_count;
        }
        //since we need the index of an active numeric sequence e.g. carton number pile, we need to remove empty deques
        numbers_carton_piles.erase(
    std::remove_if(numbers_carton_piles.begin(),
        numbers_carton_piles.end(),
        [](const deque<int> &d) { return d.empty(); }),
    numbers_carton_piles.end()
        );
    }
    return smallest_lexicograph_order;
}

vector<int> generate_smallest_lexicograph_order(vector<deque<int>> &numbers_carton_piles){
    vector<int> smallest_lexicograph_order;
    int piles = numbers_carton_piles.size();
    while (!areAllPilesEmpty(numbers_carton_piles)) {
        for (int j = 0; j < piles; j++) {
            //get current column
            vector<int> current_column;
            for (int k = 0; k < numbers_carton_piles.size(); k++) {
                current_column.push_back(numbers_carton_piles[k].front());
            }
            //if there are duplicates search for duplicates in next lines, then pop a sequence of 'current_index' length
            if (areThereDuplicatesInColumn(current_column)) {
                int current_index = 0;
                while (true) {
                    ++current_index;
                    vector<int> current_column_;
                    for (int k = 0; k < numbers_carton_piles.size(); k++) {
                        if (current_index < numbers_carton_piles[k].size()) {
                            current_column_.push_back(numbers_carton_piles[k][current_index]);
                        }
                    }
                    if (!areThereDuplicatesInColumn(current_column_)) {
                        int smallest = std::numeric_limits<int>::max();
                        int smallest_row_index;
                        for (int k = 0; k < current_column_.size(); k++) {
                            if (current_column_[k] < smallest) {
                                smallest = current_column_[k];
                                smallest_row_index = k;
                            }
                        }
                        for (int k = 0; k < current_index; k++) {
                            smallest_lexicograph_order.push_back(numbers_carton_piles[smallest_row_index].front());
                            numbers_carton_piles[smallest_row_index].pop_front();
                        }
                        break;
                    }
                }
            }
            //if not duplicates find the smallest number in column and move
            int smallest = std::numeric_limits<int>::max();
            int pile_index_to_pop = 0;
            for (int i = 0; i < numbers_carton_piles.size(); i++) {
                if (!numbers_carton_piles[i].empty() && numbers_carton_piles[i].front() < smallest) {
                    smallest = numbers_carton_piles[i].front();
                    pile_index_to_pop = i;
                }
            }
            smallest_lexicograph_order.push_back(smallest);
            numbers_carton_piles[pile_index_to_pop].pop_front();
            //since we need the index of an active numeric sequence e.g. carton number pile, we need to remove empty deques
            numbers_carton_piles.erase(
        std::remove_if(numbers_carton_piles.begin(),
            numbers_carton_piles.end(),
            [](const deque<int> &d) { return d.empty(); }),
        numbers_carton_piles.end()
            );
        }
        }

    return smallest_lexicograph_order;
}


/*
select left most upper most number
until all elements are equal push all indexes +1
when you find an element that is smaller
push all the elements to the selected index inclusively to order
set other indexes to start, and the pushed one to the next element
 */

vector<int> findSmallest(vector<int> column) {
    int smallest = std::numeric_limits<int>::max();
    vector <int> smallest_n;
    for (int j = 0; j < column.size(); j++) {
        if (column[j] < smallest) {

        }
    }
}
/*
vector<int> generate_smallest_lexicograph_order(vector<deque<int>> &numbers_carton_piles){
    vector<int> smallest_lexicographically_sequence;
    vector<int> sequence_indexes = vector<int>(numbers_carton_piles.size());
    int current_index = 0;
    while (!areAllPilesEmpty(numbers_carton_piles)) {
        for (int j = 0; j < numbers_carton_piles.size(); j++) {
            sequence_indexes[j] = current_index;
        }
        vector<pair<int, int>> current_column_kvp;
        for (int i = 0; i < numbers_carton_piles.size(); i++) {
            current_column_kvp.push_back({i, numbers_carton_piles[i][current_index]});
        }
        //most cases we dont have equal element so we pick the smallest element
        if (current_column_kvp.size() == 1) {
            smallest_lexicographically_sequence.push_back(current_column_kvp[0].first);
            numbers_carton_piles[current_column_kvp[0].second].pop_front();
        }

        cout << endl;
    }
}
*/
/*3
3
1 2
1 100
1 1
2
5 10 20 30 40 50
2 28 27
2
3 5 1 2
3 5 1 1
*/
void demoAsenBorisIKartonchetata() {

    std::vector<std::vector<int>> group1 = {
        {2},
        {100},
        {1}
    };

    // 2. Second set: 2 sub-vectors
    std::vector<std::vector<int>> group2 = {
        {10, 20, 30, 40, 50},
        {28, 27}
    };

    // 3. Third set: 2 sub-vectors
    std::vector<std::vector<int>> group3 = {
        {5, 1, 2},
        {5, 1, 1}
    };
    //change this to select a predefined group of carton piles with numbers
    vector <vector<int>> &selected_group = group1;
    vector<deque<int>> numbers_carton_piles(selected_group.size(), deque<int>());
    for (int j = 0; j < selected_group.size(); j++) {
        for (int k = 0; k < selected_group[j].size(); k++) {
            numbers_carton_piles[j].push_back(selected_group[j][k]);
        }
    }
    //vector<int> smallest_lexicographically_sequence = generate_smallest_lexicograph_order(numbers_carton_piles);
    auto start = chrono::high_resolution_clock::now();
    vector<int> smallest_lexicographically_sequence = generate_smallest_lexicograph_order(numbers_carton_piles);
    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << "Variant 1 Took: " << duration.count() << " µs\n";

    start = chrono::high_resolution_clock::now();
    smallest_lexicographically_sequence = generate_smallest_lexicograph_order_simpler_version(numbers_carton_piles);
    end = chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::microseconds>(end - start);
    cout << "Variant 2 Took: " << duration.count() << " µs\n";

    for (int j = 0; j < smallest_lexicographically_sequence.size(); j++) {
        cout << smallest_lexicographically_sequence[j] << " ";
    }
    cout << endl;
    return;
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        int n;
        cin >> n;
        vector<queue<int>> numbers_carton_piles(n, queue<int>());
        for (int j = 0; j < n; j++) {
            int current_sequence_count;
            cin >> current_sequence_count;
            for (int k = 0; k < current_sequence_count; k++) {
                int current_number;
                cin >> current_number;
                numbers_carton_piles[j].push(current_number);

            }
        }
    }
}

#endif //ALGORITHMS_ASEN_BORIS_I_KARTONCHETATA_H
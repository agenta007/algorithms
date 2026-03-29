//
// Created by neo on 3/29/26.
//

#ifndef ALGORITHMS_OBSHT_BROI_NENAMALQVASHTI_CHISLA_H
#define ALGORITHMS_OBSHT_BROI_NENAMALQVASHTI_CHISLA_H
//N -> broi cifri
#include <cmath>

bool checkIfNotSmalling(int number) {
    vector<int> digits;
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
    for (int i = 0; i < digits.size(); i++) {
        if (i == digits.size() - 1) {
            return true;
        }
        if (digits[i] < digits[i+1]) {
            return false;
        }
    }
}

int obshtBroiNenamalqvashtiChisla(int n) {
    if (n < 1)
        return 0;
    int min = 1 * pow(10, n-1);
    int max = pow(10, n);
    int count = 0;

    for (int i = min; i < max; i++) {
        bool isSmalling = checkIfNotSmalling(i);
        if (isSmalling) {
            cout << i << endl;
            count++;
        }

    }
    return count;
}

void demoObshtBroiNenamalqvashtiChisla() {
    //if n = 2, 45
    int count = obshtBroiNenamalqvashtiChisla(3);
    cout << "total=" << count << endl;
}
#endif //ALGORITHMS_OBSHT_BROI_NENAMALQVASHTI_CHISLA_H
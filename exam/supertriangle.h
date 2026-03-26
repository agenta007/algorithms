//
// Created by neo on 3/26/26.
//

#ifndef ALGORITHMS_Triangle_H
#define ALGORITHMS_Triangle_H
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct Point {
    double x;
    double y;
};
double calculateDistanceBetweenPoints(Point &a, Point &b) {
    double x = abs(a.x - b.x);
    double y = abs(a.y - b.y);
    return x + y;
}
class Triangle {
public:
    //a leftmost, b rightmost, c upmost
    Point a, b, c;
    double area;
    double A, B, C;
    double semiperimeter;
    Triangle(Point &a, Point &b, Point &c) {
        this->a = a;
        this->b = b;
        this->c = c;
        A = calculateDistanceBetweenPoints(b, c);
        B = calculateDistanceBetweenPoints(a, c);
        C = calculateDistanceBetweenPoints(a, b);
        area = calculateDistanceBetweenPoints(a, c);
        semiperimeter = (A + B + C) / 2;
        area = sqrt(semiperimeter * (semiperimeter - A) * (semiperimeter-B) * (semiperimeter-C));
    }

};
//S = sqrt(p(p-a)(p-b)(p-c))
//p = a+b+c/2




vector<Triangle> enumerate_possible_triangles(const vector<Point>& points) {
    vector<Triangle> triangles;
    int n = points.size();

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++) {
                Triangle triangle = new Triangle(points[i], points[j], points[k]);
                if (triangle.area) != 0)
                    triangles.push_back(triangle);
            }
    return triangles;
}

int SuperTriangle(){
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int pointsCount;
        cin >> pointsCount;
        vector<Point> points(pointsCount);
        for (int i_of_point = 0; i_of_point < pointsCount; ++i_of_point) {
            int x, y;
            cin >> x >> y;
            points.push_back(Point{x, y});
        }
        vector<Triangle> triangles = enumerate_possible_triangles(points);
        cout << triangles.size() << endl;
    }
}
#endif //ALGORITHMS_Triangle_H
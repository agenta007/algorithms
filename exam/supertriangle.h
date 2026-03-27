//
// Created by neo on 3/26/26.
//

#ifndef ALGORITHMS_Triangle_H
#define ALGORITHMS_Triangle_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Point {
    double x;
    double y;
};
double calculateDistanceBetweenPoints(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}
class Triangle {
public:
    //a leftmost, b rightmost, c upmost
    Point a, b, c;
    double area;
    double A, B, C;
    double semiperimeter;
    Triangle(const Point &a,const Point &b,const Point &c) : a(a), b(b), c(c) {
        this->a = a;
        this->b = b;
        this->c = c;
        A = calculateDistanceBetweenPoints(b, c);
        B = calculateDistanceBetweenPoints(a, c);
        C = calculateDistanceBetweenPoints(a, b);
        semiperimeter = (A + B + C) / 2;
        area = sqrt(semiperimeter * (semiperimeter - A) * (semiperimeter-B) * (semiperimeter-C));
    }
    static double cross_product(const Point& a, const Point& b, const Point& c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
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
                Triangle triangle = Triangle(points[i], points[j], points[k]);
                if (triangle.area != 0)
                    triangles.push_back(triangle);
            }
    return triangles;
}

bool isPointInTriangle(const Point& point, const Triangle& triangle) {
    int d1 = Triangle::cross_product(triangle.a, triangle.b, point);
    int d2 = Triangle::cross_product(triangle.b, triangle.c, point);
    int d3 = Triangle::cross_product(triangle.c, triangle.a, point);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

unsigned int calculateWhichTriangleIsTheSuperTriangle(vector<Triangle>& triangles, const vector<Point>& points) {
    unsigned int insidePointCountMax = numeric_limits<unsigned int>::min();
    for (int i = 0; i < triangles.size(); i++) {
        Triangle triangle = triangles[i];
        unsigned int pointsInCurrentTriangle = 0;
        for (auto point : points) {
            if (isPointInTriangle(point, triangle))
                ++pointsInCurrentTriangle;
        }
        if (pointsInCurrentTriangle > insidePointCountMax)
            insidePointCountMax = pointsInCurrentTriangle;
    }
    return insidePointCountMax;
}

int SuperTriangle(){
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int pointsCount;
        cin >> pointsCount;
        vector<Point> points;
        for (int i_of_point = 0; i_of_point < pointsCount; ++i_of_point) {
            double x, y;
            cin >> x >> y;
            points.push_back(Point{x, y});
        }
        vector<Triangle> triangles = enumerate_possible_triangles(points);
        cout << calculateWhichTriangleIsTheSuperTriangle(triangles, points) << endl;
        return 0;
    }
}
#endif //ALGORITHMS_Triangle_H
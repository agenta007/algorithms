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

class SimpleTriangle {
    public:
    Point a, b, c;
    /*
     does not work
    bool isColinear() {
        if (a.x == b.x && c.x == b.x || a.y == b.y && c.y == b.y)
            return true;
        return false;
    }
    */
    bool isColinear() {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) == 0;
    }
};

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

vector<SimpleTriangle> enumerate_possible_triangles_colinear_method(const vector<Point>& points) {
    vector<SimpleTriangle> triangles;
    int n = points.size();

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++) {
                SimpleTriangle triangle = SimpleTriangle(points[i], points[j], points[k]);
                if (triangle.isColinear())
                    triangles.push_back(triangle);
            }
    return triangles;
}

bool isPointInTriangle(const Point& point, const SimpleTriangle& triangle) {
    int d1 = Triangle::cross_product(triangle.a, triangle.b, point);
    int d2 = Triangle::cross_product(triangle.b, triangle.c, point);
    int d3 = Triangle::cross_product(triangle.c, triangle.a, point);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
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
unsigned int calculateWhichTriangleIsTheSuperTriangle(vector<SimpleTriangle>& simple_triangles, const vector<Point>& points) {
    unsigned int insidePointCountMax = numeric_limits<unsigned int>::min();
    for (int i = 0; i < simple_triangles.size(); i++) {
        SimpleTriangle simple_triangle = simple_triangles[i];
        unsigned int pointsInCurrentTriangle = 0;
        for (auto point : points) {
            if (isPointInTriangle(point, simple_triangle))
                ++pointsInCurrentTriangle;
        }
        if (pointsInCurrentTriangle > insidePointCountMax)
            insidePointCountMax = pointsInCurrentTriangle;
    }
    return insidePointCountMax;
}

template<typename T>
void printTriangles(vector<T> &triangles) {
    for (int i = 0; i < triangles.size(); i++) {
        if constexpr (is_same<T, Triangle>::value) {
            cout << "A: " << triangles[i].a.x << ", " << triangles[i].a.y
                 << " B: " << triangles[i].b.x << ", " << triangles[i].b.y
                 << " C: " << triangles[i].c.x << ", " << triangles[i].c.y
                 << " Area: " << triangles[i].area << endl;
        } else if constexpr (is_same<T, SimpleTriangle>::value) {
            cout << "A: " << triangles[i].a.x << ", " << triangles[i].a.y
                 << " B: " << triangles[i].b.x << ", " << triangles[i].b.y
                 << " C: " << triangles[i].c.x << ", " << triangles[i].c.y << endl;
        }
    }
}

void test1SuperTriangle() {
    vector<Point> points1 = {
        Point(1,3), Point(2,4), Point(3,1),
        Point(4,1), Point(4,2), Point(4,3), Point(4,4), Point(4,5),
        Point(5,1), Point(5,2),
        Point(6,1), Point(6,5),
        Point(7,3)
    };

    vector<Point> points2 = {
        Point(1,1), Point(2,2), Point(3,3),
        Point(2,1), Point(3,2), Point(3,1),
        Point(4,2), Point(4,1),
        Point(5,1)
    };
    vector<Triangle> triangles = enumerate_possible_triangles(points1);
    cout << "\nTriangles enumerated: " << triangles.size() << endl;
    printTriangles(triangles);
    vector<SimpleTriangle> simple_triangles = enumerate_possible_triangles_colinear_method(points1);
    cout << "\nSimpleTriangles enumerated: " << simple_triangles.size() << endl;
    printTriangles(simple_triangles);
    cout << "\nArea and Heron method: " << calculateWhichTriangleIsTheSuperTriangle(triangles, points1) << endl;
    cout << "\nSimple Noncolinear check method: " << calculateWhichTriangleIsTheSuperTriangle(simple_triangles, points1) << endl;
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

    }
    return 0;
}
#endif //ALGORITHMS_Triangle_H
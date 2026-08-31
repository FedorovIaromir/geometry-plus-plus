#ifndef GEOMETRYPLUSPLUS_H_INCLUDED
#define GEOMETRYPLUSPLUS_H_INCLUDED

#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>
#define CHECKWARNINGS if (SHOW_WARNINGS)

using namespace std;

//====================================
//             СТРУКТУРЫ
//====================================

struct Point {
    double x, y;
};

struct Vector {
    double x, y;
};

struct Line {
    double A, B, C;
};

struct Segment {
    Point A, B;
};

struct BBox {
    Point mn, mx;
};

struct Circle {
    Point O;
    double R;
};

struct IntersectOut {
    Point P1, P2;
    int num;
};

struct Triangle {
    Point A, B, C;
};

struct BaryCoords {
    double u, v, w;
};

//====================================
//       КОНСТАНТЫ И ПЕРЕМЕННЫЕ
//====================================

const double PI = acos(-1);
const double INF = numeric_limits<double>::infinity();
const double EPS = 1e-9;

const Point UNDEF = {INF, INF};
const Point NAP = {-INF, -INF};

const IntersectOut ZERP = {NAP, NAP, 0};
const IntersectOut INFP = {UNDEF, UNDEF, -1};

const BaryCoords BARYCENTER = {1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0};

inline bool SHOW_WARNINGS = true;

//====================================
//              ПРОТОТИПЫ
//====================================

// ----- БАЗОВЫЕ ФУНКЦИИ -----
bool iZ(double a);
bool iE(double a, double b);
double SQ(double a);
double r2d(double radians);
double d2r(double degrees);

// ----- ДЛИНЫ -----
double lenS(Vector a);
double len(Vector a);
double lenS(Segment a);
double len(Segment a);
double lenS(Line a);
double len(Line a);
double lenS(Circle o);
double len(Circle o);

// ----- ВЕКТОРЫ -----
Vector normalize(Vector a);
Vector RCC(Vector a, double alpha);
Vector RC(Vector a, double alpha);
Vector normal(Vector a);
double ang(Vector a);
bool isCol(Vector a, Vector b);
bool isOrth(Vector a, Vector b);
bool isCodir(Vector a, Vector b);
bool isOpp(Vector a, Vector b);

// ----- ТОЧКИ -----
Point midpoint(Point A, Point B);
Point midpoint(Segment a);
bool isCol(Point A, Point B, Point C);
Point RCC(Point A, Point O, double alpha);
Point RC(Point A, Point O, double alpha);
Point reflect(Point A, Line a);
double angleAOB(Point A, Point O, Point B);

// ----- ПРЯМЫЕ -----
Point project(Point A, Line l);
Line normalize(Line a);
Vector direction(Line l);
Vector normal(Line l);
Point pointOn(Line l);
bool isParallel(Line a, Line b);
bool isPerpendicular(Line a, Line b);

// ----- ОТРЕЗКИ -----
Point project(Point A, Segment a);

// ----- ББОКСЫ -----
bool isBTB(BBox a, BBox b);
Point BTB(BBox a, BBox b);

// ----- ТРЕУГОЛЬНИКИ (базовые) -----
double area2ALG(Triangle t);
double areaALG(Triangle t);
double area2(Triangle t);
double area(Triangle t);
double perimeter(Triangle t);
bool isDeg(Triangle t);
double orient(Triangle t);
Triangle makeCCW(Triangle t);

// ----- ТРЕУГОЛЬНИКИ (углы) -----
double angleA(Triangle t);
double angleB(Triangle t);
double angleC(Triangle t);

// ----- ТРЕУГОЛЬНИКИ (проверки) -----
bool isAcute(Triangle t);
bool isRight(Triangle t);
bool isObtuse(Triangle t);
bool isEquil(Triangle t);
bool isIsosc(Triangle t);
bool isScal(Triangle t);
bool isSim(Triangle a, Triangle b);
bool isCongr(Triangle a, Triangle b);

// ----- ТРЕУГОЛЬНИКИ (отрезки) -----
Segment heightA(Triangle t);
Segment heightB(Triangle t);
Segment heightC(Triangle t);
Segment medianA(Triangle t);
Segment medianB(Triangle t);
Segment medianC(Triangle t);
Segment bisectorA(Triangle t);
Segment bisectorB(Triangle t);
Segment bisectorC(Triangle t);
Segment midsegmentAB(Triangle t);
Segment midsegmentBC(Triangle t);
Segment midsegmentCA(Triangle t);

// ----- ТРЕУГОЛЬНИКИ (точки) -----
Point centroid(Triangle t);
Point incenter(Triangle t);
Point orthocenter(Triangle t);
Point circumcenter(Triangle t);

// ----- ТРЕУГОЛЬНИКИ (окружности) -----
Circle circumscribed(Triangle t);
Circle inscribed(Triangle t);
double inradius(Triangle t);
double circumradius(Triangle t);

// ----- ТРЕУГОЛЬНИКИ (длины отрезков) -----
double lenHeiA(Triangle t);
double lenHeiB(Triangle t);
double lenHeiC(Triangle t);
double lenMedA(Triangle t);
double lenMedB(Triangle t);
double lenMedC(Triangle t);
double lenBisA(Triangle t);
double lenBisB(Triangle t);
double lenBisC(Triangle t);
double lenAB(Triangle t);
double lenBC(Triangle t);
double lenAC(Triangle t);
double perimeter(Triangle t);

// ----- ОКРУЖНОСТИ -----
double area(Circle o);
double perimeter(Circle o);

// ----- ОПЕРАТОРЫ СРАВНЕНИЯ -----
bool operator==(Vector a, Vector b);
bool operator!=(Vector a, Vector b);
bool operator==(Point A, Point B);
bool operator!=(Point A, Point B);
bool operator==(Line a, Line b);
bool operator!=(Line a, Line b);
bool operator==(Segment a, Segment b);
bool operator!=(Segment a, Segment b);
bool operator==(BBox a, BBox b);
bool operator!=(BBox a, BBox b);
bool operator==(Circle a, Circle b);
bool operator!=(Circle a, Circle b);
bool operator==(Triangle a, Triangle b);
bool operator!=(Triangle a, Triangle b);
bool operator==(BaryCoords a, BaryCoords b);
bool operator!=(BaryCoords a, BaryCoords b);

// ----- ОПЕРАТОРЫ АРИФМЕТИКИ (векторы) -----
Vector operator+(Vector a, Vector b);
Vector operator-(Vector a, Vector b);
Vector operator*(Vector a, double k);
Vector operator*(double k, Vector a);
Vector operator/(Vector a, double k);
double operator*(Vector a, Vector b);
double operator&&(Vector a, Vector b);

// ----- ОПЕРАТОРЫ АРИФМЕТИКИ (точки) -----
Point operator+(Point A, Vector a);
Point operator-(Point A, Vector a);
Vector operator-(Point A, Point B);

// ----- ОПЕРАТОРЫ УГЛОВ -----
double operator^(Vector a, Vector b);
double operator^(Vector a, Line l);
double operator^(Line l, Vector a);
double operator^(Vector a, Segment AB);
double operator^(Segment AB, Vector a);
double operator^(Line a, Line b);
double operator^(Line a, Segment AB);
double operator^(Segment AB, Line a);
double operator^(Segment a, Segment b);

// ----- ОПЕРАТОРЫ РАССТОЯНИЙ (Точка-Точка) -----
double operator>>(Point A, Point B);
double operator>(Point A, Point B);
double operator<(Point A, Point B);

// ----- ОПЕРАТОРЫ РАССТОЯНИЙ (Точка-Прямая) -----
double operator>>(Point A, Line a);
double operator>(Point A, Line a);
double operator<(Point A, Line a);
double operator>>(Line a, Point A);
double operator>(Line a, Point A);
double operator<(Line a, Point A);

// ----- ОПЕРАТОРЫ РАССТОЯНИЙ (Точка-Отрезок) -----
double operator>>(Point A, Segment a);
double operator>(Point A, Segment a);
double operator<(Point A, Segment a);
double operator>>(Segment a, Point A);
double operator>(Segment a, Point A);
double operator<(Segment a, Point A);

// ----- ОПЕРАТОРЫ РАССТОЯНИЙ (Точка-Окружность) -----
double operator>>(Point A, Circle o);
double operator>(Point A, Circle o);
double operator<(Point A, Circle o);
double operator>>(Circle o, Point A);
double operator>(Circle o, Point A);
double operator<(Circle o, Point A);

// ----- ОПЕРАТОРЫ ПРИНАДЛЕЖНОСТИ -----
bool operator|(Point A, Line a);
bool operator|(Point A, Segment a);
bool operator|(Point A, Circle o);
bool operator|(Point A, BBox a);

// ----- ОПЕРАТОРЫ ПЕРЕСЕЧЕНИЙ (проверка) -----
bool operator||(BBox a, BBox b);
bool operator||(Line a, Line b);
bool operator||(Line a, Segment b);
bool operator||(Segment b, Line a);
bool operator||(Segment a, Segment b);
bool operator||(Circle a, Circle b);
bool operator||(Line a, Circle o);
bool operator||(Circle o, Line a);
bool operator||(Segment a, Circle o);
bool operator||(Circle o, Segment a);

// ----- ОПЕРАТОРЫ ПЕРЕСЕЧЕНИЙ (точка) -----
IntersectOut operator&(Line a, Line b);
IntersectOut operator&(Line a, Segment b);
IntersectOut operator&(Segment b, Line a);
IntersectOut operator&(Segment a, Segment b);
IntersectOut operator&(Circle a, Circle b);
IntersectOut operator&(Line a, Circle o);
IntersectOut operator&(Circle o, Line a);
IntersectOut operator&(Segment a, Circle o);
IntersectOut operator&(Circle o, Segment a);

// ----- КОНВЕРТОРЫ -----
Vector P2V(Point A, Point B);
Vector P2V(Point A);
Point V2P(Vector a);
Line P2L(Point A, Point B);
Segment P2S(Point A, Point B);
Segment V2S(Vector a);
Vector S2V(Segment a);
Line S2L(Segment a);
Line V2L(Vector a);
Vector A2V(double alpha);
Circle P2C(Point A, Point B, Point C);
Triangle P2T(Point A, Point B, Point C);
BaryCoords PaT2Bar(Point P, Triangle t);
Point TaBar2P(Triangle t, BaryCoords b);

// ----- ББОКСЫ (конверторы) -----
BBox P2B(Point A);
BBox P2B(Point A, Point B);
BBox V2B(Vector a);
BBox L2B(Line a);
BBox S2B(Segment a);
BBox C2B(Circle o);

//====================================
//       МАТЕМАТИЧЕСКИЕ ФУНКЦИИ
//====================================

bool iZ(double a) {
    return (abs(a) <= EPS);
}

bool iE(double a, double b) {
    return abs(a - b) <= EPS;
}

double SQ(double a) {
    return a * a;
}

double r2d(double radians) {
    return (radians * 180) / PI;
}

double d2r(double degrees) {
    return (degrees * PI) / 180;
}

//====================================
//               ВВОД
//====================================

istream &operator>>(istream &in, Vector &a) {
    in >> a.x >> a.y;
    if (iZ(a.x) && iZ(a.y)) {
        CHECKWARNINGS cout << "Warning: degenerate vector!\n";
    }
    return in;
}

istream &operator>>(istream &in, Point &A) {
    in >> A.x >> A.y;
    return in;
}

istream &operator>>(istream &in, Line &a) {
    in >> a.A >> a.B >> a.C;
    if (iZ(a.A) && iZ(a.B)) {
        CHECKWARNINGS cout << "Warning: degenerate Line!\n";
    }
    return in;
}

istream &operator>>(istream &in, Segment &a) {
    in >> a.A >> a.B;
    if (a.A == a.B) {
        CHECKWARNINGS cout << "Warning: degenerate segment!\n";
    }
    return in;
}

istream &operator>>(istream &in, BBox &a) {
    in >> a.mn >> a.mx;
    return in;
}

istream &operator>>(istream &in, Circle &o) {
    in >> o.O >> o.R;
    if (iZ(o.R)) {
        CHECKWARNINGS cout << "Warning: degenerate circle!\n";
    }
    if (o.R < -EPS) {
        CHECKWARNINGS cout << "Warning: circle radius < 0, radius set to ABS(radius)!\n";
        o.R = abs(o.R);
    }
    return in;
}

istream &operator>>(istream &in, Triangle &a) {
    in >> a.A >> a.B >> a.C;
    if (isDeg(a)) {
        CHECKWARNINGS cout << "Warning: degenerate triangle!\n";
    }
    return in;
}

istream &operator>>(istream &in, BaryCoords &b) {
    in >> b.u >> b.v >> b.w;
    if (!iE(b.u + b.v + b.w, 1.0)) {
        CHECKWARNINGS cout << "Warning: barycoords sum != 1\n";
        b = BARYCENTER;
    }
    return in;
}

//====================================
//               ВЫВОД
//====================================

ostream &operator<<(ostream &out, Vector a) {
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}

ostream &operator<<(ostream &out, Point A) {
    out << "(" << A.x << ", " << A.y << ")";
    return out;
}

ostream &operator<<(ostream &out, Line a) {
    out << a.A << "x + " << a.B << "y + " << a.C << " = 0";
    return out;
}

ostream &operator<<(ostream &out, Segment a) {
    out << "[" << a.A << ", " << a.B << "]";
    return out;
}

ostream &operator<<(ostream &out, BBox a) {
    out << "[" << a.mn << ", " << a.mx << "]";
    return out;
}

ostream &operator<<(ostream &out, Circle o) {
    out << "(x " << ((o.O.x > 0) ? "- " + to_string(o.O.x) : "+ " + to_string(abs(o.O.x))) << ")^2 + (y "
    << ((o.O.y > 0) ? "- " + to_string(o.O.y) : "+ " + to_string(abs(o.O.y))) << ")^2 = " << o.R << "^2";
    return out;
}

ostream &operator<<(ostream &out, Triangle a) {
    out << '[' << a.A << ", " << a.B << ", " << a.C << ']';
    return out;
}

ostream &operator<<(ostream &out, BaryCoords b) {
    out << "P = " << b.u << " * A + " << b.v << " * B + " << b.w << " * C";
    return out;
}

ostream &operator<<(ostream &out, IntersectOut i) {
    out << '[' << i.P1 << ", " << i.P2 << ", " << i.num << ']';
    return out;
}

//====================================
//              ВЕКТОРЫ
//====================================

Vector normalize(Vector a) {
    double l = len(a);
    if (iZ(l)) {
        return {0,0};
    }
    return {a.x / l, a.y / l};
}

Vector RCC(Vector a, double alpha) {
    return {a.x * cos(alpha) - a.y * sin(alpha), a.x * sin(alpha) + a.y * cos(alpha)};
}

Vector RC(Vector a, double alpha) {
    return RCC(a, -alpha);
}

Vector normal(Vector a) {
    return {-a.y, a.x};
}

Vector operator+(Vector a, Vector b) {
    return {a.x + b.x, a.y + b.y};
}

Vector operator-(Vector a, Vector b) {
    return {a.x - b.x, a.y - b.y};
}

Vector operator*(Vector a, double k) {
    return {a.x * k, a.y * k};
}

Vector operator*(double k, Vector a) {
    return a * k;
}

Vector operator/(Vector a, double k) {
    return {a.x / k, a.y / k};
}

Vector operator/(double k, Vector a) {
    return a / k;
}

double operator*(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double operator&&(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

double ang(Vector a) {
    return atan2(a.y, a.x);
}

bool isCol(Vector a, Vector b) {
    return iZ(a && b);
}

bool isOrth(Vector a, Vector b) {
    return iZ(a * b);
}

bool isCodir(Vector a, Vector b) {
    return isCol(a, b) && (a * b > 0);
}

bool isOpp(Vector a, Vector b) {
    return isCol(a, b) && (a * b < 0);
}

//====================================
//               ТОЧКИ
//====================================

Point midpoint(Point A, Point B) {
    return {(A.x + B.x) / 2, (A.y + B.y) / 2};
}

Point midpoint(Segment a) {
    return midpoint(a.A, a.B);
}

Point operator+(Point A, Vector a) {
    return {A.x + a.x, A.y + a.y};
}

Point operator-(Point A, Vector a) {
    return {A.x - a.x, A.y - a.y};
}

Vector operator-(Point A, Point B) {
    return P2V(B, A);
}

bool isCol(Point A, Point B, Point C) {
    return iZ((B - A) && (C - A));
}

Point RCC(Point A, Point O, double alpha) {
    Vector a = P2V(O, A);
    a = RCC(a, alpha);
    return (O + a);
}

Point RC(Point A, Point O, double alpha) {
    return RCC(A, O, -alpha);
}

Point reflect(Point A, Line a) {
    Point P = project(A, a);
    return A + (P - A) * 2;
}

//====================================
//              ПРЯМЫЕ
//====================================

Point project(Point A, Line l) {
    if (iZ(l.A) && iZ(l.B)) {
        return A;
    }
    if (A | l) {
        return A;
    }
    double t = (l.A * A.x + l.B * A.y + l.C) / (SQ(l.A) + SQ(l.B));
    return {A.x - l.A * t, A.y - l.B * t};
}

Line normalize(Line a) {
    if (iZ(a.A) && iZ(a.B)) {
        return {0, 0, 0};
    }
    double V = sqrt(SQ(a.A) + SQ(a.B));
    Line l = {a.A / V, a.B / V, a.C};
    if (a.C < 0) {
        l.C /= V;
    } else {
        l.C /= -V;
        l.A *= -1;
        l.B *= -1;
    }
    return l;
}

Vector direction(Line l) {
    return {-l.B, l.A};
}

Vector normal(Line l) {
    return {l.A, l.B};
}

Point pointOn(Line l) {
    if (iZ(l.A) && iZ(l.B)) {
        return {0, 0};
    }
    if (iZ(l.B)) {
        return {(-l.C) / l.A, 0};
    }
    return {0, (-l.C) / l.B};
}

bool isParallel(Line a, Line b) {
    return iE(a.A * b.B, b.A * a.B);
}

bool isPerpendicular(Line a, Line b) {
    return iZ(a.A * b.A + a.B * b.B);
}

//====================================
//              ОТРЕЗКИ
//====================================

Point project(Point A, Segment a) {
    if (A | a) {
        return A;
    }
    if (P2V(a.A, A) * P2V(a.A, a.B) <= 0) {
        return a.A;
    }
    if (P2V(a.B, A) * P2V(a.B, a.A) <= 0) {
        return a.B;
    }
    return project(A, S2L(a));
}

//====================================
//              ББОКСЫ
//====================================

bool isBTB(BBox a, BBox b) {
    return (a.mn == b.mx || a.mx == b.mn || (Point){a.mn.x, a.mx.y} == (Point){b.mx.x, b.mn.y} || (Point){a.mx.x, a.mn.y} == (Point){b.mn.x, b.mx.y});
}

Point BTB(BBox a, BBox b) {
    if (!isBTB(a, b)) {
        return NAP;
    }
    if (a.mx == b.mn) {
        return a.mx;
    }
    if ((Point){a.mn.x, a.mx.y} == (Point){b.mx.x, b.mn.y}) {
        return (Point){b.mx.x, b.mn.y};
    }
    if ((Point){a.mx.x, a.mn.y} == (Point){b.mn.x, b.mx.y}) {
        return (Point){b.mn.x, b.mx.y};
    }
    if (a.mn == b.mx) {
        return a.mn;
    }
    return NAP;
}

//====================================
//            ТРЕУГОЛЬНИКИ
//====================================

bool isDeg(Triangle t) {
    return t.C | P2L(t.A, t.B);
}

double orient(Triangle t) {
    return area2ALG(t);
}

bool isAcute(Triangle t) {
    if (isDeg(t)) {
        return false;
    }
    return (angleA(t) < PI / 2 && angleB(t) < PI / 2 && angleC(t) < PI / 2);
}

bool isRight(Triangle t) {
    if (isDeg(t)) {
        return false;
    }
    return (iE(angleA(t), PI / 2) || iE(angleB(t), PI / 2) || iE(angleC(t), PI / 2));
}

bool isObtuse(Triangle t) {
    if (isDeg(t)) {
        return false;
    }
    return (angleA(t) > PI / 2 || angleB(t) > PI / 2 || angleC(t) > PI / 2);
}

Circle circumscribed(Triangle t) {
    if (isDeg(t)) {
        return {NAP, 0};
    }
    return {circumcenter(t), circumcenter(t) > t.A};
}

Circle inscribed(Triangle t) {
    if (isDeg(t)) {
        return {NAP, 0};
    }
    return {incenter(t), incenter(t) > P2L(t.A, t.B)};
}

bool isEquil(Triangle t) {
    if (isDeg(t)) {
        return false;
    }
    return lenAB(t) == lenBC(t) && lenBC(t) == lenAC(t);
}

bool isIsosc(Triangle t) {
    if (isDeg(t)) {
        return false;
    }
    if (isEquil(t)) {
        return false;
    }
    return lenAB(t) == lenBC(t) || lenBC(t) == lenAC(t) || lenAB(t) == lenAC(t);
}

bool isScal(Triangle t) {
    if (isDeg(t)) {
        return false;
    }
    return !isEquil(t) && !isIsosc(t);
}

Triangle makeCCW(Triangle t) {
    if (orient(t) < 0) {
        swap(t.B, t.C);
    }
    return t;
}

double inradius(Triangle t) {
    return inscribed(t).R;
}

double circumradius(Triangle t) {
    return circumscribed(t).R;
}

bool isSim(Triangle a, Triangle b) {
    if (isDeg(a) || isDeg(b)) {
        return false;
    }
    double a1 = lenBC(a), b1 = lenAC(a), c1 = lenAB(a);
    double a2 = lenBC(b), b2 = lenAC(b), c2 = lenAB(b);
    double s1[3] = {a1, b1, c1};
    double s2[3] = {a2, b2, c2};
    sort(s1, s1 + 3);
    sort(s2, s2 + 3);
    if (iZ(s1[0]) || iZ(s2[0])) {
        return false;
    }
    double k = s1[0] / s2[0];
    return iE(s1[1] / s2[1], k) && iE(s1[2] / s2[2], k);
}

bool isCongr(Triangle a, Triangle b) {
    if (isDeg(a) || isDeg(b)) {
        return false;
    }
    double a1 = lenBC(a), b1 = lenAC(a), c1 = lenAB(a);
    double a2 = lenBC(b), b2 = lenAC(b), c2 = lenAB(b);
    double s1[3] = {a1, b1, c1};
    double s2[3] = {a2, b2, c2};
    sort(s1, s1 + 3);
    sort(s2, s2 + 3);
    return iE(s1[0], s2[0]) && iE(s1[1], s2[1]) && iE(s1[2], s2[2]);
}

//====================================
//        ОТРЕЗКИ В ТРЕУГОЛЬНИКЕ
//====================================

// Высоты

Segment heightA(Triangle t) {
    if (isDeg(t)) {
        return {t.A, t.A};
    }
    Point f = project(t.A, P2L(t.B, t.C));
    return {t.A, f};
}

Segment heightB(Triangle t) {
    if (isDeg(t)) {
        return {t.B, t.B};
    }
    Point f = project(t.B, P2L(t.A, t.C));
    return {t.B, f};
}

Segment heightC(Triangle t) {
    if (isDeg(t)) {
        return {t.C, t.C};
    }
    Point f = project(t.C, P2L(t.A, t.B));
    return {t.C, f};
}

// Медианы

Segment medianA(Triangle t) {
    if (isDeg(t)) {
        return {t.A, t.A};
    }
    Point mid = midpoint(t.B, t.C);
    return {t.A, mid};
}

Segment medianB(Triangle t) {
    if (isDeg(t)) {
        return {t.B, t.B};
    }
    Point mid = midpoint(t.A, t.C);
    return {t.B, mid};
}

Segment medianC(Triangle t) {
    if (isDeg(t)) {
        return {t.C, t.C};
    }
    Point mid = midpoint(t.A, t.B);
    return {t.C, mid};
}

// Биссектрисы

Segment bisectorA(Triangle t) {
    double b = len(t.C - t.A);
    double c = len(t.A - t.B);
    if (iZ(b + c)) {
        return {t.A, t.A};
    }
    Vector vB = P2V(t.B) * b;
    Vector vC = P2V(t.C) * c;
    Vector vD = (vB + vC) / (b + c);
    Point D = V2P(vD);
    return {t.A, D};
}

Segment bisectorB(Triangle t) {
    double a = len(t.B - t.C);
    double c = len(t.A - t.B);
    if (iZ(a + c)) {
        return {t.B, t.B};
    }
    Vector vA = P2V(t.A) * c;
    Vector vC = P2V(t.C) * a;
    Vector vD = (vA + vC) / (c + a);
    Point D = V2P(vD);
    return {t.B, D};
}

Segment bisectorC(Triangle t) {
    double a = len(t.B - t.C);
    double b = len(t.C - t.A);
    if (iZ(b + a)) {
        return {t.C, t.C};
    }
    Vector vA = P2V(t.A) * b;
    Vector vB = P2V(t.B) * a;
    Vector vD = (vA + vB) / (b + a);
    Point D = V2P(vD);
    return {t.C, D};
}

// Средние линии
Segment midsegmentAB(Triangle t) {
    Point mid1 = midpoint(t.A, t.C);
    Point mid2 = midpoint(t.B, t.C);
    return {mid1, mid2};
}

Segment midsegmentBC(Triangle t) {
    Point mid1 = midpoint(t.B, t.A);
    Point mid2 = midpoint(t.C, t.A);
    return {mid1, mid2};
}

Segment midsegmentCA(Triangle t) {
    Point mid1 = midpoint(t.C, t.B);
    Point mid2 = midpoint(t.A, t.B);
    return {mid1, mid2};
}

//====================================
//        ТОЧКИ В ТРЕУГОЛЬНИКЕ
//====================================

Point centroid(Triangle t) {
    if (isDeg(t)) {
        return NAP;
    }
    return (S2L(medianA(t)) & S2L(medianB(t))).P1;
}

Point incenter(Triangle t) {
    if (isDeg(t)) {
        return NAP;
    }
    return (S2L(bisectorA(t)) & S2L(bisectorB(t))).P1;
}

Point orthocenter(Triangle t) {
    if (isDeg(t)) {
        return NAP;
    }
    return (S2L(heightA(t)) & S2L(heightB(t))).P1;
}

Point circumcenter(Triangle t) {
    double d = 2 * ((t.A.x * (t.B.y - t.C.y) +
    t.B.x * (t.C.y - t.A.y) +
    t.C.x * (t.A.y - t.B.y)));
    if (iZ(d)) {
        return NAP;
    }
    double ux = ((SQ(t.A.x) + SQ(t.A.y)) * (t.B.y - t.C.y) +
    (SQ(t.B.x) + SQ(t.B.y)) * (t.C.y - t.A.y) +
    (SQ(t.C.x) + SQ(t.C.y)) * (t.A.y - t.B.y)) / d;
    double uy = ((SQ(t.A.x) + SQ(t.A.y)) * (t.C.x - t.B.x) +
    (SQ(t.B.x) + SQ(t.B.y)) * (t.A.x - t.C.x) +
    (SQ(t.C.x) + SQ(t.C.y)) * (t.B.x - t.A.x)) / d;
    return {ux, uy};
}

//====================================
//         СОВПАДЕНИЕ / НЕТ
//====================================

bool operator==(Vector a, Vector b) {
    return iE(a.x, b.x) && iE(a.y, b.y);
}

bool operator!=(Vector a, Vector b) {
    return !(a == b);
}

bool operator==(Point A, Point B) {
    return iE(A.x, B.x) && iE(A.y, B.y);
}

bool operator!=(Point A, Point B) {
    return !(A == B);
}

bool operator==(Line a, Line b) {
    return iE(a.A * b.B, b.A * a.B) && iE(a.B * b.C, b.B * a.C);
}

bool operator!=(Line a, Line b) {
    return !(a == b);
}

bool operator==(Segment a, Segment b) {
    if (a.A == b.A) {
        return a.B == b.B;
    }
    if (a.B == b.A) {
        return a.A == b.B;
    }
    return false;
}

bool operator!=(Segment a, Segment b) {
    return !(a == b);
}

bool operator==(BBox a, BBox b) {
    return (a.mn == b.mn) && (a.mx == b.mx);
}

bool operator!=(BBox a, BBox b) {
    return !(a == b);
}

bool operator==(Circle a, Circle b) {
    return ((a.O == b.O) && iE(a.R, b.R));
}

bool operator!=(Circle a, Circle b) {
    return !(a == b);
}

bool operator==(Triangle a, Triangle b) {
    return (a.A == b.A && a.B == b.B && a.C == b.C);
}

bool operator!=(Triangle a, Triangle b) {
    return !(a == b);
}

bool operator==(BaryCoords a, BaryCoords b) {
    return iE(a.u, b.u) && iE(a.v, b.v) && iE(a.w, b.w);
}

bool operator!=(BaryCoords a, BaryCoords b) {
    return !(a == b);
}

//====================================
//     ДЛИНЫ / ПЛОЩАДИ / ПЕРИМЕТРЫ
//====================================

double lenS(Vector a) {
    return SQ(a.x) + SQ(a.y);
}

double len(Vector a) {
    return sqrt(lenS(a));
}

double lenS(Segment a) {
    return SQ(a.A.x - a.B.x) + SQ(a.A.y - a.B.y);
}

double len(Segment a) {
    return sqrt(lenS(a));
}

double lenS(Line a) {
    return INF;
}

double len(Line a) {
    return INF;
}

double area(Circle o) {
    return PI * SQ(o.R);
}

double perimeter(Circle o) {
    return 2 * PI * o.R;
}

double area2ALG(Triangle t) {
    return (P2V(t.A, t.B) && P2V(t.A, t.C));
}

double areaALG(Triangle t) {
    return area2ALG(t) / 2;
}

double area2(Triangle t) {
    return abs(area2ALG(t));
}

double area(Triangle t) {
    return abs(areaALG(t));
}

double lenS(Circle o) {
    return SQ(perimeter(o));
}

double len(Circle o) {
    return perimeter(o);
}

double lenHeiA(Triangle t) {
    return len(heightA(t));
}

double lenHeiB(Triangle t) {
    return len(heightB(t));
}

double lenHeiC(Triangle t) {
    return len(heightC(t));
}

double lenMedA(Triangle t) {
    return len(medianA(t));
}

double lenMedB(Triangle t) {
    return len(medianB(t));
}

double lenMedC(Triangle t) {
    return len(medianC(t));
}

double lenBisA(Triangle t) {
    return len(bisectorA(t));
}

double lenBisB(Triangle t) {
    return len(bisectorB(t));
}

double lenBisC(Triangle t) {
    return len(bisectorC(t));
}

double lenAB(Triangle t) {
    return t.A > t.B;
}

double lenBC(Triangle t) {
    return t.B > t.C;
}

double lenAC(Triangle t) {
    return t.A > t.C;
}

double perimeter(Triangle t) {
    return lenAB(t) + lenBC(t) + lenAC(t);
}

//====================================
//             УГЛЫ МЕЖДУ
//====================================

double operator^(Vector a, Vector b) {
    if (iZ(len(a)) || iZ(len(b))) {
        return 0;
    }
    return acos((a * b) / ((len(a)) * (len(b))));
}

double operator^(Vector a, Line l) {
    return a ^ direction(l);
}

double operator^(Line l, Vector a) {
    return a ^ l;
}

double operator^(Vector a, Segment AB) {
    return a ^ S2V(AB);
}

double operator^(Segment AB, Vector a) {
    return a ^ AB;
}

double operator^(Line a, Line b) {
    return direction(a) ^ direction(b);
}

double operator^(Line a, Segment AB) {
    return direction(a) ^ S2V(AB);
}

double operator^(Segment AB, Line a) {
    return a ^ AB;
}

double operator^(Segment a, Segment b) {
    return S2V(a) ^ S2V(b);
}

double angleAOB(Point A, Point O, Point B) {
    return P2V(O, A) ^ P2V(O, B);
}

double angleA(Triangle t) {
    return angleAOB(t.B, t.A, t.C);
}

double angleB(Triangle t) {
    return angleAOB(t.A, t.B, t.C);
}

double angleC(Triangle t) {
    return angleAOB(t.A, t.C, t.B);
}

//====================================
//             РАССТОЯНИЯ             >> алгебраическое, > геометрическое, < квадрат
//====================================

// Точка - точка

double operator>>(Point A, Point B) {
    return len(P2V(A, B));
}

double operator>(Point A, Point B) {
    return len(P2V(A, B));
}

double operator<(Point A, Point B) {
    return lenS(P2V(A, B));
}

// Точка - прямая

double operator>>(Point A, Line a) {
    if (iZ(a.A) && iZ(a.B)) {
        return 0;
    }
    return (a.A * A.x + a.B * A.y + a.C) / sqrt(SQ(a.A) + SQ(a.B));
}

double operator>(Point A, Line a) {
    return abs(A >> a);
}

double operator<(Point A, Line a) {
    return SQ(A >> a);
}

// Прямая - точка

double operator>>(Line a, Point A) {
    return (A >> a);
}

double operator>(Line a, Point A) {
    return abs(A >> a);
}

double operator<(Line a, Point A) {
    return SQ(A >> a);
}

// Точка - отрезок

double operator>>(Point A, Segment a) {
    if (A | a) {
        return 0;
    }
    if (iZ(len(a))) {
        return len(P2V(a.A, A));
    }
    if (P2V(a.A, A) * P2V(a.A, a.B) <= 0) {
        return (A > a.A);
    }
    if (P2V(a.B, A) * P2V(a.B, a.A) <= 0) {
        return (A > a.B);
    }
    return (A >> S2L(a));
}

double operator>(Point A, Segment a) {
    return abs(A >> a);
}

double operator<(Point A, Segment a) {
    return SQ(A >> a);
}

// Отрезок - точка

double operator>>(Segment a, Point A) {
    return (A >> a);
}

double operator>(Segment a, Point A) {
    return abs(A >> a);
}

double operator<(Segment a, Point A) {
    return SQ(A >> a);
}

// Точка - окружность

double operator>>(Point A, Circle o) {
    return len(P2V(o.O, A)) - o.R;
}

double operator>(Point A, Circle o) {
    return abs(A >> o);
}

double operator<(Point A, Circle o) {
    return SQ(A >> o);
}

// Окружность - точка

double operator>>(Circle o, Point A) {
    return (A >> o);
}

double operator>(Circle o, Point A) {
    return abs(A >> o);
}

double operator<(Circle o, Point A) {
    return SQ(A >> o);
}

//====================================
//            ПРИНАДЛЕЖНОСТЬ
//====================================

// Точка - прямая

bool operator|(Point A, Line a) {
    return iZ(a.A * A.x + a.B * A.y + a.C);
}

// Точка - отрезок

bool operator|(Point A, Segment a) {
    Line l = S2L(a);
    if (!(A | l)) {
        return false;
    }
    if (A.x >= min(a.A.x, a.B.x) && A.x <= max(a.A.x, a.B.x)) {
        if (A.y >= min(a.A.y, a.B.y) && A.y <= max(a.A.y, a.B.y)) {
            return true;
        }
    }
    return false;
}

// Точка - окружность

bool operator|(Point A, Circle o) {
    return iE(lenS(P2V(o.O, A)), SQ(o.R));
}

// Точка - ББокс

bool operator|(Point A, BBox a) {
    return (A.x >= a.mn.x - EPS && A.x <= a.mx.x + EPS && A.y >= a.mn.y - EPS && A.y <= a.mx.y + EPS);
}

//====================================
//          ПЕРЕСЕКАЮТСЯ ЛИ
//====================================

// ББокс - ББокс

bool operator||(BBox a, BBox b) {
    return a.mn.x <= b.mx.x + EPS && b.mn.x <= a.mx.x + EPS && a.mn.y <= b.mx.y + EPS && b.mn.y <= a.mx.y + EPS;
}

// Прямая - прямая

bool operator||(Line a, Line b) {
    if (a == b) {
        return true;
    }
    if (iE(a.A * b.B, b.A * a.B)) {
        return false;
    }
    return true;
}

// Прямая - отрезок

bool operator||(Line a, Segment b) {
    Line l = S2L(b);
    if (l == a) {
        return true;
    }
    if (!(l || a)) {
        return false;
    }
    double u1 = a.A * b.A.x + a.B * b.A.y + a.C, u2 = a.A * b.B.x + a.B * b.B.y + a.C;
    return (u1 * u2 <= EPS);
}

bool operator||(Segment b, Line a) {
    return (a || b);
}

// Отрезок - отрезок

bool operator||(Segment a, Segment b) {
    Line A = S2L(a), B = S2L(b);
    if (!(S2B(a) || S2B(b))) {
        return false;
    }
    if (A == B) {
        return true;
    }
    if ((A || b) && (a || B)) {
        return true;
    }
    return false;
}

// Окружность - окружность

bool operator||(Circle a, Circle b) {
    double d = len(P2V(a.O, b.O));
    return (d <= a.R + b.R + EPS && d >= abs(a.R - b.R) - EPS);
}

// Прямая - окружность

bool operator||(Line a, Circle o) {
    if (iZ(a.A) && iZ(a.B)) {
        return false;
    }
    return (o.O > a) <= o.R + EPS;
}

bool operator||(Circle o, Line a) {
    return (a || o);
}

// Отрезок - окружность

bool operator||(Segment a, Circle o) {
    double dA = o.O > a.A;
    double dB = o.O > a.B;
    if ((dA <= o.R + EPS) != (dB <= o.R + EPS)) {
        return true;
    }
    if (dA > o.R + EPS && dB > o.R + EPS) {
        return (o.O > a) <= o.R + EPS;
    }
    if (iE(dA, o.R) || iE(dB, o.R)) {
        return true;
    }
    return false;
}

bool operator||(Circle o, Segment a) {
    return (a || o);
}

//====================================
//         ТОЧКА ПЕРЕСЕЧЕНИЯ
//====================================

// Прямая - прямая

IntersectOut operator&(Line a, Line b) {
    if (a == b) {
        return INFP;
    }
    if (!(a || b)) {
        return ZERP;
    }
    double d = a.A * b.B - a.B * b.A;
    Point t = {(-a.C * b.B + a.B * b.C) / d, (-a.A * b.C + a.C * b.A) / d};
    return {t, NAP, 1};
}

// Прямая - отрезок

IntersectOut operator&(Line a, Segment b) {
    if (!(a || b)) {
        return ZERP;
    }
    if (iZ(len(b))) {
        if (b.A | a) {
            return {b.A, NAP, 1};
        }
        return ZERP;
    }
    if (iZ(a.A) && iZ(a.B)) {
        return ZERP;
    }
    Line l = S2L(b);
    if (l == a) {
        return INFP;
    }
    return (a & l);
}

IntersectOut operator&(Segment b, Line a) {
    return (a & b);
}

// Отрезок - отрезок

IntersectOut operator&(Segment a, Segment b) {
    BBox AA = S2B(a), BB = S2B(b);
    if (!(AA || BB)) {
        return ZERP;
    }
    Line A = S2L(a), B = S2L(b);
    if (A == B) {
        if (iZ(len(a)) && iZ(len(b))) {
            if (a.A == b.A || a.A == b.B) {
                return {a.A, NAP, 1};
            }
            return ZERP;
        }
        if (iZ(len(a))) {
            if (a.A | b) {
                return {a.A, NAP, 1};
            }
            return ZERP;
        }
        if (iZ(len(b))) {
            if (b.A | a) {
                return {b.A, NAP, 1};
            }
            return ZERP;
        }
        if (isBTB(AA, BB)) {
            return {BTB(AA, BB), NAP, 1};
        }
        return INFP;
    }
    return (A & b);
}

// Окружность - окружность

IntersectOut operator&(Circle a, Circle b) {
    if (!(a || b)) {
        return ZERP;
    }
    if (a == b) {
        return INFP;
    }
    double d = len(b.O - a.O);
    double x = (SQ(a.R) - SQ(b.R) + SQ(d)) / (2 * d);
    double h = sqrt(max(0.0, SQ(a.R) - SQ(x)));
    Vector dir = normalize(b.O - a.O);
    Point O = a.O + dir * x;
    Vector P0 = normal(dir);
    Point P1 = O + P0 * h;
    Point P2 = O - P0 * h;
    if (iE(h, 0)) {
        return {P1, NAP, 1};
    }
    return {P1, P2, 2};
}

// Прямая - окружность

IntersectOut operator&(Line a, Circle o) {
    if (iZ(a.A) && iZ(a.B)) {
        return ZERP;
    }
    double d = o.O > a;
    double ad = abs(d);
    if (!(a || o)) {
        return ZERP;
    }
    Point P0 = project(o.O, a);
    if (iE(ad, o.R)) {
        return {P0, NAP, 1};
    }

    Vector dir = normalize(direction(a));
    double h = sqrt(max(0.0, SQ(o.R) - SQ(d)));
    Point P1 = P0 + dir * h;
    Point P2 = P0 - dir * h;
    return {P1, P2, 2};
}

IntersectOut operator&(Circle o, Line a) {
    return (a & o);
}

// Отрезок - окружность

IntersectOut operator&(Segment a, Circle o) {
    if (iZ(len(a))) {
        if (a.A | o) {
            return {a.A, NAP, 1};
        }
        return ZERP;
    }
    if (!(a || o)) {
        return ZERP;
    }
    Line l = S2L(a);
    IntersectOut tmp = l & o;
    if (tmp.num <= 0) {
        return tmp;
    }
    vector<Point> pts;
    if (tmp.num >= 1 && (tmp.P1 | a)) {
        pts.push_back(tmp.P1);
    }
    if (tmp.num >= 2 && (tmp.P2 | a)) {
        pts.push_back(tmp.P2);
    }
    if (pts.size() == 2 && pts[0] == pts[1]) {
        pts.pop_back();
    }
    if (pts.empty()) {
        return ZERP;
    }
    if (pts.size() == 1) {
        return {pts[0], NAP, 1};
    }
    return {pts[0], pts[1], 2};
}

IntersectOut operator&(Circle o, Segment a) {
    return (a & o);
}

//====================================
//             КОНВЕРТОРЫ
//====================================

Vector P2V(Point A, Point B) {
    if (A == B) {
        CHECKWARNINGS cout << "Warning: degenerate vector!\n";
    }
    return {B.x - A.x, B.y - A.y};
}

Vector P2V(Point A) {
    if (A == (Point){0, 0}) {
        CHECKWARNINGS cout << "Warning: degenerate vector!\n";
    }
    return {A.x, A.y};
}

Point V2P(Vector a) {
    return {a.x, a.y};
}

Line P2L(Point A, Point B) {
    if (A == B) {
        CHECKWARNINGS cout << "Warning: degenerate line!\n";
        return {0, 0, 0};
    }
    return {A.y - B.y, B.x - A.x, A.x * B.y - B.x * A.y};
}

Segment P2S(Point A, Point B) {
    if (A == B) {
        CHECKWARNINGS cout << "Warning: degenerate segment!\n";
        return {A, A};
    }
    return {A, B};
}

Segment V2S(Vector a) {
    if (iZ(len(a))) {
        CHECKWARNINGS cout << "Warning: degenerate segment!\n";
        return {0, 0, 0, 0};
    }
    return {{0, 0}, {a.x, a.y}};
}

Vector S2V(Segment a) {
    if (iZ(len(a))) {
        CHECKWARNINGS cout << "Warning: degenerate vector!\n";
        return {0, 0};
    }
    return {a.B.x - a.A.x, a.B.y - a.A.y};
}

Line S2L(Segment a) {
    if (a.A == a.B) {
        CHECKWARNINGS cout << "Warning: degenerate line!\n";
        return {0, 0, 0};
    }
    return P2L(a.A, a.B);
}

Line V2L(Vector a) {
    if (iZ(len(a))) {
        CHECKWARNINGS cout << "Warning: degenerate line!\n";
        return {0, 0, 0};
    }
    return P2L({0, 0}, V2P(a));
}

Vector A2V(double alpha) {
    return {cos(alpha), sin(alpha)};
}

Triangle P2T(Point A, Point B, Point C) {
    if (isCol(A, B, C)) {
        CHECKWARNINGS cout << "Warning: degenerate triangle!\n";
    }
    return {A, B, C};
}

Circle P2C(Point A, Point B, Point C) {
    if (isCol(A, B, C)) {
        CHECKWARNINGS cout << "Warning: degenerate circle!\n";
        return {UNDEF, 0};
    }
    return circumscribed(P2T(A, B, C));
}

BaryCoords PaT2Bar(Point P, Triangle t) {
    if (isDeg(t)) {
        CHECKWARNINGS cout << "Warning: degenerate triangle!\n";
        return BARYCENTER;
    }
    double ABC = area(t);
    double PBC = area(P2T(P, t.B, t.C));
    double APC = area(P2T(t.A, P, t.C));
    double ABP = area(P2T(t.A, t.B, P));
    return {PBC / ABC, APC / ABC, ABP / ABC};
}

Point TaBar2P(Triangle t, BaryCoords b) {
    if (isDeg(t)) {
        CHECKWARNINGS cout << "Warning: degenerate triangle!\n";
        return UNDEF;
    }
    return {
        b.u * t.A.x + b.v * t.B.x + b.w * t.C.x,
        b.u * t.A.y + b.v * t.B.y + b.w * t.C.y
    };
}

// ББоксы

BBox P2B(Point A) {
    return {A, A};
}

BBox P2B(Point A, Point B) {
    return {{min(A.x, B.x), min(A.y, B.y)}, {max(A.x, B.x), max(A.y, B.y)}};
}

BBox V2B(Vector a) {
    return P2B(V2P(a), {0, 0});
}

BBox L2B(Line a) {
    if (iZ(a.A) && iZ(a.B)) {
        return {{0, 0}, {0, 0}};
    }
    if (iZ(a.A)) {
        return {{INF, a.C / a.B}, {INF, a.C / a.B}};
    }
    if (iZ(a.B)) {
        return {{a.C / a.A, -INF}, {INF, a.C / a.A}};
    }
    CHECKWARNINGS cout << "Warning: undefined BBox!\n";
    return {UNDEF, UNDEF};
}

BBox S2B(Segment a) {
    return P2B(a.A, a.B);
}

BBox C2B(Circle o) {
    return {{o.O.x - o.R, o.O.y - o.R}, {o.O.x + o.R, o.O.y + o.R}};
}

#endif // GEOMETRYPLUSPLUS_H_INCLUDED

#ifndef FIGURES_H
#define FIGURES_H
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

class Figure {
public:
    virtual ~Figure() = default;
    virtual double area() const = 0;
    virtual operator double() const = 0;
    virtual pair<double, double> center() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    virtual void print(ostream& os) const = 0;
    virtual void read(istream& is) = 0;
};

ostream& operator<<(ostream& os, const Figure& fig);
istream& operator>>(istream& is, Figure& fig);

class Hexagon : public Figure {
private:
    vector<pair<double, double>> vertices;
    double center_x, center_y;
    void calculateCenterFromVertices();

public:
    Hexagon();
    Hexagon(const vector<pair<double, double>>& verts);
    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;
    Hexagon& operator=(const Hexagon& other);
    bool operator==(const Figure& other) const override;
    double area() const override;
    operator double() const override;
    pair<double, double> center() const override;
    void print(ostream& os) const override;
    void read(istream& is) override;
};

class Octagon : public Figure {
private:
    vector<pair<double, double>> vertices;
    double center_x, center_y;
    void calculateCenterFromVertices();

public:
    Octagon();
    Octagon(const vector<pair<double, double>>& verts);
    Octagon(const Octagon& other);
    Octagon(Octagon&& other) noexcept;
    Octagon& operator=(const Octagon& other);
    bool operator==(const Figure& other) const override;
    double area() const override;
    operator double() const override;
    pair<double, double> center() const override;
    void print(ostream& os) const override;
    void read(istream& is) override;
};

class Triangle : public Figure {
private:
    vector<pair<double, double>> vertices;
    double center_x, center_y;
    void calculateCenterFromVertices();

public:
    Triangle();
    Triangle(const vector<pair<double, double>>& verts);
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(const Triangle& other);
    bool operator==(const Figure& other) const override;
    double area() const override;
    operator double() const override;
    pair<double, double> center() const override;
    void print(ostream& os) const override;
    void read(istream& is) override;
};

#endif
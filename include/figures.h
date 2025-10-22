#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

class Figure {
public:
    virtual ~Figure() = default;
    virtual double area() const = 0;
    virtual operator double() const = 0;
    virtual std::pair<double, double> center() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
};

std::ostream& operator<<(std::ostream& os, const Figure& fig);
std::istream& operator>>(std::istream& is, Figure& fig);

class Hexagon : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
    double center_x, center_y;
    void calculateRegularVertices(double side);
    void calculateCenterFromVertices();

public:
    Hexagon();
    Hexagon(double side);
    Hexagon(double side, double cx, double cy);
    Hexagon(const std::vector<std::pair<double, double>>& verts);
    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;
    Hexagon& operator=(const Hexagon& other);
    bool operator==(const Figure& other) const override;
    double area() const override;
    operator double() const override;
    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};

class Octagon : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
    double center_x, center_y;
    void calculateRegularVertices(double side);
    void calculateCenterFromVertices();

public:
    Octagon();
    Octagon(double side);
    Octagon(double side, double cx, double cy);
    Octagon(const std::vector<std::pair<double, double>>& verts);
    Octagon(const Octagon& other);
    Octagon(Octagon&& other) noexcept;
    Octagon& operator=(const Octagon& other);
    bool operator==(const Figure& other) const override;
    double area() const override;
    operator double() const override;
    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};

class Triangle : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;
    double center_x, center_y;
    void calculateRegularVertices(double side);
    void calculateCenterFromVertices();

public:
    Triangle();
    Triangle(double side);
    Triangle(double side, double cx, double cy);
    Triangle(const std::vector<std::pair<double, double>>& verts);
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(const Triangle& other);
    bool operator==(const Figure& other) const override;
    double area() const override;
    operator double() const override;
    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};

#endif
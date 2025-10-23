#include "../include/figures.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

istream& operator>>(istream& is, Figure& fig) {
    fig.read(is);
    return is;
}

Hexagon::Hexagon() {
    vertices = {
        {1.0, 0.0}, {0.5, 0.866}, {-0.5, 0.866},
        {-1.0, 0.0}, {-0.5, -0.866}, {0.5, -0.866}
    };
    calculateCenterFromVertices();
}

Hexagon::Hexagon(const vector<pair<double, double>>& verts) : vertices(verts) {
    calculateCenterFromVertices();
}

Hexagon::Hexagon(const Hexagon& other) 
    : vertices(other.vertices), center_x(other.center_x), center_y(other.center_y) {}

Hexagon::Hexagon(Hexagon&& other) noexcept 
    : vertices(move(other.vertices)), center_x(move(other.center_x)), center_y(move(other.center_y)) {}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        vertices = other.vertices;
        center_x = other.center_x;
        center_y = other.center_y;
    }
    return *this;
}

void Hexagon::calculateCenterFromVertices() {
    center_x = 0;
    center_y = 0;
    for (const auto& vertex : vertices) {
        center_x += vertex.first;
        center_y += vertex.second;
    }
    center_x /= vertices.size();
    center_y /= vertices.size();
}

double Hexagon::area() const {
    double area = 0;
    int n = vertices.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += vertices[i].first * vertices[j].second;
        area -= vertices[j].first * vertices[i].second;
    }
    return abs(area) / 2.0;
}

Hexagon::operator double() const {
    return area();
}

pair<double, double> Hexagon::center() const {
    return {center_x, center_y};
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* hex = dynamic_cast<const Hexagon*>(&other);
    if (!hex || vertices.size() != hex->vertices.size()) return false;
    
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i] != hex->vertices[i]) return false;
    }
    return true;
}

void Hexagon::print(ostream& os) const {
    os << "Hexagon vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << "| Center: (" << center_x << ", " << center_y << ")";
}

void Hexagon::read(istream& is) {
    vertices.clear();
    for (int i = 0; i < 6; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
    calculateCenterFromVertices();
}

Octagon::Octagon() {
    vertices = {
        {1.0, 0.0}, {0.707, 0.707}, {0.0, 1.0}, {-0.707, 0.707},
        {-1.0, 0.0}, {-0.707, -0.707}, {0.0, -1.0}, {0.707, -0.707}
    };
    calculateCenterFromVertices();
}

Octagon::Octagon(const vector<pair<double, double>>& verts) : vertices(verts) {
    calculateCenterFromVertices();
}

Octagon::Octagon(const Octagon& other) 
    : vertices(other.vertices), center_x(other.center_x), center_y(other.center_y) {}

Octagon::Octagon(Octagon&& other) noexcept 
    : vertices(move(other.vertices)), center_x(move(other.center_x)), center_y(move(other.center_y)) {}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        vertices = other.vertices;
        center_x = other.center_x;
        center_y = other.center_y;
    }
    return *this;
}

void Octagon::calculateCenterFromVertices() {
    center_x = 0;
    center_y = 0;
    for (const auto& vertex : vertices) {
        center_x += vertex.first;
        center_y += vertex.second;
    }
    center_x /= vertices.size();
    center_y /= vertices.size();
}

double Octagon::area() const {
    double area = 0;
    int n = vertices.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += vertices[i].first * vertices[j].second;
        area -= vertices[j].first * vertices[i].second;
    }
    return abs(area) / 2.0;
}

Octagon::operator double() const {
    return area();
}

pair<double, double> Octagon::center() const {
    return {center_x, center_y};
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* oct = dynamic_cast<const Octagon*>(&other);
    if (!oct || vertices.size() != oct->vertices.size()) return false;
    
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i] != oct->vertices[i]) return false;
    }
    return true;
}

void Octagon::print(ostream& os) const {
    os << "Octagon vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << "| Center: (" << center_x << ", " << center_y << ")";
}

void Octagon::read(istream& is) {
    vertices.clear();
    for (int i = 0; i < 8; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
    calculateCenterFromVertices();
}

Triangle::Triangle() {
    vertices = {
        {0.0, 0.577}, {-0.5, -0.289}, {0.5, -0.289}
    };
    calculateCenterFromVertices();
}

Triangle::Triangle(const vector<pair<double, double>>& verts) : vertices(verts) {
    calculateCenterFromVertices();
}

Triangle::Triangle(const Triangle& other) 
    : vertices(other.vertices), center_x(other.center_x), center_y(other.center_y) {}

Triangle::Triangle(Triangle&& other) noexcept 
    : vertices(move(other.vertices)), center_x(move(other.center_x)), center_y(move(other.center_y)) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        vertices = other.vertices;
        center_x = other.center_x;
        center_y = other.center_y;
    }
    return *this;
}

void Triangle::calculateCenterFromVertices() {
    center_x = 0;
    center_y = 0;
    for (const auto& vertex : vertices) {
        center_x += vertex.first;
        center_y += vertex.second;
    }
    center_x /= vertices.size();
    center_y /= vertices.size();
}

double Triangle::area() const {
    double area = 0;
    int n = vertices.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += vertices[i].first * vertices[j].second;
        area -= vertices[j].first * vertices[i].second;
    }
    return abs(area) / 2.0;
}

Triangle::operator double() const {
    return area();
}

pair<double, double> Triangle::center() const {
    return {center_x, center_y};
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* tri = dynamic_cast<const Triangle*>(&other);
    if (!tri || vertices.size() != tri->vertices.size()) return false;
    
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i] != tri->vertices[i]) return false;
    }
    return true;
}

void Triangle::print(ostream& os) const {
    os << "Triangle vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << "| Center: (" << center_x << ", " << center_y << ")";
}

void Triangle::read(istream& is) {
    vertices.clear();
    for (int i = 0; i < 3; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
    calculateCenterFromVertices();
}
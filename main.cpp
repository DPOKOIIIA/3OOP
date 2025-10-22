#include "include/figures.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
    vector<unique_ptr<Figure>> figures;
    cout << "Enter figures in one of the following formats:" << endl;
    cout << "For regular figures: [type] regular [side] [center_x] [center_y]" << endl;
    cout << "For custom figures: [type] custom [x1 y1 x2 y2 ...]" << endl;
    cout << "Types: hexagon, octagon, triangle" << endl;
    cout << "Examples:" << endl;
    cout << "  hexagon regular 1.0 0.0 0.0" << endl;
    cout << "  triangle custom 0.0 0.0 1.0 0.0 0.5 0.866" << endl;
    cout << "Enter 'done' to finish input" << endl;
    string type;
    while (true) {
        cin >> type;
        if (type == "done") {
            break;
        }
        if (type == "hexagon") {
            auto hex = make_unique<Hexagon>();
            cin >> *hex;
            figures.push_back(move(hex));
        }
        else if (type == "octagon") {
            auto oct = make_unique<Octagon>();
            cin >> *oct;
            figures.push_back(move(oct));
        }
        else if (type == "triangle") {
            auto tri = make_unique<Triangle>();
            cin >> *tri;
            figures.push_back(move(tri));
        }
        else {
            cout << "Unknown figure type: " << type << endl;
            cout << "Available types: hexagon, octagon, triangle" << endl;
            break;
        }
    }
    
    double totalArea = 0;
    for (const auto& fig : figures) {
        totalArea += static_cast<double>(*fig);
    }
    cout << "\n=== Results ===" << endl;
    cout << "Total area of all figures: " << totalArea << endl;
    cout << "Number of figures: " << figures.size() << endl;
    for (size_t i = 0; i < figures.size(); ++i) {
        cout << "\nFigure " << i + 1 << ":" << endl;
        cout << *figures[i] << endl;
        auto center = figures[i]->center();
        cout << "Center: (" << center.first << ", " << center.second << ")" << endl;
        cout << "Area: " << static_cast<double>(*figures[i]) << endl;
    }
    return 0;
}
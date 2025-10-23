#include <gtest/gtest.h>
#include "figures.h"
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

TEST(FigureTest, HexagonAreaAndCenter) {
    vector<pair<double, double>> vertices = {
        {0, 0}, {2, 0}, {3, 1.732}, {2, 3.464}, {0, 3.464}, {-1, 1.732}
    };
    Hexagon hex(vertices);
    EXPECT_NEAR(static_cast<double>(hex), 10.392, 0.001);
    auto center = hex.center();
    EXPECT_NEAR(center.first, 1.0, 1e-6);
    EXPECT_NEAR(center.second, 1.732, 1e-3);
}

TEST(FigureTest, OctagonAreaAndCenter) {
    vector<pair<double, double>> vertices = {
        {1, 1}, {2, 1}, {3, 1}, {3, 2}, {3, 3}, {2, 3}, {1, 3}, {1, 2}
    };
    Octagon oct(vertices);
    EXPECT_NEAR(static_cast<double>(oct), 4.0, 1e-6);
    auto center = oct.center();
    EXPECT_NEAR(center.first, 2.0, 1e-6);
    EXPECT_NEAR(center.second, 2.0, 1e-6);
}

TEST(FigureTest, TriangleAreaAndCenter) {
    vector<pair<double, double>> vertices = {
        {0, 0}, {3, 0}, {0, 4}
    };
    Triangle tri(vertices);
    EXPECT_NEAR(static_cast<double>(tri), 6.0, 1e-6);
    auto center = tri.center();
    EXPECT_NEAR(center.first, 1.0, 1e-6);
    EXPECT_NEAR(center.second, 1.333, 1e-3);
}

TEST(FigureTest, HexagonInputOutput) {
    Hexagon hex;
    istringstream iss("0 0 2 0 3 1.732 2 3.464 0 3.464 -1 1.732");
    iss >> hex;   
    EXPECT_NEAR(static_cast<double>(hex), 10.392, 0.001);
    ostringstream oss;
    oss << hex;
    string output = oss.str();
    EXPECT_NE(output.find("Hexagon"), string::npos);
    EXPECT_NE(output.find("Center"), string::npos);
}

TEST(FigureTest, OctagonInputOutput) {
    Octagon oct;
    istringstream iss("1 1 2 1 3 1 3 2 3 3 2 3 1 3 1 2");
    iss >> oct;
    EXPECT_NEAR(static_cast<double>(oct), 4.0, 1e-6);
    ostringstream oss;
    oss << oct;
    string output = oss.str();
    EXPECT_NE(output.find("Octagon"), string::npos);
}

TEST(FigureTest, TriangleInputOutput) {
    Triangle tri;
    istringstream iss("0 0 3 0 0 4");
    iss >> tri;
    EXPECT_NEAR(static_cast<double>(tri), 6.0, 1e-6);
    ostringstream oss;
    oss << tri;
    string output = oss.str();
    EXPECT_NE(output.find("Triangle"), string::npos);
}

TEST(CopyMoveTest, HexagonCopyAndMove) {
    vector<pair<double, double>> vertices = {
        {0, 0}, {1, 0}, {1.5, 0.866}, {1, 1.732}, {0, 1.732}, {-0.5, 0.866}
    };
    Hexagon hex1(vertices);
    double original_area = static_cast<double>(hex1);
    Hexagon hex2(hex1);
    EXPECT_NEAR(static_cast<double>(hex2), original_area, 1e-6);
    EXPECT_TRUE(hex1 == hex2);
    Hexagon hex3;
    hex3 = hex1;
    EXPECT_NEAR(static_cast<double>(hex3), original_area, 1e-6);
    EXPECT_TRUE(hex1 == hex3);
    Hexagon hex4(move(hex1));
    EXPECT_NEAR(static_cast<double>(hex4), original_area, 1e-6);
}

TEST(CopyMoveTest, TriangleCopyAndMove) {
    Triangle tri1;
    double original_area = static_cast<double>(tri1);
    Triangle tri2(tri1);
    EXPECT_NEAR(static_cast<double>(tri2), original_area, 1e-6);
    Triangle tri3;
    tri3 = move(tri1);
    EXPECT_NEAR(static_cast<double>(tri3), original_area, 1e-6);
}

TEST(ComparisonTest, FigureEquality) {
    vector<pair<double, double>> vertices1 = {
        {0, 0}, {1, 0}, {1.5, 0.866}, {1, 1.732}, {0, 1.732}, {-0.5, 0.866}
    };
    vector<pair<double, double>> vertices2 = {
        {0, 0}, {1, 0}, {1.5, 0.866}, {1, 1.732}, {0, 1.732}, {-0.5, 0.866}
    };
    Hexagon hex1(vertices1);
    Hexagon hex2(vertices2);
    EXPECT_TRUE(hex1 == hex2);
}

TEST(ComparisonTest, DifferentFiguresNotEqual) {
    vector<pair<double, double>> vertices1 = {
        {0, 0}, {1, 0}, {1.5, 0.866}, {1, 1.732}, {0, 1.732}, {-0.5, 0.866}
    };
    vector<pair<double, double>> vertices2 = {
        {0, 0}, {2, 0}, {3, 1.732}, {2, 3.464}, {0, 3.464}, {-1, 1.732}
    };
    Hexagon hex1(vertices1);
    Hexagon hex2(vertices2);
    EXPECT_FALSE(hex1 == hex2);
}

TEST(ComparisonTest, DifferentTypesNotEqual) {
    Hexagon hex;
    Triangle tri;
    Octagon oct;
    
    EXPECT_FALSE(hex == tri);
    EXPECT_FALSE(hex == oct);
    EXPECT_FALSE(tri == oct);
}

TEST(PolymorphismTest, PolymorphicBehavior) {
    vector<unique_ptr<Figure>> figures;
    figures.push_back(make_unique<Hexagon>());
    figures.push_back(make_unique<Triangle>());
    figures.push_back(make_unique<Octagon>());
    EXPECT_EQ(figures.size(), 3);
    for (const auto& fig : figures) {
        EXPECT_GT(static_cast<double>(*fig), 0);
        auto center = fig->center();
        EXPECT_FALSE(isnan(center.first));
        EXPECT_FALSE(isnan(center.second));
    }
}

TEST(PolymorphismTest, VectorOfFigures) {
    vector<unique_ptr<Figure>> figures;
    figures.push_back(make_unique<Hexagon>());
    figures.push_back(make_unique<Triangle>());
    figures.push_back(make_unique<Octagon>());
    double total_area = 0;
    for (const auto& fig : figures) {
        total_area += static_cast<double>(*fig);
    }
    EXPECT_GT(total_area, 0);
    EXPECT_EQ(figures.size(), 3);
}

TEST(EdgeCaseTest, SmallValues) {
    vector<pair<double, double>> vertices = {
        {0, 0}, {0.001, 0}, {0.0015, 0.000866}, 
        {0.001, 0.001732}, {0, 0.001732}, {-0.0005, 0.000866}
    };
    Hexagon hex(vertices);
    EXPECT_GT(static_cast<double>(hex), 0);
    EXPECT_LT(static_cast<double>(hex), 0.01);
}

TEST(EdgeCaseTest, DefaultConstructors) {
    Hexagon hex;
    Triangle tri;
    Octagon oct;
    EXPECT_GT(static_cast<double>(hex), 0);
    EXPECT_GT(static_cast<double>(tri), 0);
    EXPECT_GT(static_cast<double>(oct), 0);
    auto center_hex = hex.center();
    auto center_tri = tri.center();
    auto center_oct = oct.center();
    EXPECT_FALSE(isnan(center_hex.first));
    EXPECT_FALSE(isnan(center_tri.first));
    EXPECT_FALSE(isnan(center_oct.first));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    cout << "Running simplified test suite for geometric figures" << endl;
    cout << "Testing: Area calculation, Center computation, I/O operations" << endl;
    cout << "Copy/move semantics, Polymorphism, Edge cases" << endl;
    int result = RUN_ALL_TESTS();
    cout << "\n=== Test Summary ===" << endl;
    cout << "Core functionality tested:" << endl;
    cout << "- Area and center calculations" << endl;
    cout << "- Input/output operations" << endl;
    cout << "- Copy and move semantics" << endl;
    cout << "- Figure comparisons" << endl;
    cout << "- Polymorphic behavior" << endl;
    cout << "- Edge cases" << endl;
    return result;
}
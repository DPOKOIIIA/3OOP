#include <gtest/gtest.h>
#include "figures.h"
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

TEST(HexagonTest, AreaCalculationRegular) {
    Hexagon hex(1.0);
    double expected = (3 * sqrt(3) * 1.0 * 1.0) / 2.0;
    EXPECT_NEAR(static_cast<double>(hex), expected, 1e-6);
}

TEST(HexagonTest, AreaCalculationCustom) {
    vector<pair<double, double>> vertices = {
        {0, 0}, {1, 0}, {1.5, 0.866}, {1, 1.732}, {0, 1.732}, {-0.5, 0.866}
    };
    Hexagon hex(vertices);
    EXPECT_GT(static_cast<double>(hex), 0);
}

TEST(HexagonTest, CenterCalculation) {
    Hexagon hex(1.0, 2.0, 3.0);
    auto center = hex.center();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 3.0);
}

TEST(HexagonTest, OutputOperator) {
    Hexagon hex(1.0);
    ostringstream oss;
    oss << hex;
    string output = oss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("Hexagon"), string::npos);
}

TEST(HexagonTest, InputOperatorRegular) {
    Hexagon hex;
    istringstream iss("regular 2.5 1.0 1.0");
    iss >> hex;
    auto center = hex.center();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
    EXPECT_GT(static_cast<double>(hex), 0);
}

TEST(HexagonTest, InputOperatorCustom) {
    Hexagon hex;
    istringstream iss("custom 0 0 1 0 1.5 0.866 1 1.732 0 1.732 -0.5 0.866");
    iss >> hex; 
    EXPECT_GT(static_cast<double>(hex), 0);
    auto center = hex.center();
    EXPECT_NEAR(center.first, 0.5, 1e-6);
    EXPECT_NEAR(center.second, 0.866, 1e-6);
}

TEST(HexagonTest, EqualityOperator) {
    Hexagon hex1(1.0);
    Hexagon hex2(1.0);
    Hexagon hex3(2.0);
    EXPECT_TRUE(hex1 == hex2);
    EXPECT_FALSE(hex1 == hex3);
}

TEST(HexagonTest, CopyConstructor) {
    Hexagon hex1(3.0, 1.0, 2.0);
    Hexagon hex2(hex1);
    EXPECT_TRUE(hex1 == hex2);
}

TEST(HexagonTest, CopyAssignment) {
    Hexagon hex1(1.5, 0.0, 0.0);
    Hexagon hex2(4.0, 5.0, 6.0);
    EXPECT_FALSE(hex1 == hex2);
    hex2 = hex1;
    EXPECT_TRUE(hex1 == hex2);
}

TEST(HexagonTest, MoveConstructor) {
    Hexagon hex1(2.0, 1.0, 1.0);
    double original_area = static_cast<double>(hex1);
    Hexagon hex2(move(hex1));
    EXPECT_NEAR(static_cast<double>(hex2), original_area, 1e-6);
    auto center = hex2.center();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
}

TEST(HexagonTest, MoveAssignment) {
    Hexagon hex1(1.0, 2.0, 3.0);
    double original_area = static_cast<double>(hex1);
    Hexagon hex2(3.0, 4.0, 5.0);
    hex2 = move(hex1);
    EXPECT_NEAR(static_cast<double>(hex2), original_area, 1e-6);
    auto center = hex2.center();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 3.0);
}

TEST(OctagonTest, AreaCalculationRegular) {
    Octagon oct(1.0);
    double area = static_cast<double>(oct);
    EXPECT_GT(area, 0);
    EXPECT_LT(area, 10);
    Octagon oct2(2.0);
    double area2 = static_cast<double>(oct2);
    EXPECT_NEAR(area2 / area, 4.0, 1e-6);
}

TEST(OctagonTest, CenterCalculation) {
    Octagon oct(1.0, 4.0, 5.0);
    auto center = oct.center();
    EXPECT_DOUBLE_EQ(center.first, 4.0);
    EXPECT_DOUBLE_EQ(center.second, 5.0);
}

TEST(OctagonTest, OutputOperator) {
    Octagon oct(1.0);
    ostringstream oss;
    oss << oct;
    string output = oss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("Octagon"), string::npos);
}

TEST(OctagonTest, InputOperatorRegular) {
    Octagon oct;
    istringstream iss("regular 3.0 2.0 2.0");
    iss >> oct;
    auto center = oct.center();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
    EXPECT_GT(static_cast<double>(oct), 0);
}

TEST(OctagonTest, InputOperatorCustom) {
    Octagon oct;
    istringstream iss("custom 0 0 1 0 2 0 2 1 2 2 1 2 0 2 0 1");
    iss >> oct;
    EXPECT_GT(static_cast<double>(oct), 0);
    auto center = oct.center();
    EXPECT_NEAR(center.first, 1.0, 1e-6);
    EXPECT_NEAR(center.second, 1.0, 1e-6);
}

TEST(OctagonTest, EqualityOperator) {
    Octagon oct1(1.0);
    Octagon oct2(1.0);
    Octagon oct3(2.0);
    EXPECT_TRUE(oct1 == oct2);
    EXPECT_FALSE(oct1 == oct3);
}

TEST(OctagonTest, CopyConstructor) {
    Octagon oct1(3.0, 1.0, 2.0);
    Octagon oct2(oct1);
    EXPECT_TRUE(oct1 == oct2);
}

TEST(OctagonTest, CopyAssignment) {
    Octagon oct1(1.5, 0.0, 0.0);
    Octagon oct2(4.0, 5.0, 6.0);
    EXPECT_FALSE(oct1 == oct2);
    oct2 = oct1;
    EXPECT_TRUE(oct1 == oct2);
}

TEST(OctagonTest, MoveConstructor) {
    Octagon oct1(2.0, 1.0, 1.0);
    double original_area = static_cast<double>(oct1);
    Octagon oct2(move(oct1));
    EXPECT_NEAR(static_cast<double>(oct2), original_area, 1e-6);
    auto center = oct2.center();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
}

TEST(OctagonTest, MoveAssignment) {
    Octagon oct1(1.0, 2.0, 3.0);
    double original_area = static_cast<double>(oct1);
    Octagon oct2(3.0, 4.0, 5.0);
    oct2 = move(oct1);
    EXPECT_NEAR(static_cast<double>(oct2), original_area, 1e-6);
    auto center = oct2.center();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 3.0);
}

TEST(TriangleTest, AreaCalculationRegular) {
    Triangle tri(1.0);
    double area = static_cast<double>(tri);
    EXPECT_GT(area, 0);
    EXPECT_LT(area, 2);
    Triangle tri2(2.0);
    double area2 = static_cast<double>(tri2);
    EXPECT_NEAR(area2 / area, 4.0, 1e-6);
}

TEST(TriangleTest, AreaCalculationCustom) {
    vector<pair<double, double>> vertices = {
        {0, 0}, {3, 0}, {0, 4}
    };
    Triangle tri(vertices);
    EXPECT_NEAR(static_cast<double>(tri), 6.0, 1e-6);
}

TEST(TriangleTest, CenterCalculation) {
    Triangle tri(1.0, 10.0, 20.0);
    auto center = tri.center();
    EXPECT_DOUBLE_EQ(center.first, 10.0);
    EXPECT_DOUBLE_EQ(center.second, 20.0);
}

TEST(TriangleTest, OutputOperator) {
    Triangle tri(1.0);
    ostringstream oss;
    oss << tri;
    string output = oss.str();
    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find("Triangle"), string::npos);
}

TEST(TriangleTest, InputOperatorRegular) {
    Triangle tri;
    istringstream iss("regular 2.0 5.0 5.0");
    iss >> tri;
    auto center = tri.center();
    EXPECT_DOUBLE_EQ(center.first, 5.0);
    EXPECT_DOUBLE_EQ(center.second, 5.0);
    EXPECT_GT(static_cast<double>(tri), 0);
}

TEST(TriangleTest, InputOperatorCustom) {
    Triangle tri;
    istringstream iss("custom 0 0 3 0 0 4");
    iss >> tri; 
    EXPECT_NEAR(static_cast<double>(tri), 6.0, 1e-6);
    auto center = tri.center();
    EXPECT_NEAR(center.first, 1.0, 1e-6);
    EXPECT_NEAR(center.second, 1.333333, 1e-6);
}

TEST(TriangleTest, EqualityOperator) {
    Triangle tri1(1.0);
    Triangle tri2(1.0);
    Triangle tri3(2.0);
    EXPECT_TRUE(tri1 == tri2);
    EXPECT_FALSE(tri1 == tri3);
}

TEST(TriangleTest, CopyConstructor) {
    Triangle tri1(3.0, 1.0, 2.0);
    Triangle tri2(tri1);
    EXPECT_TRUE(tri1 == tri2);
}

TEST(TriangleTest, CopyAssignment) {
    Triangle tri1(1.5, 0.0, 0.0);
    Triangle tri2(4.0, 5.0, 6.0);
    EXPECT_FALSE(tri1 == tri2);
    tri2 = tri1;
    EXPECT_TRUE(tri1 == tri2);
}

TEST(TriangleTest, MoveConstructor) {
    Triangle tri1(2.0, 1.0, 1.0);
    double original_area = static_cast<double>(tri1);
    Triangle tri2(move(tri1));
    EXPECT_NEAR(static_cast<double>(tri2), original_area, 1e-6);
    auto center = tri2.center();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
}

TEST(TriangleTest, MoveAssignment) {
    Triangle tri1(1.0, 2.0, 3.0);
    double original_area = static_cast<double>(tri1);
    Triangle tri2(3.0, 4.0, 5.0);
    tri2 = move(tri1);
    EXPECT_NEAR(static_cast<double>(tri2), original_area, 1e-6);
    auto center = tri2.center();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 3.0);
}

TEST(CrossTypeTest, DifferentTypesNotEqual) {
    Hexagon hex(1.0);
    Octagon oct(1.0);
    Triangle tri(1.0);
    EXPECT_FALSE(hex == oct);
    EXPECT_FALSE(hex == tri);
    EXPECT_FALSE(oct == tri);
}

TEST(CrossTypeTest, PolymorphicBehavior) {
    Hexagon hex(2.0);
    Octagon oct(2.0);
    Triangle tri(2.0);
    Figure* fig1 = &hex;
    Figure* fig2 = &oct;
    Figure* fig3 = &tri;
    EXPECT_GT(static_cast<double>(*fig1), 0);
    EXPECT_GT(static_cast<double>(*fig2), 0);
    EXPECT_GT(static_cast<double>(*fig3), 0);
}

TEST(CrossTypeTest, OutputStreamPolymorphism) {
    Hexagon hex(1.0);
    Octagon oct(1.0);
    Triangle tri(1.0);
    ostringstream oss1, oss2, oss3;
    Figure* fig1 = &hex;
    Figure* fig2 = &oct;
    Figure* fig3 = &tri;
    fig1->print(oss1);
    fig2->print(oss2);
    fig3->print(oss3);
    EXPECT_FALSE(oss1.str().empty());
    EXPECT_FALSE(oss2.str().empty());
    EXPECT_FALSE(oss3.str().empty());
}

TEST(CrossTypeTest, AllFiguresInArray) {
    vector<unique_ptr<Figure>> figures;
    figures.push_back(make_unique<Hexagon>(1.0, 0.0, 0.0));
    figures.push_back(make_unique<Octagon>(1.0, 1.0, 1.0));
    figures.push_back(make_unique<Triangle>(1.0, 2.0, 2.0));
    EXPECT_EQ(figures.size(), 3);
    double total_area = 0;
    for (const auto& fig : figures) {
        total_area += static_cast<double>(*fig);
        EXPECT_GT(static_cast<double>(*fig), 0);
    }
    EXPECT_GT(total_area, 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    cout << "Running tests for all 3 figures..." << endl;
    cout << "Testing: Hexagon, Octagon, Triangle" << endl;
    int result = RUN_ALL_TESTS();
    cout << "\n=== Test Summary ===" << endl;
    cout << "All required operations tested:" << endl;
    cout << "- Area calculation (regular and custom polygons)" << endl;
    cout << "- Center calculation" << endl;
    cout << "- Input/output operations" << endl;
    cout << "- Copy/move operations" << endl;
    cout << "- Comparison operations" << endl;
    cout << "- Polymorphic behavior" << endl;
    
    return result;
}
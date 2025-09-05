#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <stdexcept>
// Example of a class to be tested (if you have your own class, replace it)
class Calculator {
public:
    int Add(int a, int b) { return a + b; }
    int Subtract(int a, int b) { return a - b; }
    double Divide(int a, int b) {
        if (b == 0) throw std::invalid_argument("Division by zero!");
        return static_cast<double>(a) / b;
    }
};
// 1. Basic arithmetic tests
TEST(CalculatorTest, Addition) {
    Calculator calc;
    EXPECT_EQ(calc.Add(2, 3), 5);
    EXPECT_EQ(calc.Add(-1, 1), 0);
}
TEST(CalculatorTest, Subtraction) {
    Calculator calc;
    EXPECT_EQ(calc.Subtract(5, 3), 2);
    EXPECT_EQ(calc.Subtract(0, -1), 1);
}
//2. Error handling test
TEST(CalculatorTest, DivisionByZero) {
    Calculator calc;
    EXPECT_THROW(calc.Divide(1, 0), std::invalid_argument);
}
// 3. Tests for strings
TEST(StringTest, Concatenation) {
    std::string a = "Hello";
    std::string b = "World";
    EXPECT_EQ(a + " " + b, "Hello World");
}
//4. Tests for containers
TEST(VectorTest, SizeAndContent) {
    std::vector<int> v = {1, 2, 3};
    ASSERT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v.back(), 3);
}
// 5. User Checks
TEST(CustomTest, ApproximateComparison) {
    double result = 10.0 / 3.0;
    EXPECT_NEAR(result, 3.333, 0.001);  // Проверка с погрешностью
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
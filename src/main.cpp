#include <iostream>
#include <cmath>
using namespace std;

// Функции для математических операций
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

bool divide(double a, double b, double &result) {
    if (b == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return false;
    }
    result = a / b;
    return true;
}

double power(double a, double b) {
    return pow(a, b); // используем стандартную функцию pow из cmath
}

int main() {
    double num1, num2;
    char operation;
    
    cout << "=== НЕПРОСТОЙ КАЛЬКУЛЯТОР ===" << endl;
    cout << "Доступные операции: +, -, *, /, ^" << endl;
    cout << "Введите выражение (например: 5 + 3): ";
    
    cin >> num1 >> operation >> num2;

    double result;
    bool success = true;
    
    switch (operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            success = divide(num1, num2, result);
            break;
        case '^':
            result = power(num1, num2);
            break;
        default:
            cout << "Ошибка: неизвестная операция!" << endl;
            return 1;
    }
    
    if (success) {
            cout << "Результат: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
        }
    
    return 0;
}

#include <iostream>
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

double divide(double a, double b) {
    if (b == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return 0;
    }
    return a / b;
}

int main() {
    double num1, num2;
    char operation;
    
    cout << "=== ПРОСТОЙ КАЛЬКУЛЯТОР ===" << endl;
    cout << "Доступные операции: +, -, *, /" << endl;
    cout << "Введите выражение (например: 5 + 3): ";
    
    cin >> num1 >> operation >> num2;
    
    double result;
    
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
            result = divide(num1, num2);
            break;
        default:
            cout << "Ошибка: неизвестная операция!" << endl;
            return 1;
    }
    
    cout << "Результат: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
    
    return 0;
}

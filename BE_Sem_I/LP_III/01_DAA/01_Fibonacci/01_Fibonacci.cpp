
#include <iostream>
using namespace std;

// Recursive Fibonacci
int fibonacci_recursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative Fibonacci
int fibonacci_iterative(int n)
{
    if (n <= 1)
        return n;

    int a = 0, b = 1, fib;

    for (int i = 2; i <= n; i++)
    {
        fib = a + b;
        a = b;
        b = fib;
    }

    return fib;
}

int main()
{
    int n;

    cout << "Enter a Number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Please enter a non-negative number." << endl;
        return 1;
    }

    cout << "Fibonacci Recursive: " << fibonacci_recursive(n) << endl;
    cout << "Fibonacci Iterative: " << fibonacci_iterative(n) << endl;

    return 0;
}

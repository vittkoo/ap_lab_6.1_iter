#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High) 
{
    for (int i = 0; i < size; i++) 
        a[i] = Low + rand() % (High - Low + 1);
    
}

void Print(const int* a, const int size) 
{
    for (int i = 0; i < size; i++) 
        cout << setw(4) << a[i];
    cout << endl;
}

// обчисл. кількості, суми і заміни елементів на нулі
void ProcessArray(int* a, const int size, int& count, int& sum) 
{
    count = 0;
    sum = 0;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0 && a[i] % 3 == 0) { // непарний і кратний 3
            sum += a[i];
            count++;
            a[i] = 0;
        }
}

int main() {
    srand((unsigned)time(0));

    const int n = 21;
    int b[n];

    int Low = 10, High = 90;

    Create(b, n, Low, High);

    cout << "Start array: " << endl;
    Print(b, n);

    int count = 0, sum = 0;
    ProcessArray(b, n, count, sum);

    cout << "Number of elements that meet the criteria: " << count << endl;
    cout << "Sum of those elements: " << sum << endl;

    cout << "Modified array: " << endl;
    Print(b, n);

    return 0;
}

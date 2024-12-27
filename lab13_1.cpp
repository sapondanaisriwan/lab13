#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[], int, double[]);

int main()
{
    double A[] = {1.2, 3.5, 6.9, 7.8, 12.5, 0.5};
    int N = sizeof(A) / sizeof(A[0]);
    double B[6] = {};
    stat(A, N, B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double source[], int length, double dest[])
{
    double mean = 0, sum = 0, sum2 = 0, sd = 0, geo = 1;
    double min = source[0], max = source[0];
    for (int i = 0; i < length; i++)
    {
        sum += source[i];
        sum2 += 1.0 / source[i];
        geo *= source[i];
        if (min < source[i])
            min = source[i];
        if (max > source[i])
            max = source[i];
    }
    mean = sum / length;
    geo = pow(geo, (1.0 / length));
    double temp = 0;
    for (int i = 0; i < length; i++)
    {
        temp += pow(source[i] - mean, 2);
    }
    sd = pow(temp / length, 0.5);

    dest[0] = mean;
    dest[1] = sd;
    dest[2] = geo;
    dest[3] = length / sum2;
    dest[4] = min;
    dest[5] = max;
}
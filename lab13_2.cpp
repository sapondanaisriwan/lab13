#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool[][M], int, int, int);

void showImage(const bool[][M]);

int main()
{
    bool image[N][M] = {};
    int s, x, y;
    do
    {
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image, s, x, y);
    } while (s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool pos[][M])
{
    cout << "------------------------------------------------------------------------\n";
    for (int row = 0; row < 30; row++)
    {
        cout << "|";
        for (int col = 0; col < 70; col++)
        {
            if (pos[row][col] == 0)
            {
                cout << " ";
            }
            else if (pos[row][col] == 1)
            {
                cout << "*";
            }
            if (col == 69)
            {
                cout << "|\n";
            }
        }
    }
    cout << "------------------------------------------------------------------------\n";
}

void updateImage(bool pos[][M], int size, int row, int column)
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            double formular = sqrt(pow((i - row), 2) + pow((j - column), 2));
            if (formular <= size - 1)
            {
                pos[i][j] = 1;
            }
        }
    }
}
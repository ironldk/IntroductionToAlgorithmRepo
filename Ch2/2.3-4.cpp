#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#define uint unsigned int
void insertion_sort(int A[], uint p, uint r);
void insertion(int A[], uint p, uint q, uint r);
int main()
{
    int A[] = {3, 41, 52, 26, 38, 57, 9, 49};
    for (uint i = 0; i < 8; i++)
    {
        cout << A[i] << " ";
    }
    insertion_sort(A, 0, 7);
    for (uint i = 0; i < 8; i++)
    {
        cout << A[i] << " ";
    }
}

void insertion_sort(int A[], uint p, uint r)
{
    if (p < r)
    {
        uint q = r - 1;
        insertion_sort(A, p, q);
        insertion(A, p, q, r);
    }
}

void insertion(int A[], uint p, uint q, uint r)
{
    int key = A[r];
    for (uint i = q; i >= p; i--)
    {
        if (key < A[i])
        {
            A[i + 1] = A[i];
        }
        else
        {
            A[i + 1] = key;
            break;
        }
    }
}

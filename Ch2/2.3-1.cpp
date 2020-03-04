#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#define uint unsigned int
void merge_sort(int A[], uint p, uint r);
void my_merge(int A[], uint p, uint q, uint r);
int main()
{
    int A[] = {3, 41, 52, 26, 38, 57, 9, 49};
    for (uint i = 0; i < 8; i++)
    {
        cout << A[i] << " ";
    }
    merge_sort(A, 0, 7);
    for (uint i = 0; i < 8; i++)
    {
        cout << A[i] << " ";
    }
}

void merge_sort(int A[], uint p, uint r)
{
    if (p < r)
    {
        uint q = (p + r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        my_merge(A, p, q, r);
    }
}

void my_merge(int A[], uint p, uint q, uint r)
{
    uint n1 = q - p + 1;
    uint n2 = r - q;
    int L[n1], R[n2];
    for (uint i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (uint j = 0; j < n2; j++)
        R[j] = A[q + j + 1];
    uint i = 0;
    uint j = 0;
    for (uint k = p; k <= r; k++)
    {
        if ((i < n1) && ((j == n2) || (L[i] <= R[j])))
        {
            A[k] = L[i];
            i++;
        }
        else if (j < n2)
        {
            A[k] = R[j];
            j++;
        }
    }
}

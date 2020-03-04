#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#define uint unsigned int
uint merge_sort(int A[], uint p, uint r);
uint my_merge(int A[], uint p, uint q, uint r);
int main()
{
    int A[] = {3, 41, 52, 26, 38, 57, 9, 49};
    // int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (uint i = 0; i < 8; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    uint inversion = merge_sort(A, 0, 7);
    for (uint i = 0; i < 8; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << inversion << " inversions were found" << endl;
}

uint merge_sort(int A[], uint p, uint r)
{
    uint inversion = 0;
    if (p < r)
    {
        uint q = (p + r)/2;
        inversion += merge_sort(A, p, q);
        inversion += merge_sort(A, q + 1, r);
        inversion += my_merge(A, p, q, r);
    }
    return inversion;
}

uint my_merge(int A[], uint p, uint q, uint r)
{
    uint inversion = 0;
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
        else// if ((j < n2) && ((i == n1) || (L[i] > R[j])))
        {
            A[k] = R[j];
            inversion += n1 + j + p - k;
            j++;
        }
    }
    return inversion;
}

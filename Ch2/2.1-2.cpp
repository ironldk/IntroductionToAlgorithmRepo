#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    int length = 0;
    cout << "input length: ";
    cin >> length;
    int seq[length];
    cout << "input " << length << " elements: ";
    for (int i = 0; i < length; i++)
    {
        cin >> seq[i];
    }
    for (int i = 0; i < length; i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl;
    int key;
    int c;
    int &i = c;
    for (int j = 1; j < length; j++)
    {
        key = seq[j];
        i = j - 1;
        while ((i >= 0) && (seq[i] < key))
        {
            seq[i + 1] = seq[i];
            i -= 1;
        }
        seq[i + 1] = key;

    }
    for (int i = 0; i < length; i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl;
}

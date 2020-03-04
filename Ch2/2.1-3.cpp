// linear search
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    // Input
    int length = 0;
    cout << "input length: ";
    cin >> length;
    int seq[length];
    int v = 0;
    cout << "input number to find: ";
    cin >> v;
    cout << "input " << length << " integers: ";
    for (int i = 0; i < length; i++)
    {
        cin >> seq[i];
    }

    //Linear search
    for (int i = 0; i < length; i++)
    {
        if (seq[i] == v)
            return i + 1;
    }
    return NULL;
}

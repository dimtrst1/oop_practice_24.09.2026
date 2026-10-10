#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    Array<int> arr(5, 5);

    cout << "Add:" << endl;

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);
    arr.Add(40);

    arr.Show();

    cout << "Size: " << arr.GetSize() << endl;
    cout << "UpperBound: " << arr.GetUpperBound() << endl;
    cout << "IsEmpty: " << arr.IsEmpty() << endl;

    cout << "\nSetAt:" << endl;

    arr.SetAt(1, 100);
    arr.Show();

    cout << "\nGetAt:" << endl;

    cout << arr.GetAt(2) << endl;

    cout << "\nOperator []:" << endl;

    arr[0] = 500;
    arr.Show();

    cout << "\nInsertAt:" << endl;

    arr.InsertAt(2, 777);
    arr.Show();

    cout << "\nRemoveAt:" << endl;

    arr.RemoveAt(1);
    arr.Show();

    cout << "\nAppend:" << endl;

    Array<int> arr2;

    arr2.Add(60);
    arr2.Add(70);

    arr.Append(arr2);
    arr.Show();

    cout << "\nCopy constructor:" << endl;

    Array<int> arr3(arr);
    arr3.Show();

    cout << "\nOperator =:" << endl;

    Array<int> arr4;
    arr4 = arr2;
    arr4.Show();

    cout << "\nGetData:" << endl;

    int* ptr = arr.GetData();

    for (int i = 0; i <= arr.GetUpperBound(); i++)
        cout << ptr[i] << " ";

    cout << endl;

    cout << "\nFreeExtra:" << endl;

    arr.FreeExtra();

    cout << "Size: " << arr.GetSize() << endl;
    arr.Show();

    cout << "\nRemoveAll:" << endl;

    arr.RemoveAll();

    cout << "IsEmpty: " << arr.IsEmpty() << endl;
    cout << "Size: " << arr.GetSize() << endl;

    cout << "\nArray<string>:" << endl;

    Array<string> words;

    words.Add("Hello");
    words.Add("World");
    words.Add("C++");

    words.Show();

    words.InsertAt(1, "Programming");
    words.Show();
}

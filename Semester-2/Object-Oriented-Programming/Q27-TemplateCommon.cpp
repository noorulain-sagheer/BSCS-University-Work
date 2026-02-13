#include <iostream>
using namespace std;
template <class T>
T common(T arr[], int size) 
   {
    for (int i = 0; i < size; i++) 
    {
        arr[i] = arr[i] * 2;
    }

    T mostFrequent = arr[0];
    int maxCount = 0;

    for (int i = 0; i < size; i++) 
    {
        int count = 0;
        for (int j = 0; j < size; j++) 
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    return mostFrequent;
}

int main() 
{
    int arr1[] = {1, 2, 2, 3, 1};
    int size1 = 5;
    cout << "Most Frequent (int): " << common(arr1, size1) << endl;
    double arr2[] = {1.5, 2.0, 1.5, 3.0};
    int size2 = 4;
    cout << "Most Frequent (double): " << common(arr2, size2) << endl;
    return 0;
}

#include <iostream>
using namespace std;
template <class T>
class Queue 
{
    T list[10];
public:
    Queue() 
    {
        for (int i = 0; i < 10; i++)
            list[i] = 0;
    }

    void setQueue(T arr[]) 
   {
        for (int i = 0; i < 10; i++)
            list[i] = arr[i];
    }

    void sort() 
{
        for (int i = 0; i < 10 - 1; i++)
          {
            for (int j = i + 1; j < 10; j++) 
            {
                if (list[i] > list[j])
                {
                    T temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    }

    T max() 
{
        T maxVal = list[0];
        int count = 1;
        for (int i = 1; i < 10; i++) 
        {
            if (list[i] > maxVal) 
            {
                maxVal = list[i];
                count = 1;
            } else if (list[i] == maxVal) 
            {
                count++;
            }
        }
        cout << "Maximum value " << maxVal << " appears " << count << " times." << endl;
        return maxVal;
    }

    T min() 
{
        T minVal = list[0];
        int count = 1;
        for (int i = 1; i < 10; i++) 
        {
            if (list[i] < minVal)
            {
                minVal = list[i];
                count = 1;
            } 
            else if (list[i] == minVal) 
            {
                count++;
            }
        }
        cout << "Minimum value " << minVal << " appears " << count << " times." << endl;
        return minVal;
    }

    void return_queue()
{
        cout << "Queue elements: ";
        for (int i = 0; i < 10; i++)
            cout << list[i] << " ";
        cout << endl;
    }
};

int main()
{
    Queue<int> q1;
    int arr1[10] = {5, 2, 8, 5, 3, 8, 1, 0, 2, 5};
    q1.setQueue(arr1);
    q1.return_queue();
    q1.sort();
    q1.return_queue();
    q1.max();
    q1.min();

    Queue<double> q2;
    double arr2[10] = {1.5, 2.0, 3.5, 2.0, 4.0, 1.5, 5.0, 2.0, 1.5, 3.0};
    q2.setQueue(arr2);
    q2.return_queue();
    q2.sort();
    q2.return_queue();
    q2.max();
    q2.min();

    Queue<float> q3;
    float arr3[10] = {0.5, 1.0, 2.5, 1.0, 3.0, 0.5, 4.0, 1.0, 0.5, 2.0};
    q3.setQueue(arr3);
    q3.return_queue();
    q3.sort();
    q3.return_queue();
    q3.max();
    q3.min();

    return 0;
}

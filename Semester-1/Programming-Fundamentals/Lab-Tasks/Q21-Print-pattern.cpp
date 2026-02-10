#include <iostream>
using namespace std;

int main() {

    int total = 16;   // 4 rows × 4 columns
    for (int i = 1; i <= total; i++)
      {
        if (i <= 4)
            cout << "*";
        else if (i <= 7)
            cout << "*";
        else if (i <= 9)
            cout << "*";
        else if (i <= 10)
            cout << "*";
        else
            cout << "-";

        // Line breaks at 4, 8, 12, 16
        if (i % 4 == 0)
            cout << endl;
    }
    return 0;
}

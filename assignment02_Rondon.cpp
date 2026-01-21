#include <iostream>
#include <string>
using namespace std;

int main()
{
    int length;
    cout << "How many numbers are in your secret sequence?" << endl;
    cin >> length;

    if (length <= 0)
    {
        cout << "Please select a number greater than 0." << endl;
        return 0;
    }

    string decodedmessage = "";

    for (int i = 0; i < length; i++)
    {
        int number;
        cout << "Enter number " << (i + 1) << ": ";
        cin >> number;

        if (number < 1 || number > 26)
        { 
            cout << "Invalid number. Please select a number between 1 and 26." << endl;
            return 0;
        }

        decodedmessage += char('A' + number - 1);
    }

    cout << "Your decoded message is: " << decodedmessage << endl;

    return 0;
}



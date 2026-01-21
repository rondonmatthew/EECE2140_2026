#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n===== Secret Code Menu =====\n";
        cout << "1) Decode a message\n";
        cout << "2) Help / Rules\n";
        cout << "0) Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                // Task 3: validate length using while
                int length;
                cout << "How many numbers are in your secret sequence? ";
                cin >> length;

                while (length <= 0)
                {
                    cout << "Invalid length. Please enter a number greater than 0: ";
                    cin >> length;
                }

                // Decode
                string decodedMessage = "";
                for (int i = 0; i < length; i++)
                {
                    int number;
                    cout << "Enter number " << (i + 1) << ": ";
                    cin >> number;

                    // Task requirement: invalid codes become '?', do NOT stop
                    if (number >= 1 && number <= 26)
                        decodedMessage += char('A' + number - 1);
                    else
                        decodedMessage += '?';
                }

                cout << "Decoded message: " << decodedMessage << endl;
                break;
            }

            case 2:
            {
                cout << "\nRules:\n";
                cout << "1 -> A, 2 -> B, ..., 26 -> Z\n";
                cout << "Any other number is invalid and becomes '?'.\n";
                break;
            }

            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid option. Please choose 1, 2, or 0.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}

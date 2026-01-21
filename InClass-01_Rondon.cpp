#include <iostream>

using namespace std;

    // EX1
    /*
    int x=5;
    int y=10;

    cout<<endl;
    cout<< x + y <<" "<< x * y <<endl;
    cout<<endl;

    return 0;
    */

    // EX2
    /*
    int age;
    cout<< "please enter your age: ";
    cin>> age;
    cout << "you entered: "<< age << endl;
    return 0;
    */

    // EX3
    /*
    int a = 10;
    double b = 3.5;
    
    double result = (double)a / b; //type casting

    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    cout << " result of a/b = " << result << endl;

    return 0;
   */

    // EX4
    /*
    int x = 8;
    int y = 3;

    cout << "x + y = " << x + y << endl;
    cout << "x - y = " << x - y << endl;
    cout << "x * y = " << x * y << endl;
    cout << "x / y = " << x / y << endl;
    cout << "x % y = " << x % y << endl;

    return 0;
    */

    // EX5
    /*
    int temp = 30;

    if (temp > 25)
        cout << "It's hot outside!" << endl;
    else
        cout << "It's cool outside." << endl;

    return 0;    
    */

    // EX6
    /*
    int day = 3;

    switch(day) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        default: cout << "Invalid day"; break;
    }
    return 0;
    */

    // EX7
    /*
    for(int i = 1; i <= 5; i++) {
        cout << "Count: " << i << endl;
    }
    return 0;
    */

   // EX8
   /*
   void greet()
   {
   cout << "Hello from a function!" << endl;
}
int main()
{
    greet();
    return 0;
    */

    // EX9
    /*
    int add(int a, int b)
    {
        return a + b;
    }
        int main()
    {
    
    int result = add(4, 6);
    cout << " Sum = " << result << endl;
    return 0;
    */

// EX10
double area(double width, double height)
{
    return width * height;
}
int main()
{
double w,h;
cout << "Enter width: ";
cin >> w;
cout << "Enter height: ";
cin >> h;

cout << "Area= " << area(w, h) << endl;

return 0;
}

   

   


#include<iostream.h>
using namespace std;/#include<string.h>


int main ()
{
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "pavan" && userPassword == "pavbyk")
        {
            cout << "Welcome Pavan!\n";
            break;
        }
        else if (userName == "ayush" && userPassword == "vilina")
        {
            cout << "Welcome Ayush!\n";
            break;
        }
        else if (userName == "rajat" && userPassword == "rajubaby")
        {
            cout << "Welcome Rajat!\n";
            break;
        }
        else if (userName == "Lufthansa Airlines" && userPassword == "la0987")
        {
            cout << "Welcome Lufthansa admin!\n";
            break;
        }
       else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return 0;
    }

    cout << "Have a good day!!\n";
}
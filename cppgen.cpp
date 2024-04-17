#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;




// Generate a random number.  |  I know NOTHING about cryptography in c++ and what would be the best for generating passwords.
// Plz fix if you know a better way.
int rng_int(int min, int max) {
    if (min > max) {
        system("clear||cls");
        throw invalid_argument("min must be less than or equal to max");
    }
    random_device rd;
    mt19937 gen(rd()); // Seed the Mersenne Twister PRNG with the random device.
    uniform_int_distribution<> dis(min, max); // Create a uniform distribution to generate random integers within the specified range.

    int result = dis(gen);
    return result;
}




// Check to see if user input can be turned into an actual integer.
bool isInt(const string & str) {
    int n;
    istringstream istreamObject(str);
    istreamObject >> noskipws >> n;
    return istreamObject.eof() && !istreamObject.fail();
}




// Need to do to many things just to get user input so I made my own input function.
string input(string m) {
    string i;
    system("clear||cls");
    cout << m;
    getline(cin, i);

    return i;
}





// Our main goodies.
int main() {
    system("clear||cls");
    string ps_msg = "How long do you want your password?: ";
    string length = input(ps_msg);

    system("clear||cls");
    string count_msg = "How many passwords would you like to generate?: ";
    string count = input(count_msg);

    if (isInt(length) && isInt(count))
    {
        int len = stoi(length);
        int cnt = stoi(count);
        string characters = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz01234567890123456789~\"`'!!!!@@@@#$%^&*)(_-+=][}{|\\/><;:?.,";
        // I have multiple of certain characters and numbers because I want them to be used more often.

        system("clear||cls");
        for (int i = 0; i < cnt; ++i) {
            string password = "";
            for (int j = 0; j < len; ++j) {
                int index = rng_int(0, characters.size()-1);
                char letter = characters[index];
                password += letter;
            }
            cout << "Password " << (i + 1) << ": " << password << endl;
            cout << endl;
        }
        return 0;
    }
    else
    {
        system("clear||cls");
        throw invalid_argument("String(s) can\'t be converted to an int.");
    }

}

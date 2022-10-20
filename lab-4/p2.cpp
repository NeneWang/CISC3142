#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{

    // TODO: 1 soda _ 350g _ 1/10 * 0.01 is artificional sweetener

    const double SWEET_PER_CAN = 350 * 0.1 * 0.01;
    const int GRAMS_PER_POUND = 45400 * 0.01;

    // TODO: Ask for the nutrition stats:
    // amount to kill (grams, INT), mass mouse (mass, INT), dieter wieght (pounds, INT),
    // each 100 pounds is 45400g

    int grams_tokill, size_mouse, weight_friend;
    bool wishes_continue = true;

    while (wishes_continue)
    {

        cout << "Enter amount to kill mouse (grams, INT), \n size of that mouse (frams, INT) \n friend's weight (pounds, INT)" << endl;
        cin >> grams_tokill >> size_mouse >> weight_friend;

        // Amount one can drink is if the friend doesnt pass: KILL_MOUSE_POUND * POUND_FRIEND
        int kill_mouse_pound = GRAMS_PER_POUND * size_mouse / grams_tokill;
        cout << "Your friend can drink (in grams): " << weight_friend * kill_mouse_pound << endl;

        cout << "Do you wish to continue (0/1)" <<endl;
        cin >> wishes_continue;
    }

    return 0;
}

// Works well
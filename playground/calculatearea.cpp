#include <iostream>
using namespace std;

int main(){
    cout << "Enter Width and Length of room: ";
    int room_width {0};
    int room_length {0};
    cin >> room_width >> room_length;
    cout << room_width * room_length << " Square feed" << endl;
    return 0;
}



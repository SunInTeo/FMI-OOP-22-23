#include "./src/MyString.hpp"

using namespace std;

int main() {
    MyString str("Hello");
    cout << str.front() << endl;
    cout << str.back() << endl;

    return 0;
}
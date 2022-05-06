#include <iostream>
using namespace std;

int main() {
    cout << "Hello World, I am alive" << endl;

    auto result = (10 <=> 20) > 0;
    cout << result << endl;

    return 0;
}
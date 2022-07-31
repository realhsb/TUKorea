#include <iostream>
using namespace std;
ostream& fivestar(ostream& outs){
    return outs << "*****";
}

int main() {
    cout << "Visual. " << fivestar << endl;
}


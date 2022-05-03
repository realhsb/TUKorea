#include <iostream>
using namespace std;
class Rect;

class RectManager {
    public :
        bool equals(Rect r, Rect s);
};
class Rect {
    int width, height;
    public :
        Rect(int width, int height) {        }
}
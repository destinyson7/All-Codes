#include <bits/stdc++.h>

using namespace std;

class Cpoint
{
    public:
        int x, y, z;

    Cpoint(int tmp_x, int tmp_y, int tmp_z)
    {
        x = tmp_x;
        y = tmp_y;
        z = tmp_z;
    }

    Cpoint operator+(Cpoint b)
    {
        return Cpoint(this -> x + b.x, this -> y + b.y, this -> z + b.z);
    }

    Cpoint operator-(Cpoint b)
    {
        return Cpoint(this -> x - b.x, this -> y - b.y, this -> z - b.z);
    }
};

int main()
{
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    // Cpoint a(x0, y0);
    // Cpoint b(x1, y1);

    // cout << (a + b).x << " " << (a + b).y << endl;
    // cout << (a - b).x << " " << (a - b).y << endl;

    return 0;
}

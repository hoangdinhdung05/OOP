#include<bits/stdc++.h>

using namespace std;

class diem{
    private:
        double x, y;
    public:
        diem(){
            x = y = 0;
        }

        void nhap();
        void xuat();
        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
};

void diem::nhap(){
    cin >> x >> y;
}

double khoangcach(diem a, diem b){
    return sqrt((a.getX()-b.getX())*(a.getX()-b.getX()) + (a.getY()-b.getY())*(a.getY()-b.getY()));
}

void diem::xuat(){
    cout << "Toa do x: " << x << endl << "Toa do y: " << y << endl;
}

int main(){
    diem a, b;
    a.nhap();
    b.nhap();
    a.xuat();
    b.xuat();
    double kc = khoangcach(a, b);
    cout << kc;
    return 0;
}
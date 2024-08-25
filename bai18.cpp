#include<bits/stdc++.h>

using namespace std;

class ps1{
    protected:
        int tu, mau;
    public:

        ps1(int tu = 0, int mau = 1){
            this->tu = tu;
            this->mau = mau;
        }

        void toigian();
        void nhap(){
            cin >> tu;
            do{
                cin >> mau;
                if(mau == 0){
                    cout << "Khong hop le\n";
                }
            } while(mau == 0);
        }
        void in(){
            cout << tu << "/" << mau << endl;
        }

        int getTu(){
            return tu;
        }

        int getMau(){
            return mau;
        }
};

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void ps1::toigian(){
    int uc = gcd(tu, mau); // Đoạn này đã sửa
    tu /= uc;
    mau /= uc;
}

int main(){
    ps1 p;
    p.nhap();
    p.toigian();
    p.in();
    return 0;
}

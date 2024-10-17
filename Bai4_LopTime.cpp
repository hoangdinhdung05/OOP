#include<bits/stdc++.h>

using namespace std;

class thoigian{
    private:
        int gio, phut, giay;
    public:
        thoigian(){
            gio = phut = giay = 0;
        }
        thoigian(int gio, int phut, int giay){
            this->gio = gio;    
            this->phut = phut;
            this->giay = giay;
        }

        ~thoigian(){
            gio = phut = giay = 0;
        }

        void nhap();
        void xuat();

        thoigian& operator++ ();
        thoigian& operator-- ();
};

void thoigian::nhap(){
    cin >> gio >> phut >> giay;
}

void thoigian::xuat(){
    cout << gio << ":" << phut << ":" << giay << endl;
}

thoigian& thoigian::operator++ (){
    giay++;
    if(giay == 60){
        giay = 0;
        phut++;
        if(phut == 60){
            phut = 0;
            gio++;
            if(gio == 24){
                gio = 0;
            }
        }
    }
    return *this;
}

thoigian& thoigian::operator-- (){
    giay--;
    if(giay == -1){
        giay = 59;
        phut--;
        if(phut == -1){
            phut = 59;
            gio--;
            if(gio == -1){
                gio = 23;
            }
        }
    }
    return *this;
}

int main(){
    thoigian t;
    t.nhap();
    t.xuat();
    cout << "t++ = ";
    ++t;
    t.xuat();
    cout << "t-- = ";
    --t;
    t.xuat();
    return 0;
}
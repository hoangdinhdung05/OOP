#include<bits/stdc++.h>

using namespace std;

class canbo{
    protected:
        string ten, ns, gt, dc;
    public:
        canbo(){
            ten = ns = gt = dc = "";
        }
        canbo(string ten, string ns, string gt, string dc){
            this->ten = ten;
            this->ns = ns;
            this->gt = gt;
            this->dc = dc;
        }

        void nhap();
        void xuat();
};

void canbo::nhap(){
    getline(cin, ten);
    cin >> ns >> gt >> dc;
}

void canbo::xuat(){
    cout << ten << " " << ns << " " << gt << " " << dc << " ";
}

class congnhan : public canbo{
    private:
        string bac;
    public:
        congnhan(){
            bac = "";
        }

        congnhan(string bac){
            this->bac = bac;
        }

        void nhap();
        void xuat();
};

void congnhan::nhap(){
    canbo::nhap();
    cin >> bac;
}

void congnhan::xuat(){
    canbo::xuat();
    cout << bac << endl;
}



int main(){

    return 0;
}
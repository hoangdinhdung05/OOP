#include<bits/stdc++.h>

using namespace std;

class dathuc{
    private:
        int bac;
        int heso[100];
    public:
        dathuc(){
            bac = 0;
            memset(heso, 0, sizeof(heso));
        }

        void nhap();
        void xuat();

        dathuc operator + (dathuc);
        dathuc operator - (dathuc);
};

void dathuc::nhap(){
    cin >> bac;
    for(int i = bac; i >= 0; i--){
        cin >> heso[i];
    }
}

void dathuc::xuat(){
    for(int i = bac; i >= 0; i--){
        if(bac == i){
            if(heso[bac] > 0){
                cout << heso[bac] << "x^" << i;
            }
            else{
                cout << "- " << abs(heso[bac]) << "x^" << i;
            }
        }
        else if(i > 0 && i < bac){
            if(heso[i] > 0){
                cout << " + " << heso[i] << "x^" << i;
            }
            else{
                cout << " - " << heso[i] << "x^" << i;
            }
        }
        else{
            if(heso[0] > 0){
                cout << " + " << heso[0] << endl;
            }
            else cout << " - " << abs(heso[0]) << endl;
        }
    }
}

dathuc dathuc::operator+ (dathuc a){
    dathuc b;
    b.bac = max(this->bac, a.bac);
    for(int i = 0; i <= b.bac; i++){
        b.heso[i] += this->heso[i] + a.heso[i];
    }
    return b;
}

dathuc dathuc::operator- (dathuc a){
    dathuc b;
    b.bac = max(this->bac, a.bac);
    for(int i = 0; i <= b.bac; i++){
        b.heso[i] += this->heso[i] - a.heso[i];
    }
    return b;
}

int main(){
    dathuc a, b, c;
    a.nhap();
    a.xuat();
    b.nhap();
    b.xuat();
    c = a - b;
    cout << endl;
    c.xuat();
    return 0;
}
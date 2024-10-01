#include<bits/stdc++.h>

using namespace std;

class matran{
    private:
        int bac;
        int heso[100][100];
    public:
        matran(){
            bac = 0;
            memset(heso, 0, sizeof(heso));
        }

        friend istream& operator >> (istream& in, matran&);
        friend ostream& operator << (ostream& out, matran);

        matran operator + (matran);
        matran operator - (matran);
        matran operator * (matran);
};

istream& operator >> (istream& in, matran& a){
    in >> a.bac;
    for(int i = 0; i < a.bac; i++){
        for(int j = 0; j < a.bac; j++){
            in >>  a.heso[i][j];
        }
    }
    return in;
}

ostream& operator << (ostream& out, matran a){
    for(int i = 0; i < a.bac; i++){
        for(int j = 0; j < a.bac; j++){
            out << a.heso[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

matran matran::operator+ (matran a){
    matran b;
    b.bac = a.bac;
    if(a.bac == this->bac){
        b.bac = a.bac;
        for(int i = 0; i < a.bac; i++){
            for(int j = 0; j < a.bac; j++){
                b.heso[i][j] = this->heso[i][j] + a.heso[i][j];
            }
        }
    }
    else{
        cout << "Khong the tinh\n";
    }
    return b;
}

matran matran::operator- (matran a){
    matran b;
    if(a.bac == this->bac){
        b.bac = a.bac;
        for(int i = 0; i < a.bac; i++){
            for(int j = 0; j < a.bac; j++){
                b.heso[i][j] = this->heso[i][j] - a.heso[i][j];
            }
        }
    }
    else cout << "Khong the tinh\n";
    return b;
}

matran matran::operator* (matran a){
    matran b;
     if(a.bac == this->bac){
        b.bac = this->bac;
        for(int i = 0; i < this->bac; i++){
            for(int j = 0; j < this->bac; j++){
                b.heso[i][j] = 0;  // Khởi tạo giá trị cho ma trận b
                for(int k = 0; k < this->bac; k++){
                    b.heso[i][j] += this->heso[i][k] * a.heso[k][j];
                }
            }
        }
    } else {
        cout << "Khong the tinh\n";
    }
    return b;
}

int main(){
    matran a, b, c, d;
    cin >> a >> b;
    // c = a + b;
    // cout << endl;
    // cout << c;
    // c = a - b;
    // cout << endl << c << endl;
    d = a * b;
    cout << d;
    return 0;
}
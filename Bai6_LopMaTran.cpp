#include<bits/stdc++.h>

using namespace std;

class matran{
    private:
        int hang, cot;
        int heso[100][100];
    public:
        matran(){
            hang = cot = 0;
            memset(heso, 0, sizeof(heso));
        }

        void nhap(){
            cin >> hang >> cot;
            for(int i = 0; i < hang; i++){
                for(int j = 0; j < cot; j++){
                    cin >> heso[i][j];
                }
            }
        }

        void xuat(){
            for(int i = 0; i < hang; i++){
                for(int j = 0; j < cot; j++){
                    cout << heso[i][j] << " ";
                }
                cout << endl;
            }
        }

        matran operator+ (matran a){
            matran b;
            b.hang = a.hang;
            b.cot = a.cot;
            for(int i = 0; i < a.hang; i++){
                for(int j = 0; j < a.cot; j++){
                    b.heso[i][j] = a.heso[i][j] + heso[i][j];
                }
            }
            return b;
        }

        matran operator- (matran a){
            matran b;
            b.hang = a.hang;
            b.cot = a.cot;
            for(int i = 0; i < a.hang; i++){
                for(int j = 0; j < a.cot; j++){
                    b.heso[i][j] = a.heso[i][j] - heso[i][j];
                }
            }
            return b;   
        }

        void tongPT(matran a){
            int tongH1 = 0, tongC1 = 0, tongHc = 0, tongcC = 0;
            for(int i = 0; i < a.hang; i++){
                tongH1 += a.heso[i][cot - 1];
            }
            for(int j = 0; j < a.cot; j++){
                tongC1 += a.heso[hang - 1][j];
            }
            for(int i = 0; i < a.hang; i++){
                for(int j = 0; j < a.cot; j++){
                    if(i == 0 && j == cot - 1){
                        tongHc += a.heso[i][j];
                    }
                    if(i == hang - 1 && j == cot - 1){
                        tongcC += a.heso[i][j];
                    }
                }
            }
            cout << tongH1 << " " << tongC1 << " " << tongHc << " " << tongcC << endl;
        }
};

int main(){
    matran a, b;
    a.nhap();
    b.nhap();
    a.xuat(); cout << endl;
    b.xuat(); cout << endl;
    matran c = a + b;
    matran d = a - b;
    c.xuat(); cout << endl;
    d.xuat(); cout << endl;
    a.tongPT(a); cout << endl;
    b.tongPT(b);
    return 0;
}
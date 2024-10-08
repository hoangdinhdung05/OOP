#include<bits/stdc++.h>

using namespace std;

class Number{
    private:
        int value, _max, _min;
    public:
        Number(){
            value = _max = _min = 0;
        }

        Number(int value, int _max, int _min){
            this->value = value;
            this->_max = _max;
            this->_min = _min;
        }

        void nhap(){
            //xu li ngoai le khi nhap thoa man dk _min < value < _max
            cin >> value >> _min >> _max;
            try
            {
                /* code */
                if(value > _min || value < _max){
                    throw invalid_argument("Value khong hop le");
                }
            }
            catch(invalid_argument& e)
            {
                cout << "Loi: " << e.what() << endl;
            }
        }


        bool check(){
            if(value < 2 ) return false;
            for(int i = 2; i <= sqrt(value); i++){
                if(value % i == 0) return false;
            }
            return value > 1;
        }
};

int main(){
    Number a;
    a.nhap();
    if(a.check()){
        cout << "YES\n";
    }
    else cout << "NO\n";
    return 0;
}
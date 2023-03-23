#include <iostream>
using namespace std;

class Complex{
    int r,c;
public:
    Complex(){
        r = 0;
        c = 0;
    }
    Complex(int r,int c){
        this->r = r;
        this->c = c;
    }
    void setValues(){
        cout << "Enter the real part: ";
        cin >> r;
        cout << "Enter the complex part: ";
        cin >> c;
    }
    void getValues(){
        cout << ">> " << r << " + j" << c << endl;
    }
    Complex operator -(Complex &obj){
        Complex temp;
        temp.r = obj.r - r;
        temp.c = obj.c - c;
        return temp;
    }
    Complex operator +(Complex &obj){
        Complex temp;
        temp.r = r + obj.r;
        temp.c = c + obj.c;
        return temp;
    }
    Complex operator *(Complex &obj){
        Complex temp;
        temp.r = r*obj.r - obj.c*c;
        temp.c = r*obj.c + c*obj.r;
        return temp;
    }
    friend istream& operator >>(istream& temp, Complex &obj);
    friend ostream& operator <<(ostream& temp, Complex &obj);
};

istream& operator >>(istream& temp, Complex &obj){
    cout << "Enter the real and imaginary part of the complex number respectively: ";
    temp >> obj.r >> obj.c;
    return temp;
}
ostream& operator <<(ostream& temp, Complex &obj){
    temp << ">> " << obj.r << " + i" << obj.c << endl;
    return temp;
}

int main()
{
    Complex obj;
    while(true){
        cout << "1. Enter a complex number." << endl;
        cout << "2. Print the complex number." << endl;
        cout << "3. Multiply with another complex number." << endl;
        cout << "4. Subtract from another complex number." << endl;
        cout << "5. Add with another complex number." << endl;
        cout << "0. Exit" << endl;
        int choice;
        cout << ">> ";
        cin >> choice;
        if(choice == 1){
            cin >> obj;
        }
        else if(choice == 2){
            cout << obj;
        }
        else if(choice == 3){
            Complex third;
            cin >> third;
            Complex multiply = obj*third;
            cout << multiply;
        }
        else if(choice == 4){
            Complex x;
            cin >> x;
            Complex subtract = obj - x;
            cout << subtract;
        }
        else if(choice == 0){
            break;
        }
        else if(choice == 5){
            Complex x;
            cin >> x;
            Complex subtract = obj + x;
            cout << subtract;
        }
        cout << endl << endl;
    }
    return 0;
}

/*

    friend ostream& operator <<(ostream& temp, Complex &obj);
    friend istream& operator >>(istream& temp, COmplex &obj);

    ostream& operator <<(ostream& temp, Complex &obj){
        temp << obj.r << " + i" << obj.c << endl;
        return temp;
    }
    
    istream& operator >>(Complex& temp, Complex &obj){
        temp >> obj.r >> obj.c;
        return temp;
    }

*/
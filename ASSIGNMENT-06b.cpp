#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Item{
    string name;
    int itemCode;
    float cost;
    int quantity;
public:
    Item(){
        name = "";
        itemCode = 0;
        cost = 0.0;
        quantity = 0;
    }
    static bool cmp(Item &it1, Item &it2){
        return it1.cost < it2.cost;
    }
    void setValues(){
        cout << "ENTER THE NAME OF THE ITEM: ";
        getline(cin,name);
        cout << "ENTER THE CODE OF THE ITEM: ";
        cin >> itemCode;
        cout << "ENTER THE COST OF THE ITEM: ";
        cin >> cost;
        cout << "ENTER THE QUANTITY OF THE ITEM: ";
        cin >> quantity;
    }
    void displayValues(){
        cout << "--------------------------------------------------" << endl;
        cout << "ITEM NAME: " << name << endl;
        cout << "ITEM CODE: " << itemCode << endl;
        cout << "ITEM COST: " << cost << endl;
        cout << "ITEM QUANTITY: " << quantity << endl;
        cout << "--------------------------------------------------" << endl;
    }
    string getName(){
        return name;
    }
};

int main()
{
    vector<Item> items;
    while(true){
        cout << "1. Add item data." << endl;
        cout << "2. Read item data." << endl;
        cout << "3. Sort items as per cost." << endl;
        cout << "4. Search item." << endl;
        cout << "0. Exit" << endl;
        int choice;
        cout << ">> ";
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            Item obj;
            obj.setValues();
            items.push_back(obj);
        }
        else if(choice == 2){
            for(int i=0;i<items.size();i++){
                items[i].displayValues();
            }
        }
        else if(choice == 3){
            sort(items.begin(),items.end(),Item::cmp);
        }
        else if(choice == 4){
            cout << "Enter the name of item: ";
            string s;
            getline(cin,s);
            bool present = false;
            int n = items.size();
            for(int i=0;i<n;i++){
                if(items[i].getName() == s){
                    present = true;
                    items[i].displayValues();
                    break;
                }
            }
            if(!present){
                cout << "-----------------" << endl;
                cout << "ITEM NOT PRESENT." << endl;
                cout << "-----------------" << endl;
            }
        }
        else if(choice == 0){
            cout << "GoodBye!" << endl;
            break;
        }
    }
    return 0;
}
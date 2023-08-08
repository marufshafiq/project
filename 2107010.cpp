#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include<map>
#include<conio.h>

using namespace std;

class info {
private:
    string company,owner;
    int money;
public:
    friend class products;

    void companyinfo() {
        cout << "Enter Company Name: ";
        getline(cin,company);
        cout << "Enter your Name: ";
         getline(cin,owner);
        cout << "Invested Ammount: ";
        cin >> money;

    cout<<money<<" Tk Invested Successfullly by "<<owner<<endl;
    }
};

class products {
private:
    string productt,raw;
    double price, pquantity, quantity,sum=0;
vector<string>p;

public:
    friend class factory;
    friend class sell;

    void product(info &t) {


        cout << "Enter Product Name: ";
        cin >> productt;
        p.push_back(productt);
        cout << "Number of raw materials needed for the product: ";
        cin >> pquantity;
        for (int i = 0; i < pquantity; i++) {
            cout << endl << "Name of raw material no. " << i + 1 << ": ";
            cin.ignore();
            getline(cin, raw);
            cout << "Quantity of raw materials (kg/litre): ";
            cin >> quantity;

            cout << "Enter the Price of raw material no. " << i + 1 << " (Per kg/litre): ";
            cin >> price;
            sum += price * quantity;
        }
        t.money -= sum;
    }
};

class factory {
    int  num = 200;

public:
    friend class sell;
    void status(products &q) {
      cout<<endl<<"Production complete "<<endl<<"Production details :"<<endl<<endl;
    {
        cout<<"Name of Product : "<<q.productt<<endl;
        cout<<"Number of production : "<<num<<" pieces "<<q.productt<<endl;
       cout<<"Production cost : "<<q.sum<<" Taka"<<endl;
       cout<<"Total cost : "<<q.sum<<" Taka"<<endl;
    }
    }
};

class employee {
private:
    vector<string>name;
    vector<string>id;
    vector<string>contact;
 int j,day;
 char c='y';
public:
    void data() {
    string ename;
    string eid;
    string econtact;
    while(c=='y')
        {cout << "Enter Employee name: ";
        getline(cin,ename);
       getline(cin, ename);
        name.push_back(ename);
        cout << "Enter Employee id: ";
        getline(cin, eid);
        id.push_back(eid);
        cout << "Enter Contact Number: ";
        getline(cin, econtact);
        contact.push_back(econtact);
        cout << endl<<"Do you want to add more employees (y/n)? ";
        char ch;
        cin >> ch;
        c=ch;
        }
    }

void display() {
    cout << "Display all employee details " << endl << endl;
    for (int i = 0; i < name.size(); i++) {
        cout << "Employee's name: " << name[i] << endl;
        cout << "Employee id: " << id[i] << endl;
        cout << "Contact Number: " << contact[i] << endl;
    }
}
};

    class sell
    {  
    double l,k,taka,sproduct=0,h=0,prof=0;double x=0;
public:
    friend class report;
    void show(products &t,factory &e)
    {
    for(int i=0;i<t.p.size();i++)
        {
        cout<<"Product name : "<<t.p[i];
        cout<<"In Stock: "<<e.num<<" Pieces"<<endl;
        }
        cout<<"Press 1 to sell "<<endl;
        cin>>l;
        if(l==1)
        {
            cout<<"quantity of products to sell: "<<endl;
            cin>>k;
            sproduct+=k;
            cout<<"Set the selling price (Per piece) : "<<endl;
            cin>>taka;
            cout<<" Total selling price : "<<k*taka<<endl<<endl;
            h+=k*taka;
cout<<"Production cost :"<<t.sum<<endl<<endl;
x+=t.sum;
cout<<"Profit : "<<k*taka-(t.sum)<<endl;
prof+=k*taka-(t.sum);
        } else return;
    }
};
class report
{ double per;
public:
    void reportshow(sell &g)
    {cout<<endl<<endl<<endl<<endl;
        cout<<"Total sold products : "<<g.sproduct<<endl;
        cout<<"Total cost : "<<g.x<<endl;
        cout<<"Total money gain : "<<g.h<<endl;
        cout<<"Total profit : "<<g.prof<<endl;
    }
};


int main() {
    int  m, v;
    info in;
    vector<products>b;
   vector< factory> c;
    employee d;
    sell s;
    report r;
    int o=1;
        in.companyinfo();
        l3:
        cout << "1. Production" << endl << "2. Employee management" <<endl<<"3. Sell"<< endl;
        cin >> v;

        if (v == 1) {

            products bb;
            bb.product(in);
            factory cc;

              b.push_back(bb);

            cout << "Press 1 to go to the factory section"<< endl;
            cin >> m;
            if (m == 1) {
                system("cls");
                int x;
                cout << "Press 1 to start all machines"<< endl;
                cin >> x;
                for (int i=0;i<b.size();i++)
                {
                cc.status(b[i]);
                c.push_back(cc);
                cout <<endl<< "Press 1 to produce more products or 0 to exit" << endl;
                
                goto l3;
                
                }
            }
        }
        l2:
        if (v == 2) {
            int b;
            cout << "1. Show all employee data" << endl << "2. Add employee" << endl;
            cin >> b;
            if (b == 2) {
                d.data();

                goto l2;
            }
if(b==1)
{
    d.display();
    goto l3;

}
 }
    
if(v==3)
        {
        for (int i=0;i<b.size();i++)
          s.show(b[i],c[i]);
          for(int i=0;i<4;i++)
          {
              Sleep(1000);
          }
          system("cls");

    cout<<endl<<endl<<endl;

    cout<<"LOADING SELLING REPORT";

    for(int i=0;i<4;i++ )
    {
       cout<<".";
            Sleep(1000);
    }
    system("cls");

r.reportshow(s);
char ch;
cout<<endl<<endl<<"Press space bar to go back"<<endl;
ch=_getch();
if(ch==' ')
    goto l3;

         }
         getch();
      return 0;  
}
    




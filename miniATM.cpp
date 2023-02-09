#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string>

using namespace std;

class atm{

   private:
           long int acc_no;
           string name;
           int PIN;
           double balance;
           string mob_no;
   public:
          void setData(long int acc_no1, string name1, int PIN1, double balance1, string mob_no1){
          acc_no=acc_no1;
          name=name1;
          PIN=PIN1;
          balance=balance1;
          mob_no=mob_no1;
          }

          long int getAcc_no(){
          return acc_no;
          }

          string getname(){
          return name;
          }

          int getpin(){
          return PIN;
          }

          double getbalance(){
          return balance;
          }

          string getmobno(){
          return mob_no;
          }

          void setmobile(string mob_prev, string mob_new)
          {
          if(mob_prev==mob_no){
            mob_no=mob_new;
            cout<<endl<<"Mobile number successfully updated";
            }
            else{
                cout<<endl<<"Mobile number does not match";
            }
            _getch();

          }
          void cashwithdraw(int amount1){
          if(amount1>0 && amount1<balance){
            balance-=amount1;
            cout<<endl<<"Please collect your cash";
            cout<<endl<<"Available balance:"<<balance;
            _getch();
          }
          else{
            cout<<endl<<"Invalid amount or insufficient balance";
            _getch();
          }
          }

};


int main()
{
    int choice=0;
    int entpin;
    long int enteraccno;
    system("cls");
     atm user1;

    user1.setData(1234567, "Chinmay", 6071, 50000.00, "8448510875");

    do{
        system("cls");
        cout<<endl<<"****WELCOME****";
        cout<<endl<<"Enter your account number\n";
        cin>>enteraccno;
        cout<<endl<<"enter PIN\n";
        cin>>entpin;

        if((enteraccno==user1.getAcc_no()) && (entpin==user1.getpin())){
            do{
                int amount=0;
                string oldmobno, newmobno;
                system("cls");
                cout<<endl<<"***WELCOME***";
                cout<<endl<<"1.Check balance";
                cout<<endl<<"2.Cash withdrawal";
                cout<<endl<<"3.Show user details";
                cout<<endl<<"4.Update mobile number";
                cout<<endl<<"5.exit\n";
                cin>>choice;

                switch(choice){

                case 1:
                       cout<<endl<<"Your bank balance is:"<<user1.getbalance();
                       _getch();
                       break;
                case 2:
                       cout<<endl<<"Enter amount\n";
                       cin>>amount;
                       user1.cashwithdraw(amount);
                       break;
                case 3:
                       cout<<endl<<"User details are:-";
                       cout<<endl<<"->Account no:"<<user1.getAcc_no();
                       cout<<endl<<"->Name:"<<user1.getname();
                       cout<<endl<<"->Balance:"<<user1.getbalance();
                       cout<<endl<<"->Mobile no:"<<user1.getmobno();
                       _getch();
                       break;

                case 4:
                      cout<<endl<<"Enter old mobile no.";
                      cin>>oldmobno;
                      cout<<endl<<"Enter new mobile no.\n";
                      cin>>newmobno;
                      user1.setmobile(oldmobno, newmobno);
                      break;

                case 5:
                       exit(0);
                default:
                        cout<<endl<<"Enter valid data";

                }
            }while(1);
        }
        else
            cout<<endl<<"Invalid user details";

    }while(1);
    return 0;
}

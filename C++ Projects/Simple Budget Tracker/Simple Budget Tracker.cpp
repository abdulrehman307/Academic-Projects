#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class user
{
private:


    string email;
    string phonenumber;
    string address;



public:
     int userid;
      string name;
    friend void ManageUser();

    void setUserID(int uID)
    {
        userid = uID;
    }

    void setName(string n)
    {
        name = n;
    }

    void setEmail(string e)
    {
        email = e;
    }

    void setPhoneNumber(string pnumber)
    {
        phonenumber = pnumber;
    }

    void setAddress(string addre)
    {
        address = addre;
    }

    int getUserID()
    {
        return userid;
    }

    string getName()
    {
        return name;
    }

    string getEmail()
    {
        return email;
    }

    string getphonenumber()
    {
        return phonenumber;
    }

    string getAddress()
    {
        return address;
    }

    user()
    {
        userid = 0;
        name = "";
        email = "";
        phonenumber = "";
        address = "";

    }

    user(int uID, string n, string e, string pNumber, string addr)
    {
        userid = uID;
        name = n;
        email = e;
        phonenumber = pNumber;
        address = addr;

    }
    ~user()
    {

    }
    user(const user& u)
    {
        userid = u.userid;
        name = u.name;
        email = u.email;
        phonenumber = u.phonenumber;
        address = u.address;

    }

    void displayUserDetails()
    {
        cout << "User Id :  " << userid << endl;
        cout << "Name :     " << name << endl;
        cout << "Email :    " << email << endl;
        cout << "Phone Number:" << phonenumber << endl;
        cout << "Address :  " << address << endl << endl;
    }
    void getstring()
    {

        string strUID = to_string(userid);
        return strUID + "," +
        name + "," +
        email + "," +
        address;
    }
    void WriteToFile( ofstream & out)
    {
        out << name << "," <<email << "," <<address;
    }
};
 class usercollection
    {

        int ucount=0;
    public:
        user U_array[100];
        usercollection()
        {

        }
        int getcount()
        {
            return ucount;

        }
        void AddUser(user u)
        {
            U_array[ucount] = u;
            ucount++;

        }
        void AddUser(int uID, string n, string e, string pNumber, string addr)
        {

            U_array[ucount].setUserID(uID);
            U_array[ucount].setName(n);
            U_array[ucount].setEmail(e);
            U_array[ucount].setPhoneNumber(pNumber);
            U_array[ucount].setAddress(addr);
            ucount++;



        }
        void displayAll()
        {

            for(int i=0; i< ucount; i++)
            {
                U_array[i].displayUserDetails();
            }
        }
        user* GetuserById(int id)

        {
            for(int i=0;i< ucount ; i++)
            {

                if(U_array[i].getUserID() ==id)
                {
                    return &U_array[i];
                }
            }
            return NULL;
        }


    };
class category
{

    int cid;
    string name;
    string type;
public:
    friend void ManageCategory();
    void setcid(int id)
    {
        cid = id;
    }
    void setcname(string n)
    {

        name = n;

    }
    void settype(string t)
    {
        type = t;
    }
    int getid()
    {
        return cid;
    }
    string getname()
    {
        return name;
    }
    string gettype()
    {
        return type;
    }
    category()
    {
        cid =0;
        name = "";
        type = "";
    }
    category(int id, string n, string t)
    {
        cid = id;
        name = n;
        type = t;
    }
    ~category()
    {

    }
    category(const category& c)
    {
        cid = c.cid;
        name = c.name;
        type = c.type;
    }
    void display()
    {
        cout<< "Category ID :"<<cid<<endl;
        cout<< "Category Name :"<<name<<endl;
        cout<< "Category Type :"<<type<<endl;
    }

};
class categorycollection
{
    int ctcount=0;
public:
    category C_array[100];
    categorycollection()
    {

    }
    int getcount()
    {
        return ctcount;
    }
    void addcategory(category c)
    {
        C_array[ctcount] = c;
        ctcount++;

    }
    void addcategory(int id , string n ,string t )
    {
        C_array[ctcount].setcid(id);
        C_array[ctcount].setcname(n);
        C_array[ctcount].settype(t);

    }
    category* getcategoryByid(int id)

        {
            for(int i=0;i< ctcount ; i++)
            {

                if(C_array[i].getid() ==id)
                {
                    return &C_array[i];
                }
            }
            return NULL;
        }

    void displayAll()
    {

        for(int i=0; i< ctcount ; i++)
        {
            C_array[i].display();
        }
    }

};
class wallet
{

    int walletid;
    string name;
    double balance;
public:
    friend void ManageWallet();
    void setid(int id)
    {
        walletid = id;
    }
    void setname(string n)
    {
        name = n;

    }
    void setbalance(double a)
    {
        balance = a;

    }
    int getid()
    {

        return walletid;
    }
    string getname()
    {
        return name;

    }
    double getbalance()
    {


    return balance;
    }
    wallet(){
    walletid=0;
    name = "";
    balance = 0.0;
    }
    wallet(int id , string n , double b)
    {
        walletid= id;
        name = n;
        balance = b;
    }
    ~wallet()
    {

    }
    wallet(const wallet& w)
    {
        walletid = w.walletid;
        name = w.name;
        balance = w.balance;
    }
    void display(){
    cout<< "Wallet ID :"<<walletid<<endl;
    cout<< "Wallet Name :"<<name<<endl;
    cout<< "Wallet Balance :"<<balance<<endl;;
    }

};
class walletcollection
{
    int wcount;
public:
    wallet W_array[100];
    walletcollection()
    {
        wcount = 0;
    }
    void addwallet(wallet w)
    {
        W_array[wcount] = w;
        wcount ++;
    }
    void addwallet(int id, string n, double b)
{
    W_array[wcount].setid(id);
    W_array[wcount].setname(n);
    W_array[wcount].setbalance(b);
}
    void displayall()
    {

        for(int i= 0; i< wcount; i++)
        {
            W_array[i].display();
        }
    }
    wallet* getwalletbyid(int id)
     {
            for(int i=0;i< wcount ; i++)
            {

                if(W_array[i].getid() ==id)
                {
                    return &W_array[i];
                }
            }
            return NULL;
        }


};
class transaction
{
private:

public:
    int transactionid;
    string transactiontype;
    double amount;


    friend void ManageTransaction();
    //Aggrigation
    user* users;
    category* categories;
    wallet* wallets;


    void setTransactionID(int tID)
    {
        transactionid = tID;
    }

    void setTransactionType(string tType)
    {
        transactiontype = tType;
    }

    void setAmount(double a)
    {
        amount = a;
    }
    int getTransactionID()
    {
        return transactionid;
    }

    string getTransactionType()
    {
        return transactiontype;
    }

    double getAmount()
    {
        return amount;
    }


    transaction()
    {
        transactionid = 0;
        transactiontype = "";
        amount = 0.0;
        users = nullptr;
        categories = nullptr;
        wallets = nullptr;
    }

    transaction(int tID, string tType, double a, user* u, category* c, wallet* w)
    {
        transactionid = tID;
        transactiontype = tType;
        amount = a;
        users = u;
        categories = c;
        wallets = w;
    }
     transaction(const transaction& t)
    {
        transactionid = t.transactionid;
        transactiontype = t.transactiontype;
        amount = t.amount;
        users = t.users;
        categories = t.categories;
        wallets = t.wallets;
    }


    void displayTransactionDetails()
    {
        cout << "Transaction Id:       " << transactionid << endl;
        cout << "Transaction Type:     " << transactiontype << endl;
        cout << "Transaction amount:   " << amount << endl;
        cout<< "User ID :   "<<users->userid<<endl;
        cout<< "User name :     "<<users->getName()<<endl;

        cout<< "Category :  "<<categories->getname() <<endl;
        cout<< " Wallet Balance :    "<<wallets->getbalance() <<endl;
    }
};
class transactioncollection
{
    int tcount;
public:
    transaction t_array[100];
    transactioncollection()
    {
        tcount =0;
    }
    void addtransaction(transaction t)
    {
        t_array[tcount] =t;
        tcount ++;
    }
   void addtransaction(int id, string tType, double a,string name, string catn, double wall_bal)
    {
        t_array[tcount].setTransactionID(id);
        t_array[tcount].setTransactionType(tType);
        t_array[tcount].setAmount(a);
        t_array[tcount].users->setName(name);
        t_array[tcount].categories->setcname(catn);
        t_array[tcount].wallets->setbalance(wall_bal);

    }
    void displayall()
    {
        for(int i=0 ; i< tcount ; i++)
        {
            t_array[i].displayTransactionDetails();
        }
    }
    transaction* gettransactionbyid(int id)
     {
            for(int i=0;i< tcount ; i++)
            {

                if(t_array[i].getTransactionID() ==id)
                {
                    return &t_array[i];
                }
            }
            return NULL;
        }
        void findtransactionbyid(int id)
        {
            for(int i=0; i<tcount; i++)
            {


                if(t_array[i].getTransactionID() ==id)
            {



                t_array[i].displayTransactionDetails();
            }
        }
        cout<< "Transaction Not found "<<endl;
        }
        void removetransactionByID(int id)
        {
              for(int i=0; i<tcount; i++)
            {


                if(t_array[i].getTransactionID() ==id)
            {
                for(int j=i; j<tcount -1; j++)
                {
                t_array[j] = t_array[j+1];
                cout<< "Transaction Removed Successfully"<<endl;
                }
            }


        }
        cout<< "Transaction Not Found with ID "<<id<<endl;
        }

};


class budget
{
private:
    int budgetId;
    double totalBudget;
    double remainingBudget;

public:
    //Aggrigation
    user* users;
    transaction* transactions;

    void setBudgetId(int bId)
    {
        budgetId = bId;
    }

    void setTotalBudget(double tBudget)
    {
        totalBudget = tBudget;
    }

    void setRemainingBudget(double rBudget)
    {
        remainingBudget = rBudget;
    }

    int getBudgetid()
    {
        return budgetId;
    }

    double getTotalBudget()
    {
        return totalBudget;
    }

    double getRemainingBudget()
    {
        return remainingBudget;
    }

    budget()
    {
        budgetId = 0;
        totalBudget = 0.0;
        remainingBudget = 0.0;
        users = nullptr;
        transactions = nullptr;
    }

    budget(int bId, double tBudget, double rBudget, user* u, transaction* t)
    {
        budgetId = bId;
        totalBudget = tBudget;
        remainingBudget = rBudget;
        users = u;
        transactions = t;
    }

    ~budget()
    {

    }
    budget(const budget& b)
    {
        budgetId = b.budgetId;
        totalBudget = b.totalBudget;
        remainingBudget = b.remainingBudget;
        users = b.users;
        transactions = b.transactions;
    }
    void settransaction(transaction* t)

    {
        transactions =t;
        if(transactions!= nullptr && transactions->transactiontype == "expense")
        {
            remainingBudget -= transactions->amount;
        }


    }



    void displayBudgetDetails()
    {
        cout << " Budget Id:     " << budgetId << endl;
        cout << "Total Budget   :  " << totalBudget << endl;
        cout<< "Remaining Budget    "<<remainingBudget<<endl;
        if(users != nullptr )
        {
            cout<< "User Name :"<<users->getName() <<endl;

        }
        if(transactions != nullptr)
        {
            cout<< "Last Transaction "<< transactions->getTransactionType()<<endl;
            cout<< "Transaction Amount "<<transactions->getAmount()<<endl;
        }

    }
};
class budgetcollection
{

    int bcount;
public:
    budget b_array[100];
    budgetcollection()
    {
        bcount=0;
    }
    void addbudget(budget b)
    {
        b_array[bcount] = b;
        bcount++;

    }
    void displayall()
    {
        for(int i=0; i< bcount ; i++)
        {
            b_array[i].displayBudgetDetails();
        }

    }
    budget* getbudgetByID(int id)
    {

        for(int i=0; i< bcount; i++ )
        {
            if(b_array[i].getBudgetid() == id)
            {
                return &b_array[i];
            }
            return nullptr;
        }
    }
    void RemovebudgetByID(int id)
    {

        for(int i=0; i< bcount; i++ )
        {
            if(b_array[i].getBudgetid() == id)
            {
                for(int j=i; j<bcount-1; j++)
                {
                    b_array[j] = b_array[j+1];
                }
                bcount--;
                cout<< "Budget Removed Successfully"<<endl;
                return ;

            }
        }
        cout<< "BudgetID Not Found"<<endl;
    }
};



usercollection Ucoll;
categorycollection CTcoll;
walletcollection wcoll;
transactioncollection tcoll;
budgetcollection bcoll;
void ManageUser()
{
     int ch1;
            do {

        cout<<"                              ___________________________________ "<<endl;
        cout<<"                             |                                   |    \n";
        cout<<"                         ---|     1.  MANAGE USER                |--- "<<endl;
        cout<<"                             |___________________________________|    "<<endl;
        cout << "                                |1 |Add User               |" << endl;
        cout << "                                |2 |View All Users         | " << endl;
        cout << "                                |3 |Update User Details    |" << endl;
        cout << "                                |4 |Remove User Details    |" << endl;
        cout << "                                |5 |Find User BY ID        |" << endl;
        cout << "                                |6 |Back to Main Menu      |" << endl;
        cout<<  "                                |__________________________|"<<endl;
                cout << " Enter your choice: ";
                cin >> ch1;
                cout << "\n";

                switch (ch1) {
                case 1:
                    {user u;
                    int id;
                    string name, email, pnumber, addr;
                    cout<< "Enter User id :";
                    cin>>id;
                    u.setUserID(id);
                    cin.ignore();
                    cout<< "Enter User Name :";
                    cin>>name;
                    cin.ignore();
                    u.setName(name);
                    cout<< "Enter User Email :";
                    cin>>email;
                    u.setEmail(email);
                    cout<< "Enter User Phone Number :";
                    cin>>pnumber;
                    u.setPhoneNumber(pnumber);
                    cout<< "Enter User Address :";
                    cin>>addr;
                    u.setAddress(addr);
                    Ucoll.AddUser(u);

                    }
                    break;
                case 2:

                    Ucoll.displayAll();
                    break;
                case 3:
                    {
                        cout<< "Enter User id To Update/Edit :";
                        int id;
                        cin>>id;

                        user* ptru = Ucoll.GetuserById(id);
                        if(ptru == NULL)
                        {
                            cout<< "User Not Found "<<endl;
                        }
                        else
                        {

                            cout<< "Enter User id :";
                            cin>> ptru->userid;
                            cout<< "Enter User Name :";
                            cin>>ptru->name;
                            cout<< "Enter User Email :";
                            cin>>ptru->email;
                            cout<< "Enter User Phone Number :";
                            cin>>ptru->phonenumber;
                            cout<< "Enter User Address :";
                            cin>>ptru->address;


                        }

                    }

                default:
                    cout << "Back to main menu.\n";
                }
            } while (ch1 != 6);
}
void ManageCategory()
{
    int ch2;
            do {
        cout<<"                              ___________________________________ "<<endl;
        cout<<"                             |                                   |    \n";
        cout<<"                         ---|     2.  MANAGE CATEGORY              |--- "<<endl;
        cout<<"                             |___________________________________|    "<<endl;
        cout << "                                |1 |Add Category              |" << endl;
        cout << "                                |2 |View All Category Details | " << endl;
        cout << "                                |3 |Update Category Details   |" << endl;
        cout << "                                |4 |Remove Category Details   |" << endl;
        cout << "                                |5 |Find Category By ID       |" << endl;
        cout << "                                |6 |Back to Main Menu         |" << endl;
        cout<<  "                                |_____________________________|"<<endl;
                cout << "Enter your choice: ";
                cin >> ch2;
                cout << "\n";

                switch (ch2) {
                case 1:
                    {
                        category c;
                        int id;
                        string n , t;
                        cout<< "Enter Category ID :";
                        cin>>id;
                        c.setcid(id);
                        cin.ignore();
                        cout<< "Enter Category Name :";
                        cin>>n;
                        cin.ignore();
                        c.setcname(n);
                        cout<< "Enter Category Type (expense/income):";
                        cin>>t;
                        c.settype(t);
                        CTcoll.addcategory(c);
                    break;
                    }
                case 2:
                   CTcoll.displayAll();
                    break;
                case 3:
                     {
                        cout<< "Enter Category id To Update:";
                        int id;
                        cin>>id;

                        category* ptrct = CTcoll.getcategoryByid(id);
                        if(ptrct == NULL)
                        {
                            cout<< "Category Not Found "<<endl;
                        }
                        else
                        {

                            cout<< "Enter Category id :";
                            cin>> ptrct->cid;
                            cout<< "Enter Category Name :";
                            cin>>ptrct->name;
                            cout<< "Enter Category Type :";
                            cin>>ptrct->type;


                        }

                    }

                    break;
                default:
                    cout << "Back to main menu.\n";
                }
            } while (ch2 != 6);
}
void ManageWallet()
{
     int ch3;
            do {
        cout<<"                              ___________________________________ "<<endl;
        cout<<"                             |                                   |    \n";
        cout<<"                         ---|     3.  MANAGE WALLET               |--- "<<endl;
        cout<<"                             |___________________________________|    "<<endl;
        cout << "                                |1 |Add Wallet               |" << endl;
        cout << "                                |2 |View All Wallet Detail   | " << endl;
        cout << "                                |3 |Update Wallet Details    |" << endl;
        cout << "                                |4 |Remove Wallet Details    |" << endl;
        cout << "                                |5 |Find Wallet BY ID        |" << endl;
        cout << "                                |6 |Back to Main Menu      |" << endl;
        cout<<  "                                |__________________________|"<<endl;
                cout << "Enter your choice: ";
                cin >> ch3;
                cout << "\n";

                switch (ch3) {
                case 1:
                    {
                        wallet w;
                        int id;
                        string name;
                        double balance;
                        cout<< "Enter Wallet id :";
                        cin>>id;
                        w.setid(id);
                        cin.ignore();
                        cout<< "Enter Wallet Name :";
                        cin>>name;
                        cin.ignore();
                        w.setname(name);
                        cout<< "Enter Balance In Wallet :";
                        cin>>balance;
                        w.setbalance(balance);
                        wcoll.addwallet(w);




                    break;
                    }
                case 2:
                    wcoll.displayall();

                    break;
                case 3:
                     {
                        cout<< "Enter Wallet id To Update:";
                        int id;
                        cin>>id;

                        wallet* ptrw = wcoll.getwalletbyid(id);
                        if(ptrw == NULL)
                        {
                            cout<< "Wallet ID Not Found "<<endl;
                        }
                        else
                        {

                            cout<< "Enter Wallet id :";
                            cin>> ptrw->walletid;
                            cout<< "Enter Wallet Name :";
                            cin>>ptrw->name;
                            cout<< "Enter Wallet Balance :";
                            cin>>ptrw->balance;


                        }

                    }
                    break;
                default:
                    cout << "Back to main menu.\n";
                }
            } while (ch3 != 6);
}
void ManageTransaction()
{
    int ch4;
            do {
        cout<<"                              ___________________________________ "<<endl;
        cout<<"                             |                                   |    \n";
        cout<<"                         ---|    4.  MANAGE TRANSACTION           |--- "<<endl;
        cout<<"                             |___________________________________|    "<<endl;
        cout << "                                |1 |Add Transaction             |" << endl;
        cout << "                                |2 |View All Transactions       | " << endl;
        cout << "                                |3 |Update Transactions Details |" << endl;
        cout << "                                |4 |Remove Transactions Details |" << endl;
        cout << "                                |5 |Find Transaction BY ID      |" << endl;
        cout << "                                |6 |Back to Main Menu      |" << endl;
        cout<<  "                                |__________________________|"<<endl;
                cout << "Enter your choice: ";
                cin >> ch4;
                cout << "\n";

                switch (ch4) {
                case 1:
                   {
                       transaction t;
                       int uid, cid;
                       int wid;
                       cout<< "Enter Transaction ID :"<<endl;
                       cin>>t.transactionid;
                       cout<< "Enter User  ID :";
                       cin>> uid;
                       user* ptru = Ucoll.GetuserById(uid);
                       if(ptru!= NULL)
                       {
                           t.users = ptru;
                           cout<< "Enter Category ID :";
                           cin>>cid;
                           category* ptrc = CTcoll.getcategoryByid(cid);
                           if(ptrc != NULL)
                           {
                               t.categories = ptrc;
                               cout<< "Enter Wallet ID :";
                               cin>>wid;
                               wallet* ptrw = wcoll.getwalletbyid(wid);
                               if(ptrw != NULL)
                               {
                                   t.wallets = ptrw;
                               }
                               else{
                                cout<< "Invalid Wallet ID"<<endl;
                                cout<< "Unable to add Transaction"<<endl;
                               }
                           }
                           else
                           {
                               cout<< "Invalid Category ID "<<endl;
                           }
                       }
                       else{
                        cout<< "Invalid User ID"<<endl;
                       }
                       cin.ignore();

                       cout<< "Enter Transaction Type :";
                       cin >> t.transactiontype;
                       cin.ignore();
                      cout<< "Enter Transaction Amount :";
                       cin>> t.amount;
                       tcoll.addtransaction(t);
                       cout<< "Transaction Added Successfully "<<endl;
                            break;
                   }

                case 2:
                    tcoll.displayall();

                    break;
                case 3:
                    default:
                    cout << "Back to main menu.\n";
                }
            } while (ch4 != 6);

        }
void ManageBudget()
{
     int ch5;
            do {
        cout<<"                              ___________________________________ "<<endl;
        cout<<"                             |                                   |    \n";
        cout<<"                         ---|     5.  MANAGE BUDGET                |--- "<<endl;
        cout<<"                             |___________________________________|    "<<endl;
        cout << "                                |1 |Add Budget               |" << endl;
        cout << "                                |2 |View All Budget Details  | " << endl;
        cout << "                                |3 |Update Budget Details    |" << endl;
        cout << "                                |4 |Remove Budget Details    |" << endl;
        cout << "                                |5 |Find Budget BY ID        |" << endl;
        cout << "                                |6 |Back to Main Menu        |" << endl;
        cout<<  "                                |____________________________|"<<endl;
                cout << "Enter your choice: ";
                cin >> ch5;
                cout << "\n";

                switch (ch5) {
                case 1:
                    {


                    budget b;
                    int bid,uid,tid;
                    double total;
                    cout<< "Enter Budget ID :";
                    cin>>bid;
                    b.setBudgetId(bid);
                    cout<< "Enter Total Budget :";
                    cin>>total;
                    b.setTotalBudget(total);
                    cout<< "Enter User ID For This Budget :";
                    cin>>uid;
                    user* ptru = Ucoll.GetuserById(uid);
                    if(ptru == nullptr)
                    {
                        cout<< "User Not Found "<<endl;
                        cout<< "Absorting Budget Creation"<<endl;
                        break;
                    }
                    b.users = ptru;
                    cout<< "Enter Transaction ID TO Link :";
                    cin>>tid;
                    transaction* ptrt = tcoll.gettransactionbyid(tid);
                    if(ptrt == nullptr)
                    {
                        cout<< "Transaction Not Found "<<endl;
                        cout<< "Budget Creation Stoped "<<endl;
                        break;
                    }
                    }


                case 2:
                    bcoll.displayall();
                    break;
                case 3:
                    {

                        int id;
                        cout<< "Enter Budget ID To View :";
                        cin>> id;
                        budget* b= bcoll.getbudgetByID(id);
                        if(b!= nullptr)
                        {

                            b->displayBudgetDetails();
                        }
                        else{
                            cout<< "Budget Not Found "<<endl;
                        }
                        break;

                    }
                case 4:
                    {
                       break;
                    }
                case 5:
                    {
                        int id;
                        cout<< "Enter Budger ID To Remove :";
                        cin>>id;
                        bcoll.RemovebudgetByID(id);
                        break;
                    }
                case 6:
                    cout<< "Returning TO Main Menu "<<endl;
                default:
                    cout << "Invalid Choice \n";
                }


            } while (ch5 != 6);



}


int main() {


    int choice;
    do {
                cout << "                             =========================================================================        \n";
        cout << "                            |                                                                         |       \n";
        cout << "                   -------{                     SIMPLE BUDGET TRACKER                                   }-------\n";
        cout << "                            |                                                                         |       \n";
        cout << "                              =======================================================================           \n";


        cout<<"                                           __________________________________" <<endl;
        cout<<"                                          |                                  |\n";
        cout<<"                                          |     1.  MANAGE USER              |"<<endl;
        cout<<"                                          |__________________________________|"<<endl;
        cout<<"                                           __________________________________" <<endl;
        cout<<"                                          |                                  |\n";
        cout<<"                                          |     2.  MANAGE CATEGORY          |"<<endl;
        cout<<"                                          |__________________________________|"<<endl;
        cout<<"                                           __________________________________" <<endl;
        cout<<"                                          |                                  |\n";
        cout<<"                                          |     3.   MANAGE WALLET           | "<<endl;
        cout<<"                                          |__________________________________| "<<endl;
        cout<<"                                           __________________________________" <<endl;
        cout<<"                                          |                                  |\n";
        cout<<"                                          |     4.  MANAGE TRANSACTION       | "<<endl;
        cout<<"                                          |__________________________________| "<<endl;
        cout<<"                                           __________________________________" <<endl;
        cout<<"                                          |                                  |\n";
        cout<<"                                          |     5.    MANAGE BUDGET          | "<<endl;
        cout<<"                                          |__________________________________| "<<endl;
        cout<<"                                           __________________________________" <<endl;
        cout<<"                                          |                                  |\n";
        cout<<"                                          |     6.   *******EXIT*****        | "<<endl;
        cout<<"                                          |__________________________________| "<<endl;



        cout << "--------------------------------------\n" << endl;
        cout << " Enter your choice: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
        case 1: {
            ManageUser();

            break;
        }

       case 2: {
           ManageCategory();

            break;
        }

        case 3: {
            ManageWallet();

            break;
        }


        case 4:
            {
                ManageTransaction();
                break;
            }

      case 5: {
          ManageBudget();
          break;
      }


        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a Valid number" <<endl;
        }

    }while (choice != 6);

    return 0;

}


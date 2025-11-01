#include <bits/stdc++.h>
#include <conio.h>
#include<windows.h>
using namespace std;
class iteam{
    public:
    int id;
    string name;
    int price;
    int quantity;
    iteam(){
        id = 0;
        name = " ";
        price = 0;
        quantity = 0;
    }
};
//creating bill for the customer
void bill(iteam it[], int size, string cName , string CAddress, double discount=0.0, double tax=0.0){
    int total=0;

    // Get current time
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Format: YYYY-MM-DD HH:MM:SS
    char dateTime[20];
    strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %H:%M:%S", ltm);

    cout<<"\n\n";
    cout<<"\t\t GLOBAL GENERAL STRORE\n";
    cout<<"\t\t---------------------------\n";
    cout<<"\n";
    cout << "Customer Name: " << cName 
         << setw(45 - cName.length())  // Adjusts spacing
         << dateTime << endl;
    cout<<"Customer Address: "<<CAddress<<endl;
    cout << "-----------------------------------------------------------\n";
    cout << "| ID | Name             | Price  | Quantity | Subtotal     |\n";
    cout << "-----------------------------------------------------------\n";    
    for(int i=0; i<size; i++){
        int subtotal = it[i].price * it[i].quantity;
        total += subtotal;
        cout << "| " << setw(3) << it[i].id 
             << " | " << setw(15) << it[i].name 
             << " | " << setw(6) << it[i].price 
             << " | " << setw(8) << it[i].quantity 
             << " | " << setw(12) << subtotal << " |\n";
    }
    cout << "-----------------------------------------------------------\n";
    //Apply discount
    int discountAmount = total * discount / 100;
    total -= discountAmount;

    //Apply tax
    int taxAmount = total * tax / 100;
    total += taxAmount;

    cout<<"Discount: "<<discountAmount<<endl;
    cout<<"Tax: "<<taxAmount<<endl;
    cout<<"Total: "<<total<<endl;
    cout<<"\n\n";
    cout<<"\t Thank you for shopping with us.\n";
    cout<<"\t Visit Again!!\n";
    cout<<"\n\n";

}
//saving the data in the file
void saveFile(iteam it[], int size, string cName , string CAddress, double discount=0.0, double tax=0.0){
    ofstream file;
    file.open("bill.txt");
    int total=0;
    // Get current time
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Format: YYYY-MM-DD HH:MM:SS
    char dateTime[20];
    strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %H:%M:%S", ltm);

    file<<"\n\n";
    file<<"\t\t GLOBAL GENERAL STRORE\n";
    file<<"\t\t---------------------------\n";
    file<<"\n";
    file << "Customer Name: " << cName 
         << setw(45 - cName.length())  // Adjusts spacing
         << dateTime << endl;
    file<<"Customer Address: "<<CAddress<<endl;
    file << "-----------------------------------------------------------\n";
    file << "| ID | Name             | Price  | Quantity | Subtotal     |\n";
    file << "-----------------------------------------------------------\n";    
    for(int i=0; i<size; i++){
        int subtotal = it[i].price * it[i].quantity;
        total += subtotal;
        file << "| " << setw(3) << it[i].id 
             << " | " << setw(15) << it[i].name 
             << " | " << setw(6) << it[i].price 
             << " | " << setw(8) << it[i].quantity 
             << " | " << setw(12) << subtotal << " |\n";
    }
    file << "-----------------------------------------------------------\n";
    //Apply discount
    int discountAmount = total * discount / 100;
    total -= discountAmount;

    //Apply tax
    int taxAmount = total * tax / 100;
    total += taxAmount;

    file<<"Discount: "<<discountAmount<<endl;
    file<<"Tax: "<<taxAmount<<endl;
    file<<"Total: "<<total<<endl;
    file<<"\n\n";
    file<<"\t Thank you for shopping with us.\n";
    file<<"\t Visit Again!!\n";
    file<<"\n\n";
    file.close();
    cout<<"Bill is saved in the file named bill.txt"<<endl;

}
void newBill(){
    system("cls");
    cout<<"\n \t\t ...welcome to the store....\n"<<endl;
    string Name,address;
    int totalIteams;
    cout<<"Enter your name: ";
    cin>>Name;
    cout<<"Enter your address: ";
    cin>>address;
    cout<<"Enter the total number of items you want to buy: ";
    cin>>totalIteams;
    cin.ignore();
    cout<<"\t\t Enter the details of the iteams\n";
    iteam it[totalIteams];

    // for loop to take input of iteams
    for(int i=0; i<totalIteams; i++){
        cout<<"Enter the Id of the " << i + 1 << " iteam: ";
        cin>>it[i].id;
        cin.ignore();
        cout<<"Enter the name : ";
        cin>>it[i].name;
        cout<<"Enter the price : ";
        cin>>it[i].price;
        cout<<"Enter the quantity of the iteam: ";
        cin>>it[i].quantity;
    }
    double discount, tax;
    cout<<"Enter the discount percentage: ";
    cin>>discount;
    cout<<"Enter the tax percentage: ";
    cin>>tax;
    // call display function
    bill(it, totalIteams, Name, address, discount, tax);
    saveFile(it, totalIteams, Name, address, discount, tax);

}
int main(){
    system("cls");
    // system("color 16");  //16 (light blue, white), 0A(black, green)
    char choice;
    cout<<"Press 1 to generate a new bill or Press 2 to see previous bill.";
    choice = getch(); 
    switch (choice)
    {
    case '1' : newBill();
        break;
    case '2' : 
    { ifstream file;
        file.open("bill.txt");
        string s;
        while(getline(file,s)){
            cout<<s<<endl;
        }
        file.close();
    }
        break;
    
    default: 
    cout<<"Invalid choice"<<endl;
        break;
    }
    return 0;
}


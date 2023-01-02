#include "MLL1toN.h"
int main() {
    listCredit Credits; 
    listCustomer Customers;
    adrCredit credP; 
    adrCustomer custP;
    int command;
    
    createListCredit(Credits);
    createlistCustomer(Customers);
    /*
    menu(command);
    while(command != 0) {
        switch(command) {
            case 1: {
                int iCust; 
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan berapa banyak data customer yang ingin di input :";
                cin>>iCust;
                for(int i = 0 ; i < iCust ; i++) {
                    cout<<"Masukkan nama : ";
                    cin>>dataCust.name;
                    cout<<"Masukkan umur : ";
                    cin>>dataCust.age;
                    cout<<"Masukkan jenis kelamin : ";
                    cin>>dataCust.gender;
                    custP = createElementCustomer(Customers, dataCust);
                    insertLastCustomer(Customers, custP);
                    cout<<"\n";
                }
                break;
            }
            case 2: {
                system("cls");
                dataCustomer dataCust; 
                cout<<"Masukan nama customer :";
                cin>>dataCust.name;
                showCustomerData(Customers, dataCust);
                break;
            }
            case 3: {
                system("cls");
                dataCustomer dataCust;
                cout<<"Masukan nama customer yang akan diapus :";
                cin>>dataCust.name;
                deleteCustomer(Credits, Customers, dataCust);
                break;
            }
            case 4: {
                system("cls");
                dataCustomer dataCust;
                adrCustomer thisCust;
                cout<<"Masukan nama customer :";
                cin>>dataCust.name;
                thisCust = getCustomer(Customers, dataCust);
                if(thisCust == NULL) {
                    cout<<"Data Kosong\n";
                } else {
                    cout<<"Nama :"<<data(thisCust).name<<"\n";
                    cout<<"Umur :"<<data(thisCust).age<<"\n";
                    cout<<"gender :"<<data(thisCust).gender<<"\n";
                    cout<<"total kredit :"<<data(thisCust).totalCredits<<"\n";
                }
                break;
            }
            case 5: {
                system("cls");
                dataCredit dataCred;
                dataCustomer dataCust;
                string namaCust;
                cout<<"Masukkan nama pelanggan :";
                cin>>dataCust.name;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL) {
                    cout<<"Masukan nama kredit :";
                    cin>>dataCred.creditName;
                    cout<<"Masukan nomor rekening :";
                    cin>>dataCred.creditID;
                    credP = createElementCredit(Credits, dataCred);
                    addCreditToCustomer(Credits, Customers, dataCred, namaCust);
                } else {
                    cout<<"data customer tidak ditemukan\n";
                }
            break;
            }
            case 6: {
                dataCustomer namaCust;
                cout<<"Masukan nama customer :";
                cin>>namaCust.name;
                deleteCreditInCustomer(Credits, Customers, namaCust.name); 
            }
            break;
        }
        string state;
        cout<<"kembali ke menu utama (ya\'tidak)";
        if(state == "tidak"){
            command = 0;
        }
    }
    */
    return 0;
}
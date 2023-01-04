#include "MLL1toN.h"
int main() {
    listCredit Credits; 
    listCustomer Customers;
    adrCredit credP; 
    adrCustomer custP;
    int command;

    createListCredit(Credits);
    createlistCustomer(Customers);
    menu(command);

    while(command != 0){
        switch(command){
            case 1:{ // Menambahkan customer baru [done]
                int iCust;
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan berapa banyak data customer yang ingin di input : ";
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
                    cout<<"Menambahkan pelanggan berhasil!\n";
                    cout<<"\n";
                }
                break;
            }
            case 2:{ // Menampilkan data customer X [done]
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama customer : ";
                cin>>dataCust.name;
                showCustomerData(Customers, dataCust);
                break;
            }
            case 3:{ // Menghapus customer tertentu
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama customer yang akan diapus : ";
                cin>>dataCust.name;
                deleteCustomer(Credits, Customers, dataCust);
                break;
            }
            case 4: { // Mencari customer X
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama customer : ";
                cin>>dataCust.name;
                custP = getCustomer(Customers, dataCust);
                if(custP == NULL) {
                    cout<<"Data Kosong\n";
                } else {
                    cout<<"Nama :"<<data(custP).name<<"\n";
                    cout<<"Umur :"<<data(custP).age<<"\n";
                    cout<<"gender :"<<data(custP).gender<<"\n";
                    cout<<"total kredit :"<<data(custP).totalCredits<<"\n";
                }
                break;
            }
            case 5: { // Menambahkan kartu kredit dari customer X
                dataCredit dataCred;
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukkan nama pelanggan : ";
                cin>>dataCust.name;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL) {
                    cout<<"Nama customer berhasil ditemukan\n";
                    cout<<"Masukan nama kredit : ";
                    cin>>dataCred.creditName;
                    cout<<"Masukan nomor rekening : ";
                    cin>>dataCred.creditID;
                    addCreditToCustomer(Credits, Customers, dataCred, dataCust);
                } else {
                    cout<<"Nama customer tidak ditemukan\n";
                }
                cout<<"\n";
            break;
            }
            case 6: { // Menghapus kartu kredit dari customer X
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama customer : ";
                cin>>dataCust.name;
                deleteCreditInCustomer(Credits, Customers, dataCust);
                break;  
            }
            case 7: { // Menampilkan seluruh kartu kredit dari customer X
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama customer : ";
                cin>>dataCust.name;
                showCustomerCredit(Credits, Customers, dataCust);
                break;
            }
            case 8: { // Mencari kartu kredit Y dari customer X
                system("cls");
                break;
            }
            case 9: { // Membuat relasi antara customer X dan kartu kredit Y
                system("cls");
                break;
            }
            case 10: { // Menghapus relasi antara customer X dan kartu kredit Y
                system("cls");
                break;
            }
            case 11: { // Menampilkan data customer yang memiliki kredit terbanyak
                system("cls");
                break;
            }
            case 12: { // Mencari nama customer dari kartu kredit Y
                system("cls");
                break;
            }
           default:
            break;
        }
        string state;
        cout<<"kembali ke menu utama (ya\\tidak): ";
        cin>>state;
        while(state != "ya" && state !="tidak"){
            cout<<"Entry kurang tepat!\n";
            cout<<"kembali ke menu utama (ya\\tidak): ";
            cin>>state;
        }
        system("cls");
        if(state == "tidak"){
            command = 0;
        } else if(state == "ya"){
            menu(command);
        }
    }
    cout<<"Terima kasih :)\n";
    return 0;
}
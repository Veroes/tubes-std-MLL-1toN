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
            case 1:{ // Menambahkan customer baru [done] [clean]
                int iCust, typeInt;
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukkan berapa banyak data pelanggan yang ingin di input : ";
                iCust = validateIntInput(iCust);
                for(int i = 0 ; i < iCust ; i++) {
                    cout<<"Masukkan nama : ";
                    cin>>dataCust.name;
                    custP = getCustomer(Customers, dataCust);                    
                    if(custP != NULL){
                        cout<<"Pelanggan sudah ada dalam list\n";
                    }else{
                        cout<<"Masukkan umur : ";
                        cin>>dataCust.age;
                        cout<<"Masukkan jenis kelamin : ";
                        cin>>dataCust.gender;
                        custP = createElementCustomer(Customers, dataCust);
                        insertLastCustomer(Customers, custP);
                        cout<<"Pelanggan berhasil ditambahkan!\n";
                    }
                    cout<<"\n";
                }
                break;
            }

            case 2:{ // Menampilkan data customer X [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama pelanggan : ";
                cin>>dataCust.name;
                showCustomerData(Customers, dataCust);
                break;
            }

            case 3:{ // Menghapus customer tertentu [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama pelanggan yang akan dihapus : ";
                cin>>dataCust.name;
                deleteCustomer(Credits, Customers, dataCust);
                break;
            }

            case 4: { // Mencari customer X [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama customer : ";
                cin>>dataCust.name;
                custP = getCustomer(Customers, dataCust);
                if(custP == NULL){
                    cout<<"Data pelanggan tidak ditemukan\n";
                }else{
                    cout<<"Pelanggan ditemukan\n\n";
                    cout<<"Nama\t\t: "<<data(custP).name<<"\n";
                    cout<<"Umur\t\t: "<<data(custP).age<<"\n";
                    cout<<"gender\t\t: "<<data(custP).gender<<"\n";
                    cout<<"total kredit\t: "<<data(custP).totalCredits<<"\n";
                }
                break;
            }

            case 5: { // Menambahkan kartu kredit dari customer X [done] [clean]
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
                    adrCredit credP = getCredit(Credits, dataCred);
                    if(credP != NULL){
                        cout<<"Data credit sudah ada dalam list\n";
                    }else{
                        addCreditToCustomer(Credits, Customers, dataCred, dataCust);
                        cout<<"Kaeru kredit berhasil ditambahkan\n";
                    }
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
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"Masukkan nama pelanggan : ";
                cin>>dataCust.name;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL) {
                    cout<<"Nama customer berhasil ditemukan\n";
                    cout<<"Masukan nama kredit : ";
                    cin>>dataCred.creditName;
                    cout<<"Masukan nomor rekening : ";
                    cin>>dataCred.creditID;
                    if(credP != NULL){
                        cout<<"\n";
                        cout<<"Data customer dengan kredit "<<dataCred.creditName
                        <<" dan nomor rekening "<<dataCred.creditID<<" : \n";
                        showCustomerData(Customers, dataCust);
                    }
                } else {
                    cout<<"Nama customer tidak ditemukan\n";
                }
                cout<<"\n";
                break;
            }
            case 9: { // Membuat relasi antara customer X dan kartu kredit Y
                system("cls");
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"Masukkan nama pelanggan : ";
                cin>>dataCust.name;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL) {
                    cout<<"Nama customer berhasil ditemukan\n";
                    cout<<"Masukan nama kredit : ";
                    cin>>dataCred.creditName;
                    cout<<"Masukan nomor rekening : ";
                    cin>>dataCred.creditID;
                    connectCreditToCustomer(Credits, Customers, dataCred, dataCust);
                    cout<<"Berhasil menghubungkan kartu kredit dnegan customer\n";
                } else {
                    cout<<"Nama customer tidak ditemukan\n";
                }
                cout<<"\n";
                break;
            }
            case 10: { // Menghapus relasi antara customer X dan kartu kredit Y
                system("cls");
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"Masukkan nama pelanggan : ";
                cin>>dataCust.name;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL) {
                    cout<<"Nama customer berhasil ditemukan\n";
                    showCustomerCredit(Credits, Customers, dataCust);
                    cout<<"Masukan nama kredit : ";
                    cin>>dataCred.creditName;
                    cout<<"Masukan nomor rekening : ";
                    cin>>dataCred.creditID;
                    credP = getCredit(Credits, dataCred);
                    if(credP == NULL){
                        cout<<"Data Credit tidak ditemukan/tidak terdaftar\n";
                    }else{
                        disconnectCreditAndCustomer(Credits, Customers, dataCred, dataCust);
                        cout<<"Berhasil memutuskan hubungan antara kartu kredit dnegan customer\n";
                    }
                } else {
                    cout<<"Nama customer tidak ditemukan\n";
                }
                cout<<"\n";
                break;
            }
            case 11: { // Menampilkan data customer yang memiliki kredit terbanyak
                system("cls");
                showHighestCustomerCredits(Credits, Customers);
                break;
            }
            case 12: { // Mencari nama customer dari kartu kredit Y
                system("cls");
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"Masukan nama kredit : ";
                cin>>dataCred.creditName;
                cout<<"Masukan nomor rekening : ";
                cin>>dataCred.creditID;
                credP = getCredit(Credits, dataCred);
                if(credP == NULL){
                        cout<<"Data Credit tidak ditemukan/tidak terdaftar\n";
                }else{
                    custP = getCustomerFromCredit(Credits, dataCred);
                    if(custP == NULL){
                        cout<<"Credit ini tidak memiliki relasi ke customer\n";
                    }else{
                        cout<<"Data Customer\n";
                        showCustomerData(Customers, data(custP));
                    }  
                }
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
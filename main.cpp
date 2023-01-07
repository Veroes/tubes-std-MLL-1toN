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
                cout<<"Masukkan berapa banyak data customer yang ingin di input : ";
                iCust = validateIntInput(iCust);
                for(int i = 0 ; i < iCust ; i++) {
                    cout<<"Masukkan nama : ";
                    cin>>dataCust.name;
                    cout<<"Masukkan NIK : ";
                    cin>>dataCust.NIK;
                    cout<<"Masukkan umur : ";
                    dataCust.age = validateIntInput(dataCust.age);
                    cout<<"Masukkan jenis kelamin : ";
                    cin>>dataCust.gender;
                    custP = getCustomer(Customers, dataCust);                    
                    if(custP != NULL){ // or if(getCustomer(Customers, dataCust) != NULL){...}
                        cout<<"customer/NIK sudah terdaftar\n";
                    }else{
                        custP = createElementCustomer(Customers, dataCust);
                        insertLastCustomer(Customers, custP);
                        cout<<"customer berhasil ditambahkan!\n";
                    }
                    cout<<"\n";
                }
                break;
            }
            case 2:{ // Menampilkan data customer X [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama customer : ";
                cin>>dataCust.name;
                cout<<"Masukan NIK : ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){
                    showCustomerData(Customers, dataCust);
                }else{
                    cout<<"Customer tidak terdaftar\n";
                }
                break;
            }
            case 3:{ // Menghapus customer tertentu [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama customer yang akan dihapus : ";
                cin>>dataCust.name;
                cout<<"Masukan NIK customer : ";
                cin>>dataCust.NIK;
                deleteCustomer(Credits, Customers, dataCust);
                break;
            }
            case 4: { // Mencari customer X [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukan nama customer : ";
                cin>>dataCust.name;
                cout<<"Masukan NIK customer : ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP == NULL){ // or if(getCustomer(Customers, dataCust) != NULL){...}
                    cout<<"Customer tidak ditemukan\n";
                }else{
                    cout<<"Customer ditemukan\n\n";
                    cout<<"Nama\t\t: "<<data(custP).name<<"\n";
                    cout<<"NIK\t\t: "<<data(custP).NIK<<"\n";
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
                cout<<"Masukkan nama customer : ";
                cin>>dataCust.name;
                cout<<"Masukkan NIK customer : ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){ // or if(getCustomer(Customers, dataCust) != NULL){...}
                    cout<<"Customer berhasil ditemukan\n";
                    cout<<"Masukkan nama kredit : ";
                    cin>>dataCred.creditName;
                    cout<<"Masukan nomor rekening : ";
                    cin>>dataCred.creditID;
                    adrCredit credP = getCredit(Credits, dataCred);
                    if(credP != NULL){
                        cout<<"Kartu kredit sudah ada dalam list\n";
                    }else{
                        addCreditToCustomer(Credits, Customers, dataCred, dataCust);
                        cout<<"Kartu kredit berhasil ditambahkan\n";
                    }
                }else{
                    cout<<"Customer tidak ditemukan\n";
                }
                cout<<"\n";
            break;
            }
            case 6: { // Menghapus kartu kredit dari customer X [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukkan nama customer : ";
                cin>>dataCust.name;
                cout<<"Masukkan NIK customer : ";
                cin>>dataCust.NIK;
                deleteAllCreditInCustomer(Credits, Customers, dataCust);
                break;  
            }
            case 7: { // Menampilkan seluruh kartu kredit dari customer X [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"Masukkan nama customer : ";
                cin>>dataCust.name;
                cout<<"Masukkan NIK customer : ";
                cin>>dataCust.NIK;
                showCustomerCredit(Credits, Customers, dataCust);
                break;
            }
            case 8: { // Mencari kartu kredit Y dari customer X [done] [clean]
                system("cls");
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"Masukkan nama customer : ";
                cin>>dataCust.name;
                cout<<"Masukkan NIK customer : ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){ // or if(getCustomer(Customers, dataCust) != NULL){...}
                    cout<<"Customer berhasil ditemukan\n";
                    cout<<"Masukkan nama kredit : ";
                    cin>>dataCred.creditName;
                    cout<<"Masukkan nomor rekening : ";
                    cin>>dataCred.creditID;
                    credP = getCredit(Credits, dataCred);
                    if(credP != NULL && child(credP) == custP){
                        cout<<"\n";
                        cout<<"Data customer dengan kredit "<<dataCred.creditName
                        <<" dan nomor rekening "<<dataCred.creditID<<" : \n";
                        showCustomerData(Customers, dataCust);
                    }else{
                        cout<<"Kartu kredit tidak ditemukan";
                    }
                }else{
                    cout<<"Customer tidak ditemukan\n";
                }
                cout<<"\n";
                break;
            }
            case 9: { // Membuat relasi antara customer X dan kartu kredit Y [done] [clean]
                system("cls");
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"Masukkan nama customer : ";
                cin>>dataCust.name;
                cout<<"Masukkan NIK customer : ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){ // or if(getCustomer(Customers, dataCust) != NULL){...}
                    cout<<"Customer berhasil ditemukan\n";
                    cout<<"Masukkan nama kredit : ";
                    cin>>dataCred.creditName;
                    cout<<"Masukan nomor rekening : ";
                    cin>>dataCred.creditID;
                    connectCreditToCustomer(Credits, Customers, dataCred, dataCust);
                    cout<<"Berhasil menghubungkan kartu kredit dengan customer\n";
                }else{
                    cout<<"Customer tidak ditemukan\n";
                }
                cout<<"\n";
                break;
            }
            case 10: { // Menghapus relasi antara customer X dan kartu kredit Y
                system("cls");
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"Masukkan nama Customer : ";
                cin>>dataCust.name;
                cout<<"Masukkan NIK customer : ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){ // // or if(getCustomer(Customers, dataCust) != NULL){...}
                    cout<<"Customer berhasil ditemukan\n";
                    if(data(custP).totalCredits > 0){
                        showCustomerCredit(Credits, Customers, dataCust);
                        cout<<"Masukkan nama kredit : ";
                        cin>>dataCred.creditName;
                        cout<<"Masukkan nomor rekening : ";
                        cin>>dataCred.creditID;
                        credP = getCredit(Credits, dataCred);
                        if(credP == NULL){
                            cout<<"Data kredit tidak ditemukan/tidak terdaftar\n";
                        }else{
                            disconnectCreditAndCustomer(Credits, Customers, dataCred, dataCust);
                            cout<<"Berhasil memutuskan hubungan antara kartu kredit dengan customer\n";
                        }
                    }else{
                        cout<<"Customer tidak memiliki kartu kredit\n";
                    }
                }else{
                    cout<<"Customer tidak ditemukan\n";
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
                cout<<"Masukkan nama kredit : ";
                cin>>dataCred.creditName;
                cout<<"Masukkan nomor rekening : ";
                cin>>dataCred.creditID;
                credP = getCredit(Credits, dataCred);
                if(credP == NULL){ // or if(getCredit(Credits, dataCred) != NULL){...}
                        cout<<"Kredit tidak ditemukan/tidak terdaftar\n";
                }else{
                    custP = getCustomerFromCredit(Credits, Customers, dataCred);
                    if(custP == NULL){
                        cout<<"Kredit ini tidak memiliki relasi ke customer\n";
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
        if(state == "ya"){
            menu(command);
        }else if(state == "tidak"){
            command = 0;
        }
    }
    cout<<"Terima kasih :)\nCreated by : Arifki Ilham and Rifqah Amaliyah [Tugas Besar STD]";
    return 0;
}
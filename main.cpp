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
                cout<<"\n";
                cout<<"\t\t\t======[[ 1. Menambahkan Customer Baru ]]======\n\n\n";
                cout<<"--- Masukkan berapa banyak data customer yang ingin di input : ";
                iCust = validateIntInput(iCust);
                for(int i = 0 ; i < iCust ; i++) {
                    cout<<"--- Masukkan Nama\t\t: ";
                    cin>>dataCust.name;
                    cout<<"--- Masukkan NIK\t\t: ";
                    cin>>dataCust.NIK;
                    cout<<"--- Masukkan Umur\t\t: ";
                    cin>>dataCust.age;
                    cout<<"--- Masukkan Gender\t\t: ";
                    cin>>dataCust.gender;
                    bool findNIK = getNIK(Customers, dataCust);
                    if(findNIK == true){
                        cout<<"\n";
                        cout<<"--- NIK Sudah Terdaftar!\n";
                        cout<<"\n";
                    }else{
                        custP = createElementCustomer(Customers, dataCust);
                        insertLastCustomer(Customers, custP);
                        cout<<"\n";
                        cout<<"--- Data Customer Berhasil Ditambahkan!\n";
                        cout<<"\n";
                    }
                    cout<<"=============================================================\n";
                    cout<<"\n";
                }
                break;
            }
            case 2:{ // Menampilkan data customer X [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 2. Menampilkan data customer X ]]======\n\n";
                cout<<"--- Masukkan Nama\t\t: ";
                cin>>dataCust.name;
                cout<<"--- Masukkan NIK\t\t: ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){
                    cout<<"\n";
                    cout<<"========================================================\n\n";
                    cout<<"--- Data Customer\n";
                    showCustomerData(Customers, dataCust);
                }else{
                    cout<<"\n";
                    cout<<"--- Nama/NIK Tidak Terdaftar!\n";
                }
                cout<<"\n";
                break;
            }
            case 3:{ // Menghapus customer tertentu [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 3. Menghapus customer X ]]======\n\n";
                cout<<"--- Masukkan Nama\t\t: ";
                cin>>dataCust.name;
                cout<<"--- Masukkan NIK\t\t: ";
                cin>>dataCust.NIK;
                deleteCustomer(Credits, Customers, dataCust);
                cout<<"\n";
                break;
            }
            case 4: { // Mencari customer X [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 4. Mencari customer X ]]======\n\n";
                cout<<"--- Masukkan Nama\t\t: ";
                cin>>dataCust.name;
                cout<<"--- Masukkan NIK\t\t: ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP == NULL){ // or if(getCustomer(Customers, dataCust) != NULL){...}
                    cout<<"\n";
                    cout<<"--- Data Customer Tidak Ditemukan!\n";
                }else{
                    cout<<"\n";
                    cout<<"--- Customer Ditemukan!\n\n";
                    cout<<"========================================================\n\n";
                    cout<<"--- Data Customer\n";
                    cout<<"--- Nama\t\t\t: "<<data(custP).name<<"\n";
                    cout<<"--- NIK\t\t\t\t: "<<data(custP).NIK<<"\n";
                    cout<<"--- Umur\t\t\t: "<<data(custP).age<<"\n";
                    cout<<"--- Gender\t\t\t: "<<data(custP).gender<<"\n";
                    cout<<"--- Total kredit\t\t: "<<data(custP).totalCredits<<"\n";
                }
                cout<<"\n";
                break;
            }
            case 5: { // Menambahkan kartu kredit dari customer X [done] [clean]
                dataCredit dataCred;
                dataCustomer dataCust;
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 5. Menambahkan kartu kredit dari customer X ]]======\n\n";
                cout<<"--- Masukkan Nama\t\t\t: ";
                cin>>dataCust.name;
                cout<<"--- Masukkan NIK\t\t\t: ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){ // or if(getCustomer(Customers, dataCust) != NULL){...}
                    cout<<"\n";
                    cout<<"--- Data Customer Berhasil Ditemukan!\n\n";
                    cout<<"--- Masukkan Nama Kredit\t\t: ";
                    cin>>dataCred.creditName;
                    cout<<"--- Masukan Nomor Rekening\t\t: ";
                    cin>>dataCred.creditID;
                    adrCredit credP = getCredit(Credits, dataCred);
                    if(credP != NULL){
                        cout<<"\n";
                        cout<<"--- Data Kredit Sudah Ada Dalam List!\n";
                    }else{
                        addCreditToCustomer(Credits, Customers, dataCred, dataCust);
                        cout<<"\n";
                        cout<<"--- Kartu Kredit Berhasil Ditambahkan!\n";
                    }
                }else{
                    cout<<"\n";
                    cout<<"--- Data Customer Tidak Ditemukan!\n";
                }
                cout<<"\n";
            break;
            }
            case 6: { // Menghapus kartu kredit dari customer X [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 6. Menghapus kartu kredit dari customer X ]]======\n\n";
                cout<<"--- Masukkan Nama\t\t: ";
                cin>>dataCust.name;
                cout<<"--- Masukkan NIK\t\t: ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){
                    deleteAllCreditInCustomer(Credits, Customers, dataCust);
                }else{
                    cout<<"\n";
                    cout<<"--- Customer Tidak Terdaftar!\n";
                }
                break;
                cout<<"\n";
            }
            case 7: { // Menampilkan seluruh kartu kredit dari customer X [done] [clean]
                dataCustomer dataCust;
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 7. Menampilkan seluruh kartu kredit dari customer X ]]======\n\n";
                cout<<"--- Masukkan Nama\t\t: ";
                cin>>dataCust.name;
                cout<<"--- Masukkan NIK\t\t: ";
                cin>>dataCust.NIK;
                cout<<"\n";
                showCustomerCredit(Credits, Customers, dataCust);
                cout<<"\n";
                break;
            }
            case 8: { // Mencari kartu kredit Y dari customer X [done] [clean]
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 8. Mencari kartu kredit Y dari customer X ]]======\n\n";
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"--- Masukkan Nama\t\t\t: ";
                cin>>dataCust.name;
                cout<<"--- Masukkan NIK\t\t\t: ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){ // or if(getCustomer(Customers, dataCust) != NULL){...}
                    cout<<"\n";
                    cout<<"--- Data Customer Berhasil Ditemukan!\n";
                    cout<<"\n";
                    cout<<"--- Masukkan Nama Kredit\t\t: ";
                    cin>>dataCred.creditName;
                    cout<<"--- Masukkan Nomor Rekening\t\t: ";
                    cin>>dataCred.creditID;
                    credP = getCredit(Credits, dataCred);
                    if(credP != NULL && child(credP) == custP){
                        cout<<"\n";
                        cout<<"--- Data Customer Dengan Kredit "<<dataCred.creditName
                        <<" Dan Nomor Rekening "<<dataCred.creditID<<" : \n";
                        showCustomerData(Customers, dataCust);
                    }else{
                        cout<<"\n";
                        cout<<"--- Data Kredit Tidak Ditemukan!";
                        cout<<"\n";
                    }
                }else{
                    cout<<"\n";
                    cout<<"--- Data Customer Tidak Ditemukan!\n";
                }
                cout<<"\n";
                break;
            }
            case 9: { // Membuat relasi antara customer X dan kartu kredit Y [done] [clean]
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 9. Membuat relasi antara customer X dan kartu kredit Y ]]======\n\n";
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"--- Masukkan Nama\t\t\t: ";
                cin>>dataCust.name;
                cout<<"--- Masukkan NIK\t\t\t: ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){ // or if(getCustomer(Customers, dataCust) != NULL){...}
                    cout<<"\n";
                    cout<<"--- Nama Customer Berhasil Ditemukan!\n";
                    cout<<"\n";
                    cout<<"--- Masukkan Nama Kredit\t\t: ";
                    cin>>dataCred.creditName;
                    cout<<"--- Masukan Nomor Rekening\t\t: ";
                    cin>>dataCred.creditID;
                    connectCreditToCustomer(Credits, Customers, dataCred, dataCust);
                    cout<<"\n";
                    cout<<"--- Berhasil Menghubungkan Kartu Kredit Dengan Customer!\n";
                }else{
                    cout<<"\n";
                    cout<<"--- Data Customer Tidak Ditemukan!\n";
                }
                cout<<"\n";
                break;
            }
            case 10: { // Menghapus relasi antara customer X dan kartu kredit Y
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 10. Menghapus relasi antara customer X dan kartu kredit Y ]]======\n\n";
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"--- Masukkan Nama\t\t\t: ";
                cin>>dataCust.name;
                cout<<"--- Masukkan NIK\t\t\t: ";
                cin>>dataCust.NIK;
                custP = getCustomer(Customers, dataCust);
                if(custP != NULL){ // // or if(getCustomer(Customers, dataCust) != NULL){...}
                    cout<<"\n";
                    if(data(custP).totalCredits > 0){
                        cout<<"===============================================\n";
                        cout<<"\n";
                        showCustomerCredit(Credits, Customers, dataCust);
                         cout<<"\n";
                        cout<<"===============================================\n";
                        cout<<"\n";
                        cout<<"--- Masukkkan Data Credit Yang Ingin Dihapus\n";
                        cout<<"--- Nama kredit\t\t\t\t: ";
                        cin>>dataCred.creditName;
                        cout<<"--- Nomor rekening\t\t\t: ";
                        cin>>dataCred.creditID;
                        credP = getCredit(Credits, dataCred);
                        if(credP == NULL){
                            cout<<"\n";
                            cout<<"--- Data Kredit Tidak Ditemukan/Tidak Terdaftar!\n";
                        }else{
                            disconnectCreditAndCustomer(Credits, Customers, dataCred, dataCust);
                            cout<<"\n";
                            cout<<"--- Berhasil Memutuskan Hubungan Antara Kartu Kredit Dengan Customer\n";
                        }
                    }else{
                        cout<<"\n";
                        cout<<"--- Customer Tidak Memiliki Kartu Kredit!\n";
                    }
                }else{
                    cout<<"\n";
                    cout<<"--- Data Customer Tidak Ditemukan!\n";
                }
                cout<<"\n";
                break;
            }
            case 11: { // Menampilkan data customer yang memiliki kredit terbanyak
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 11. Menampilkan data customer yang memiliki kredit terbanyak ]]======\n\n";
                showHighestCustomerCredits(Credits, Customers);
                cout<<"\n";
                break;
            }
            case 12: { // Mencari nama customer dari kartu kredit Y
                system("cls");
                cout<<"\n";
                cout<<"\t\t\t======[[ 12. Mencari nama customer dari kartu kredit Y ]]======\n\n";
                dataCredit dataCred;
                dataCustomer dataCust;
                cout<<"--- Masukkan Nama\t\t: ";
                cin>>dataCred.creditName;
                cout<<"--- Masukkan Nomor Rekening\t: ";
                cin>>dataCred.creditID;
                credP = getCredit(Credits, dataCred);
                if(credP == NULL){ // or if(getCredit(Credits, dataCred) != NULL){...}
                    cout<<"\n";
                    cout<<"-- Data Kredit Tidak Ditemukan/Tidak Terdaftar\n";
                }else{
                    custP = getCustomerFromCredit(Credits, Customers, dataCred);
                    if(custP == NULL){
                        cout<<"\n";
                        cout<<"--- Kartu Kredit Ini Tidak Memiliki Relasi Ke Customer\n";
                    }else{
                        cout<<"\n";
                        cout<<"--- Data Customer\n";
                        showCustomerData(Customers, data(custP));
                    }  
                }
                cout<<"\n";
                break;
            }
            default:
                break;
        }
        string state;
        cout<<"--- Kembali ke menu utama (ya\\tidak): ";
        cin>>state;
        while(state != "ya" && state !="tidak"){
            cout<<"--- Entry kurang tepat!\n";
            cout<<"--- Kembali ke menu utama (ya\\tidak): ";
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
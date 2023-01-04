#include "MLL1toN.h"
void insertLastCustomer(listCustomer &Customers, adrCustomer custP) { // CSLL [done]
// {I.S Pelanggan mungkin belum ada atau sudah ada
//  F.S Menambahkan pelanggan kedalam daftar pelanggan}
    if(first(Customers) == NULL) {
        first(Customers) = custP;
        nextCustomer(custP) = first(Customers);
    } else {
        adrCustomer thisCustomer = first(Customers);
        while(nextCustomer(thisCustomer) != first(Customers)) {
            thisCustomer = nextCustomer(thisCustomer);
        }
        nextCustomer(thisCustomer) = custP;
        nextCustomer(custP) = first(Customers);
    }
} // 1
void showCustomerData(listCustomer &Customers, dataCustomer cust) { // CSLL [done]
// {I.S Daftar pelanggan mungkin belum ada atau sudah ada
//  F.S Menampilkan data tiap pelangan di daftar pelanggan}
    if(first(Customers) == NULL) {
        cout<<"Tidak ada pelanggan yang terdaftar\n";
    } else {
        adrCustomer thisCustomer = getCustomer(Customers, cust);
        cout<<"Nama\t\t: "<<data(thisCustomer).name<<"\n";
        cout<<"Jenis Kelamin\t: "<<data(thisCustomer).gender<<"\n";
        cout<<"Umur\t\t: "<<data(thisCustomer).age<<"\n";
        cout<<"Total Credit\t: "<<data(thisCustomer).totalCredits<<"\n\n";
        thisCustomer = nextCustomer(thisCustomer);
    }
} // 2
adrCredit getCreditInCustomer(listCredit Credits, dataCredit cred, dataCustomer cust) { // [done]
// {I.S -
//  F.S Mengembalikan address kartu kredit dari sebuah pelanggan}
    if(first(Credits) != NULL){
        adrCredit thisCredit = first(Credits);
        while(thisCredit != NULL && data(child(thisCredit)).name != cust.name) {
            thisCredit = nextCredit(thisCredit);
        }
        return thisCredit;
    }
    return NULL;
} // 8
void deleteCreditInCustomer(listCredit &Credits, listCustomer &Customers, dataCustomer cust) { // [done]
// {I.S terdaftar tiap kredit dari pelanggan atau tidak
//  F.S menghapus tiap kredit yang dimiliki oleh pelanggan}
    int deletedCredits;
    adrCredit deletedCreditP;
    adrCredit thisCredit = first(Credits);
    while(thisCredit != NULL) {
        if(data(child(thisCredit)).name == cust.name) {
            disconnectCreditAndCustomer(Credits, Customers, data(thisCredit), data(child(thisCredit)));
            cout<<"1";
            cout<<"2";
            if(thisCredit == first(Credits)) {
                cout<<"3";
                deleteFirstCredit(Credits, deletedCreditP);
                cout<<"4";
            } else if(nextCredit(thisCredit) == NULL) {
                cout<<"5";
                deleteLastCredit(Credits, deletedCreditP);
                cout<<"6";
            } else {
                cout<<"7";
                deleteAfterCredit(Credits, deletedCreditP, data(thisCredit));
            }
            ++deletedCredits;
            cout<<"2";
        }
        thisCredit = nextCredit(thisCredit);
    }
    if(deletedCredits == 0) {
        cout<<"Pelanggan tidak mempunyai kredit yang terdaftar\n";
    } else {
        cout<<"Berhasil mengapus kartu kredit\n";
    }
} // 6
adrCustomer getCustomerFromCredit(listCredit Credits, dataCredit cred) {
// {I.S -
//  F.S Mengembalikan address pelanggan dari daftar kredit}
    adrCredit thisCredit = first(Credits);
    while(thisCredit != NULL && data(thisCredit).creditID == cred.creditID) {
        thisCredit = nextCredit(thisCredit);
    }
    cout<<"1";
    return child(thisCredit);
} // (12)
void connectCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, dataCustomer cust) {
// {I.S Kredit belum memiliki child (terkoneksi) dengan pelanggan atau daftar kredit kosong
//  F.S Melakukan konektivitas pelanggan dengan kartu kredit nya}
    adrCustomer thisCustuomer = getCustomer(Customers, cust);
    if(thisCustuomer != NULL) {
        adrCredit thisCredit = first(Credits);
        while(thisCredit != NULL && data(thisCredit).creditID != cred.creditID) {
            thisCredit = nextCredit(thisCredit);
        }
        child(thisCredit) = thisCustuomer;
        ++data(thisCustuomer).totalCredits;
    } else {
        cout<<"Pelanggan tidak terdaftar\n";
    }
} // (9)
void deleteFirstCredit(listCredit &Credits, adrCredit &credP) {
    if(first(Credits) == NULL) {
        cout<<"Tidak ada kredit yang terdaftar\n";
    }else if(nextCredit(first(Credits)) == NULL) {
        credP = first(Credits);
        first(Credits) = NULL;
    } else {
        credP = first(Credits);
        first(Credits) = nextCredit(first(Credits));
    }
} // (13)
void deleteAfterCredit(listCredit &Credits, adrCredit &credP, dataCredit cred) {
    if(first(Credits) == NULL) {
        cout<<"Tidak ada kredit yang terdaftar\n";
    } else {
        adrCredit precCredit = first(Credits);
        while((data(nextCredit(precCredit)).creditID != cred.creditID)) {
            precCredit = nextCredit(precCredit);
        }
        credP = nextCredit(precCredit);
        nextCredit(precCredit) = nextCredit(credP);
        nextCredit(credP) = NULL;
    }
} // (13)
void deleteLastCredit(listCredit &Credits, adrCredit &credP) {
    if(first(Credits) == NULL) {
        cout<<"Tidak ada kredit yang terdaftar\n";
    } else if(next(first(Credits)) == NULL) {
        credP = first(Credits);
        first(Credits) == NULL;
    } else {
        adrCredit thisCredit = first(Credits);
        adrCredit P;
        while(next(thisCredit) != NULL) {
            P = thisCredit;
            thisCredit = nextCredit(thisCredit);
        }
        credP = thisCredit;
        nextCredit(P) == NULL;
    }
} // (13)
void createListCredit(listCredit &Credits) {
    first(Credits) = NULL;
} // (14)
adrCredit createElementCredit(listCredit &Credits, dataCredit data) {
    adrCredit thisCredit = new elmCredit;
    data(thisCredit) = data;
    nextCredit(thisCredit) = NULL;
    return thisCredit;
} // (14)
void insertLastCredit(listCredit &Credits, adrCredit credP) {
    if(first(Credits) == NULL) {
        first(Credits) = credP;
    } else {
        adrCredit thisCredit = first(Credits);
        while(nextCredit(thisCredit) != NULL) {
            thisCredit = nextCredit(thisCredit);
        }
        nextCredit(thisCredit) = credP;
    }
} // (15)

void menu(int &command) {
    cout<<"[1] Menambahkan customer baru\n";
    cout<<"[2] Menampilkan data customer\n";
    cout<<"[3] Menghapus customer tertentu\n";
    cout<<"[4] Mencari customer X\n";
    cout<<"[5] Menambahkan kartu kredit dari customer X\n";
    cout<<"[6] Menghapus kartu kredit dari customer X\n";
    cout<<"[7] Menampilkan seluruh kartu kredit dari customer X\n";
    cout<<"[8] Mencari kartu kredit Y dari customer X\n";
    cout<<"[9] Membuat relasi antara customer X dan kartu kredit Y\n";
    cout<<"[10] Menghapus relasi antara customer X dan kartu kredit Y\n";
    cout<<"[11] Menampilkan data customer yang memiliki kredit terbanyak\n";
    cout<<"[12] Mencari nama customer dari kartu kredit Y\n";
    cout<<"[0] exit\n";
    cout<<"Masukan Angka: ";
    cin>>command;
}
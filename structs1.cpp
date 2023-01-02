#include "MLL1toN.h"
void insertLastCustomer(listCustomer &Customers, adrCustomer custP) { // CSLL [done]
// {I.S Pelanggan mungkin belum ada atau sudah ada
//  F.S Menambahkan pelanggan kedalam daftar pelanggan}
    if(first(Customers) == NULL) {
        first(Customers) = custP;
        nextCustomer(custP) = first(Customers);
    } else {
        adrCustomer thisCustomer = first(Customers);
        while(next(thisCustomer) != first(Customers)) {
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
        cout<<"========================DAFTAR PELANGGAN========================\n";
        adrCustomer thisCustomer = first(Customers);
        do {
            cout<<"Nama\t\t: "<<data(thisCustomer).name<<"\n";
            cout<<"Jenis Kelamin\t: "<<data(thisCustomer).gender<<"\n";
            cout<<"Umur\t\t: "<<data(thisCustomer).age<<"\n";
            cout<<"Total Credit\t: "<<data(thisCustomer).totalCredits<<"\n\n";
            thisCustomer = nextCustomer(thisCustomer);
        } while(thisCustomer != first(Customers));
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
void deleteCreditInCustomer(listCredit &Credits, listCustomer &Customers, string namaCust) { // [done]
// {I.S terdaftar tiap kredit dari pelanggan atau tidak
//  F.S menghapus tiap kredit yang dimiliki oleh pelanggan}
    int deletedCredits;
    adrCredit deletedCreditP;
    adrCredit thisCredit = first(Credits);
    while(thisCredit != NULL) {
        if(data(child(thisCredit)).name == namaCust) {
            disconnectCreditAndCustomer(Credits, Customers, data(thisCredit), data(child(thisCredit)));
            if(thisCredit == first(Credits)) {
                deleteFirstCredit(Credits, deletedCreditP);
            } else if(nextCredit(thisCredit) == NULL) {
                deleteLastCredit(Credits, deletedCreditP);
            } else {
                deleteAfterCredit(Credits, deletedCreditP, data(thisCredit));
            }
            ++deletedCredits;
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
//  F.S Mengembaalikan address pelanggan dari daftar kredit}
    
} // (12)
void connectCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, dataCustomer cust) {
// {I.S Kredit belum memiliki child (terkoneksi) dengan pelanggan atau daftar kredit kosong
//  F.S Melakukan konektivitas pelanggan dengan kartu kredit nya}
} // (9)
void deleteFirstCredit(listCredit &Credits, adrCredit &credP) {
    if(first(Credits) == NULL) {
        cout<<"Tidak ada kredit yang terdaftar\n";
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
    if(first(Credits) != NULL) {
        first(Credits) = credP;
    } else {
        adrCredit thisCredit = first(Credits);
        while(nextCredit(thisCredit) != NULL) {
            thisCredit = nextCredit(thisCredit);
        }
        nextCredit(thisCredit) = credP;
    }
} // (15)
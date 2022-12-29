#ifndef MLL1TON_H_INCLUDED
#define MLL1TON_H_INCLUDED
#include <bits\stdc++.h>
using namespace std;
#define nextCustomer(P) P->nextCustomer
#define nextCredit(P) P->nextCredit
#define data(P) P->data
#define child(P) P->child
#define first(L) ((L).first)

// Credit Abstract Data Type [single linked list]
struct dataCredit {
    string creditName, creditID; 
};
typedef struct elmCredit *adrCredit;
struct elmCredit {
    dataCredit data;
    adrCredit nextCredit;
    adrCustomer child;
};

// Customer Abstract Data Type [single circular linked list]
struct dataCustomer {
    string name, gender, creditID;
    int age;
};
typedef struct elmCustomer *adrCustomer;
struct elmCustomer {
    dataCustomer data;
    adrCustomer nextCustomer;
};

// Lists Abstract Data Type
struct listCredit {
    adrCredit first;
};
struct listCustomer {
    adrCustomer first;
};

// create lists and elements
// credit
void createListCredit(listCredit &Credits);
void createElementCredit(listCredit &Credits, dataCredit data);
// customer
void createlistCustomer(listCustomer &Customers);
void creatElementCustomer(listCustomer &Customers, dataCustomer data);


// insert data to lists
void insertLastCredit(listCredit &Credits, adrCredit credP);
// menambakan customer baru
void insertLastCustomer(listCustomer &Customers, adrCustomer custP); // (1)


// show customer X data [name, age, gender, creditName]
// menampilkan data customer X
void showCustomerData(listCustomer &Customers, dataCustomer cust); // (2)


// delete customer
// menghapus customer tertentu
void deleteCustomer(listCredit &Credits, listCustomer &Customers, dataCustomer cust); // (3)


// find customer
// mencari customer X
adrCustomer getCustomer(listCustomer Customers, dataCustomer cust); // (4)


// add new credit to customer X
// menambahkan kartu kredit dari customer X
void addCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, string namaCust); // (5)


// delete credit from customer X
// menghapus kartu kredit dari customer X
void deleteCreditInCustomer(listCredit &Credits, listCustomer &Customers, string namaCust); // (6)


// show all credits from customer x
// menampilkan seluruh karut kredit dari customer X
void showCustomerCredit(listCredit &Credits, listCustomer &Customers, dataCustomer cust); // (7)


// find credit from customer
// mencari kartu kredit Y dari customer X
adrCredit getCreditInCustomer(listCredit Credits, dataCredit cred, dataCustomer cust); // (8)


// connect credit to customer
// membuat relasi antara customer X dan kartu kredit Y
void connectCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, dataCustomer cust); // (9)


// delete connection betweeen credit and customer
// menghapus relasi antara customer X dan kartu kredit Y
void disconnectCreditAndCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, dataCustomer cust); // (10)


// highest credit cards owner
// menampilkan customer yang memiliki jumlah kartu kredit yang paling banyak dan menampilkan kartu kredit tersebut
void showHighestCustomerCredits(listCredit &Credits, listCustomer &Customers); // (11)


// find customer name from the credit cards identity
// Mencari nama customer dari kartu kredit Y 
adrCustomer getCustomerFromCredit(listCredit Credits, dataCredit cred); // (12)


// extra function and procedure
// credit delete [single linked list]
void deleteFirstCredit(listCredit &Credits, adrCredit credP);
void deleteAfterCredit(listCredit &Credits, adrCredit credP);
void deleteLastCredit(listCredit &Credits, adrCredit credP);
// customer delete [single circular linked list]
void deleteFirstCustomer(listCustomer &Customers, adrCustomer custP);
void deleteAfterCustomer(listCustomer &Customers, adrCustomer custP);
void deleteLastCustomer(listCustomer &Customers, adrCustomer custP);


#endif // MLL1TON_H_INCLUED
/* placeholder
//----------------------------------------------------------
// count child from specific parent
int countChild (listCredit&Credits, dataCredit data);

// connecting parent to child
void connectingParentToChild (listCredit &Credits, listCustomer Customers, dataCredit dataP, data dataC);

// delete child from a specific parent
// ini hapus child dari list child? atau cuma hapus hubungan parent ke child???
void deleteChildfromParent (listCredit &Credits, dataCredit dataP, data dataC);
*/
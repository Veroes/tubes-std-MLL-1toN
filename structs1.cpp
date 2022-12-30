#include "MLL1toN.h"
void insertLastCustomer(listCustomer &Customers, adrCustomer custP) { // CSLL [done]
    if(first(Customers) == NULL) {
        first(Customers) = custP;
        nextCustomer(first(Customers)) = first(Customers);
    } else {
        adrCustomer thisCustomer = first(Customers);
        while(next(thisCustomer) != first(Customers)) {
            thisCustomer = nextCustomer(thisCustomer);
        }
        nextCustomer(thisCustomer) = custP;
        nextCustomer(custP) = first(Customers);
    }
} // 1
void showCustomerData(listCustomer &Customers, dataCustomer cust) { // CSLL []
    if(first(Customers) == NULL) {
        cout<<"Tidak ada pelanggan yang terdaftar\n";
    } else {
        adrCustomer thisCustomer = first(Customers);
        while(thisCustomer != NULL) {
            if(data(thisCustomer).name == cust.name || data(thisCustomer).creditID == cust.creditID) {
                cout<<"";
                break;
            } else {
                thisCustomer = nextCustomer(thisCustomer);
            }
        }
    }
} // 2
adrCredit getCreditInCustomer(listCredit Credits, dataCredit cred, dataCustomer cust) {

} // 8
void deleteCreditInCustomer(listCredit &Credits, listCustomer &Customers, string namaCust) {

} // 6
adrCustomer getCustomerFromCredit(listCredit Credits, dataCredit cred) {

} // (12)
void connectCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, dataCustomer cust) {

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
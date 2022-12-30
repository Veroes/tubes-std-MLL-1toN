#include "MLL1toN.h"
void insertLastCustomer(listCustomer &Customers, adrCustomer custP) {

} // 1
void showCustomerData(listCustomer &Customers, dataCustomer cust) {

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
    } else if(nextCredit(first(Credits)) == NULL) {
        credP = first(Credits);
        first(Credits) = NULL;
    } else {
        adrCredit thisCredit = first(Credits);
        first(Credits) = nextCredit(thisCredit);
        credP = thisCredit;
        nextCredit(thisCredit) = NULL;
    }
} // (13)
void deleteAfterCredit(listCredit &Credits, adrCredit &credP) {

} // (13)
void deleteLastCredit(listCredit &Credits, adrCredit &credP) {

} // (13)
void createListCredit(listCredit &Credits) {
    first(Credits) = NULL;
} // (14)
adrCredit createElementCredit(listCredit &Credits, dataCredit data) {
    adrCredit thisCredit = new elmCredit;
    data(thisCredit) = data;
    nextCredit(thisCredit) = NULL;
} // (14)
void insertLastCredit(listCredit &Credits, adrCredit credP) {
    if(first(Credits) == NULL) {
        cout<<"Tidak ada kredit yang terdaftar\n";
    } else {
        adrCredit thisCredit = first(Credits);
        while(nextCredit(thisCredit) != NULL) {
            thisCredit = nextCredit(thisCredit);
        }
        nextCredit(thisCredit) = credP;
    }
} // (15)
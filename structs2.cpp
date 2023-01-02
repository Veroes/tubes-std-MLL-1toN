#include "MLL1toN.h"
//void addCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, string namaCust) 
// string namaCust diganti ke dataCustomer cust gpp
void addCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, dataCustomer cust) { 
// IS : Terdefinisi nama customer X
// FS : Data credit baru ditambahkan ke dalam list credit sebagai elemen terakhir kemduian hubungkan cust x dengan elemen credit baru

// 1. cari cust x dalam list cust. kalo ga ada, return "cust tidak ditemukan"
// 2. kalo ada, create elmCredit untuk memasukkan data credit baru
// 3. hubungkan cust x dengan elemen credit baru
    
    adrCredit pCred;
    adrCustomer pCust;

    dataCustomer dCust;
    dCust = data(pCust);
    
    pCust = getCustomer(Customers, cust);
    if(pCust==NULL){
        cout<<"The customer's name is not found!";
    }else{
        pCred = createElementCredit(Credits, cred);
        insertLastCredit(Credits, pCred);
        connectCreditToCustomer(Credits, Customers, cred, dCust);
    }
} // (5)

void showCustomerCredit(listCredit &Credits, listCustomer &Customers, dataCustomer cust){
// IS : Terdefinisi nama customer X
// FS : Seluruh kartu kredit dari cust x akan ditampilkan

// 1. cari cust x dalam list cust. kalo ga ada, return "cust tidak ditemukan"
// 2. kalo ada, cek apakah dia punya kredit
// 3. kalau ngga punya, cout "Tidak memiliki kartu kredit"
// 4. kalau punya, print kreditnya

    adrCustomer pCust;
    adrCredit pCred;
    int counter = 0;

    pCust = getCustomer(Customers, cust);    
    if(pCust==NULL){
        cout<<"The customer's name is not found!";
    }else{
        pCred = first(Credits);
        while(next(pCred) != first(Credits)){
            if(child(pCred) != NULL&& data(child(pCred)).name == cust.name){
                counter++;
                cout<<"Credit Name : "<<data(pCred).creditName<<endl;
                cout<<"Credit ID : "<<data(pCred).creditID<<endl;
                cout<<endl;
            }
            pCred = next(pCred);
        }
    }

    if(counter == 0){
    cout<<"The customer doesn't have a credit card!"<<endl;
    }
} // (7)

adrCustomer getCustomer(listCustomer Customers, dataCustomer cust){
// IS : Terdefinisi nama customer X
// FS : mengembalikan address dari elemen cust x jika ditemukan atau NULL jika tidak ditemukan

    adrCustomer pCust;

    if(first(Customers) == NULL){
        return NULL;
    }else{
        pCust = first(Customers);   
        while(next(pCust) != first(Customers) && data(pCust).name != cust.name){
            pCust = nextCustomer(pCust);
        }
    }
    return pCust;
}
// (4)

void deleteCustomer(listCredit &Credits, listCustomer &Customers, dataCustomer cust) {
// IS : Terdefinisi data customer
// FS : Menghapus seluruh credit card milik customer x dari list credit kemudian menghapus cust x dari list cust

// kalo listnya kosong, cout "list kosong"
// kalo cust nya ketemu, hapus semua credit yang cust punya
// cek list cust, kalau cuma isi 1 elemen atau elemen pertamanya == cust, pakai delete first
// hapus cust dari list cust : iterasi list cust sampai elm terakhir, kalau elm terakhir == cust, pakai delete last
// lainnya, pakai delete after
    
    adrCustomer gCust, pCust, custPrec;
    dataCredit dCred;
    
    gCust = getCustomer(Customers, cust);    // Kalo retrun null bisajadi list kosong atau data emang ga ditemuin
    if(gCust != NULL){      
        deleteCreditInCustomer(Credits, Customers, cust.name);  

        if(nextCustomer(first(Customers)) == first(Customers) || first(Customers) == gCust){                 
            deleteFirstCustomer(Customers, gCust);
        }else{
            pCust = first(Customers);
            while(nextCustomer(pCust) != first(Customers)){
                pCust = nextCustomer(pCust);
            }
            
            if(pCust == gCust){
                deleteLastCustomer(Customers, pCust);
            }else{
                deleteAfterCustomer(Customers, pCust, custPrec);
            } 
        }
    }else{
        cout<<"Cannot delete data! The customer's name is not found"<<endl;
    }
} // (3)

void showHighestCustomerCredits(listCredit &Credits, listCustomer &Customers) {
} // (11)

void disconnectCreditAndCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, dataCustomer cust) {
// IS : Terdefinisi data credit y dan data cust x 
// FS : memutuskan relasi antara credit y dan cust x

    adrCustomer pCust;
    adrCredit pCred;     

    pCust = getCustomerFromCredit(Credits, cred);
    if(pCust == NULL){
        cout<<"The customer's name is not found!"<<endl;
    }else{
        pCred = first(Credits);
        while(pCred != NULL && data(child(pCred)).name != cust.name){
            pCred = nextCredit(pCred);
        }
        child(pCred) = NULL;
    }
} // (10)

void createlistCustomer(listCustomer &Customers) {
    first(Customers) = NULL; 
} // (16)

adrCustomer createElementCustomer(listCustomer &Customers, dataCustomer data) {
    adrCustomer C = new elmCustomer;
    data(C) = data;
    nextCustomer(C) = NULL;
    return C;
} // (16)

void deleteFirstCustomer(listCustomer &Customers, adrCustomer &custP) {
// IS : List mungkin kosong atau berisi satu elemen
// FS : custP berisi elemen pertama yang dihapus dari list customer

    adrCustomer custQ;

    if(nextCustomer(first(Customers)) == first(Customers)){
        custP = first(Customers);
        nextCustomer(custP) = NULL;
        first(Customers) = NULL;
    }else{
        custQ = first(Customers);
        while(nextCustomer(custQ) != first(Customers)){
            custQ = nextCustomer(custQ);
        }

        custP = first(Customers);
        first(Customers) = nextCustomer(first(Customers));
        nextCustomer(custQ) = first(Customers);
        nextCustomer(custP) = NULL;
    }
} // (17)

void deleteAfterCustomer(listCustomer &Customers, adrCustomer &custP, adrCustomer custPrec) { // nambah parameter
//void deleteAfterCustomer(listCustomer &Customers, adrCustomer &custP, dataCustomer cust) // dataCustomernya buat apa?
// IS : List tidak kosong, custP adalah alamat cust yang akan dihapus
// FS : custPrec menyimpan elemen yang dihapus
    
    adrCustomer custQ;

    if(nextCustomer(first(Customers)) != first(Customers)){
        custQ = first(Customers);
        while(data(nextCustomer(custQ)).name != data(custP).name){
            custQ = nextCustomer(custQ);
        }
        custPrec = nextCustomer(custQ);
        nextCustomer(custQ) = nextCustomer(custPrec);
        nextCustomer(custPrec) =  NULL;
    }
}// (17)

void deleteLastCustomer(listCustomer &Customers, adrCustomer &custP) {
// IS : List tidak kosong
// FS : custP adalah elemen terakhir yang dihapus dari list customer
    adrCustomer custQ;
    
    custQ = first(Customers);
    while(nextCustomer(nextCustomer(custQ)) != first(Customers)){
        custQ = nextCustomer(custQ);
    }   
    custP = nextCustomer(custQ);
    nextCustomer(custQ) = first(Customers);
    nextCustomer(custP) = NULL;
} // (17)

//==========================================================================================================
/*
struct dataCustomer {
    string name, gender;
    int age
    int totalCredits;         //update tiap insert new credit
};
*/

void showHighestCustomerCredits(listCredit &Credits, listCustomer &Customers){
// IS : terdefinisi list cust dan lust credit mungkin kosong
// FS : menampilkan data customer dengan jumlah kredit terbanyak beserta kartu kredit yang dimilikinya

    adrCustomer pCust;
    dataCustomer dCust;
    dCust = data(pCust);
    int highestCredits = 0;

    if(first(Customers) != NULL){
        cout<<"Customers data is empty!"<<endl;
    }else{
        pCust = first(Customers);
        while(nextCustomer(pCust) != first(Customers)){
            if(data(pCust).totalCredits > highestCredits){
                highestCredits = data(pCust).totalCredits;
            }
            pCust = nextCustomer(pCust);
        }
    }

    cout<<"============= HIGHEST CUSTOMER CREDITS DATA ==============="<<endl;
    showCustomerData(Customers, dCust);
    showCustomerCredit(Credits, Customers, dCust);

// kalo ada yg punya jumlah credit yang sama dengan highestcred, tampilkan jg
    pCust = first(Customers);
    while(nextCustomer(pCust) != first(Customers)){
        if(data(pCust).totalCredits == highestCredits){
            showCustomerData(Customers, dCust);
            showCustomerCredit(Credits, Customers, dCust);
        }
        pCust = nextCustomer(pCust);
    }
}
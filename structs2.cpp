#include "MLL1toN.h"
void createlistCustomer(listCustomer &Customers){ // CSLL [done] [clean]
// {I.S : -
//  F.S : Membuat daftar customer}
    first(Customers) = NULL; 
} // (16)

adrCustomer createElementCustomer(listCustomer &Customers, dataCustomer dataCust){ // [done] [clean]
// {I.S : Masukkan berupa data customer
//  F.S : Membuat elemen data customer tersebut}
    adrCustomer thisCredit = new elmCustomer;
    data(thisCredit) = dataCust;
    nextCustomer(thisCredit) = NULL;
    return thisCredit;
} // (16)

void deleteFirstCustomer(listCustomer &Customers, adrCustomer &custP){ // CSLL [done] [clean]
// {I.S : List mungkin berisi satu elemen atau lebih
//  F.S : custP berisi elemen pertama yang dihapus dari list customer}
    adrCustomer thisCustomer;
    if(nextCustomer(first(Customers)) == first(Customers)){
        custP = first(Customers);
        nextCustomer(custP) = NULL;
        first(Customers) = NULL;
    }else{
        thisCustomer = first(Customers);
        while(nextCustomer(thisCustomer) != first(Customers)){
            thisCustomer = nextCustomer(thisCustomer);
        }
        custP = first(Customers);
        first(Customers) = nextCustomer(first(Customers));
        nextCustomer(thisCustomer) = first(Customers);
        nextCustomer(custP) = NULL;
    }
} // (17)

void deleteAfterCustomer(listCustomer &Customers, adrCustomer &custP, dataCustomer dataCust){ // CSLL [done] [clean]
// {I.S : List tidak kosong, cust adalah dataCustomer yang akan dihapus
//  F.S : custP menyimpan elemen yang dihapus}
    adrCustomer thisCustomer;
    if(nextCustomer(first(Customers)) != first(Customers)){
        thisCustomer = first(Customers);
        while(data(nextCustomer(thisCustomer)).name != dataCust.name && data(nextCustomer(thisCustomer)).NIK != dataCust.NIK){
            thisCustomer = nextCustomer(thisCustomer);
        }
        custP = nextCustomer(thisCustomer);
        nextCustomer(thisCustomer) = nextCustomer(custP);
        nextCustomer(custP) =  NULL;
    }
}// (17)

void deleteLastCustomer(listCustomer &Customers, adrCustomer &custP) { // CSLL [done] [clean]
// {I.S : List tidak kosong
//  F.S : custP adalah elemen terakhir yang dihapus dari list customer}
    adrCustomer thisCustomer;
    thisCustomer = first(Customers);
    while(nextCustomer(nextCustomer(thisCustomer)) != first(Customers)){
        thisCustomer = nextCustomer(thisCustomer);
    }   
    custP = nextCustomer(thisCustomer);
    nextCustomer(thisCustomer) = first(Customers);
    nextCustomer(custP) = NULL;
} // (17)

adrCustomer getCustomer(listCustomer Customers, dataCustomer dataCust){ // CSLL [done] [clean]
// {I.S : Terdefinisi nama customer X
//  F.S : Mengembalikan address dari elemen cust X jika ditemukan atau NULL jika tidak ditemukan}
    adrCustomer thisCustomer = first(Customers);
    if(thisCustomer == NULL){
        return NULL;
    }else{
        do{
            if(data(thisCustomer).NIK == dataCust.NIK){
                return thisCustomer;
            }else{
                thisCustomer = nextCustomer(thisCustomer);
            }
        }while(thisCustomer != first(Customers));
        return NULL;
    }
}
// (4)

adrCredit getCredit(listCredit Credits, dataCredit dataCred){ // SLL [done] [clean]
// {I.S : Terdefinisi data credit Y
//  F.S : Mengembalikan address dari elemen credit Y jika ditemukan atau NULL jika tidak ditemukan}
    adrCredit thisCredit = first(Credits);
    while(thisCredit != NULL){
        if(data(thisCredit).creditID == dataCred.creditID){
            return thisCredit;
        }else{
            thisCredit = nextCredit(thisCredit);
        }
    }
    return NULL;
}

void addCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit dataCred, dataCustomer dataCust){ // [done] [clean]
// {I.S : Terdefinisi nama customer X
//  F.S : Data credit baru ditambahkan ke dalam list credit sebagai elemen terakhir
//        kemudian hubungkan cust x dengan elemen credit baru}
    adrCredit thisCredit = createElementCredit(Credits, dataCred);
    insertLastCredit(Credits, thisCredit);
    connectCreditToCustomer(Credits, Customers, dataCred, dataCust);
} // (5)

void showCustomerCredit(listCredit &Credits, listCustomer &Customers, dataCustomer dataCust){ // [done] [clean]
// {I.S : Terdefinisi nama customer X
//  F.S : Seluruh kartu kredit dari cust x akan ditampilkan}
    int counter = 0;
    adrCustomer thisCustomer;
    adrCredit thisCredit;
    thisCustomer = getCustomer(Customers, dataCust);    
    if(thisCustomer==NULL){
        cout<<"Customer tidak ditemukan\n";
    }else{
        thisCredit = first(Credits);
        while(thisCredit != NULL){
            if(child(thisCredit) != NULL && data(child(thisCredit)).name == dataCust.name){
                counter++;
                cout<<"Credit Name : "<<data(thisCredit).creditName<<"\n";
                cout<<"Credit ID : "<<data(thisCredit).creditID<<"\n\n";
            }
            thisCredit = nextCredit(thisCredit);
        }
        if(counter == 0){
            cout<<"Customer tidak memiliki kartu kredit\n";
        }
    }
} // (7)

void deleteCustomer(listCredit &Credits, listCustomer &Customers, dataCustomer dataCust) { // [done] [clean]
// {I.S : Terdefinisi data customer
// {F.S : Menghapus seluruh credit card milik customer X dari list credit 
//        kemudian menghapus customer X dari list customer}
    adrCustomer thisCustomer = getCustomer(Customers, dataCust);
    adrCustomer deletedCreditP;
    if(thisCustomer == NULL){     
        cout<<"Tidak bisa menghapus data customer! nama customer tidak ditemukan\n";
    }else{
        deleteAllCreditInCustomer(Credits, Customers, dataCust);
        if(thisCustomer == first(Customers)){
            deleteFirstCustomer(Customers, deletedCreditP);
        }else if(nextCustomer(thisCustomer) == first(Customers)){
            deleteLastCustomer(Customers, deletedCreditP);
        }else{
            deleteAfterCustomer(Customers, deletedCreditP, data(thisCustomer));
        }
    }
} // (3)

void disconnectCreditAndCustomer(listCredit &Credits, listCustomer &Customers, dataCredit dataCred, dataCustomer dataCust){ // [done] [clean]
// {I.S : Terdefinisi data credit Y dan data cust X
//  F.S : Memutuskan relasi antara credit Y dan cust X}
    adrCredit thisCredit = getCreditFromCustomer(Credits, Customers, dataCust);
    if(thisCredit == NULL){
        cout<<"Kartu kredit tidak terdaftar\n";
    }else{
        --data(child(thisCredit)).totalCredits;
        child(thisCredit) = NULL;
    }
} // (10)

void showHighestCustomerCredits(listCredit &Credits, listCustomer &Customers){ // [done] [clean]
// {I.S : Terdefinisi list cust dan lust credit mungkin kosong
//  F.S : Menampilkan data customer dengan jumlah kredit terbanyak beserta kartu kredit yang dimilikinya}
    if(first(Credits) == NULL){
        cout<<"Daftar Customer kosong\n";
    }else{
        adrCustomer thisCustomer = first(Customers);
        adrCustomer highestCustomer;
        int highestCredits = 0;
        do{
            if(data(thisCustomer).totalCredits > highestCredits){
                highestCredits = data(thisCustomer).totalCredits;
                highestCustomer = thisCustomer;
            }
            thisCustomer = nextCustomer(thisCustomer);
        }while(thisCustomer != first(Customers));
        cout<<"============= HIGHEST CUSTOMER CREDITS DATA ==============="<<endl;
        showCustomerData(Customers, data(highestCustomer));
        showCustomerCredit(Credits, Customers, data(highestCustomer));
    // {Menampilkan pelanggan yang total kredit sama banyak dengan highestCustomer jika ada}
        thisCustomer = first(Customers);
        do{
            if(thisCustomer != highestCustomer && data(thisCustomer).totalCredits == highestCredits){
                showCustomerData(Customers, data(thisCustomer));
                showCustomerCredit(Credits, Customers, data(thisCustomer));
            }
            thisCustomer = nextCustomer(thisCustomer);
        }while(thisCustomer != first(Customers));
    }
} // (11)
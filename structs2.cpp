#include "MLL1toN.h"
void addCreditToCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, dataCustomer cust){  
// IS : Terdefinisi nama customer X
// FS : Data credit baru ditambahkan ke dalam list credit sebagai elemen terakhir kemduian hubungkan cust x dengan elemen credit baru

// 1. cari cust x dalam list cust. kalo ga ada, return "cust tidak ditemukan"
// 2. kalo ada, create elmCredit untuk memasukkan data credit baru
// 3. hubungkan cust x dengan elemen credit baru
// 4. update totalCredits cust x
    
    adrCredit thisCredit;
    adrCustomer thisCustomer;

    dataCustomer dataCust;
    dataCust.name = data(thisCustomer).name;
    dataCust.age = data(thisCustomer).age;
    dataCust.gender = data(thisCustomer).gender;
    dataCust.totalCredits = data(thisCustomer).totalCredits;
    
    thisCustomer = getCustomer(Customers, cust);
    if(thisCustomer==NULL){
        cout<<"The customer's name is not found!";
    }else{
        thisCredit = createElementCredit(Credits, cred);
        insertLastCredit(Credits, thisCredit);
        connectCreditToCustomer(Credits, Customers, cred, dataCust);
        data(thisCustomer).totalCredits++;
    }
} // (5)

void showCustomerCredit(listCredit &Credits, listCustomer &Customers, dataCustomer cust){
// IS : Terdefinisi nama customer X
// FS : Seluruh kartu kredit dari cust x akan ditampilkan

// 1. cari cust x dalam list cust. kalo ga ada, return "cust tidak ditemukan"
// 2. kalo ada, cek apakah dia punya kredit
// 3. kalau ngga punya, cout "Tidak memiliki kartu kredit"
// 4. kalau punya, print kreditnya

    adrCustomer thisCustomer;
    adrCredit thisCredit;
    int counter = 0;

    thisCustomer = getCustomer(Customers, cust);    
    if(thisCustomer==NULL){
        cout<<"The customer's name is not found!";
    }else{
        thisCredit = first(Credits);
        while(next(thisCredit) != first(Credits)){
            if(child(thisCredit) != NULL && data(child(thisCredit)).name == cust.name){
                counter++;
                cout<<"Credit Name : "<<data(thisCredit).creditName<<endl;
                cout<<"Credit ID : "<<data(thisCredit).creditID<<endl;
                cout<<endl;
            }
            thisCredit = next(thisCredit);
        }
    }

    if(counter == 0){
    cout<<"The customer doesn't have a credit card!"<<endl;
    }
} // (7)

adrCustomer getCustomer(listCustomer Customers, dataCustomer cust){
// IS : Terdefinisi nama customer X
// FS : mengembalikan address dari elemen cust x jika ditemukan atau NULL jika tidak ditemukan

    adrCustomer thisCustomer;

    if(first(Customers) == NULL){
        return NULL;
    }else{
        thisCustomer = first(Customers);   
        while(next(thisCustomer) != first(Customers) && data(thisCustomer).name != cust.name){
            thisCustomer = nextCustomer(thisCustomer);
        }
    }
    return thisCustomer;
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
    
    adrCustomer gCust, thisCustomer;
    
    gCust = getCustomer(Customers, cust);    // Kalo retrun null bisajadi list kosong atau data emang ga ditemuin
    if(gCust != NULL){      
        deleteCreditInCustomer(Credits, Customers, cust.name);  

        if(nextCustomer(first(Customers)) == first(Customers) || first(Customers) == gCust){                 
            deleteFirstCustomer(Customers, gCust);
        }else{
            thisCustomer = first(Customers);
            while(nextCustomer(thisCustomer) != first(Customers)){
                thisCustomer = nextCustomer(thisCustomer);
            }
            
            if(thisCustomer == gCust){
                deleteLastCustomer(Customers, thisCustomer);
            }else{
                deleteAfterCustomer(Customers, thisCustomer, cust);
            } 
        }
    }else{
        cout<<"Cannot delete data! The customer's name is not found"<<endl;
    }
} // (3)

void disconnectCreditAndCustomer(listCredit &Credits, listCustomer &Customers, dataCredit cred, dataCustomer cust) {
// IS : Terdefinisi data credit y dan data cust x 
// FS : memutuskan relasi antara credit y dan cust x

    adrCustomer thisCustomer;
    adrCredit thisCredit;     

    thisCustomer = getCustomerFromCredit(Credits, cred);
    if(thisCustomer == NULL){
        cout<<"The customer's name is not found!"<<endl;
    }else{
        thisCredit = first(Credits);
        while(thisCredit != NULL && data(child(thisCredit)).name != cust.name){
            thisCredit = nextCredit(thisCredit);
        }
        child(thisCredit) = NULL;
    }
} // (10)

void createlistCustomer(listCustomer &Customers) {
    first(Customers) = NULL; 
} // (16)

adrCustomer createElementCustomer(listCustomer &Customers, dataCustomer data) {
    adrCustomer thisCredit = new elmCustomer;
    data(thisCredit).name = data.name;
    data(thisCredit).age = data.age;
    data(thisCredit).gender = data.gender;
    data(thisCredit).totalCredits = 0;
    nextCustomer(thisCredit) = NULL;
    return thisCredit;
} // (16)

void deleteFirstCustomer(listCustomer &Customers, adrCustomer &custP) {
// IS : List mungkin berisi satu elemen atau lebih
// FS : custP berisi elemen pertama yang dihapus dari list customer

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

void deleteAfterCustomer(listCustomer &Customers, adrCustomer &custP, dataCustomer cust){
// IS : List tidak kosong, cust adalah dataCustomer yang akan dihapus
// FS : custP menyimpan elemen yang dihapus
    
    adrCustomer thisCustomer;

    if(nextCustomer(first(Customers)) != first(Customers)){
        thisCustomer = first(Customers);
        while(data(nextCustomer(thisCustomer)).name != cust.name){
            thisCustomer = nextCustomer(thisCustomer);
        }
        custP = nextCustomer(thisCustomer);
        nextCustomer(thisCustomer) = nextCustomer(custP);
        nextCustomer(custP) =  NULL;
    }
}// (17)

void deleteLastCustomer(listCustomer &Customers, adrCustomer &custP) {
// IS : List tidak kosong
// FS : custP adalah elemen terakhir yang dihapus dari list customer
    adrCustomer thisCustomer;
    
    thisCustomer = first(Customers);
    while(nextCustomer(nextCustomer(thisCustomer)) != first(Customers)){
        thisCustomer = nextCustomer(thisCustomer);
    }   
    custP = nextCustomer(thisCustomer);
    nextCustomer(thisCustomer) = first(Customers);
    nextCustomer(custP) = NULL;
} // (17)

void showHighestCustomerCredits(listCredit &Credits, listCustomer &Customers){
// IS : terdefinisi list cust dan lust credit mungkin kosong
// FS : menampilkan data customer dengan jumlah kredit terbanyak beserta kartu kredit yang dimilikinya

    adrCustomer thisCustomer;
    dataCustomer dataCust;
    dataCust.name = data(thisCustomer).name;
    dataCust.age = data(thisCustomer).age;
    dataCust.gender = data(thisCustomer).gender;
    dataCust.totalCredits = data(thisCustomer).totalCredits;
    int highestCredits = 0;

    if(first(Customers) != NULL){
        cout<<"Customers data is empty!"<<endl;
    }else{
        thisCustomer = first(Customers);
        while(nextCustomer(thisCustomer) != first(Customers)){
            if(data(thisCustomer).totalCredits > highestCredits){
                highestCredits = data(thisCustomer).totalCredits;
            }
            thisCustomer = nextCustomer(thisCustomer);
        }
    }

    cout<<"============= HIGHEST CUSTOMER CREDITS DATA ==============="<<endl;
    showCustomerData(Customers, dataCust);
    showCustomerCredit(Credits, Customers, dataCust);

// kalo ada yg punya jumlah credit yang sama dengan highestCred, tampilkan jg
    thisCustomer = first(Customers);
    while(nextCustomer(thisCustomer) != first(Customers)){
        if(data(thisCustomer).totalCredits == highestCredits){
            showCustomerData(Customers, dataCust);
            showCustomerCredit(Credits, Customers, dataCust);
        }
        thisCustomer = nextCustomer(thisCustomer);
    }
}
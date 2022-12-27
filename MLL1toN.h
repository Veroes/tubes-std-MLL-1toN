#ifndef MLL1TON_H_INCLUDED
#define MLL1TON_H_INCLUDED
#include <bits\stdc++.h>
using namespace std;
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child
#define first(L) ((L).first)
struct infoParent {
    /**/
};
struct infoChild {
    /**/
};
typedef struct elmParent *adrParent;
typedef struct elmChild *adrChild;
struct elmParent {
    infoParent info;
    adrParent next;
    adrChild child;
};
struct elmChild {
    infoChild info;
    adrChild next;
};
struct listParent {
    adrParent first;
};
struct listChild {
    adrChild first;
};

// create lists and elements
void createListParent(listParent &LP);
void createListChild(listChild &LC);
void createElementParent(listParent &LP, infoParent data);
void creatElementChild(listChild &LC, infoChild data);
// insert data to lists
void insertLastParent(listParent &LP, adrParent P);
void insertLastChild(listChild &LC, adrChild C);
// show data
void showParent(listParent LP);
void showAll(listParent LP);
//  find parent and child
adrParent findParent(listParent LP, infoParent data);
adrChild findClid(listChild LC, infoChild data);
adrChild findChildInParent(listParent LP, infoChild data); // mencari data child pada parent
// delete parent and child
void deleteParent(listParent &LP, infoParent data);
void deleteChild(listChild &LC, infoChild data);
//  create delete first, after, and last
void deleteParentAndChild(listParent &LP, listChild &LC, adrParent dataP, adrChild dataC);

//----------------------------------------------------------
// count child from specific parent
int countChild (listParent LP, infoParent data);

// connecting parent to child
void connectingParentToChild (listParent &LP, listChild LC, infoParent dataP, infoChild dataC);

// delete child from a specific parent
// ini hapus child dari list child? atau cuma hapus hubungan parent ke child???
void deleteChildfromParent (listParent &LP, infoParent dataP, infoChild dataC);

#endif // MLL1TON_H_INCLUED
//
//  productManagement.h
//  Tubes_STD
//
//  Created by Navero Sandya on 26/11/2024.
//

#ifndef PRODUCTMANAGEMENT_H_INCLUDED
#define PRODUCTMANAGEMENT_H_INCLUDED
#include <iostream>
#include <stdio.h>
#define first(L) ((L).first)
#define next(P) P->next
#define info(P) P->info
using namespace std;

struct InfoProgrammer {
    string username;
    int totalProject;
};

struct InfoProject {
    string namaProject;
    int banyakProgrammer;
};

typedef struct elmProgrammer *adrPgr;
typedef struct elmProject *adrPrj;
typedef struct elmPenugasan *adrTugas;

struct elmProgrammer {
    InfoProgrammer info;
    adrPgr nextPgr;
    adrTugas firstPenugasan;
};

struct elmProject {
    InfoProject info;
    adrPrj nextPrj;
};

struct elmPenugasan {
    adrTugas nextTugas;
    adrTugas prevTugas;
    adrPrj project;
};

struct listProgrammer {
    adrPgr first;
};

struct listProject {
    adrPrj first;
};

void insertFirst_Programmer(listProgrammer &LPGR, adrPgr PG);
void insertFirst_Penugasan(listProgrammer &LPGR, adrPgr PG, adrTugas PT);
void insertLast_Project(listProject &LPRJ, adrPrj PJ);

void deleteFirst_Programmer(listProgrammer &LPGR, adrPgr PG);
void deleteFirst_Project(listProject &LPRJ, adrPrj PJ);
void deleteFirst_Penugasan(listProgrammer &LPGR, adrPgr PG, adrTugas PT);
void deleteLast_Programmer(listProgrammer &LPGR, adrPgr PG);
void deleteLast_Project(listProject &LPRJ, adrPrj PJ);
void deleteLast_Penugasan(listProgrammer &LPGR, adrPgr PG, adrTugas PT);
void deleteAfter_Programmer(listProgrammer &LPGR, adrPgr PG, adrPgr prec);
void deleteAfter_Project(listProject &LPRJ, adrPrj PJ, adrPrj prec );
void deleteAfter_Penugasan(listProgrammer &LPGR, adrPgr PG, adrTugas PT, adrTugas prec);

void view_Programmer(listProgrammer LPGR);
void view_Project(listProject LPRJ);
void view_Penugasan(listProgrammer LPGR);
void view_All(listProgrammer LPGR, listProject LPRJ);

#endif /* productManagement_h */

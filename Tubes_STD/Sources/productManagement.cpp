//
//  productManagement.cpp
//  Tubes_STD
//
//  Created by Navero Sandya on 26/11/2024.
//

#include <stdio.h>
#include <iostream>
#include "productManagement.h"
using namespace std;

void insertFirst_Programmer(listProgrammer &LPGR, adrPgr PG) {
    if (firstPGR(LPGR) == NULL) {
        firstPGR(LPGR) = PG;
    } else {
        nextPgr(PG) = firstPGR(LPGR);
        firstPGR(LPGR) = PG;
    }
}

void insertFirst_Penugasan(listProgrammer &LPGR, adrPgr PG, adrTugas PT) {
    if (firstPenugasan(PG) == NULL) {
        firstPenugasan(PG) = PT;
    } else {
        nextTugas(PT) = firstPenugasan(PG);
        prevTugas(firstPenugasan(PG)) = PT;
        firstPenugasan(PG) = PT;
    }
}

void insertLast_Project(listProject &LPRJ, adrPrj PJ) {
    if (firstPRJ(LPRJ) == NULL) {
        firstPRJ(LPRJ) = PJ;
    } else {
        adrPrj p = firstPRJ(LPRJ);
        while (p != NULL) {
            p = nextPrj(p);
        }
        nextPrj(p) = PJ;
    }
}

void deleteFirst_Programmer(listProgrammer &LPGR, adrPgr PG) {
    cout << "coba aja" << endl;
    cout << "telkom" << endl;
}
void deleteAfter_Programmer(listProgrammer &LPGR, adrPgr PG, adrPgr prec);
void deleteAfter_Project(listProject &LPRJ, adrPrj PJ, adrPrj prec );
void deleteAfter_Penugasan(listProgrammer &LPGR, adrPgr PG, adrTugas PT, adrTugas prec);

void view_Programmer(listProgrammer LPGR) {
    if (firstPGR(LPGR) == NULL) {
        cout << "Maaf list kosong" << endl;
    } else {
        adrPgr p = firstPGR(LPGR);
        cout << "Isi list programmer: ";
        while (p != NULL) {
            cout << infoPgr(p).username << ", " << infoPgr(p).totalProject << endl;
            p = nextPgr(p);
        }
        cout << endl;
    }
}

void view_Project(listProject LPRJ) {
    if (firstPRJ(LPRJ) == NULL) {
        cout << "Maaf list kosong" << endl;
    } else {
        adrPrj p = firstPRJ(LPRJ);
        cout << "Isi list programmer: ";
        while (p != NULL) {
            cout << infoPrj(p).namaProject << ", " << infoPrj(p).banyakProgrammer << endl;
            p = nextPrj(p);
        }
        cout << endl;
    }
}

void view_Penugasan(listProgrammer LPGR, listProject LPRJ) {
    if (firstPGR(LPGR) == NULL) {
        cout << "Maaf tidak ada programmer" << endl;
    } else {
        adrPgr p = firstPGR(LPGR);
        while (p != NULL) {
            adrTugas q = firstPenugasan(p);
            if (q == NULL) {
                cout << "Maaf programmer ini tidak memiliki penugasan" << endl;
            } else {
                cout << "Tugas programmer " << infoPgr(p).username << ":" << endl;
                while (q != NULL) {
                    cout << project(q) << " | ";
                    q = nextTugas(q);
                }
            }
            p = nextPgr(p);
        }
        cout << endl;
    }
}

void view_All(listProgrammer LPGR, listProject LPRJ) {
    if (firstPGR(LPGR) == NULL || firstPRJ(LPRJ) == NULL) {
        cout << "Maaf list tidak lengkap" << endl;
    } else {
        
    }
}

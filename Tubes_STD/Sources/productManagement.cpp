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

void deleteProgrammer(listProgrammer &LPGR, adrPgr delPG) {
    if (firstPGR(LPGR) == NULL) {
        cout << "Maaf list programmer kosong" << endl;
    } else {
        adrTugas t = firstPenugasan(delPG);
        while (t != NULL) {
            project(t) = NULL;
            t = nextTugas(t);
        }
        adrPgr p = firstPGR(LPGR);
        while (nextPgr(p) != delPG) {
            p = nextPgr(p);
        }
        nextPgr(p) = nextPgr(delPG);
        nextPgr(delPG) = NULL;
    }
}

void deleteProject(listProject &LPRJ, adrPrj delPJ) {
    
}

void deletePenugasan(listProgrammer &LPGR, adrPgr PG, string namaProject, adrTugas delPT) {
    if (firstPenugasan(PG) != NULL) {
        cout << "Maaf penugasan untuk programmer ini kosong" << endl;
    } else {
        adrTugas delPT= firstPenugasan(PG);
        while (infoPrj(project(delPT)).namaProject != namaProject) {
            delPT = nextTugas(delPT);
        }
        nextTugas(prevTugas(delPT)) = nextTugas(delPT);
        prevTugas(nextTugas(delPT)) = prevTugas(delPT);
        prevTugas(delPT) = NULL;
        nextTugas(delPT) = NULL;
    }
}

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

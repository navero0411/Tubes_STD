#include <iostream>
#include "productManagement.h"
using namespace std;

void createListProgrammer(listProgrammer &LPGR) {
    firstPGR(LPGR) = NULL;
}

void createListProject(listProject &LPRJ) {
    firstPRJ(LPRJ) = NULL;
}

adrPgr createElmProgrammer(infotypeProgrammer newProg) {
    adrPgr P = new elmProgrammer;
    infoPgr(P).username = newProg.username;
    infoPgr(P).totalProject = newProg.totalProject;
    nextPgr(P) = NULL;
    return P;
}

adrPrj createElmProject(infotypeProject newProj) {
    adrPrj Q = new elmProject;
    infoPrj(Q).namaProject = newProj.namaProject;
    infoPrj(Q).banyakProgrammer = newProj.banyakProgrammer;
    infoPrj(Q).deadline = newProj.deadline;
    nextPrj(Q) = NULL;
    return Q;
}

adrTugas createElmPenugasan(adrPrj tugasproject) {
    adrTugas N = new elmPenugasan;
    nextTugas(N) = NULL;
    prevTugas(N) = NULL;
    project(N) = tugasproject;
    return N;
}

// fitur admin sudah datang
void insertProgrammer(listProgrammer &LPGR, adrPgr PG) {
    if (firstPGR(LPGR) == NULL) {
        firstPGR(LPGR) = PG;
    } else {
        nextPgr(PG) = firstPGR(LPGR);
        firstPGR(LPGR) = PG;
    }
}

void insertPenugasan(listProgrammer &LPGR, adrPgr PG, adrTugas PT) {
    if (firstPenugasan(PG) == NULL) {
        firstPenugasan(PG) = PT;
    } else {
        nextTugas(PT) = firstPenugasan(PG);
        prevTugas(firstPenugasan(PG)) = PT;
        firstPenugasan(PG) = PT;
    }
}

void insertProject(listProject &LPRJ, adrPrj PJ) {
    if (firstPRJ(LPRJ) == NULL) {
        firstPRJ(LPRJ) = PJ;
    } else {
        adrPrj p = firstPRJ(LPRJ);
        while (nextPrj(p) != NULL) {
            p = nextPrj(p);
        }
        nextPrj(p) = PJ;
    }
}

void view_Programmer(listProgrammer LPGR) {
    if (firstPGR(LPGR) == NULL) {
        cout << "Maaf list kosong" << endl;
    } else {
        adrPgr p = firstPGR(LPGR);
        cout << "Isi list programmer: " << endl;
        while (p != NULL) {
            cout << infoPgr(p).username << ", " << infoPgr(p).totalProject << ": " << endl;
            adrTugas q = firstPenugasan(p);
            while (q != NULL) {
                adrPrj r = project(q);
                cout << infoPrj(r).namaProject << ", " << infoPrj(r).deadline << " | ";
                q = nextTugas(q);
            }
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
        cout << "Isi list programmer: " << endl;
        while (p != NULL) {
            cout << infoPrj(p).namaProject << ", " << infoPrj(p).banyakProgrammer << endl;
            adrTugas q = firstPenugasan(p);
            while (q != NULL) {
                adrPrj r = project(q);
                cout << infoPrj(r).namaProject << ", " << infoPrj(r).deadline << " | ";
                q = nextTugas(q);
            }
            p = nextPrj(p);
        }
        cout << endl;
    }
}

void editProgrammer(listProgrammer &LPGR, string username) {
    int isi;
    string name;
    cout << "Apa yang ingin di ubah?" << endl;
    cout << "1) nama " << endl;
    cin >> isi;
    if (isi == 1) {
        cout << "Nama Ingin Diubah Menjadi Apa?" << endl;
        cin >> name;
        adrPgr x = firstPGR(LPGR);
        while (x != NULL && infoPgr(x).username != username) {
            x = nextPgr(x);
        }
        if (x != NULL) {
            infoPgr(x).username = name;
            cout << "Nama programmer berhasil diubah menjadi: " << name << endl;
        }
    } else {
        cout << "Maaf tidak ada menu yang diinginkan" << endl;
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

void deleteFirst_Programmer(listProgrammer &LPGR, adrPgr PG) {
    if (firstPGR(LPGR) == NULL) {
        cout << "Data Programmer Kosong" << endl;
    } else {
        PG = firstPGR(LPGR);
        firstPGR(LPGR) = nextPgr(PG);
        nextPgr(PG) = NULL;
    }
}

void deleteFirst_Project(listProject &LPRJ, adrPrj PJ) {
    if (firstPRJ(LPRJ) == NULL) {
        cout << "Data Project Kosong" << endl;
    } else {
        PJ = firstPRJ(LPRJ);
        firstPRJ(LPRJ) = nextPrj(PJ);
        nextPrj(PJ) = NULL;
    }
}

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

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
    firstPenugasan(P) = NULL;
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
            p = nextPrj(p);
        }
        cout << endl;
    }
}

void view_Penugasan(listProgrammer LPGR);
void view_All(listProgrammer LPGR, listProject LPRJ);

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

void deleteProgrammer(listProgrammer &LPGR, adrPgr delPG, string user) {
    delPG = firstPGR(LPGR);
    adrPgr prev = NULL;
    while (delPG != NULL && infoPgr(delPG).username != user) {
        prev = delPG;
        delPG = nextPgr(delPG);
    }
    
    if (delPG == NULL) {
        cout << "Maaf programmer tidak ada" << endl;
    } else {
        adrTugas p = firstPenugasan(delPG);
        while (p != NULL) {
            project(p) = NULL;
            p = nextTugas(p);
        }
        
        if (delPG == firstPGR(LPGR)) {
            firstPGR(LPGR) = nextPgr(delPG);
            nextPgr(delPG) = NULL;
        } else if (nextPgr(delPG) == NULL) {
            nextPgr(prev) = NULL;
        } else {
            nextPgr(prev) = nextPgr(delPG);
            nextPgr(delPG) = NULL;
        }
    }
}

void deleteProject(listProgrammer &LPGR, listProject &LPRJ, adrPrj delPJ, string namaProject) {
    delPJ = firstPRJ(LPRJ);
    adrPrj prev = NULL;
    while (delPJ != NULL && infoPrj(delPJ).namaProject != namaProject) {
        prev = delPJ;
        delPJ = nextPrj(delPJ);
    }
    
    if (delPJ == NULL) {
        cout << "Maaf project tidak ada" << endl;
    } else {
        adrPgr p = firstPGR(LPGR);
        while (p != NULL) {
            adrTugas t = firstPenugasan(p);
            while (t != NULL) {
                if (project(t) == delPJ) {
                    project(t) = NULL;
                }
                t = nextTugas(t);
            }
            p = nextPgr(p);
        }
        
        if (delPJ == firstPRJ(LPRJ)) {
            firstPRJ(LPRJ) = nextPrj(delPJ);
            nextPrj(delPJ) = NULL;
        } else if (nextPrj(delPJ) == NULL) {
            nextPrj(prev) = NULL;
        } else {
            nextPrj(prev) = nextPrj(delPJ);
            nextPrj(delPJ) = NULL;
        }
    }
}

void deletePenugasan(listProgrammer &LPGR, listProject LPRJ, string username, string namaProject, adrTugas delTugas) {
    adrPgr p = firstPGR(LPGR);
    while (p != NULL && infoPgr(p).username != username) {
        p = nextPgr(p);
    }
    if (p == NULL) {
        cout << "Maaf programmer tidak ada" << endl;
    } else {
        adrPrj j = firstPRJ(LPRJ);
        while (j != NULL && infoPrj(j).namaProject != namaProject) {
            j = nextPrj(j);
        }
        if (j == NULL) {
            cout << "Maaf project tidak ada" << endl;
        } else {
            adrTugas t = firstPenugasan(p);
            while (t != NULL && project(t) != j) {
                t = nextTugas(t);
            }
            if (t == NULL) {
                cout << "Maaf penugasan tidak ada" << endl;
            } else {
                if (t == firstPenugasan(p)) {
                    firstPenugasan(p) = nextTugas(t);
                    prevTugas(nextTugas(t)) = NULL;
                    nextTugas(t) = NULL;
                } else if (nextTugas(t) == NULL) {
                    nextTugas(prevTugas(t)) = NULL;
                    prevTugas(t) = NULL;
                } else {
                    nextTugas(prevTugas(t)) = nextTugas(t);
                    prevTugas(nextTugas(t)) = prevTugas(t);
                    nextTugas(t) = NULL;
                    prevTugas(t) = NULL;
                }
                project(t)= NULL;
                delTugas = t;
            }
        }
    }
}



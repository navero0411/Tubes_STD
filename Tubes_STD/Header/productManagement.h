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
#define firstPGR(L) ((L).firstPGR)
#define firstPRJ(L) ((L).firstPRJ)
#define nextPgr(P) P->nextPgr
#define nextPrj(P) P->nextPrj
#define nextTugas(P) P->nextTugas
#define infoPgr(P) P->infoPgr
#define infoPrj(P) P->infoPrj
#define prevTugas(P) P->prevTugas
#define project(P) P->project
#define firstPenugasan(P) P->firstPenugasan
#define status(P) P->status
using namespace std;

typedef struct elmProgrammer *adrPgr;
typedef struct elmProject *adrPrj;
typedef struct elmPenugasan *adrTugas;

struct InfoProgrammer {
    string username;
    int totalProject;
};

typedef InfoProgrammer infotypeProgrammer;

struct elmProgrammer {
    InfoProgrammer infoPgr;
    adrPgr nextPgr;
    adrTugas firstPenugasan;
};

struct InfoProject {
    string namaProject;
    int banyakProgrammer;
    int deadline;
};

typedef InfoProject infotypeProject;

struct elmProject {
    InfoProject infoPrj;
    adrPrj nextPrj;
};

struct elmPenugasan {
    adrTugas nextTugas;
    adrTugas prevTugas;
    adrPrj project;
    string status;
};

struct listProgrammer {
    adrPgr firstPGR;
};

struct listProject {
    adrPrj firstPRJ;
};

void createListProgrammer(listProgrammer &LPGR);
void createListProject(listProject &LPRJ);
adrPgr createElmProgrammer(infotypeProgrammer newProg);
adrPrj createElmProject(infotypeProject newProj);
adrTugas createElmPenugasan(adrPrj tugasproject);

// admin
void insertProgrammer(listProgrammer &LPGR, adrPgr PG);
void insertProject(listProject &LPRJ, adrPrj PJ);

void editProgrammer(listProgrammer &LPGR, string usname);
void editProject(listProject &LPRJ, string projectName);

void deleteProgrammer(listProgrammer &LPGR, adrPgr &delPG, string user);
void deleteProject(listProgrammer &LPGR, listProject &LPRJ, adrPrj &delPJ, string namaProject);

// manager
void insertPenugasan(listProgrammer &LPGR, listProject &LPRJ, adrPgr PG, adrTugas PT, adrPrj PJ);
void deletePenugasan(listProgrammer &LPGR, listProject LPRJ, string username, string namaProject, adrTugas &delTugas);

void view_Programmer(listProgrammer LPGR);
void view_Project(listProject LPRJ);
void view_Penugasan(listProgrammer LPGR);
void view_PenugasanProject(listProject LPRJ, listProgrammer LPGR);
void view_All(listProgrammer LPGR, listProject LPRJ);

void allProgrammerWithAllPenugasan(listProgrammer LPGR);
void jumlahProgrammerDalamProject(listProject LPRJ);
void updateStatus(listProgrammer LPGR, listProject LPRJ);

// programmer
void viewUtkProgrammer(listProgrammer LPGR, string username);

adrPgr searchUsernameProgrammer(listProgrammer &LPGR, string usn);
adrPrj searchProjectName(listProject &LPRJ, string nameproject);

#endif /* productManagement_h */

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

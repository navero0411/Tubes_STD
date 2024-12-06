#include <iostream>
#include "productManagement.h"

using namespace std;

int main()
{
    listProgrammer Programmer;
    listProject Project;

    createListProgrammer(Programmer);
    createListProject(Project);

    infotypeProgrammer infoprogrammer1 = {"A0012", "Jember", 12};
    infotypeProgrammer infoprogrammer2 = {"A0013", "Banjaran", 5};
    adrPgr programmer1 = createElmProgrammer(infoprogrammer1);
    adrPgr programmer2 = createElmProgrammer(infoprogrammer2);
    insertProgrammer(Programmer, programmer1);
    insertProgrammer(Programmer, programmer2);

    cout << "Daftar Programmer Setelah Penambahan:" << endl;
    view_Programmer(Programmer);
    cout << endl;

    // tambah Project
    infotypeProject infoProject1 = {"PRJ001", 5};
    infotypeProject infoProject2 = {"PRJ002", 2};
    adrPrj project1 = createElmProject(infoProject1);
    adrPrj project2 = createElmProject(infoProject2);
    tambahProject(Project, project1);
    tambahProject(Project, project2);

    cout << "Daftar Project Setelah Penambahan:" << endl;
    view_Project(Project);
    cout << endl;
    return 0;
}

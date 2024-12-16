#include <iostream>
#include <string>
#include "productManagement.h"

using namespace std;

void adminMenu();
void managerMenu();
void programmerMenu(string username);


listProgrammer programmer;
listProject project;
infotypeProgrammer IPG;
infotypeProject IPJ;
adrPgr PG, delPG;
adrPrj PJ, delPJ;
adrTugas PT, delPT;
string usnPgr, usnPrj;

int main() {
    listProgrammer programmer;
    listProject project;
    infotypeProgrammer IPG;
    infotypeProject IPJ;
    int choice;
    string username, password;
    
    createListProgrammer(programmer);
    createListProject(project);
    
    do {
        cout << "============================\n";
        cout << "\tWELCOME TO SYSTEM\n";
        cout << "============================\n";
        cout << "1. Login as Admin\n";
        cout << "2. Login as Manager\n";
        cout << "3. Login as Programmer\n";
        cout << "0. Exit\n";
        cout << "============================\n";
        cout << "Choose an option: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            adminMenu();
            break;

        case 2:
            managerMenu();
            break;

        case 3:
            cout << "\nProgrammer Login\n";
            cout << "Username: ";
            cin >> username;
            programmerMenu(username);
            cout << endl;
            break;

        case 0:
            cout << "Exiting the system. Goodbye!\n";
            break;

        default:
            cout << "Invalid option! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

void adminMenu() {
    int choice;
    do {
        cout << "============================\n";
        cout << "\tAdmin Menu\n";
        cout << "============================\n";
        cout << "1. Tambah Programmer\n";
        cout << "2. View Programmers\n";
        cout << "3. Tambah Project\n";
        cout << "4. View Projects\n";
        cout << "5. Update Programmer\n";
        cout << "6. Update Project\n";
        cout << "7. Delete Programmer\n";
        cout << "8. Delete Project\n";
        cout << "0. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;
        

        switch (choice) {
        case 1:
                cout << endl;
                cout << "Masukkan username programmer baru ('sudah' jika selesai): ";
                cin >> IPG.username;
                while (IPG.username != "sudah") {
                    PG = createElmProgrammer(IPG);
                    insertProgrammer(programmer, PG);
                    cout << "Masukkan username programmer baru ('sudah' jika selesai): ";
                    cin >> IPG.username;
                }
                cout << "Programmer telah ditambah" << endl;
                cout << endl;
            break;
        case 2:
                cout << endl;
                view_Programmer(programmer);
            break;
        case 3:
                cout << endl;
                cout << "Masukkan nama project ('sudah' jika selesai): ";
                cin >> IPJ.namaProject;
                cout << "Masukkan deadline: ";
                cin >> IPJ.deadline;
                while (IPJ.namaProject != "sudah" || IPJ.deadline != 0) {
                    PJ = createElmProject(IPJ);
                    insertProject(project, PJ);
                    cout << "Masukkan nama project ('sudah' jika selesai): ";
                    cin >> IPJ.namaProject;
                    cout << "Masukkan deadline: ";
                    cin >> IPJ.deadline;
                }
                cout << "Project telah ditambah" << endl;
                cout << endl;
            break;
        case 4:
                cout << endl;
                view_Project(project);
            break;
        case 5:
                cout << "Siapa yang ingin diupdate: ";
                cin >> usnPgr;
                editProgrammer(programmer, usnPgr);
            break;
        case 6:
                cout << "Project yang ingin diupdate: ";
                cin >> usnPrj;
                editProject(project, usnPrj);
            break;
        case 7:
                cout << "Programmer yang ingin dihapus: ";
                cin >> usnPgr;
                deleteProgrammer(programmer, delPG, usnPgr);
            break;
        case 8:
                cout << "Project yang ingin dihapus: ";
                cin >> usnPrj;
                deleteProject(programmer, project, delPJ, usnPrj);
            break;
        case 0:
                cout << "Logging out as Admin.\n";
                cout << endl;
            break;
        default:
            cout << "Invalid! Coba lagi.\n";
        }
    } while (choice != 0);
}

void managerMenu() {
    int choice;
    do {
        cout << "============================\n";
        cout << "\tManager Menu\n";
        cout << "============================\n";
        cout << "1. Tambah Penugasan\n";
        cout << "2. View Assignments Berdasarkan Programmer\n";
        cout << "3. View Assignments Berdasarkan Project\n";
        cout << "4. View Total Penugasan Setiap Programmer\n";
        cout << "5. View Total Penugasan Setiap Project\n";
        cout << "6. Update Assignment Status\n";
        cout << "7. Hapus Assignment\n";
        cout << "0. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
                cout << "Siapa yang akan ditugaskan? ";
                cin >> usnPgr;
                cout << "Masukkan nama project? ";
                cin >> usnPrj;
                PG = searchUsernameProgrammer(programmer, usnPgr);
                PJ = searchProjectName(project, usnPrj);
                PT = createElmPenugasan(PJ);
                if (PG != NULL && PJ != NULL) {
                    insertPenugasan(programmer, project, PG, PT, PJ);
                    cout << usnPgr << " telah ditugaskan" << endl;
                    cout << endl;
                } else {
                    cout << "Data tidak ada." << endl;
                }
                cout << endl;
            break;
        case 2:
                cout << endl;
                view_Programmer(programmer);
            break;
        case 3:
                view_PenugasanProject(project, programmer);
            break;
        case 4:
                allProgrammerWithAllPenugasan(programmer);
            break;
        case 5:
                jumlahProgrammerDalamProject(project);
            break;
        case 6:
                updateStatus(programmer, project);
            break;
        case 7:
                cout << "Siapa yang akan diubah? ";
                cin >> usnPgr;
                cout << "Hapus salah satu tugas! ";
                cin >> usnPrj;
                deletePenugasan(programmer, project, usnPgr, usnPrj, delPT);
            break;
        case 0:
            cout << "Logging out as Manager.\n";
            break;
        default:
            cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 0);
}

void programmerMenu(string username) {
    int choice;
    do {
        cout << "============================\n";
        cout << "\tProgrammer Menu\n";
        cout << "============================\n";
        cout << "1. View Assignments\n";
        cout << "0. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
                viewUtkProgrammer(programmer, username);
            break;
        case 0:
            cout << "Logging out as Programmer.\n";
            break;
        default:
            cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 0);
}

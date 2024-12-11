#include <iostream>
#include "productManagement.h"
using namespace std;

// Fungsi untuk membuat list programmer baru
void createListProgrammer(listProgrammer &LPGR) {
    firstPGR(LPGR) = NULL;
}

// Fungsi untuk membuat list project baru
void createListProject(listProject &LPRJ) {
    firstPRJ(LPRJ) = NULL;
}

// Fungsi untuk membuat elemen programmer baru
adrPgr createElmProgrammer(infotypeProgrammer newProg) {
    adrPgr P = new elmProgrammer;
    infoPgr(P).username = newProg.username;
    infoPgr(P).totalProject = 0;
    firstPenugasan(P) = NULL;
    nextPgr(P) = NULL;
    return P;
}

// Fungsi untuk membuat elemen project baru
adrPrj createElmProject(infotypeProject newProj) {
    adrPrj Q = new elmProject;
    infoPrj(Q).namaProject = newProj.namaProject;
    infoPrj(Q).banyakProgrammer = 0;
    infoPrj(Q).deadline = newProj.deadline;
    nextPrj(Q) = NULL;
    return Q;
}

// Fungsi untuk membuat elemen penugasan baru
adrTugas createElmPenugasan(adrPrj tugasproject) {
    adrTugas N = new elmPenugasan;
    nextTugas(N) = NULL;
    prevTugas(N) = NULL;
    project(N) = tugasproject;
    return N;
}

// Fungsi untuk menambahkan programmer ke dalam list
void insertProgrammer(listProgrammer &LPGR, adrPgr PG) {
    if (firstPGR(LPGR) == NULL) {
        firstPGR(LPGR) = PG; // Jika list kosong, set sebagai elemen pertama
    } else {
        nextPgr(PG) = firstPGR(LPGR); // Insert di depan
        firstPGR(LPGR) = PG;
    }
}

// Fungsi untuk menambahkan penugasan ke programmer
void insertPenugasan(listProgrammer &LPGR, listProject &LPRJ, adrPgr PG, adrTugas PT, adrPrj PJ) {
    if (firstPenugasan(PG) == NULL) {
        firstPenugasan(PG) = PT; // Jika belum ada penugasan, set sebagai pertama
    } else {
        nextTugas(PT) = firstPenugasan(PG); // Insert di depan
        prevTugas(firstPenugasan(PG)) = PT;
        firstPenugasan(PG) = PT;
    }
    infoPgr(PG).totalProject++;
    infoPrj(PJ).banyakProgrammer++;
}

// Fungsi untuk menambahkan project ke dalam list
void insertProject(listProject &LPRJ, adrPrj PJ) {
    if (firstPRJ(LPRJ) == NULL) {
        firstPRJ(LPRJ) = PJ; // Jika list kosong, set sebagai elemen pertama
    } else {
        adrPrj p = firstPRJ(LPRJ);
        while (nextPrj(p) != NULL) {
            p = nextPrj(p); // Traverse sampai elemen terakhir
        }
        nextPrj(p) = PJ; // Insert di akhir
    }
}

// Fungsi untuk menampilkan list programmer
void view_Programmer(listProgrammer LPGR) {
    if (firstPGR(LPGR) == NULL) {
        cout << "Maaf list kosong" << endl; // Jika list kosong
    } else {
        adrPgr p = firstPGR(LPGR);
        cout << "Isi list programmer: " << endl;
        while (p != NULL) {
            cout << infoPgr(p).username << ", " << infoPgr(p).totalProject << ": ";
            adrTugas q = firstPenugasan(p);
            while (q != NULL) {
                adrPrj r = project(q);
                cout << infoPrj(r).namaProject << ", " << infoPrj(r).deadline << " hari | ";
                q = nextTugas(q);
            }
            p = nextPgr(p);
            cout << endl;
        }
        cout << endl;
    }
}

// Fungsi untuk menampilkan list project
void view_Project(listProject LPRJ) {
    if (firstPRJ(LPRJ) == NULL) {
        cout << "Maaf list kosong" << endl; // Jika list kosong
    } else {
        adrPrj p = firstPRJ(LPRJ);
        cout << "Isi list project: " << endl;
        while (p != NULL) {
            cout << infoPrj(p).namaProject << ", " << infoPrj(p).banyakProgrammer << " programmer, " << infoPrj(p).deadline << " hari" << endl;
            p = nextPrj(p);
        }
        cout << endl;
    }
}


void view_Penugasan(listProgrammer LPGR);
void view_All(listProgrammer LPGR, listProject LPRJ);

// Fungsi untuk menampilkan list penugasan
void view_Penugasan(listProgrammer LPGR);

// Fungsi untuk menampilkan semua data programmer dan project
void view_All(listProgrammer LPGR, listProject LPRJ);

// Fungsi untuk mengedit data programmer berdasarkan username
void editProgrammer(listProgrammer &LPGR, string usname) {
    adrPgr P = searchUsernameProgrammer(LPGR, usname); // Cari programmer berdasarkan username
    
    if (P != NULL) {
        string newUsername;
        cout << "Username programmer ditemukan: " << infoPgr(P).username << endl;
        cout << "Masukkan username baru: ";
        cin >> newUsername; // Input username baru
        infoPgr(P).username = newUsername; // Update username
        cout << "Username programmer telah diubah menjadi " << newUsername << endl;
    } else {
        cout << "Username programmer tidak ditemukan." << endl; // Jika programmer tidak ditemukan
    }
}

// Fungsi untuk mengedit data project berdasarkan nama project
void editProject(listProject &LPRJ, string nama) {
    string jawaban;
    adrPrj Q = searchProjectName(LPRJ, nama); // Cari project berdasarkan nama
    
    if (Q != NULL) {
        string newnameproject;
        cout << "Nama projek ditemukan. " << infoPrj(Q).namaProject << endl;
        cout << "Antum yakin ingin mengubah nama projek? (1.Ya/2.Tidak)" << endl;
        cin >> jawaban;
        
        if (jawaban == "Ya") {
            cout << "Apa nama projek baru yang antum inginkan? ";
            cin >> newnameproject; // Input nama project baru
            infoPrj(Q).namaProject = newnameproject; // Update nama project
            cout << "Nama projek telah diubah menjadi " << newnameproject << endl;
        } else {
            cout << "Tidak ada nama projek yang diganti" << endl;
        }
        
        cout << "Apa mau ganti deadline? (ya/tidak) ";
        cin >> jawaban;
        
        if (jawaban == "Ya") {
            int dl;
            cout << "Berapa hari lagi deadlinenya? ";
            cin >> dl; // Input deadline baru
            infoPrj(Q).deadline = dl; // Update deadline
            cout << "Deadline project sudah diubah menjadi " << dl << " hari" << endl;
        } else {
            cout << "Tidak ada deadline yang diganti" << endl;
        }
        
    } else {
        cout << "Nama projek tidak ditemukan" << endl; // Jika project tidak ditemukan
    }
}

// Fungsi untuk menghapus programmer dari list
void deleteProgrammer(listProgrammer &LPGR, adrPgr &delPG, string user) {
    delPG = firstPGR(LPGR); // Pointer awal programmer
    adrPgr prev = NULL;
    
    // Cari programmer berdasarkan username
    while (delPG != NULL && infoPgr(delPG).username != user) {
        prev = delPG;
        delPG = nextPgr(delPG);
    }
    
    if (delPG == NULL) {
        cout << "Maaf programmer tidak ada" << endl; // Programmer tidak ditemukan
    } else {
        // Hapus semua penugasan terkait programmer
        adrTugas p = firstPenugasan(delPG);
        while (p != NULL) {
            project(p) = NULL;
            p = nextTugas(p);
        }
        
        // Hapus programmer dari list
        if (delPG == firstPGR(LPGR)) {
            firstPGR(LPGR) = nextPgr(delPG);
        } else if (nextPgr(delPG) == NULL) {
            nextPgr(prev) = NULL;
        } else {
            nextPgr(prev) = nextPgr(delPG);
        }
        nextPgr(delPG) = NULL;
        cout << "Programmer telah dihapus" << endl;
    }
}

// Fungsi untuk menghapus project dari list
void deleteProject(listProgrammer &LPGR, listProject &LPRJ, adrPrj &delPJ, string namaProject) {
    delPJ = firstPRJ(LPRJ); // Pointer awal project
    adrPrj prev = NULL;
    
    // Cari project berdasarkan nama
    while (delPJ != NULL && infoPrj(delPJ).namaProject != namaProject) {
        prev = delPJ;
        delPJ = nextPrj(delPJ);
    }
    
    if (delPJ == NULL) {
        cout << "Maaf project tidak ada" << endl; // Project tidak ditemukan
    } else {
        // Hapus referensi project dari semua penugasan
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
        
        // Hapus project dari list
        if (delPJ == firstPRJ(LPRJ)) {
            firstPRJ(LPRJ) = nextPrj(delPJ);
        } else if (nextPrj(delPJ) == NULL) {
            nextPrj(prev) = NULL;
        } else {
            nextPrj(prev) = nextPrj(delPJ);
        }
        nextPrj(delPJ) = NULL;
        cout << "Project telah dihapus" << endl;
    }
}

// Fungsi untuk menghapus penugasan dari programmer
void deletePenugasan(listProgrammer &LPGR, listProject LPRJ, string username, string namaProject, adrTugas &delTugas) {
    adrPgr p = firstPGR(LPGR); // Pointer awal programmer
    
    // Cari programmer berdasarkan username
    while (p != NULL && infoPgr(p).username != username) {
        p = nextPgr(p);
    }
    
    if (p == NULL) {
        cout << "Maaf programmer tidak ada" << endl; // Programmer tidak ditemukan
    } else {
        adrPrj j = firstPRJ(LPRJ); // Pointer awal project
        
        // Cari project berdasarkan nama
        while (j != NULL && infoPrj(j).namaProject != namaProject) {
            j = nextPrj(j);
        }
        
        if (j == NULL) {
            cout << "Maaf project tidak ada" << endl; // Project tidak ditemukan
        } else {
            adrTugas t = firstPenugasan(p); // Pointer awal penugasan
            
            // Cari penugasan berdasarkan project
            while (t != NULL && project(t) != j) {
                t = nextTugas(t);
            }
            
            if (t == NULL) {
                cout << "Maaf penugasan tidak ada" << endl; // Penugasan tidak ditemukan
            } else {
                // Hapus penugasan dari list
                if (t == firstPenugasan(p)) {
                    firstPenugasan(p) = nextTugas(t);
                    if (nextTugas(t) != NULL) prevTugas(nextTugas(t)) = NULL;
                } else if (nextTugas(t) == NULL) {
                    nextTugas(prevTugas(t)) = NULL;
                } else {
                    nextTugas(prevTugas(t)) = nextTugas(t);
                    prevTugas(nextTugas(t)) = prevTugas(t);
                }
                project(t) = NULL;
                delTugas = t; // Simpan elemen yang dihapus
                cout << "Penugasan telah dihapus" << endl;
            }
        }
    }
}


// Fungsi untuk menampilkan penugasan berdasarkan username programmer
void viewUtkProgrammer(listProgrammer LPGR, string username) {
    adrPgr p = firstPGR(LPGR); // Pointer awal programmer

    // Cari programmer berdasarkan username
    while (p != NULL && infoPgr(p).username != username) {
        p = nextPgr(p);
    }

    if (p == NULL) {
        cout << "Maaf tidak ada programmer dengan username " << username << endl; // Programmer tidak ditemukan
    } else {
        cout << "List penugasan programmer " << username << ":" << endl;
        adrTugas t = firstPenugasan(p); // Pointer awal penugasan
        int i = 1;

        // Tampilkan semua penugasan programmer
        while (t != NULL) {
            adrPrj j = project(t); // Ambil referensi project
            cout << i << ". " << infoPrj(j).namaProject << ", deadline: " << infoPrj(j).deadline << " hari" << endl;
            t = nextTugas(t);
            i++;
        }
    }
}

// Fungsi untuk mencari programmer berdasarkan username
adrPgr searchUsernameProgrammer(listProgrammer &LPGR, string usn) {
    adrPgr x = firstPGR(LPGR); // Pointer awal programmer

    // Cari programmer berdasarkan username
    while (x != NULL) {
        if (infoPgr(x).username == usn) {
            return x; // Programmer ditemukan
        }
        x = nextPgr(x);
    }

    return NULL; // Programmer tidak ditemukan
}

// Fungsi untuk mencari project berdasarkan nama project
adrPrj searchProjectName(listProject &LPRJ, string nameproject) {
    adrPrj y = firstPRJ(LPRJ); // Pointer awal project

    // Cari project berdasarkan nama
    while (y != NULL) {
        if (infoPrj(y).namaProject == nameproject) {
            return y; // Project ditemukan
        }
        y = nextPrj(y);
    }

    return NULL; // Project tidak ditemukan
}

void view_PenugasanProject(listProject LPRJ, listProgrammer LPGR) {
    if (firstPRJ(LPRJ) == NULL) {
        cout << "Tidak ada project dalam list." << endl;
    } else {
        adrPrj proj = firstPRJ(LPRJ);
        cout << "Daftar Penugasan Berdasarkan Project:" << endl;
        while (proj != NULL) {
            cout << "Project: " << infoPrj(proj).namaProject
                 << ", Banyak Programmer: " << infoPrj(proj).banyakProgrammer
                 << ", Deadline: " << infoPrj(proj).deadline << " hari" << endl;

            bool hasAssignment = false;
            adrPrj currentProj = proj;
            adrTugas tugas = NULL;

            // Cari penugasan terkait project ini
            for (adrPgr programmer = firstPGR(LPGR); programmer != NULL; programmer = nextPgr(programmer)) {
                tugas = firstPenugasan(programmer);
                while (tugas != NULL) {
                    if (project(tugas) == currentProj) {
                        hasAssignment = true;
                        cout << "  - Programmer: " << infoPgr(programmer).username << endl;
                    }
                    tugas = nextTugas(tugas);
                }
            }

            if (!hasAssignment) {
                cout << "  Tidak ada penugasan untuk project ini." << endl;
            }

            proj = nextPrj(proj);
            cout << endl;
        }
    }
}

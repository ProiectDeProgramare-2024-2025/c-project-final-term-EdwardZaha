#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Meniu {
    int nrOptiuni;
    char** optiuni;
    char* header;
    char* footer;
} Meniu;

typedef struct Activitate {
    float durata;
    char* data;
    float kmParcursi;
} Activitate;

typedef struct FisaActivitati {
    int totalActivitati;
    Activitate*** activitati;
    int **nrActivitati;
    /* 1. cardio
     * 2. forta
     * 3. inot
     * 4. alergare
     * 5. plimbare
     */
} FisaActivitati;

FisaActivitati* FisaNoua() {
    FisaActivitati *fisa = malloc(sizeof(FisaActivitati));

    fisa -> totalActivitati = 5;

    fisa -> activitati = malloc(sizeof(Activitate**)*fisa->totalActivitati);
    fisa -> nrActivitati = malloc(sizeof(int*)*fisa->totalActivitati);

    for (int i = 0; i < fisa -> totalActivitati; i++) {
        fisa -> activitati[i] = malloc(sizeof(Activitate*) * 500);
        fisa-> nrActivitati[i] = malloc(sizeof(int));
        *fisa-> nrActivitati[i] = 0;
    }
    return fisa;
}

void SaveData(FisaActivitati* _fisa, char* filePath) {
    FILE* fptr = fopen(filePath, "w");

    fprintf(fptr, "%d\n", _fisa->totalActivitati);

    for (int i = 0; i < _fisa -> totalActivitati; i++) {
        fprintf(fptr, "%d\n", *_fisa->nrActivitati[i]);
        for (int j = 0; j < *_fisa->nrActivitati[i]; j++) {
            fprintf(fptr, "%f\n%s\n%f\n", _fisa->activitati[i][j]->durata, _fisa->activitati[i][j]->data, _fisa->activitati[i][j]->kmParcursi);
        }
    }

    fclose(fptr);
}

FisaActivitati* LoadData(char* filePath) {
    FisaActivitati *fisa = FisaNoua();

    FILE* fptr = fopen(filePath, "r");

    if (fptr == NULL) {
        SaveData(fisa, filePath);
        return fisa;
    }

    char* arr = malloc(sizeof(char) * 500);
    fgets(arr, 100, fptr);

    fisa -> totalActivitati = atoi(arr);
    for (int i = 0; i < fisa -> totalActivitati; i++) {
        fgets(arr, 100, fptr);
        *fisa->nrActivitati[i] = atoi(arr);
        for (int j = 0; j < *fisa->nrActivitati[i]; j++) {
            fisa->activitati[i][j] = malloc(sizeof(Activitate));
            fgets(arr, 100, fptr);
            fisa->activitati[i][j]->durata=atof(arr);
            fgets(arr, 100, fptr);
            arr[strlen(arr) - 1] = '\0';
            fisa->activitati[i][j]->data = malloc(sizeof(char)*50);
            strcpy(fisa->activitati[i][j]->data,arr);
            fgets(arr, 100, fptr);
            fisa->activitati[i][j]->kmParcursi=atof(arr);
        }
    }

    fclose(fptr);
    return fisa;
}

char* get_input() {
    char* input = malloc(sizeof(char) * 500);
    scanf("%s", input);
    return input;
}

void afisareInterfata(int indexMeniu);

Meniu* meniuri(int indexMeniu) {
    switch (indexMeniu) {
        case 0:
            static char *op0[] = {"\033[0;31mCardio\033[0m", "\033[0;31mForta\033[0m", "\033[0;31mInot\033[0m", "\033[0;31mAlergare\033[0m", "\033[0;31mPlimbare\033[0m", "Iesire"};
            static char *header0 = "MENIU PRINCIPAL";
            static char *footer0 = "Introdu numarul optiunii pe care vrei sa o alegi: ";
            Meniu* m0 = malloc(sizeof(Meniu));
            m0->optiuni = op0;
            m0->nrOptiuni = 6;
            m0->header = header0;
            m0->footer = footer0;
            return m0;
        case 1:
            static char *op1[] = {"Inregistreaza activitate", "Statistici", "Intoarcere"};
            static char *header1 = "\033[0;31mCARDIO\033[0m";
            static char *footer1 = "Introdu numarul optiunii pe care vrei sa o alegi: ";
            Meniu* m1 = malloc(sizeof(Meniu));
            m1->optiuni = op1;
            m1->nrOptiuni = 3;
            m1->header = header1;
            m1->footer = footer1;
            return m1;
        case 2:
            static char *op2[] = {"Inregistreaza activitate", "Statistici", "Intoarcere"};
            static char *header2 = "\033[0;31mFORTA\033[0m";
            static char *footer2 = "Introdu numarul optiunii pe care vrei sa o alegi: ";
            Meniu* m2 = malloc(sizeof(Meniu));
            m2->optiuni = op2;
            m2->nrOptiuni = 3;
            m2->header = header2;
            m2->footer = footer2;
            return m2;
        case 3:
            static char *op3[] = {"Inregistreaza activitate", "Statistici", "Intoarcere"};
            static char *header3 = "\033[0;31mINOT\033[0m";
            static char *footer3 = "Introdu numarul optiunii pe care vrei sa o alegi: ";
            Meniu* m3 = malloc(sizeof(Meniu));
            m3->optiuni = op3;
            m3->nrOptiuni = 3;
            m3->header = header3;
            m3->footer = footer3;
            return m3;
        case 4:
            static char *op4[] = {"Inregistreaza activitate", "Statistici", "Intoarcere"};
            static char *header4 = "\033[0;31mALERGARE\033[0m";
            static char *footer4 = "Introdu numarul optiunii pe care vrei sa o alegi: ";
            Meniu* m4 = malloc(sizeof(Meniu));
            m4->optiuni = op4;
            m4->nrOptiuni = 3;
            m4->header = header4;
            m4->footer = footer4;
            return m4;
        case 5:
            static char *op5[] = {"Inregistreaza activitate", "Statistici", "Intoarcere"};
            static char *header5 = "\033[0;31mPLIMBARE\033[0m";
            static char *footer5 = "Introdu numarul optiunii pe care vrei sa o alegi: ";
            Meniu* m5 = malloc(sizeof(Meniu));
            m5->optiuni = op5;
            m5->nrOptiuni = 3;
            m5->header = header5;
            m5->footer = footer5;
            return m5;
        case 6:
            static char *header6 = "\033[0;31mCARDIO\033[0m: INREGISTRARE ACTIVITATE";
            static char *footer6 = "Pentru a anula inregistrarea introdu -1.";
            Meniu* m6 = malloc(sizeof(Meniu));
            m6->nrOptiuni = 0;
            m6->header = header6;
            m6->footer = footer6;
            return m6;
        case 7:
            static char *header7 = "\033[0;31mFORTA\033[0m: INREGISTRARE ACTIVITATE";
            static char *footer7 = "Pentru a anula inregistrarea introdu -1.";
            Meniu* m7 = malloc(sizeof(Meniu));
            m7->nrOptiuni = 0;
            m7->header = header7;
            m7->footer = footer7;
            return m7;
        case 8:
            static char *header8 = "\033[0;31mINOT\033[0m: INREGISTRARE ACTIVITATE";
            static char *footer8 = "Pentru a anula inregistrarea introdu -1.";
            Meniu* m8 = malloc(sizeof(Meniu));
            m8->nrOptiuni = 0;
            m8->header = header8;
            m8->footer = footer8;
            return m8;
        case 9:
            static char *header9 = "\033[0;31mALERGARE\033[0m: INREGISTRARE ACTIVITATE";
            static char *footer9 = "Pentru a anula inregistrarea introdu -1.";
            Meniu* m9 = malloc(sizeof(Meniu));
            m9->nrOptiuni = 0;
            m9->header = header9;
            m9->footer = footer9;
            return m9;
        case 10:
            static char *header10 = "\033[0;31mPLIMBARE\033[0m: INREGISTRARE ACTIVITATE";
            static char *footer10= "Pentru a anula inregistrarea introdu -1.";
            Meniu* m10 = malloc(sizeof(Meniu));
            m10->nrOptiuni = 0;
            m10->header = header10;
            m10->footer = footer10;
            return m10;
        case 11:
            static char *header11 = "\033[0;31mCARDIO\033[0m: STATISTICI";
            static char *footer11 = "";
            Meniu* m11 = malloc(sizeof(Meniu));
            m11->nrOptiuni = 0;
            m11->header = header11;
            m11->footer = footer11;
            return m11;
        case 12:
            static char *header12 = "\033[0;31mFORTA\033[0m: STATISTICI";
            static char *footer12 = "";
            Meniu* m12 = malloc(sizeof(Meniu));
            m12->nrOptiuni = 0;
            m12->header = header12;
            m12->footer = footer12;
            return m12;
        case 13:
            static char *header13 = "\033[0;31mINOT\033[0m: STATISTICI";
            static char *footer13 = "";
            Meniu* m13 = malloc(sizeof(Meniu));
            m13->nrOptiuni = 0;
            m13->header = header13;
            m13->footer = footer13;
            return m13;
        case 14:
            static char *header14 = "\033[0;31mALERGARE\033[0m: STATISTICI";
            static char *footer14 = "";
            Meniu* m14 = malloc(sizeof(Meniu));
            m14->nrOptiuni = 0;
            m14->header = header14;
            m14->footer = footer14;
            return m14;
        case 15:
            static char *header15 = "\033[0;31mPLIMBARE\033[0m: STATISTICI";
            static char *footer15= "";
            Meniu* m15 = malloc(sizeof(Meniu));
            m15->nrOptiuni = 0;
            m15->header = header15;
            m15->footer = footer15;
            return m15;
        default:
            return NULL;
    }
}

int nrOptiuniMeniu(int indexMeniu) {
    Meniu* meniu = meniuri(indexMeniu);
    int nrOptiuni = meniu ? meniu->nrOptiuni : 0;
    free(meniu);
    return nrOptiuni;
}

void clear_input() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void inregistrareActivitate(int index, FisaActivitati *fisa) {
    afisareInterfata(++index+nrOptiuniMeniu(0)-1);

    float km,durata;
    int zi,luna,an;
    do
    {
        printf("\nIntrodu \033[0;32mdurata\033[0m activitatii in minute: ");
        fflush(stdout);
        int ok = scanf("%f", &durata);
        if (ok && durata != 0) break;
        clear_input();
    } while (1);
    if (durata<0) return;
    do {
        printf("Introdu \033[0;33mZIUA\033[0m in care a fost desfasurata activitatea: ");
        fflush(stdout);
        int ok = scanf("%d", &zi);
        if (ok && zi!=0 && zi<32) break;
        clear_input();
    } while (1);
    if (zi<0) return;
    do {
        printf("Introdu \033[0;33mLUNA\033[0m in care a fost desfasurata activitatea: ");
        fflush(stdout);
        int ok = scanf("%d", &luna);
        if (ok && luna!=0 && luna<13) break;
        clear_input();
    } while (1);
    if (luna<0) return;
    do {
        printf("Introdu \033[0;33mANUL\033[0m in care a fost desfasurata activitatea: ");
        fflush(stdout);
        int ok = scanf("%d", &an);
        if (ok && an != 0) break;
        clear_input();
    } while (1);
    if (an<0) return;

    char* data = malloc(sizeof(char) * 10);
    sprintf(data,"%2d/%2d/%4d",zi,luna,an);
    for (int i=0; i<10; i++) if (data[i]==' ') data[i]='0';

    do {
        printf("Introdu \033[0;36mdistanta\033[0m parcursa in km(daca e cazul, altfel introdu 0): ");
        fflush(stdout);
        int ok = scanf("%f", &km);
        if (ok) break;
        clear_input();
    } while (1);

    if (km<0) {
        free(data);
        return;
    }
    fisa->activitati[index-1][*fisa->nrActivitati[index-1]] = malloc(sizeof(Activitate));
    fisa->activitati[index-1][*fisa->nrActivitati[index-1]]->kmParcursi = km;
    fisa->activitati[index-1][*fisa->nrActivitati[index-1]]->durata = durata;
    fisa->activitati[index-1][*fisa->nrActivitati[index-1]]->data = data;
    ++*fisa->nrActivitati[index-1];

    SaveData(fisa, "savedata.txt");
    printf("Activitate introdusa cu \033[0;32msucces\033[0m.\nIntrodu \033[0;35morice\033[0m pentru a te intoarce: ");
    fflush(stdout);
    char* cr = get_input();
    free(cr);
}

void afisareStatistici(int index, FisaActivitati *fisa) {
    afisareInterfata(++index+(nrOptiuniMeniu(0)-1)*2);

    int nrRepetari=0;
    float durataMedie=0, totalKm=0;

    nrRepetari = *fisa->nrActivitati[index-1];
    for (int i=0; i<nrRepetari; i++) {
        durataMedie+=fisa->activitati[index-1][i]->durata;
        totalKm+=fisa->activitati[index-1][i]->kmParcursi;
    }
    durataMedie /= (float)nrRepetari;

    printf("Numarul de repetari: \033[0;33m%d\033[0m\nDurata medie: \033[0;32m%.2f\033[0m\n", nrRepetari, durataMedie);
    fflush(stdout);
    if (totalKm>0) {
        printf("Total km: \033[0;36m%.2f\033[0m\n", totalKm);
        fflush(stdout);
    }
    printf("\nActivitati recente:\n");
    fflush(stdout);
    for (int i=0; i<min(5,nrRepetari); i++) {
        printf("\033[0;33m%s\033[0m, \033[0;32m%.2f\033[0m min", fisa->activitati[index-1][i]->data, fisa->activitati[index-1][i]->durata);
        fflush(stdout);
        if (fisa->activitati[index-1][i]->kmParcursi>0) {
            printf(", \033[0;36m%.2f\033[0m km", fisa->activitati[index-1][i]->kmParcursi);
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
    }

    printf("\nIntrodu \033[0;35morice\033[0m pentru a te intoarce: ");
    fflush(stdout);
    char* cr = get_input();
    free(cr);
}

void functii(int *indexMeniu, int optiune, FisaActivitati *fisa) {
    if (*indexMeniu == 0) {
        *indexMeniu = optiune;
    }
    else if ((nrOptiuniMeniu(0)-1) * 0 < *indexMeniu && *indexMeniu <= (nrOptiuniMeniu(0)-1) * 1) {
        if (optiune == 3) {
            *indexMeniu = 0;
        }
        else {
            int indexPrim = *indexMeniu;
            *indexMeniu += optiune*(nrOptiuniMeniu(0)-1);
            if (optiune == 1) {
                inregistrareActivitate(indexPrim-1, fisa);
                while (*indexMeniu - (nrOptiuniMeniu(0) - 1) > 0) *indexMeniu -= nrOptiuniMeniu(0) - 1;
            }
            else {
                afisareStatistici(indexPrim-1, fisa);
                while (*indexMeniu - (nrOptiuniMeniu(0) - 1) > 0) *indexMeniu -= nrOptiuniMeniu(0) - 1;
            }
        }
    }
    else {
        // return 1 menu back
        if (optiune == -1) while (*indexMeniu - (nrOptiuniMeniu(0) - 1) > 0) *indexMeniu -= nrOptiuniMeniu(0) - 1;
        else {
            if ((nrOptiuniMeniu(0)-1) * 1 < *indexMeniu && *indexMeniu <= (nrOptiuniMeniu(0)-1) * 2) {

            }
            else if ((nrOptiuniMeniu(0)-1) * 2 < *indexMeniu && *indexMeniu <= (nrOptiuniMeniu(0)-1) * 3) {
                while (*indexMeniu - (nrOptiuniMeniu(0) - 1) > 0) *indexMeniu -= nrOptiuniMeniu(0) - 1;
            }
        }
    }
}

void afisareInterfata(int indexMeniu) {
    system("cls");
    fflush(stdout);
    Meniu *m = meniuri(indexMeniu);

    if (m == NULL) { // Hard Reset
        m = meniuri(-1);
    }

    printf("%s\n", &*m->header);
    fflush(stdout);
    for (int i = 0; i < m->nrOptiuni; i++) {
        printf("%d. %s\n", i+1, m->optiuni[i]);
        fflush(stdout);
    }
    printf("%s", &*m->footer);
    fflush(stdout);

    free(m);
}

int main() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    int meniuActual=0;
    char *ch;

    FisaActivitati *fisa = LoadData("savedata.txt");

    while (1) {
        afisareInterfata(meniuActual);
        ch = get_input();
        if (ch != NULL) {
            int ind = atoi(ch);
            if (meniuActual == 0 && ind == 6) break;
            functii(&meniuActual, ind, fisa);
        }
    }
    free(ch);
    for (int i=0; i<fisa->totalActivitati; i++) {
        free(fisa->nrActivitati[i]);
    }
    free(fisa);
    return 0;
}

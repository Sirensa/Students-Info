#include<stdio.h>            
#include<stdlib.h>
#include<stdbool.h>

typedef struct notes {
    float math;
    float info;
    float langues;
} notes;

typedef struct Etudiants {
    int identifiant;
    char nom[20];
    char prenom[20];
    float moyen;
    notes note;
} Etudiants;

int information_etudiants(Etudiants e[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("L'etudiant num %d de id: ", i + 1);
        scanf("%d", &e[i].identifiant);

        printf("Saisir le nom : ");
        scanf("%s", e[i].nom);

        printf("Le prenom : ");
        scanf("%s", e[i].prenom);

        printf("Entrer la note de l'informatique : ");
        scanf("%f", &e[i].note.info);

        printf("Entrer la note de math : ");
        scanf("%f", &e[i].note.math);

        printf("Entrer la note de langue : ");
        scanf("%f", &e[i].note.langues);
    }
    return 0;
}

float calcul_moyen(Etudiants e[], int n) {
    float moyen = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        e[i].moyen = (e[i].note.math + e[i].note.langues + e[i].note.info) / 3.0;
    }
    return moyen ;
}

void afficher_info(Etudiants e[], int n) {
    int i;
    printf("Les informations des etudiants sont :\n");
    for (i = 0; i < n; i++) {
        printf("L'etudiant [%d] : ID: %d | Nom: %s | Prenom : %s | Moyen : %.2f\n", i + 1, e[i].identifiant, e[i].nom, e[i].prenom, e[i].moyen);
    }
}

void admis(Etudiants e[], int n) {
    int i;
    int a = 0;
    int b = 10;
    for (i = 0; i < n; i++) {
        if (e[i].moyen >= b) {
            a++;
        }
    }
    printf("Le nombre des etudiants admis : %d\n", a);
}

int tri(Etudiants e[], int n) {  // tri à bulle
    int i;
    int ech;
    Etudiants tmp;

    do {
        ech = 0;
        for (i = 0; i < n - 1; i++) {
            if (e[i].moyen < e[i + 1].moyen) {
                tmp = e[i];
                e[i] = e[i + 1];
                e[i + 1] = tmp;
                ech = 1;
            }
        }
    } while (ech > 0);

    return 0;
}

int recherche_dichotomique(Etudiants e[], int n, int ID, int* position) {
    int inf = 0;
    int sup = n - 1;
    int milieu;

    while (inf <= sup) {
        milieu = (inf + sup) / 2;

        if (e[milieu].identifiant == ID) {
            *position = milieu;
            return 1;
        } else if (e[milieu].identifiant < ID) {
            inf = milieu + 1;
        } else {
            sup = milieu - 1;
        }
    }

    return 0;
}

int main() {
    int i, n;
    float moyen;
    int ID;
    int cmp, position;

    printf("Entrer le nombre des etudiants : ");
    scanf("%d", &n);

    Etudiants e[n];
    information_etudiants(e, n);

    printf("Saisir les informations des etudiants :\n");

    moyen = calcul_moyen(e, n);
    printf("La moyenne des notes des etudiants est : %.2f\n", moyen);

    afficher_info(e, n);
    admis(e, n);

    printf("Apres le tri :\n");
    tri(e, n);
    for (i = 0; i < n; i++) {
        printf("ID: %d\n", e[i].identifiant);
    }

    printf("Entrer ID rechercher : ");
    scanf("%d", &ID);

    cmp = recherche_dichotomique(e, n, ID, &position);

    if (cmp == 0) {
        printf("ID non trouve.\n");
    } else if (cmp == 1) {
        printf("ID %d se trouve dans la position : %d\n", ID, position + 1);
    }

    return 0;
}

#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define MAX_CONTATTI 100

struct Contatto {
    char nome[30];
    char cognome[30];
    char telefono[15];
};

void aggiungiContatto(struct Contatto rubrica[], int *n);
void visualizzaContatti(struct Contatto rubrica[], int n);
void cercaContatto(struct Contatto rubrica[], int n);
void eliminaContatto(struct Contatto rubrica[], int *n);

int main() {
    struct Contatto rubrica[MAX_CONTATTI];
    int n = 0;
    int scelta;

    do {
        printf("\nRubrica\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza tutti i contatti\n");
        printf("3. Ricerca contatto per cognome\n");
        printf("4. Elimina contatto per cognome\n");
        printf("5. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                aggiungiContatto(rubrica, &n);
                break;
            case 2:
                visualizzaContatti(rubrica, n);
                break;
            case 3:
                cercaContatto(rubrica, n);
                break;
            case 4:
                eliminaContatto(rubrica, &n);
                break;
            case 5:
                printf("Chiusura programma...\n");
                break;
            default:
                printf("Scelta non valida!\n");
        }
    } while (scelta != 5);

    return 0;
}

void aggiungiContatto(struct Contatto rubrica[], int *n) {
    if (*n >= MAX_CONTATTI) {
        printf("Rubrica piena!\n");
        return;
    }
    printf("Nome: ");
    scanf("%29s", rubrica[*n].nome);
    printf("Cognome: ");
    scanf("%29s", rubrica[*n].cognome);
    printf("Telefono: ");
    scanf("%14s", rubrica[*n].telefono);

    (*n)++;
    printf("Contatto aggiunto.\n");
}

void visualizzaContatti(struct Contatto rubrica[], int n) {
    if (n == 0) {
        printf("Rubrica vuota.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d) %s %s - %s\n", i + 1,
               rubrica[i].nome, rubrica[i].cognome, rubrica[i].telefono);
    }
}

void cercaContatto(struct Contatto rubrica[], int n) {
    char cognome[30];
    printf("Cognome da cercare: ");
    scanf("%29s", cognome);

    for (int i = 0; i < n; i++) {
        if (strcmp(rubrica[i].cognome, cognome) == 0) {
            printf("Trovato: %s %s - %s\n",
                   rubrica[i].nome, rubrica[i].cognome, rubrica[i].telefono);
            return;
        }
    }
    printf("Nessun contatto trovato con cognome %s.\n", cognome);
}

void eliminaContatto(struct Contatto rubrica[], int *n) {
    char cognome[30];
    printf("Cognome da eliminare: ");
    scanf("%29s", cognome);

    for (int i = 0; i < *n; i++) {
        if (strcmp(rubrica[i].cognome, cognome) == 0) {
            for (int j = i; j < *n - 1; j++) {
                rubrica[j] = rubrica[j + 1]; // shift
            }
            (*n)--;
            printf("Contatto eliminato.\n");
            return;
        }
    }
    printf("Nessun contatto trovato con cognome %s.\n", cognome);
}

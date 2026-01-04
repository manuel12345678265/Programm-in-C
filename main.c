#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPIELER 50
#define MAX_NAME    50

/* Funktionsprototypen */
void initialisierePunkte(int spielerPunkte[], int anzahlSpieler);
void spieleRunden(char spielerNamen[][MAX_NAME], int spielerPunkte[], int anzahlSpieler, int anzahlRunden);
void zeigeAuswertung(char spielerNamen[][MAX_NAME], int spielerPunkte[], int anzahlSpieler);

int main(void) {
    int anzahlSpieler = 0;
    int anzahlRunden  = 0;
    char spielerNamen[MAX_SPIELER][MAX_NAME] = {{0}};
    int  spielerPunkte[MAX_SPIELER] = {0};

    printf("Wie viele Spieler? (1-%d): ", MAX_SPIELER);
    scanf("%d", &anzahlSpieler);
    if (anzahlSpieler < 1 || anzahlSpieler > MAX_SPIELER) {
        printf("Ungueltige Anzahl.\n");
        return 1;
    }

    for (int i = 0; i < anzahlSpieler; i++) {
        printf("Name von Spieler %d: ", i + 1); 
        scanf("%49s", spielerNamen[i]);
    }

    printf("Wie viele Runden? ");
    scanf("%d", &anzahlRunden);
    if (anzahlRunden < 1) {
        printf("Ungueltige Rundenzahl.\n");
        return 1;
    }

    initialisierePunkte(spielerPunkte, anzahlSpieler);
    spieleRunden(spielerNamen, spielerPunkte, anzahlSpieler, anzahlRunden);
    zeigeAuswertung(spielerNamen, spielerPunkte, anzahlSpieler);

    return 0;
}

/* Punkte aller Spieler auf 0 setzen */
void initialisierePunkte(int spielerPunkte[], int anzahlSpieler) {
    for (int i = 0; i < anzahlSpieler; i++) {
        spielerPunkte[i] = 0;
    }
}

/* Runden spielen: jeder Spieler rät eine Zahl */

/* Punkte anzeigen und Sieger mit den wenigsten Punkten ermitteln */
void zeigeAuswertung(char spielerNamen[][MAX_NAME], int spielerPunkte[], int anzahlSpieler) {
    /* *** MINIMALE ÄNDERUNG: minimale statt maximale Punktzahl *** */
    int minimalePunktzahl = (int)1e9;

    printf("\n===== Punkte-Auswertung =====\n");
    for (int i = 0; i < anzahlSpieler; i++) {
        printf("%s: %d Punkt(e)\n", spielerNamen[i], spielerPunkte[i]);
        if (spielerPunkte[i] < minimalePunktzahl) {
            minimalePunktzahl = spielerPunkte[i];
        }
    }

    printf("\nSieger mit %d Punkt(en) (wenigste Versuche): ", minimalePunktzahl);
    for (int i = 0; i < anzahlSpieler; i++) {
        if (spielerPunkte[i] == minimalePunktzahl) {
            printf("%s ", spielerNamen[i]);
        }
    }
    printf("\n=============================\n");
}

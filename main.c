#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPIELER 50
#define MAX_NAME    50

void initialisierePunkte(int spielerPunkte[], int anzahlSpieler);
void spieleRunden(char spielerNamen[][MAX_NAME], int spielerPunkte[], int anzahlSpieler, int anzahlRunden);
void zeigeAuswertung(char spielerNamen[][MAX_NAME], int spielerPunkte[], int anzahlSpieler);

int main(void) {
    int anzahlSpieler = 0;
    int anzahlRunden  = 0;
    char spielerNamen[MAX_SPIELER][MAX_NAME] = {{0}};
    int  spielerPunkte[MAX_SPIELER] = {0};

    printf("Wie viele Spieler? (1-%d): ", MAX_SPIELER);
    if (scanf("%d", &anzahlSpieler) != 1) return 1;
    if (anzahlSpieler < 1 || anzahlSpieler > MAX_SPIELER) {
        printf("Ungueltige Anzahl.\n");
        return 1;
    }

    for (int i = 0; i < anzahlSpieler; i++) {
        printf("Name von Spieler (ohne Leerzeichen) %d: ", i + 1);
        if (scanf("%49s", spielerNamen[i]) != 1) return 1;
    }

    printf("Wie viele Runden? ");
    if (scanf("%d", &anzahlRunden) != 1) return 1;
    if (anzahlRunden < 1) {
        printf("Ungueltige Rundenzahl.\n");
        return 1;
    }

    initialisierePunkte(spielerPunkte, anzahlSpieler);
    spieleRunden(spielerNamen, spielerPunkte, anzahlSpieler, anzahlRunden);
    zeigeAuswertung(spielerNamen, spielerPunkte, anzahlSpieler);

    return 0;
}

void initialisierePunkte(int spielerPunkte[], int anzahlSpieler) {
    for (int i = 0; i < anzahlSpieler; i++) {
        spielerPunkte[i] = 0;
    }
}

void spieleRunden(char spielerNamen[][MAX_NAME], int spielerPunkte[], int anzahlSpieler, int anzahlRunden) {
    srand((unsigned)time(NULL));

    for (int runde = 1; runde <= anzahlRunden; runde++) {
        printf("\n=== Runde %d ===\n", runde);

        for (int spieler = 0; spieler < anzahlSpieler; spieler++) {
            int geheimeZahl = (rand() % 100) + 1;
            int tipp;

            printf("\n%s ist dran! Errate die Zahl (1-100):\n", spielerNamen[spieler]);
            while (1) {
                printf("Dein Tipp: ");
                if (scanf("%d", &tipp) != 1) {
                    printf("Ungueltige Eingabe. Bitte Zahl eingeben.\n");
                    while (getchar() != '\n');
                    continue;
                }

                spielerPunkte[spieler]++;

                if (tipp < geheimeZahl) {
                    printf("Hoeher!\n");
                } else if (tipp > geheimeZahl) {
                    printf("Tiefer!\n");
                } else {
                    printf("Richtig! Die Zahl war %d.\n", geheimeZahl);
                    break;
                }
            }
        }
    }
}

void zeigeAuswertung(char spielerNamen[][MAX_NAME], int spielerPunkte[], int anzahlSpieler) {
    int minimalePunktzahl = 2147483647;

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


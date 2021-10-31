#include <stdio.h>

int user_check (char c) {
    if ((c < 'A' && c > 32 )|| c > 'Z') {
        fprintf(stderr, "Error: Neplatny symbol!\n");
        return 1;
    }
}

int main() {
    char character, first_char;
    int char_amount = 0;
    int same_amount = 1;
    int coded = 0;

    scanf("%c", &first_char);
    if (user_check(first_char) == 1) return 100;

    while (scanf("%c", &character) == 1)
    {
        char_amount++;
        // kdyz je znak zadan vice nez 255x
        if (character == first_char) {
            same_amount++;
            if (same_amount == 255){
                printf("%c%d", first_char, same_amount);
                same_amount = 1;
                coded = coded + 4;
            }
        }

        
        // zmena znaku
        else {
            // Bez opakovani
            if (same_amount == 1) {
                printf("%c", first_char);
                if (user_check(character) == 1) return 100;
                coded++;
                if (character < 32) break;
            }
            // 2x stejny znak
            else if (same_amount == 2) {
                printf("%c%c", first_char, first_char);
                if (user_check(character) == 1) return 100;
                coded = coded + 2;
                if (character < 32) break;
            }
            // 3x - 9x stejny znak
            else if (same_amount >=3 && same_amount <= 9) {
                printf("%c%d", first_char, same_amount);
                if (user_check(character) == 1) return 100;
                coded = coded + 2;
                if (character < 32) break;
            }
            // 10x - 99x stejny znak
            else if (same_amount >=10 && same_amount <= 99) {
                printf("%c%d", first_char, same_amount);
                if (user_check(character) == 1) return 100;
                coded = coded + 3;
                if (character < 32) break;
            }
            // 100x - 254x stejny znak
            else if (same_amount >= 100 && same_amount <= 254) {
                printf("%c%d", first_char, same_amount);
                if (user_check(character) == 1) return 100;
                coded = coded + 4;
                if (character < 32) break;
            }
            first_char = character;
            same_amount = 1;
        }
    }
    printf("\n");
    fprintf(stderr, "Pocet vstupnich symbolu: %d\n", char_amount);
    fprintf(stderr, "Pocet zakodovanych symbolu: %d\n", coded);
    fprintf(stderr, "kompresni pomer: %0.2f\n", (float)coded/(float)char_amount);
    return 0;
}


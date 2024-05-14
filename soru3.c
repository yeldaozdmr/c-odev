#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALFABE_UZUNLUGU 26

struct TrieNode {
    struct TrieNode *cocuk[ALFABE_UZUNLUGU];
    bool kelime_sonu;
};

struct TrieNode *yeniDugum() {
    struct TrieNode *dugum = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    dugum->kelime_sonu = false;
    for (int i = 0; i < ALFABE_UZUNLUGU; i++) {
        dugum->cocuk[i] = NULL;
    }
    return dugum;
}

void kelimeEkle(struct TrieNode *kok, const char *kelime) {
    struct TrieNode *gezgin = kok;
    int uzunluk = strlen(kelime);

    for (int seviye = 0; seviye < uzunluk; seviye++) {
        int index = kelime[seviye] - 'a';
        if (!gezgin->cocuk[index]) {
            gezgin->cocuk[index] = yeniDugum();
        }
        gezgin = gezgin->cocuk[index];
    }
    gezgin->kelime_sonu = true;
}
bool kelimeAra(struct TrieNode *kok, const char *kelime) {
    struct TrieNode *gezgin = kok;
    int uzunluk = strlen(kelime);

    for (int seviye = 0; seviye < uzunluk; seviye++) {
        int index = kelime[seviye] - 'a';
        if (!gezgin->cocuk[index]) {
            return false;
        }
        gezgin = gezgin->cocuk[index];
    }
    return (gezgin != NULL && gezgin->kelime_sonu);
}

int main() {
    struct TrieNode *kok = yeniDugum();

    kelimeEkle(kok, "ilkbahar");
    kelimeEkle(kok, "yaz");
    kelimeEkle(kok, "sonbahar");
    kelimeEkle(kok, "kis");

    printf("kelimeAra(\"ilkbahar\") : %s\n", kelimeAra(kok, "ilkbahar") ? "Var" : "Yok");
    printf("kelimeAra(\"yaz\") : %s\n", kelimeAra(kok, "yaz") ? "Var" : "Yok");
    printf("kelimeAra(\"kis\") : %s\n", kelimeAra(kok, "kis") ? "Var" : "Yok");
    printf("kelimeAra(\"sonbahar\") : %s\n", kelimeAra(kok, "sonbahar") ? "Var" : "Yok");

    return 0;
}
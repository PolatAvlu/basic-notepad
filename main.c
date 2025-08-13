#include <stdio.h>

int main() {
    char filename[100];
    char text[1000];

    printf("Dosya adini gir: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Dosya acilamadi");
        return 1;
    }

    printf("Metni gir (bitirmek icin CTRL+D):\n");
    getchar(); // önceki newline'ı temizle
    while (fgets(text, sizeof(text), stdin)) {
        fputs(text, fp);
    }

    fclose(fp);
    printf("Kaydedildi: %s\n", filename);

    return 0;
}

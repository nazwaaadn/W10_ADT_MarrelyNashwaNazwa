#include <stdio.h>
#include "BinSTree.h"
#include "boolean.h"
#include <stdlib.h>
#include <string.h>

int main() {
    BinTree T;
    int pilihan;
    infotype X, Y, cari1, cari2;
    boolean Kiri = true;
    char posisi;
    char input[200], output[200];

    MakeTree('#', Nil, Nil, &T); // Buat tree kosong dengan akar '#'

    do {
        printf("\nMenu Operasi Binary Tree\n");
        printf("1. Insert Node\n");
        printf("2. Print Tree\n");
        printf("3. Transversal PreOrder\n");
        printf("4. Transversal InOrder\n");
        printf("5. Transversal PostOrder\n");
        printf("6. Transversal Level Order\n");
        printf("7. Search Node Tree\n");
        printf("8. Jumlah Daun/Leaf\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. String to Morse\n");
        printf("12. Morse to String\n");
        printf("13. Exit\n");
        printf("Pilih Menu: ");
        scanf(" %d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Masukkan info node yang ingin ditambahkan: ");
                getchar(); // BACA DAN BUANG newline dari input sebelumnya
                scanf("%c", &X);    
                printf("Masukkan parent node: ");
                getchar();
                scanf("%c", &Y);
                printf("Masukkan posisi (L/R) : ");
                scanf(" %c", &posisi);
                
                // Periksa apakah parent node Y ada di tree
                if (Search(T, Y)) {
                    if (posisi == 'L' || posisi == 'l') {
                        Kiri = true;
                    } else if (posisi == 'R' || posisi == 'r') {
                        Kiri = false;
                    }
                    AddDaun(&T, X, Y, Kiri);  // Menambahkan node baru
                } else {
                    printf("Parent node '%c' tidak ditemukan.\n", Y);
                }
                break;
                
            case 2:
                printf("Print Tree:\n");
                PrintTree(T);
                break;

            case 3:
                printf("Transversal PreOrder: ");
                PreOrder(T);
                printf("\n");
                break;

            case 4:
                printf("Transversal InOrder: ");
                InOrder(T);
                printf("\n");
                break;

            case 5:
                printf("Transversal PostOrder: ");
                PostOrder(T);
                printf("\n");
                break;

            case 6:
                printf("Transversal Level Order: ");
                LevelOrder(T);
                printf("\n");
                break;

            case 7:
                printf("Masukkan info node yang dicari: ");
                scanf(" %c", &cari1);
                if (Search(T, cari1))
                    printf("Node '%c' ditemukan.\n", cari1);
                else
                    printf("Node '%c' tidak ditemukan.\n", cari1);
                break;

            case 8:
                printf("Jumlah Daun: %d\n", nbDaun(T));
                break;

            case 9:
                printf("Kedalaman Tree: %d\n", Depth(T));
                break;

            case 10:
                printf("Masukkan dua node:\n");
                printf("Node 1: ");
                scanf(" %c", &cari1);
                printf("Node 2: ");
                scanf(" %c", &cari2);
                if (Max(cari1, cari2) == cari1)
                    printf("Node %c lebih besar dari node %c\n", cari1, cari2);
                else if (Max(cari1, cari2) == cari2)
                    printf("Node %c lebih besar dari node %c\n", cari2, cari1);
                else
                    printf("Node %c sama dengan node %c\n", cari1, cari2);
                break;

            case 11:
                printf("Konversi string ke Morse.\n");
                while (getchar() != '\n'); // flush newline sisa
                printf("Masukkan string: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                output[0] = '\0';
                StringToMorse(T, input, output);
                printf("Morse: %s\n", output);
                break;

            case 12:
                printf("Masukkan kode Morse (pisahkan tiap huruf dengan spasi): ");
                while (getchar() != '\n'); // flush newline sisa
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                output[0] = '\0';
                MorseToString(T, output, input);
                printf("Teks: %s\n", output);
                break;

            case 13:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 13);

    return 0;
}

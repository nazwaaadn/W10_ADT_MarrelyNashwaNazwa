#include <stdio.h>
#include "BinSTree.h"
#include "boolean.h"
#include <stdlib.h>
#include <string.h>


int main() {
    BinTree P, *T;
    int pilihan;
    infotype X, Y, cari1, cari2, Akar;
    boolean Kiri = true;
    char posisi;
    char input[200], output[200];

    MakeTree('#', Nil, Nil, T); // Jumlah node sesuai tree hardcoded

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
        printf("12. morse to string\n");
        printf("13. string to morse\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
             case 1:
                 printf("Insert Node: \n");
                    printf("Masukkan info node yang ingin ditambahkan: ");
                    scanf(" %c", &X);
                    printf("Masukkan parent node: ");
                    scanf(" %c", &Y);
                    printf("masukkan posisi (L/R) : ");
                    scanf(" %c", &posisi);
                    if (posisi == 'L' || posisi == 'l')
                    {
                        Kiri = true;
                    } else if (posisi == 'R' || posisi == 'r')
                    {
                        Kiri = !Kiri;
                    }
                    AddDaun(T, X, Y, Kiri);
                    
                 break;
            case 2:
                printf("Print Tree: ");
                // InOrder(P);
                break;
            case 3:
                printf("Transversal PreOrder: ");
                // PreOrder(P);
                break;
             case 4:
                 printf("Transversal InOrder: ");
                //  LevelOrder(P, 10);
                 break;
             case 5:
                 printf("Transversal PostOrder: ");
                 //PrintTree(P);
                 break;
            case 6:
                printf("Transversal Level Order: ");
                //PrintTree(P);
                break;
            case 7:
                printf("Masukkan info node yang dicari: ");
                scanf(" %c", &cari1);
                if (Search(P, cari1))
                    printf("Node '%c' ditemukan.\n", cari1);
                else
                    printf("Node '%c' tidak ditemukan.\n", cari1);
                break;
            case 8:
                // printf("Jumlah Daun: %d\n", nbDaun(P));
                // break;
            case 9:
                // printf("Kedalaman Tree: %d\n", Depth(P));
                // break;
            case 10:
                 printf("Masukkan dua node:\n");
                 break;
            case 11:
                printf("Keluar dari program.\n");
                break;
            case 12:
                printf("konversi string to morse.\n");
                printf("Masukkan string (huruf kapital tanpa spasi): ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Hapus newline

                output[0] = '\0'; // Reset output
                StringToMorse(P, input, output);
                printf("Morse: %s\n", output);
                break;
            case 13:
                printf("Masukkan kode Morse (pisahkan tiap huruf dengan spasi): ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Hapus newline

                output[0] = '\0'; // Reset output
                MorseToString(P, output, input); // Perhatikan: input jadi morse, output jadi str
                printf("Teks: %s\n", output);
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while(pilihan != 11);

    return 0;
}
/* Nama File : BinSTree.h 	*/
/* Deskripsi : File header untuk ADT Binary Tree Dinamis */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 22-11-2001 */

#ifndef _BINTREE_H
#define _BINTREE_H
#include <stdio.h>
#include "boolean.h"
#define true 1
#define false 0
#define jml_maks 100
#define boolean unsigned char
#define Nil NULL
#define Info(T) (T)->info
#define Left(T) (T)->left
#define Right(T) (T)->right
#define InfoList(L) (L)->info
#define Next(L) (L)->next

typedef char infotype;
typedef struct tElmtTree *address;
typedef struct tElmtTree {
	infotype info;
	address left, right;
    address parent;
} Node;	

typedef struct tElmtList *address1;
typedef struct tElmtList {
	infotype info;
	address1 next;
} ElmtList;	

typedef address BinTree;
typedef address1 ListOfNode;

//kepake
/**** Primitif *****/
/* Selektor */
//udah
infotype GetAkar (BinTree P);
/* Mengirimkan informasi yang tersimpan di akar dari pohon Biner yg tdk kosong*/
BinTree GetLeft (BinTree P);
/* Mengirimkan anak kiri pohon biner P yang TIDAK kosong */
BinTree GetRight (BinTree P);
/* Mengirimkan anak kanan pohon biner P yang TIDAK kosong */
boolean IsEmpty (BinTree P);
/* Mengirimkan true jika BinTree KOSONG */
/***** Traversal *****/
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika Alokasi berhasil, maka address != Nil dan Info (P) = X */
void DeAlokasi (address P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */


//nashwa
void PreOrder (BinTree P); //rekursif
/* Traversal PreOrder menggunakan Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah diproses secara PreOrder : Akar, Kiri, Kanan */
void InOrder (BinTree P);
/* Traversal InOrder menggunakan Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah diproses secara InOrder : Kiri, Arak, Kanan */
void PostOrder (BinTree P); //rekursif
/* Traversal PostOrder menggunakan Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah diproses secara PostOrder :  Kiri, Kanan, Akar */
// Fungsi untuk mencetak node pada level tertentu
void LevelOrder(BinTree P);
void PrintLevel(BinTree P, int level);
void PrintTree (BinTree P);
/* IS : P terdefinisi, h adalah jarak indentasi */
/* FS : Semua simpul P sudah ditulis dengan indentasi */

//nazwa
/***** Search *****/
boolean Search (BinTree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P);
/* IS : BinTree Sembarang */
/* FS : Menghasilkan sebuah BinTree */
/* Menghasilkan sebuah pohon biner dari A, L dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri);
/* IS : P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* FS : P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri) */
/*      atau sebagai anak Kanan X (jika NOT Kiri) */
void StringToMorse (BinTree P, char *str, char *morse);
void MorseToString (BinTree P, char *str, char *morse);

//kasih
//orang 2
/***** Fungsi Lain *****/
int nbElmt (BinTree P){
/* Mengirimkan banyak elemen (node) pohon biner P */
    if (P == Nil) {
        return 0;
    } else {
        return 1 + nbElmt(Left(P)) + nbElmt(Right(P));
    }
}

int nbDaun (BinTree P){
/* Mengirimkan banyak daun (node) pohon biner P */
if (P == Nil) {
	return 0;
} else if (Left(P) == Nil && Right(P) == Nil) {
	return 1;
} else {
	return nbDaun(Left(P)) + nbDaun(Right(P));
}
}

int Depth (BinTree P){
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */
/* Rekurens : 1 + maksimal (Depth (Anak Kiri), Depth  (Anak Kanan)) */

if (P == Nil) {
	return 0;
} else {
	int leftDepth = Depth(Left(P));
	int rightDepth = Depth(Right(P));
	return 1 + Max(leftDepth, rightDepth);
}
}
int Max (infotype Data1, infotype Data2){
/* Mengirimkan Nilai terbesar dari dua data */
/***** Operasi Lain *****/

    return (Data1 > Data2) ? Data1 : Data2;
}
void DestroyTree (BinTree *P){
/* Menghapus seluruh elemen Tree secara Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah dihapus secara PostOrder :  Kiri, Kanan, Akar */
if (*P != Nil) {
	DestroyTree(&Left(*P));
	DestroyTree(&Right(*P));
	DeAlokasi(*P);
	*P = Nil;
}
}


#endif
#include <string.h>
#include <iostream>
#include "masovattu.h"

struct VATTU
{
    masovattu MAVT; // Ma vat tu
    wchar_t TENVT[50]; // Ten vat tu
    wchar_t DVT[20]; // Don vi tinh
    long SLT; // So luong ton
};

struct NodeVT
{
    VATTU dulieu; 
    NodeVT *trai;
    NodeVT *phai;
};

typedef NodeVT *Tree;

NodeVT *KhoiTaoNodeVT(VATTU init);
void KhoiTaoCay(Tree &root);
void HuyBoCay(Tree &root);
void ThemMotNodeVT(Tree &root, NodeVT* nodeVT);
NodeVT *TimKiemNodeVT(Tree root, masovattu x);
void InCay(Tree root);
void NLR(Tree root);
void LNR(Tree root);
void LRN(Tree root);
void TimVaThayThe1(Tree &p, Tree &tree);
void TimVaThayThe2(Tree &p, Tree &tree);
void XoaMotNodeVT(Tree &root, masovattu x);


/*
    REF:
    https://topdev.vn/blog/cay-nhi-phan-trong-c/
*/


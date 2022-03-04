#include "../vattu/masovattu.h"
#include <iostream>

struct CT_HOADON
{
    masovattu MAVT;
    long SoLuong;
    long DonGia;
    float VAT;
};

struct Node_CTHD
{
    CT_HOADON dulieu;
    Node_CTHD* next;
};

struct DSLKD_CTHD
{
    Node_CTHD* head;
    Node_CTHD* tail;
};

Node_CTHD* KhoiTaoNodeCTHD(CT_HOADON dulieu);
void KhoiTaoDanhSachCTHD(DSLKD_CTHD& l);
void ThemDauCTHD(DSLKD_CTHD& l, Node_CTHD* node);
void ThemSauCTHD(DSLKD_CTHD& l, Node_CTHD* node);
void ThemSauCTHDBatKy(DSLKD_CTHD& l, Node_CTHD* p, Node_CTHD* q);
int XoaDauCTHD(DSLKD_CTHD& l, CT_HOADON& x);
int XoaSauCTHDBatKy(DSLKD_CTHD& l, Node_CTHD* q, CT_HOADON& x);
Node_CTHD* LayNodeCTHD(DSLKD_CTHD l, int index);
void InDanhSachCTHD(DSLKD_CTHD l);
Node_CTHD* TimKiemCTHD(DSLKD_CTHD l, CT_HOADON x);
int SoLuongCTHD(DSLKD_CTHD l);
void XoaDanhSachCTHD(DSLKD_CTHD& l);


/*
    REF:
    https://topdev.vn/blog/danh-sach-lien-ket-don-trong-c/
*/
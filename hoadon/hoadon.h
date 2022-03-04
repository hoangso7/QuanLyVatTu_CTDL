#include "chitiethoadon.h"
#include "../utils/date.h"

struct THONGTINHOADON
{
    int SoHoaDon;
    Date NgayLapHoaDon;
    char Loai;
    DSLKD_CTHD* DanhSachCTHD;
};

struct Node_HOADON
{
    THONGTINHOADON dulieu;
    Node_HOADON* next;
};

struct DSLKD_HOADON
{
    Node_HOADON* head;
    Node_HOADON* tail;
};

Node_HOADON* KhoiTaoHD(THONGTINHOADON dulieu);
void KhoiTaoDanhSachCTHD(DSLKD_HOADON& l);
void ThemDauCTHD(DSLKD_HOADON& l, Node_HOADON* node);
void ThemSauCTHD(DSLKD_HOADON& l, Node_HOADON* node);
void ThemSauCTHDBatKy(DSLKD_HOADON& l, Node_HOADON* p, Node_HOADON* q);
int XoaDauCTHD(DSLKD_HOADON& l, THONGTINHOADON& x);
int XoaSauCTHDBatKy(DSLKD_HOADON& l, Node_HOADON* q, THONGTINHOADON& x);
Node_HOADON* LayNodeCTHD(DSLKD_HOADON l, int index);
void InDanhSachCTHD(DSLKD_HOADON l);
Node_HOADON* TimKiemCTHD(DSLKD_HOADON l, int x);
int SoLuongCTHD(DSLKD_HOADON l);
void XoaDanhSachCTHD(DSLKD_HOADON& l);

/*
    REF:
    https://topdev.vn/blog/danh-sach-lien-ket-don-trong-c/
*/
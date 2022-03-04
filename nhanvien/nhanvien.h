#include <string>
#include "../hoadon/hoadon.h"

#define MAX_SL_NHAN_VIEN 500

int SoLuongNhanVien = 0;

struct MaNV
{
    std::string Ma;
    int So;
};

struct NhanVien
{
    MaNV MANV;
    std::string HO;
    std::string TEN;
    std::string PHAI;
    DSLKD_HOADON *DSHD;
};

NhanVien *DSNhanVien = new NhanVien[MAX_SL_NHAN_VIEN];

MaNV ChuyenStringThanhMaNV(std::string MaNV);
void SinhMaNhanVien(NhanVien NV);
NhanVien TimKiemNhanVien(std::string MaNV);
void ThemNhanVien();
void SuaNhanVien(std::string MaNV);
void XoaNhanVien(std::string MaNV);
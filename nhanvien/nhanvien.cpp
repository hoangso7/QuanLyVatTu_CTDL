#include "nhanvien.h"

void SinhMaNhanVien(NhanVien NV)
{
    std::string MaNV = NV.TEN + NV.HO[0] ;
    NV.MANV.Ma = MaNV;
    for(int i = 0 ; i < SoLuongNhanVien; i++)
    {
        if(DSNhanVien[i].MANV.Ma == MaNV)
        {
            int Sl = DSNhanVien[i].MANV.So;
            Sl++;
            NV.MANV.So = Sl;
            return;
        }
    }
    NV.MANV.So = 1;
}

NhanVien TimKiemNhanVien(std::string MaNV)
{
    
}
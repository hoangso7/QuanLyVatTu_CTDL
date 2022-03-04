#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

const int SoNgayCuaThang[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct Date{
	int ngay;
	int thang;
	int nam;
};

bool KiemTraNamNhuan(int nam);
bool KiemTraNamNhuan(Date date);
std::string ChuyenDateThanhString(Date date);
Date ChuyenStringThanhDate(std::string date);
Date LayDateHienTai();
int SoSanhDate(Date d1,Date d2);
int KiemTraDate(Date date);
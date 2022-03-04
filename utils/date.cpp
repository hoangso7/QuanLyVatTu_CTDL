#include "date.h"
#include "math.h"

bool KiemTraNamNhuan(int nam){
    return (((nam % 4 == 0) && (nam % 100 != 0)) || 
        (nam % 400 == 0)); 
}

bool KiemTraNamNhuan(Date date){
    return (((date.nam  % 4 == 0) && (date.nam % 100 != 0)) || 
        (date.nam % 400 == 0)); 
}

std::string ChuyenDateThanhString(Date date){
    char bufferngay[5];
    char bufferthang[5];
    char buffernam[5];
    char *intStrngay = itoa(date.ngay,bufferngay,10);
    char *intStrthang = itoa(date.thang,bufferthang,10);
    char *intStrnam = itoa(date.nam,buffernam,10);
    std::string strngay = std::string(intStrngay);
    std::string strthang = std::string(intStrthang);
    if(strngay.length() < 2 )
        strngay = "0"+strngay;
    if(strthang.length() < 2 )
        strthang = "0"+strthang;    
    return strngay + "/" + strthang + "/" + std::string(intStrnam);
}

Date ChuyenStringThanhDate(std::string strDate){
	Date date;
	int indexngay = strDate.find("/");
	std::string strngay = strDate.substr(0,indexngay);
	int indexthang = strDate.find("/",indexngay+1); 
	std::string strthang;
	switch(indexthang-indexngay){
		case 2:
		{
			strthang = strDate.substr(indexngay+1,1);		
			break;
		}
		case 3:
		{
			strthang = strDate.substr(indexngay+1,2);		
			break;
		}
	}
	std::string strnam = strDate.substr(indexthang+1,4);
	date.ngay = atoi(strngay.c_str());
	date.thang = atoi(strthang.c_str());
	date.nam = atoi(strnam.c_str());
	return date;
}

Date LayDateHienTai(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	Date date;
	date.ngay = ltm->tm_mday;
	date.thang = 1 + ltm->tm_mon;
	date.nam = 1900 + ltm->tm_year;
	return date;
}

int SoSanhDate(Date d1,Date d2){
	if(d1.nam > d2.nam) 
		return 1;
	else if(d1.nam == d2.nam)
		if(d1.thang > d2.thang) 
			return 1;
		else if(d1.thang == d2.thang)
			if(d1.ngay > d2.ngay) 
				return 1;
			else if(d1.ngay == d2.ngay) 
				return 0;
	return -1;
}

int KiemTraDate(Date date){
    if(date.nam < 2000)
        return 1;// 1 la loi sai nam
    if(KiemTraNamNhuan(date.nam)){
        if(date.thang == 2 && (date.ngay <= 0 || date.ngay > 29))
            return 3; // 3 la loi sai ngay
        else if(date.thang == 2 && (date.ngay > 0 && date.ngay <= 29))
            return 0; // 0 la hop le
    }    
    else{
        if(date.thang == 2 && (date.ngay <= 0 || date.ngay > 28))
            return 3; // 3 la loi sai ngay
        else if(date.thang == 2 && (date.ngay > 0 && date.ngay <= 28))
            return 0;
    }    
    switch(date.thang){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            if(date.ngay <= 0 || date.ngay > 31)
                return 3;
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
        {
            if(date.ngay <= 0 || date.ngay > 30)
                return 3;
            break;
        }
        default :
            return 2; // 2 la sai thang
    }
    return 0; // 0 la hop le
}
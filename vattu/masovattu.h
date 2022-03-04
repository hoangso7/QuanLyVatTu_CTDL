#define LON_HON 1
#define NHO_HON -1
#define BANG 0

struct masovattu
{
    char alpha;
    int beta;
};

void KhoiTaoMaSo(masovattu &init, char alpha, int beta);
int SoSanhMaSo(masovattu maso1, masovattu maso2);
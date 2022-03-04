#include "masovattu.h"

void KhoiTaoMaso(masovattu &init, char alpha, int beta)
{
    init.alpha = alpha;
    init.beta = beta;
}

int SoSanhMaSo(masovattu maso1, masovattu maso2)
{
    if(maso1.alpha == maso2.alpha && maso1.beta == maso2.beta)
        return BANG;
    
    if(maso1.alpha > maso2.alpha || (maso1.alpha == maso2.alpha && maso1.beta > maso2.beta))
        return LON_HON;
    else if (maso1.alpha < maso2.alpha || (maso1.alpha == maso2.alpha && maso1.beta < maso2.beta))
        return NHO_HON;
}
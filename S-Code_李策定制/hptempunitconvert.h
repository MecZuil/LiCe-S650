#ifndef HPTEMPUNITCONVERT_H
#define HPTEMPUNITCONVERT_H

#include  <QString>

class HpTempUnitConvert
{
public:
    HpTempUnitConvert();
    QString getTempUnitString(int tempunit);
    int getTempValue(int tempunit,int nCtemp100);
    int getCTempValue(int tempunit, int temp100);

};

#endif // HPTEMPUNITCONVERT_H

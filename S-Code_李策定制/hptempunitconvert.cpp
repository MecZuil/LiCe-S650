#include  "hptempunitconvert.h"

HpTempUnitConvert::HpTempUnitConvert()
{

}

QString HpTempUnitConvert::getTempUnitString(int tempunit)
{
    switch(tempunit)
    {
    case 0:
        return "℃";
    case 1:
        return "℉";
    case 2:
        return "K";
    default:
        return NULL;
    }
}

int HpTempUnitConvert::getTempValue(int tempunit, int nCtemp100)
{
    int value;
    switch(tempunit)
    {
    case 0:
        value = nCtemp100;
        break;
    case 1:
        value = 9*nCtemp100/5+3200;
        break;
    case 2:
        value = nCtemp100+27315;
        break;
    default:
        value = 0;
        break;
    }
    return value;
}

int HpTempUnitConvert::getCTempValue(int tempunit, int temp100)
{
    int value;
    switch(tempunit)
    {
    case 0:
        value = temp100;
        if(value %10 ==9) //tiao
        {
            value+=1;
        }
        if(value %10 ==1) //
        {
            value-=1;
        }
        break;
    case 1:
        value = (temp100-3200)*5/9;
        break;
    case 2:
        value = temp100-27315;
        break;
    default:
        value = 0;
        break;
    }
    return value;
}

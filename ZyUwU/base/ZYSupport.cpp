#include "ZYSupport.h"

NS_ZY_BEGIN

//

ZYSupport* ZYSupport::sp_pInstance = nullptr;

ZYSupport::ZYSupport()
{

}

//// Public

bool ZYSupport::isInt(float fNum)
{
    return (fNum - (int)fNum) == 0;
}

std::string ZYSupport::shorterDecimal(float fNum, int nLength)
{
   std::stringstream stream;
   stream << std::fixed << std::setprecision(nLength) << fNum;
    return stream.str();
}

std::string ZYSupport::tabString(int nTab)
{
    if (0 > nTab || nTab > 10) nTab = 2;
    std::string tab = "\n";
    for (int i = 0; i < nTab; i++) tab += "\t";
    return tab;
}

std::string ZYSupport::numberToString(float fNum)
{
    if(this->isInt(fNum)) return this->shorterDecimal(fNum, 0);
    return this->shorterDecimal(fNum, sgc_nDefaultFloatLength);
}

std::string ZYSupport::noNumberString(std::string sText)
{
    sText.erase(std::remove_if(sText.begin(), sText.end(), ::isdigit), sText.end());
    return sText;
}

std::string ZYSupport::sizeToString(cocos2d::Size size)
{
    return "(" + ZYSP_NTS(size.width) + " - " + ZYSP_NTS(size.height) + ")";
}

std::string ZYSupport::vec2ToString(cocos2d::Point vec2)
{
    return "(" + ZYSP_NTS(vec2.x) + ", " + ZYSP_NTS(vec2.y) + ")";
}

float ZYSupport::radToDegree(float fRad)
{
    return fRad*180/PI;
}

float ZYSupport::degreeToRad(float fDegree)
{
    return fDegree*PI/180;
}

bool ZYSupport::isOdd(int nNum)
{
    return (nNum%2==1);
}

//Virtual

bool ZYSupport::init()
{
    return true;
}

std::string ZYSupport::toString(int nTab)
{
    std::string ts;
    return ts;
}

void ZYSupport::log()
{

}
//protected

NS_ZY_END

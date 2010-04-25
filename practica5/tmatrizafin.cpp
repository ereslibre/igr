#include "tmatrizafin.h"

TMatrizAfin::TMatrizAfin()
{
}

TMatrizAfin::TMatrizAfin(const TMatrizAfin& matriz)
{

}

TMatrizAfin::~TMatrizAfin()
{
}

void TMatrizAfin::cargarIdentidad()
{
}

void TMatrizAfin::trasladar(double x, double y, double z)
{
}

void TMatrizAfin::trasladar(const PV3f& vec)
{
}

void TMatrizAfin::rotar(double ang, double x, double y, double z)
{

}

void TMatrizAfin::rotar(double ang, const PV3f& vec)
{

}

void TMatrizAfin::escalar(double x, double y, double z)
{

}

void TMatrizAfin::escalar(const PV3f& vec)
{

}

double* TMatrizAfin::getMatrizAfin()
{

}

void TMatrizAfin::postMultiplicar(double mm[16])
{

}

PV3f TMatrizAfin::multiplicarVector(const PV3f& v)
{

}

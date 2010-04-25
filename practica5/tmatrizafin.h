#ifndef TMATRIZAFIN_H
#define TMATRIZAFIN_H

#include "pv3f.h"

class TMatrizAfin
{
public:
    TMatrizAfin();
    TMatrizAfin(const TMatrizAfin &matriz);
    virtual ~TMatrizAfin();

    void cargarIdentidad();
    void trasladar(const PV3f &vec);
    void trasladar(double x, double y, double z);

    void rotar(double ang, const PV3f &vec);
    void rotar(double ang, double x, double y, double z);

    void escalar(const PV3f &vec);
    void escalar(double x, double y, double z);

    double *getMatrizAfin();

    void postMultiplicar(double mm[16]);
    PV3f multiplicarVector(const PV3f &v);

private:
    double m[16];
};

#endif // TMATRIZAFIN_H

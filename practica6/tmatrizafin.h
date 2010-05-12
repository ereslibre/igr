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
    void trasladar(GLdouble x, GLdouble y, GLdouble z);

    void rotar(GLdouble ang, const PV3f &vec);
    void rotar(GLdouble ang, GLdouble x, GLdouble y, GLdouble z);

    void escalar(const PV3f &vec);
    void escalar(GLdouble x, GLdouble y, GLdouble z);

    GLdouble *getMatrizAfin();

    void postMultiplicar(GLdouble mm[16]);
    PV3f multiplicarVector(const PV3f &v);

private:
    GLdouble m_matriz[16];
};

#endif // TMATRIZAFIN_H

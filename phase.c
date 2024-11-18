#include <stdio.h>
#include <time.h>
#include <math.h>

#define RAD(deg) ((deg)/180.0*M_PI)
#define SIN(deg) sin(RAD(deg))
#define COS(deg) cos(RAD(deg))

int main()
{
    time_t unix2010_01_01_00_00 = 14610 * 86400;
    double D = (time(NULL) - unix2010_01_01_00_00) / 86400.0;

    double N = 360 / 365.242191 * D;
    N = fmod(N, 360);
    N += N < 0 ? 360 : 0;

    double M0 = N + 279.557208 - 283.112438;
    M0 = fmod(M0, 360);
    M0 += M0 < 0 ? 360 : 0;

    double Ec = 360/M_PI * 0.016705 * SIN(M0);

    double L0 = N + Ec + 279.557208;
    L0 = fmod(L0, 360);
    L0 += L0 < 0 ? 360 : 0;

    // for the above, only D, M0 and L0 are required.
    // others can be re-assigned.

    double l0 = 91.929336;
    double P0 = 130.143076;
    double N0 = 291.682547;

    double l = 13.1763966 * D + l0;
    double Mm = l - 0.111404 * D - P0;
           N = N0 - 0.0529539 * D;
    double C = l - L0;
    double Ev = 1.2739 * SIN(2*C - Mm);
    double Ae = 0.1858 * SIN(M0);
    double A3 = 0.37 * SIN(M0);
    double M1m = Mm + Ev - Ae - A3;
           Ec = 6.2886 * SIN(M1m);
    double A4 = 0.214 * SIN(2*M1m);
    double l1 = l + Ev + Ec - Ae + A4;
    double V = 0.6583 * SIN(2*(l1-L0));
    double l11 = l1 + V;

    double F = 0.5 * (1 - COS(l11 - L0));
    printf("%.16f\n", F);
}

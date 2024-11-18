#!/usr/bin/python3
import math

def SIN(deg):
    return math.sin(math.radians(deg))

def COS(deg):
    return math.cos(math.radians(deg))

def phase(t):
    unix2010_01_01_00_00 = 14610 * 86400
    D = (int(t) - unix2010_01_01_00_00) / 86400

    N = 360 / 365.242191 * D
    N %= 360
    N += 360 if N < 0 else 0

    M0 = N + 279.557208 - 283.112438
    M0 %= 360
    M0 += 360 if M0 < 0 else 0

    M_PI = math.pi
    Ec = 360/M_PI * 0.016705 * SIN(M0)

    L0 = N + Ec + 279.557208
    L0 %= 360
    L0 += 360 if L0 < 0 else 0

    l0 = 91.929336
    P0 = 130.143076
    N0 = 291.682547

    l = 13.1763966 * D + l0
    Mm = l - 0.111404 * D - P0
    N = N0 - 0.0529539 * D
    C = l - L0
    Ev = 1.2739 * SIN(2*C - Mm)
    Ae = 0.1858 * SIN(M0)
    A3 = 0.37 * SIN(M0)
    M1m = Mm + Ev - Ae - A3
    Ec = 6.2886 * SIN(M1m)
    A4 = 0.214 * SIN(2*M1m)
    l1 = l + Ev + Ec - Ae + A4
    V = 0.6583 * SIN(2*(l1-L0))
    l11 = l1 + V

    F = 0.5 * (1 - COS(l11 - L0))
    return F

if __name__ == '__main__':
    import time
    print("%.16f" % phase(time.time()))

import gmpy2
import math

def basel(n, x=8):
    if x == 8:
        zeta = gmpy2.mpfr(0)
        for k in range(1, n+1):
            zeta += gmpy2.mpfr(1 / (gmpy2.mpfr(k) ** gmpy2.mpfr(8)))
        return ((gmpy2.mpfr(9450) * zeta) ** gmpy2.mpfr(1 / 8))

def get_constant():

    pi = gmpy2.mpfr(3.14159265358979323846264338)
    A = gmpy2.mpfr(9450) / gmpy2.mpfr(8) * (pi ** (-7))
    A = 0.4
    N = (2 * A / gmpy2.mpfr(7) * 10 ** 20) ** gmpy2.mpfr(1 / 7)
    m = gmpy2.mpfr(20) + math.log(A * N, 10)
    print(A)
    print(N)
    print(m)

if __name__ == '__main__':
    gmpy2.get_context().precision = 77
    # get_constant()
    print(basel(527))
    # print(math.pi)
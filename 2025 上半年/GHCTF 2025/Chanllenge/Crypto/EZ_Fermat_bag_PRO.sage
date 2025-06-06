from Crypto.Util.number import getPrime, bytes_to_long
from random import *
from secret import f, flag

assert len(flag) == 88
assert flag.startswith(b'NSSCTF{')
assert flag.endswith(b'}')

p = getPrime(512)
q = getPrime(512)
n = p*q

P.<x,y> = ZZ[]
f = P(str(f))

w = pow(2,f(p,q),n)
assert all(chr(i) in ''.join(list(set(str(p)))) for i in flag[7:-1:])
c = bytes_to_long(flag) % p



print(f'{n = }\n')
print(f'{f = }\n')
print(f'{w = }\n')
print(f'{c = }\n')

'''
n = 95656952327201449381426394713246214670537600365883923624876350719801926817916514429721785287844335184715049179879891389941974481490433975689601829920289485889138252888029716516069912637121531561601839948367426922036690701168975937162280451323099126372019216020898338909808577022618554997063496690156977790629
f = x^31 - x^30*y - 2*x^29*y^2 + 7*x^28*y^3 + 2*x^27*y^4 - 4*x^24*y^7 + 3*x^23*y^8 - x^20*y^11 - 4*x^19*y^12 + x^18*y^13 - 5*x^17*y^14 - 4*x^16*y^15 - x^15*y^16 + x^14*y^17 + x^13*y^18 + x^12*y^19 - 2*x^11*y^20 - 3*x^9*y^22 + 5*x^7*y^24 + x^6*y^25 + 6*x^4*y^27 + x^3*y^28 + 2*x*y^30 + y^31 - 2*x^30 - 3*x^29*y + 2*x^28*y^2 + 2*x^27*y^3 - x^26*y^4 - x^25*y^5 - 2*x^24*y^6 - 3*x^23*y^7 - 3*x^22*y^8 - 3*x^20*y^10 - 4*x^19*y^11 + 2*x^18*y^12 + x^15*y^15 - x^14*y^16 - 2*x^12*y^18 - 3*x^11*y^19 - x^10*y^20 + x^9*y^21 + 2*x^8*y^22 + x^7*y^23 + x^5*y^25 - x^4*y^26 - 2*x^3*y^27 - 2*x^2*y^28 - y^30 - 2*x^29 - x^28*y + 3*x^26*y^3 - x^25*y^4 - 2*x^24*y^5 + x^23*y^6 - x^22*y^7 - x^20*y^9 + 2*x^19*y^10 + 2*x^18*y^11 + x^16*y^13 + x^15*y^14 + x^14*y^15 + x^13*y^16 + x^12*y^17 + 5*x^11*y^18 - x^9*y^20 - 2*x^8*y^21 - 5*x^7*y^22 - 2*x^6*y^23 + 3*x^5*y^24 - 5*x^3*y^26 - x^2*y^27 + 2*x*y^28 - y^29 + 3*x^28 + 3*x^27*y - 2*x^26*y^2 + x^25*y^3 + 2*x^24*y^4 - x^23*y^5 - 2*x^22*y^6 - 3*x^20*y^8 - 3*x^19*y^9 + 4*x^17*y^11 - x^16*y^12 - 3*x^15*y^13 - 2*x^14*y^14 + x^13*y^15 + 2*x^12*y^16 - 2*x^11*y^17 + x^10*y^18 - 2*x^9*y^19 + x^8*y^20 - 2*x^7*y^21 - x^6*y^22 + x^5*y^23 - x^4*y^24 + x^3*y^25 + x^2*y^26 - x*y^27 - y^28 + x^27 + x^26*y - 2*x^24*y^3 + x^23*y^4 - 3*x^22*y^5 - 2*x^21*y^6 - 2*x^20*y^7 - 5*x^19*y^8 + 2*x^18*y^9 - 5*x^17*y^10 + x^16*y^11 - 3*x^15*y^12 - 4*x^14*y^13 - x^13*y^14 + x^12*y^15 + 3*x^11*y^16 + 2*x^10*y^17 - 4*x^9*y^18 - 2*x^6*y^21 + x^5*y^22 + 4*x^3*y^24 + 2*x^2*y^25 + 2*x*y^26 - 2*y^27 + x^25*y + x^24*y^2 + x^23*y^3 + 5*x^22*y^4 + x^20*y^6 - 3*x^19*y^7 + x^18*y^8 - x^17*y^9 + 2*x^15*y^11 - x^14*y^12 + 2*x^13*y^13 - x^12*y^14 + 4*x^11*y^15 - x^10*y^16 - 2*x^6*y^20 - x^5*y^21 + 3*x^3*y^23 + x^2*y^24 - 3*x*y^25 - 3*y^26 + 3*x^25 - 2*x^23*y^2 - x^21*y^4 + x^17*y^8 + 2*x^16*y^9 - x^15*y^10 - 2*x^14*y^11 - x^13*y^12 + 2*x^12*y^13 - 2*x^11*y^14 - x^9*y^16 - x^8*y^17 - x^6*y^19 - x^5*y^20 + x^4*y^21 + x^3*y^22 + 5*x*y^24 - 2*y^25 - x^24 + 2*x^23*y + x^22*y^2 - x^21*y^3 - x^19*y^5 + x^18*y^6 - x^17*y^7 + 2*x^16*y^8 - 4*x^15*y^9 - x^14*y^10 - x^13*y^11 - x^12*y^12 + 4*x^10*y^14 + 2*x^9*y^15 - x^8*y^16 - 2*x^7*y^17 - 2*x^6*y^18 + 4*x^5*y^19 + x^4*y^20 + 2*x^2*y^22 - 5*x*y^23 - y^24 + x^23 - x^22*y + 2*x^21*y^2 - x^20*y^3 - x^18*y^5 - x^17*y^6 - 5*x^15*y^8 + x^14*y^9 - 3*x^13*y^10 + 3*x^12*y^11 + 2*x^11*y^12 - 2*x^10*y^13 - 2*x^9*y^14 - x^8*y^15 + 2*x^7*y^16 - 2*x^6*y^17 - 4*x^5*y^18 - 5*x^3*y^20 - x^2*y^21 - x*y^22 - 4*y^23 - x^22 + 2*x^21*y - 2*x^20*y^2 - 2*x^19*y^3 - 3*x^17*y^5 - x^16*y^6 - x^15*y^7 + 4*x^13*y^9 + 2*x^12*y^10 + 3*x^11*y^11 + 2*x^10*y^12 - x^9*y^13 - x^7*y^15 + 2*x^6*y^16 + x^3*y^19 + 2*x^2*y^20 + 2*x*y^21 + 3*y^22 - 3*x^21 - x^20*y - x^19*y^2 + 2*x^17*y^4 - x^16*y^5 - x^15*y^6 + x^14*y^7 - 5*x^12*y^9 - 2*x^11*y^10 + x^10*y^11 + x^6*y^15 + x^5*y^16 + x^4*y^17 - 3*x^2*y^19 - 2*x*y^20 - 2*y^21 + x^20 + 2*x^19*y - 2*x^17*y^3 + 2*x^16*y^4 - 3*x^15*y^5 + 4*x^14*y^6 + 2*x^13*y^7 - x^12*y^8 - 2*x^11*y^9 + x^10*y^10 + 6*x^9*y^11 + x^8*y^12 + x^7*y^13 + 2*x^5*y^15 + 4*x^4*y^16 + x^3*y^17 - x^2*y^18 + 3*x*y^19 - x^17*y^2 + 2*x^16*y^3 + 3*x^14*y^5 - x^13*y^6 + 2*x^11*y^8 + x^10*y^9 + 3*x^9*y^10 - x^7*y^12 - x^6*y^13 + 3*x^5*y^14 - 4*x^4*y^15 + x^2*y^17 + 2*y^19 - x^18 - x^16*y^2 - 2*x^14*y^4 - 2*x^13*y^5 - 2*x^12*y^6 + 2*x^11*y^7 + 3*x^9*y^9 + 3*x^8*y^10 + x^6*y^12 - x^4*y^14 + 2*x^3*y^15 + 2*x^2*y^16 - 2*x*y^17 - x^17 - 4*x^16*y - 2*x^15*y^2 + 2*x^14*y^3 - x^13*y^4 + x^12*y^5 - 2*x^11*y^6 - 3*x^10*y^7 - x^9*y^8 - 5*x^8*y^9 + 2*x^7*y^10 + 2*x^6*y^11 - x^5*y^12 + x^4*y^13 - 3*x^2*y^15 + x*y^16 - 3*x^16 + x^15*y - 3*x^14*y^2 - x^13*y^3 - x^12*y^4 + 2*x^11*y^5 - x^10*y^6 + 5*x^8*y^8 + 3*x^7*y^9 + 3*x^6*y^10 + 2*x^5*y^11 + 4*x^4*y^12 + 2*x^3*y^13 + x^2*y^14 - 3*x*y^15 - x^15 + 3*x^14*y + x^13*y^2 - x^12*y^3 - 3*x^11*y^4 + x^10*y^5 - x^9*y^6 + 2*x^8*y^7 - x^7*y^8 + 4*x^5*y^10 - 2*x^4*y^11 + x^3*y^12 - x^14 + x^13*y + 2*x^12*y^2 + x^11*y^3 - 5*x^10*y^4 - x^9*y^5 - 3*x^8*y^6 - 2*x^7*y^7 + x^6*y^8 + 3*x^5*y^9 + x^4*y^10 + 2*x^3*y^11 - x^2*y^12 - 4*x*y^13 + 3*y^14 + x^12*y - 2*x^11*y^2 - x^9*y^4 - x^8*y^5 + 5*x^7*y^6 - 4*x^6*y^7 + 3*x^5*y^8 + 4*x^4*y^9 - 3*x^3*y^10 - x^2*y^11 - 2*x*y^12 - 3*y^13 + 3*x^12 + x^11*y + x^10*y^2 + x^9*y^3 + x^8*y^4 - x^6*y^6 - x^5*y^7 - 4*x^3*y^9 - x^2*y^10 - 3*x*y^11 - 2*y^12 + x^10*y + 5*x^9*y^2 + x^8*y^3 + 3*x^5*y^6 + x^4*y^7 + 2*x^3*y^8 - 4*x^2*y^9 + 2*x*y^10 + 3*y^11 - x^10 - 2*x^9*y - 2*x^7*y^3 - x^6*y^4 + x^5*y^5 + 3*x^4*y^6 - 2*x^2*y^8 - x*y^9 + 4*x^9 - 3*x^8*y - 3*x^6*y^3 + x^5*y^4 - x^4*y^5 - 2*x^3*y^6 - 2*x^2*y^7 + x*y^8 + 4*y^9 + 2*x^8 - x^7*y - 2*x^5*y^3 - 4*x^4*y^4 + 3*x^3*y^5 + 4*x^2*y^6 + 2*x*y^7 - 2*y^8 + 2*x^7 + 3*x^5*y^2 + 3*x^2*y^5 - x*y^6 - 4*x^6 + 6*x^3*y^3 + 2*x^2*y^4 - 2*x*y^5 - 3*y^6 + x^5 - 3*x^4*y + x^3*y^2 + x^2*y^3 - 2*x*y^4 + 2*x^4 - 2*x^3*y + 6*x^2*y^2 - 3*x*y^3 - 2*y^4 - 5*x^3 - 2*x^2*y - 2*x*y^2 + 3*y^3 + 2*x^2 - x*y + y^2 - 2*x + 2*y - 2
w = 12796020294902567574981427270787776254781813995526831579805652479456168245098217943847166109912113827479436654134179666391771173421469188197935460525521295192736123648410762964187396897298542198935971755852754544978564521188423737649175136194386664628304164316905741781089536713701674793641345344818309314224
c = 10266913434526071998707605266130137733134248608585146234981245806763995653822203763396430876254213500327272952979577138542487120755771047170064775346450942
'''
"""

boneh_durfee.sage

Code Copyright (C) 2015 by David Wong

Preamble written by Maxim Masiutin in 2022, see https://github.com/maximmasiutin/rsa-boneh-durfee

This software demonstrates the Boneh & Durfee attack to recovery a low private exponent of an RSA key.

Lattice reduction technique of Coppersmith's method for finding small roots of
univariate or bivariate modular polynomial equations originally proposed to
extract ciphertext bits as described in https://doi.org/10.1007/s001459900030
can also be used to recover the private exponent (d)
of the RSA key when the exponent is low relative to the public modulus (n), 
e.g. d < n^0.292, as described by Dan Boneh & Glenn Durfee in a 1999
conference paper available at https://doi.org/10.1007/3-540-48910-X_1
that was an improvement over the 1990 result of Wiener showing that when 
d < N 0.25 the RSA system is insecure, as described in https://doi.org/10.1109/18.54902

This implementation was written by David Wong (https://github.com/mimoo/) from San Francisco, http://www.cryptologie.net
and first published in 2015 (with updates up to 2021) at https://github.com/mimoo/RSA-and-LLL-attacks/blob/master/boneh_durfee.sage
- see https://github.com/mimoo/RSA-and-LLL-attacks for more details.

To run, use `sage boneh_durfee.sage`. If you don't have Sage Math installed, under you can install it under Ubuntu using `apt install sagemath`.

To use this script with actual data, modify the immediate values of `N` and `e` in the `example()` function and run the script, 
or call the `boneh_durfee` function with the appropriate parameters. 
Fore more details, see https://github.com/mimoo/RSA-and-LLL-attacks#boneh-durfee
"""


from __future__ import print_function
import time

############################################
# Config
##########################################

"""
Setting debug to true will display more informations
about the lattice, the bounds, the vectors...
"""
debug = True

"""
Setting strict to true will stop the algorithm (and
return (-1, -1)) if we don't have a correct
upperbound on the determinant. Note that this
doesn't necesseraly mean that no solutions
will be found since the theoretical upperbound is
usualy far away from actual results. That is why
you should probably use `strict = False`
"""
strict = False

"""
This is experimental, but has provided remarkable results
so far. It tries to reduce the lattice as much as it can
while keeping its efficiency. I see no reason not to use
this option, but if things don't work, you should try
disabling it
"""
helpful_only = True
dimension_min = 7 # stop removing if lattice reaches that dimension

############################################
# Functions
##########################################

# display stats on helpful vectors
def helpful_vectors(BB, modulus):
    nothelpful = 0
    for ii in range(BB.dimensions()[0]):
        if BB[ii,ii] >= modulus:
            nothelpful += 1

    print(nothelpful, "/", BB.dimensions()[0], " vectors are not helpful")

# display matrix picture with 0 and X
def matrix_overview(BB, bound):
    for ii in range(BB.dimensions()[0]):
        a = ('%02d ' % ii)
        for jj in range(BB.dimensions()[1]):
            a += '0' if BB[ii,jj] == 0 else 'X'
            if BB.dimensions()[0] < 60:
                a += ' '
        if BB[ii, ii] >= bound:
            a += '~'
        print(a)

# tries to remove unhelpful vectors
# we start at current = n-1 (last vector)
def remove_unhelpful(BB, monomials, bound, current):
    # end of our recursive function
    if current == -1 or BB.dimensions()[0] <= dimension_min:
        return BB

    # we start by checking from the end
    for ii in range(current, -1, -1):
        # if it is unhelpful:
        if BB[ii, ii] >= bound:
            affected_vectors = 0
            affected_vector_index = 0
            # let's check if it affects other vectors
            for jj in range(ii + 1, BB.dimensions()[0]):
                # if another vector is affected:
                # we increase the count
                if BB[jj, ii] != 0:
                    affected_vectors += 1
                    affected_vector_index = jj

            # level:0
            # if no other vectors end up affected
            # we remove it
            if affected_vectors == 0:
                print("* removing unhelpful vector", ii)
                BB = BB.delete_columns([ii])
                BB = BB.delete_rows([ii])
                monomials.pop(ii)
                BB = remove_unhelpful(BB, monomials, bound, ii-1)
                return BB

            # level:1
            # if just one was affected we check
            # if it is affecting someone else
            elif affected_vectors == 1:
                affected_deeper = True
                for kk in range(affected_vector_index + 1, BB.dimensions()[0]):
                    # if it is affecting even one vector
                    # we give up on this one
                    if BB[kk, affected_vector_index] != 0:
                        affected_deeper = False
                # remove both it if no other vector was affected and
                # this helpful vector is not helpful enough
                # compared to our unhelpful one
                if affected_deeper and abs(bound - BB[affected_vector_index, affected_vector_index]) < abs(bound - BB[ii, ii]):
                    print("* removing unhelpful vectors", ii, "and", affected_vector_index)
                    BB = BB.delete_columns([affected_vector_index, ii])
                    BB = BB.delete_rows([affected_vector_index, ii])
                    monomials.pop(affected_vector_index)
                    monomials.pop(ii)
                    BB = remove_unhelpful(BB, monomials, bound, ii-1)
                    return BB
    # nothing happened
    return BB

""" 
Returns:
* 0,0   if it fails
* -1,-1 if `strict=true`, and determinant doesn't bound
* x0,y0 the solutions of `pol`
"""
def boneh_durfee(pol, modulus, mm, tt, XX, YY):
    """
    Boneh and Durfee revisited by Herrmann and May
    
    finds a solution if:
    * d < N^delta
    * |x| < e^delta
    * |y| < e^0.5
    whenever delta < 1 - sqrt(2)/2 ~ 0.292
    """

    # substitution (Herrman and May)
    PR.<u, x, y> = PolynomialRing(ZZ)
    Q = PR.quotient(x*y + 1 - u) # u = xy + 1
    polZ = Q(pol).lift()

    UU = XX*YY + 1

    # x-shifts
    gg = []
    for kk in range(mm + 1):
        for ii in range(mm - kk + 1):
            xshift = x^ii * modulus^(mm - kk) * polZ(u, x, y)^kk
            gg.append(xshift)
    gg.sort()

    # x-shifts list of monomials
    monomials = []
    for polynomial in gg:
        for monomial in polynomial.monomials():
            if monomial not in monomials:
                monomials.append(monomial)
    monomials.sort()
    
    # y-shifts (selected by Herrman and May)
    for jj in range(1, tt + 1):
        for kk in range(floor(mm/tt) * jj, mm + 1):
            yshift = y^jj * polZ(u, x, y)^kk * modulus^(mm - kk)
            yshift = Q(yshift).lift()
            gg.append(yshift) # substitution
    
    # y-shifts list of monomials
    for jj in range(1, tt + 1):
        for kk in range(floor(mm/tt) * jj, mm + 1):
            monomials.append(u^kk * y^jj)

    # construct lattice B
    nn = len(monomials)
    BB = Matrix(ZZ, nn)
    for ii in range(nn):
        BB[ii, 0] = gg[ii](0, 0, 0)
        for jj in range(1, ii + 1):
            if monomials[jj] in gg[ii].monomials():
                BB[ii, jj] = gg[ii].monomial_coefficient(monomials[jj]) * monomials[jj](UU,XX,YY)

    # Prototype to reduce the lattice
    if helpful_only:
        # automatically remove
        BB = remove_unhelpful(BB, monomials, modulus^mm, nn-1)
        # reset dimension
        nn = BB.dimensions()[0]
        if nn == 0:
            print("failure")
            return 0,0

    # check if vectors are helpful
    if debug:
        helpful_vectors(BB, modulus^mm)
    
    # check if determinant is correctly bounded
    det = BB.det()
    bound = modulus^(mm*nn)
    if det >= bound:
        print("We do not have det < bound. Solutions might not be found.")
        print("Try with highers m and t.")
        if debug:
            diff = (log(det) - log(bound)) / log(2)
            print("size det(L) - size e^(m*n) = ", floor(diff))
        if strict:
            return -1, -1
    else:
        print("det(L) < e^(m*n) (good! If a solution exists < N^delta, it will be found)")

    # display the lattice basis
    if debug:
        matrix_overview(BB, modulus^mm)

    # LLL
    if debug:
        print("optimizing basis of the lattice via LLL, this can take a long time")

    BB = BB.LLL()

    if debug:
        print("LLL is done!")

    # transform vector i & j -> polynomials 1 & 2
    if debug:
        print("looking for independent vectors in the lattice")
    found_polynomials = False
    
    for pol1_idx in range(nn - 1):
        for pol2_idx in range(pol1_idx + 1, nn):
            # for i and j, create the two polynomials
            PR.<w,z> = PolynomialRing(ZZ)
            pol1 = pol2 = 0
            for jj in range(nn):
                pol1 += monomials[jj](w*z+1,w,z) * BB[pol1_idx, jj] / monomials[jj](UU,XX,YY)
                pol2 += monomials[jj](w*z+1,w,z) * BB[pol2_idx, jj] / monomials[jj](UU,XX,YY)

            # resultant
            PR.<q> = PolynomialRing(ZZ)
            rr = pol1.resultant(pol2)

            # are these good polynomials?
            if rr.is_zero() or rr.monomials() == [1]:
                continue
            else:
                print("found them, using vectors", pol1_idx, "and", pol2_idx)
                found_polynomials = True
                break
        if found_polynomials:
            break

    if not found_polynomials:
        print("no independant vectors could be found. This should very rarely happen...")
        return 0, 0
    
    rr = rr(q, q)

    # solutions
    soly = rr.roots()

    if len(soly) == 0:
        print("Your prediction (delta) is too small")
        return 0, 0

    soly = soly[0][0]
    ss = pol1(q, soly)
    solx = ss.roots()[0][0]

    #
    return solx, soly

def example():
    ############################################
    # How To Use This Script
    ##########################################

    #
    # The problem to solve (edit the following values)
    #

    # the modulus
    N = 0xc2fd2913bae61f845ac94e4ee1bb10d8531dda830d31bb221dac5f179a8f883f15046d7aa179aff848db2734b8f88cc73d09f35c445c74ee35b01a96eb7b0a6ad9cb9ccd6c02c3f8c55ecabb55501bb2c318a38cac2db69d510e152756054aaed064ac2a454e46d9b3b755b67b46906fbff8dd9aeca6755909333f5f81bf74db
    # the public exponent
    e = 0x19441f679c9609f2484eb9b2658d7138252b847b2ed8ad182be7976ed57a3e441af14897ce041f3e07916445b88181c22f510150584eee4b0f776a5a487a4472a99f2ddc95efdd2b380ab4480533808b8c92e63ace57fb42bac8315fa487d03bec86d854314bc2ec4f99b192bb98710be151599d60f224114f6b33f47e357517
    

    N = 16145163005933810407752261390690458192000069934308800024793251111968297506978117680236631519134867456575599695051667859912486947325264983719050757010183264697879891337878352798559722307748191755884685168019750761992350866988144145508350759530849991025771815475490203524655715315406455490957031437606278684238684357961687750515481282458824342733221757328761803977347968239166300156697100824105916874354045078956289531442842186668325781737778325666035240164210867972975845514644865573894980966648127102115771282611672127276763261636922198587850125676847952570005820048642886137010843289815486863693662806191261840920411
    e = 9413840062586532516010523846263448906176903339366168394620351383285203947784786691952534789875266051104991259694538552192226487375828641132781200775057320309298063487771973945854529521500040457563489147143649268428244922519913499151774826637646647277986297748039444242699406522861854432612700464070029031566474884803644131248088552581978906584088582170799199341999768616640639555746799089601035552285981690558357540924827239689083275440582504390522264302671874408125583806343189980990565854951321732991659947134880309636077682130661181437635505073400803788606635750774788853039972661648725169986554624217364019814143

    e= 100797590979191597676081881632112443200677974501832055481332601002844223186483558337099380805371010917502984674789369037985572270571944684404114475915036053451756526659905789324413633016308331745100752282051937597697581233757669107763643041665187533373053952694612521031477624363476981177214961821456672635823
    N= 133020919573254586736009662994351483197630110046444622015176359062686053521475990861985101412597512894313048001198942449066636145265799205815566892581351543233960812384316942438814742826123037762680960898927252792974233266551853930274479435403549161383103059746381782668941421906340168652870371226382805032027

    
    
    # the hypothesis on the private exponent (the theoretical maximum is 0.292)
    delta = .20 # this means that d < N^delta

    #
    # Lattice (tweak those values)
    #

    # you should tweak this (after a first run), (e.g. increment it until a solution is found)
    m = 4 # size of the lattice (bigger the better/slower)

    # you need to be a lattice master to tweak these
    t = int((1-2*delta) * m)  # optimization from Herrmann and May
    X = 2*floor(N^delta)  # this _might_ be too much
    Y = floor(N^(1/2))    # correct if p, q are ~ same size

    #
    # Don't touch anything below
    #

    # Problem put in equation
    P.<x,y> = PolynomialRing(ZZ)
    A = int((N+1)/2)
    pol = 1 + x * (A + y)

    #
    # Find the solutions!
    #

    # Checking bounds
    if debug:
        print("=== checking values ===")
        print("* delta:", delta)
        print("* delta < 0.292", delta < 0.292)
        print("* size of e:", int(log(e)/log(2)))
        print("* size of N:", int(log(N)/log(2)))
        print("* m:", m, ", t:", t)

    # boneh_durfee
    if debug:
        print("=== running algorithm ===")
        start_time = time.time()

    solx, soly = boneh_durfee(pol, e, m, t, X, Y)

    # found a solution?
    if solx > 0:
        print("=== solution found ===")
        if False:
            print("x:", solx)
            print("y:", soly)

        d = int(pol(solx, soly) / e)
        print("private key found:", d)
    else:
        print("=== no solution was found ===")

    if debug:
        print(("=== %s seconds ===" % (time.time() - start_time)))

if __name__ == "__main__":
    example()
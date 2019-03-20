# -*- coding: utf-8 -*-
"""
Created on Wed Feb 20 16:56:44 2019

@author: Alan Adamiak
"""

import numpy as np
import matplotlib.pyplot as plt
import scipy.optimize as opt
import random as rdm
import time

Base = 10

def intnb(nbint):
    res = []
    while nbint:
        res.append(nbint % Base)
        nbint = nbint // Base
    return res

def nbint(nb):
    res = 0
    for i in nb[::-1]:
        res = res*10 + i
    return res

def ajoute_decal(n, m, d):
    if m == []: return
    n.extend([0]*(len(m) + d - len(n)))
    retenue = 0
    for i in range(len(m)):
        n[d] += m[i]+retenue
        if n[d] >= Base:
            n[d] -= Base
            retenue = 1
        else:
            retenue = 0
        d += 1
    while d < len(n) and retenue:
        n[d] += retenue
        if n[d] >= Base:
            n[d] -= Base
            retenue = 1
        else:
            retenue = 0
        d += 1
    if retenue:
        n.append(retenue)

def somme(n, m):
    res = n[:]
    ajoute_decal(res, m, 0)
    return res

def retranche(n, m):
    if m == []: return
    retenue = 0
    for i in range(len(m)):
        n[i] -= m[i]+retenue
        if n[i] < 0:
            n[i] += Base
            retenue = 1
        else:
            retenue = 0
    i += 1
    while i < len(n):
        n[i] -= retenue
        if n[i] < 0:
            n[i] += Base
            retenue = 1
        else:
            retenue = 0
        i += 1
    assert retenue == 0, "n doit etre plus grand que m"
    while n != [] and n[-1] == 0:
        del n[-1]

def difference(n, m):
    res = n[:]
    retranche(n, m)
    return n

def produit_chiffre(n, c):
    if c == 0: return []
    if c == 1: return n
    retenue = 0
    res = [0]*len(n)
    for i in range(len(n)):
        resc = n[i]*c + retenue
        res[i] = resc % Base
        retenue = resc // Base
    if retenue:
        res.append(retenue)
    return res

def produit_naif(n, m):
    res = []
    for i in range(len(n)):
        ajoute_decal(res, produit_chiffre(m, n[i]), i)
    return res

def Karatsuba(n, m, seuil = 10):
    if len(n) < len(m):
        n, m = m, n
    if m == []: return []
    if len(m) == 1: return produit_chiffre(n, m[0])
    if len(m) <= seuil: return produit_naif(n, m)
    cut = len(n) // 2
    n1 = n[:cut]; n2 = n[cut:]
    m1 = m[:cut]; m2 = m[cut:]
    n1m1 = Karatsuba(n1, m1)
    n2m2 = Karatsuba(n2, m2)
    mid = Karatsuba(somme(n1, n2), somme(m1, m2))
    retranche(mid, n1m1)
    retranche(mid, n2m2)
    res = n1m1
    ajoute_decal(res, mid, cut)
    ajoute_decal(res, n2m2, 2*cut)
    return res

def mesure(fun, nb_chiffres):
    nb = [rdm.randint(1,9)]*nb_chiffres
    debut = time.time()
    fun(nb, nb)
    fin = time.time()
    return((fin - debut)*10**6)

taille = [10*(2**i) for i in range(0, 9)]

s = [mesure(somme,i) for i in taille]
p = [mesure(produit_naif, i) for i in taille]
k = [mesure(Karatsuba, i) for i in taille]
for i in range(len(taille)) :
    print "Taille de l'entier:", taille[i]
    print "Temps somme:", s[i], "µs"
    print "Temps produit naif:", p[i], "µs"
    print "Temps Karatsuba:", k[i], "µs"
    print


def tmpSomme(n, C) :
    return C * n

def tmpProd(n, C) :
    return n**2 * C

def tmpKara(n, a, C) :
    return n**a * C

f1, = plt.plot(taille, s, label="Fonction somme")
f2, = plt.plot(taille, p, label="Fonction produit_naif")
f3, = plt.plot(taille, k, label="Fonction Karatsuba")
plt.rcParams["legend.loc"] = 'upper left'
plt.xlabel("Taille de l'entier")
plt.ylabel("Temps (en micro s)")
#plt.xscale('log')
#plt.yscale('log')
plt.legend(handles=[f1,f2,f3])
plt.savefig('img1.png')
plt.show()























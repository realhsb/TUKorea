#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 23:39:26 2022

@author: hansubin
"""

import random
def makelotto(a) :
    while len(a) < 6 :
        lotto = random.randint(1, 45)
        if lotto not in a :
            a.append(lotto)
            
win = []
my = []
makelotto(win)
makelotto(my)
win.sort()
my.sort()
print('금주 번호 :', win)
print('나의 번호 : ', my)

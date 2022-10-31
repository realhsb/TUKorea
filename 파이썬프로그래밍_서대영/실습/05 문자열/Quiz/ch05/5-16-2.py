#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 23:29:43 2022

@author: hansubin
"""

def times2(k) :
    k[0] = k[0] * 2
    k[1] = k[1] * 2
a = [1,2]
b = [3,4]
times2(a)
times2(b)
print('a=', a, ' b=', b)
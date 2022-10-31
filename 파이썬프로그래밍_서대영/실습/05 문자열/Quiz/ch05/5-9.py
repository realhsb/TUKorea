#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 16:11:53 2022

@author: hansubin
"""

def new(n, x) :
    n = 2
    x.append(x[-1]+1)
    print('new: ', n, x)
    
def one() :
    n = 1
    x = [0, 1, 2]
    print('one: ', n, x)
    new(n, x)
    print('one: ', n, x)
one()
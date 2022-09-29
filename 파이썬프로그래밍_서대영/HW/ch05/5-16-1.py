#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 23:26:17 2022

@author: hansubin
"""

def times2(a) :
    for i in range(len(a)) :
        a[i] = a[i] * 2
    print(a)
nums = [1,2,3]
times2(nums)
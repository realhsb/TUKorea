#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 23:05:33 2022

@author: hansubin
"""

import random
bigdata = []
nodata = []
for i in range(100) :
    bigdata.append(random.randint(1, 33))
print(bigdata)
nodata = [i for i in range(1, 33) if i not in bigdata]
print('존재하지 않는 값(들) : ', nodata)
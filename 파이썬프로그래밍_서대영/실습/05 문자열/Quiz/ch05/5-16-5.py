#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 23:37:12 2022

@author: hansubin
"""

fruitdb = [['사과', 1020], ['오렌지', 880], ['포도', 3160]]
sum = 0
for i in range(len(fruitdb)) :
    sum += fruitdb[i][1]
avg = sum/len(fruitdb)
print('%.1f원' % avg)››
# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import random
bigdata = []
nodata = []
for i in range(100) :
    bigdata.append(random.randint(1, 33))
print(bigdata)
for i in range(1, 33) :
    if i not in bigdata :
        nodata.append(i)
print('존재하지 않는 값(들) : ', nodata)
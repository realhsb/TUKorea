#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 14 00:01:08 2022

@author: hansubin
"""

age = {'동혁' : 21, '민지' : 19, '준혁' : 23}

print(age.get('동혁'))                    # 1

age['민지'] = age.get('민지') + 1          # 2
print(age.get('민지'))


# 3
student = {'Gildong' : 2345, 'Sunsin' : 1234, 'SeJong' : 3456}
for name in student :
    print(name, ': ', student.get(name))
    
# 4
for name, num in  student.items():
    print(name, ': ', num)
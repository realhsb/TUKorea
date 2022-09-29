#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 14 00:32:43 2022

@author: hansubin
"""

training_data = [['연두', 3, '사과'],
                 ['노랑', 3, '사과'],
                 ['빨강', 2, '포도'],
                 ['빨강', 1, '포도'],
                 ['노랑', 3, '레몬']]

def fruit_counts(data) :
    counts = {}
    for row in data :
        color = row[0]
        if color not in counts :
            counts[color] = 0
        counts[color] += 1
    return counts
result = fruit_counts(training_data)
print(result)
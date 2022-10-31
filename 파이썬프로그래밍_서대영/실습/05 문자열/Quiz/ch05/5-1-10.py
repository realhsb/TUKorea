#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 16:27:27 2022

@author: hansubin
"""

bird_pos = []
animals = ['새', '코끼리', '강아지', '새', '강아지', '새']
for i, animal in enumerate(animals) :
    if (animal=='새'):
        bird_pos.append(i)
print(bird_pos)
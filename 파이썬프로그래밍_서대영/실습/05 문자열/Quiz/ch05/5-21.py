#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 14 00:22:46 2022

@author: hansubin
"""

males = {0, 2, 4, 8, 9}
females = {1, 3, 5, 6, 7}
everyone = males | females
print(everyone & set([1, 2, 3, 10]))
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Sep 15 12:35:58 2022

@author: hansubin
"""

class Calc :
    def __init__(self, n) :
        self.a = n
    def plus(self, value) :
        print(self.a, '+', value, '=', self.a + value)
    def mult(self, value) :
        print(self.a, '*', value, '=', self.a * value)

my = Calc(3)
my.plus(7)
my.mult(10)
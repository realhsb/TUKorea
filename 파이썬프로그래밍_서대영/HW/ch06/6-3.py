#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Sep 15 12:40:54 2022

@author: hansubin
"""

class Calc :
    def __init__(self, n1, n2) :
        self.a = n1
        self.b = n2
    def calculate(self, op) :
        if(op=='+') :
            print(self.a, '+', self.b, '=', self.a + self.b)
        elif(op=='*') :
            print(self.a, '*', self.b, '=', self.a * self.b)

num1 = int(input("Num1 : "))
num2 = int(input("Num2 : "))

obj = Calc(num1, num2)

obj.calculate('+')
obj.calculate('*')
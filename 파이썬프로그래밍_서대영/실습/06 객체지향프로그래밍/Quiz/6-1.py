#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Sep 15 12:06:28 2022

@author: hansubin
"""

class You : 
    def setname(self, n) :
        self.name = n
    def setage(self, a) :
        self.age = a;
    def show(self) :
        print('이름 : ', self.name, ' 나이 : ', self.age)
my = You()
my.setname('수빈')
my.setage(21)
my.show()

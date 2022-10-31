#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 15:42:27 2022

@author: hansubin
"""

import random
def passwd(length) :
    pw = str()      # str()는 빈 문자열 생성
    chars = 'abcdefghijklmnopqrstuvwxyz' + '0123456789' + '!@#$%^&*'
    
    for i in range(length) :
        pw = pw + random.choice(chars)
    return pw
print(passwd(8))
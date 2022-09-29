#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 15:39:12 2022

@author: hansubin
"""

import random
pw = str()          # pw 이름의 빈 문자열을 생성 
chars = '한글우수'
for i in range(5) :
    pw = pw + random.choice(chars)
print(pw)

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 14 14:00:43 2022

@author: hansubin
"""

import turtle
import random

col = random.randint(0, 3)
if (0 == col) :
    turtle.pencolor('yellow')
elif (1 == col) :
    turtle.pencolor('blue')
elif (2 == col) :
    turtle.pencolor('red')
turtle.circle(50)
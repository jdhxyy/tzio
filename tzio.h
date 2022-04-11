// Copyright 2020-2020 The TZIOT Authors. All rights reserved.
// io口设备框架
// Authors: jdh99 <jdh821@163.com>

#ifndef TZIO_H
#define TZIO_H

#include "tztype.h"

// 输出引脚的输出模式
typedef enum {
    TZIO_OUT_PP = 0,
    TZIO_OUT_OD
} TZIOOutMode;

// 输入引脚的上拉模式
typedef enum {
    TZIO_NOPULL = 0,
    TZIO_PULLDOWN,
    TZIO_PULLUP
} TZIOPullMode;

// 中断触发模式
typedef enum {
    TZIO_LO_TO_HI = 0,
    TZIO_HI_TO_LO,
    TZIO_TOGGLE
} TZIOIrqPolarity;

// TZIOConfigOutput 设置为输出
// 本函数需要驱动定义
void TZIOConfigOutput(int pin, TZIOPullMode pullMode, TZIOOutMode outMode);

// TZIOConfigInput 设置为输入
// 本函数需要驱动定义
void TZIOConfigInput(int pin, TZIOPullMode pullMode);

// TZIOSetHigh 输出高电平
// 本函数需要驱动定义
void TZIOSetHigh(int pin);

// TZIOSetLow 输出低电平
// 本函数需要驱动定义
void TZIOSetLow(int pin);

// TZIOSet 输出电平
// 本函数需要驱动定义
void TZIOSet(int pin, bool level);

// TZIOToggle 输出跳变信号
// 本函数需要驱动定义
void TZIOToggle(int pin);

// TZIOReadInputPin 读取输入引脚电平
// 本函数需要驱动定义
bool TZIOReadInputPin(int pin);

// TZIOReadOutputPin 读取输出引脚电平
// 本函数需要驱动定义
bool TZIOReadOutputPin(int pin);

// TZIOConfigIrq 配置中断模式
// 本函数会配置io为输入,不用提前配置.且配置完成后已经使能中断
// 本函数需要驱动定义
void TZIOConfigIrq(int pin, TZIOIrqPolarity polarity, TZEmptyFunc callback);

// TZIOIrqEnable 使能中断
// 本函数需要驱动定义
void TZIOIrqEnable(int pin);

// TZIOIrqDisable 禁止中断
// 本函数需要驱动定义
void TZIOIrqDisable(int pin);

#endif

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

// TZIOWakeMode 唤醒模式
typedef enum {
    TZIO_WAKE_DISABLE = 0,
    // 上升沿唤醒
    TZIO_WAKE_HIGH,
    // 下降沿唤醒
    TZIO_WAKE_LOW
} TZIOWakeMode;

// TZIOConfigOutput 设置为输出
// 本函数需要驱动定义
void TZIOConfigOutput(int pin, TZIOPullMode pullMode, TZIOOutMode outMode);

// TZIOConfigInput 设置为输入
// 本函数需要驱动定义
void TZIOConfigInput(int pin, TZIOPullMode pullMode, TZIOWakeMode wakeMode);

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
// 本函数需要驱动定义
void TZIOConfigIrq(int pin, TZIOIrqPolarity polarity, TZEmptyFunc callback);

// TZIOIrqEnable 使能中断
// 本函数需要驱动定义
void TZIOIrqEnable(int pin);

// TZIOIrqDisable 禁止中断
// 本函数需要驱动定义
void TZIOIrqDisable(int pin);

// TZIOConfigIrqPort 配置PORT中断模式
// PORT中断只允许一个引脚.调用本函数之前需要调用TZIOConfigInput初始化
// PORT中断是nRF52832中的特殊中断.需要驱动中定义
void TZIOConfigIrqPort(int pin, TZEmptyFunc callback);

#endif

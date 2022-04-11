// Copyright 2020-2020 The TZIOT Authors. All rights reserved.
// io���豸���
// Authors: jdh99 <jdh821@163.com>

#ifndef TZIO_H
#define TZIO_H

#include "tztype.h"

// ������ŵ����ģʽ
typedef enum {
    TZIO_OUT_PP = 0,
    TZIO_OUT_OD
} TZIOOutMode;

// �������ŵ�����ģʽ
typedef enum {
    TZIO_NOPULL = 0,
    TZIO_PULLDOWN,
    TZIO_PULLUP
} TZIOPullMode;

// �жϴ���ģʽ
typedef enum {
    TZIO_LO_TO_HI = 0,
    TZIO_HI_TO_LO,
    TZIO_TOGGLE
} TZIOIrqPolarity;

// TZIOConfigOutput ����Ϊ���
// ��������Ҫ��������
void TZIOConfigOutput(int pin, TZIOPullMode pullMode, TZIOOutMode outMode);

// TZIOConfigInput ����Ϊ����
// ��������Ҫ��������
void TZIOConfigInput(int pin, TZIOPullMode pullMode);

// TZIOSetHigh ����ߵ�ƽ
// ��������Ҫ��������
void TZIOSetHigh(int pin);

// TZIOSetLow ����͵�ƽ
// ��������Ҫ��������
void TZIOSetLow(int pin);

// TZIOSet �����ƽ
// ��������Ҫ��������
void TZIOSet(int pin, bool level);

// TZIOToggle ��������ź�
// ��������Ҫ��������
void TZIOToggle(int pin);

// TZIOReadInputPin ��ȡ�������ŵ�ƽ
// ��������Ҫ��������
bool TZIOReadInputPin(int pin);

// TZIOReadOutputPin ��ȡ������ŵ�ƽ
// ��������Ҫ��������
bool TZIOReadOutputPin(int pin);

// TZIOConfigIrq �����ж�ģʽ
// ������������ioΪ����,������ǰ����.��������ɺ��Ѿ�ʹ���ж�
// ��������Ҫ��������
void TZIOConfigIrq(int pin, TZIOIrqPolarity polarity, TZEmptyFunc callback);

// TZIOIrqEnable ʹ���ж�
// ��������Ҫ��������
void TZIOIrqEnable(int pin);

// TZIOIrqDisable ��ֹ�ж�
// ��������Ҫ��������
void TZIOIrqDisable(int pin);

#endif

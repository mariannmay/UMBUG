#ifndef THM_H
#define THM_H

#include <stdio.h>
#include "../ApplicationConfig.h"
#include "../../system/System.h"
#include "../../system/Log.h"

void setupADC(void);
void getThermalSensor(void);
void startHeating(void);
void stopHeating(void);
void thm_routine(void);

#endif

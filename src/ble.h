#pragma once

#include "asu_flip.h"

typedef enum {
    BleThreadFlagExit = 1,
} BleThreadFlag;

void asu_ble_thread(AsuApp* app);

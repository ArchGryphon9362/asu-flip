#include "src/ble.h"

#include <furi.h>

#include "asu_flip.h"

void asu_ble_thread(AsuApp* app) {
    UNUSED(app);
    for (;;) {
        const uint32_t flags = furi_thread_flags_get();
        if (flags == BleThreadFlagExit) break;
    }
}

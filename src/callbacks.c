#include "src/callbacks.h"

#include <furi.h>
#include <gui/gui.h>
#include <gui/view_port.h>

#include "asu_flip.h"
#include "src/render.h"
#include "src/ble.h"

void asu_draw_cb(Canvas* canvas, void* ctx) {
    AsuApp* app = ctx;
    AsuUiState* ui = app->ui;

    asu_render(canvas, ui);
}

void asu_input_cb(InputEvent* event, void* ctx) {
    AsuApp* app = ctx;
    furi_message_queue_put(app->input_queue, event, 50);
}

int32_t asu_ble_cb(void* ctx) {
    AsuApp* app = ctx;

    asu_ble_thread(app);

    return 0;
}

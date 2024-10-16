#include "src/callbacks.h"

#include <furi.h>
#include <gui/gui.h>
#include <gui/view_port.h>

#include "asu_flip.h"

void asu_draw_cb(Canvas* canvas, void* ctx) {
    AsuApp* app = ctx;
    AsuUiState* ui = app->ui;

    const size_t middle_x = canvas_width(canvas) / 2U;
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str_aligned(canvas, middle_x, 12, AlignCenter, AlignBottom, "ASU for Flipper");
    canvas_draw_line(canvas, 0, 16, 128, 16);

    canvas_set_font(canvas, FontSecondary);
    canvas_draw_str_aligned(canvas, middle_x, 30, AlignCenter, AlignBottom, "Status");

    canvas_set_font(canvas, FontKeyboard);
    canvas_draw_str_aligned(canvas, middle_x, 42, AlignCenter, AlignBottom, ui->text);
}

void asu_input_cb(InputEvent* event, void* ctx) {
    AsuApp* app = ctx;
    furi_message_queue_put(app->input_queue, event, FuriWaitForever);
}

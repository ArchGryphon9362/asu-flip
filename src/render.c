#include "src/render.h"

#include <furi.h>
#include <gui/gui.h>
#include <gui/view_port.h>

#include "asu_flip.h"

void asu_render(Canvas* canvas, AsuUiState* ui) {
    const size_t middle_x = canvas_width(canvas) / 2U;
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str_aligned(canvas, middle_x, 12, AlignCenter, AlignBottom, "ASU for Flipper");
    canvas_draw_line(canvas, 0, 16, 128, 16);

    canvas_set_font(canvas, FontSecondary);
    canvas_draw_str_aligned(canvas, middle_x, 30, AlignCenter, AlignBottom, "Status");

    canvas_set_font(canvas, FontKeyboard);
    canvas_draw_str_aligned(canvas, middle_x, 42, AlignCenter, AlignBottom, ui->text);
}

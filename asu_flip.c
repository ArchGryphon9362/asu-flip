#include "asu_flip.h"

#include <furi.h>
#include <gui/gui.h>
#include <gui/view_port.h>

#include "src/main.h"
#include "src/callbacks.h"

/* App startup/exit code */
static AsuUiState* asu_init_ui(void) {
    AsuUiState* ui = malloc(sizeof(AsuUiState));

    strlcpy(ui->text, "Disconnected", UI_TEXT_SIZE);

    return ui;
}

static AsuApp* asu_init_app(void) {
    // allocate internal structures
    AsuApp* app = malloc(sizeof(AsuApp));
    app->ui = asu_init_ui();

    // init view port
    app->view_port = view_port_alloc();
    view_port_draw_callback_set(app->view_port, asu_draw_cb, app);
    view_port_input_callback_set(app->view_port, asu_input_cb, app);

    // init queues
    app->input_queue = furi_message_queue_alloc(10, sizeof(InputEvent));
    
    // init gui
    app->gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(app->gui, app->view_port, GuiLayerFullscreen);

    return app;
}

static void asu_free_app(AsuApp* app) {
    // stop ui
    view_port_enabled_set(app->view_port, false);
    gui_remove_view_port(app->gui, app->view_port);

    // free queues
    furi_message_queue_free(app->input_queue);

    // free ui
    view_port_free(app->view_port);
    furi_record_close(RECORD_GUI);
}

int32_t asu_flip_app(void* p) {
    UNUSED(p);

    AsuApp* app = asu_init_app();
    asu_main_loop(app);
    asu_free_app(app);

    return 0;
}

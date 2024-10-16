#include "src/main.h"

#include <furi.h>

#include "asu_flip.h"

void asu_handle_input(AsuApp* app, InputEvent event) {
    if ((event.type == InputTypeShort) && (event.key == InputKeyBack)) {
        app->state = AsuStateExit;
    }
}

void asu_main_loop(AsuApp* app) {
    for (app->state = AsuStateMainMenu; app->state != AsuStateExit;) {
        // handle inputs
        InputEvent input_event;
        const FuriStatus status = furi_message_queue_get(app->input_queue, &input_event, FuriWaitForever);
        if (status == FuriStatusOk) {
            asu_handle_input(app, input_event);
        }
    }
}

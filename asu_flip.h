#pragma once

#include <gui/gui.h>
#include <gui/view_port.h>

#define UI_TEXT_SIZE 64U

typedef enum {
    AsuStateMainMenu,
    AsuStateExit
} AsuState;

typedef struct {
    char text[UI_TEXT_SIZE];
} AsuUiState;

typedef struct {
    Gui* gui;
    ViewPort* view_port;
    FuriMessageQueue* input_queue;

    FuriThread* ble_thread;
    FuriMessageQueue* ble_tx_queue;
    FuriMessageQueue* ble_rx_queue;

    // states
    AsuState state;
    AsuUiState* ui;
} AsuApp;

#include <pebble.h>
#include "main.h"

Window *window;
TextLayer *text_layer;
BitmapLayer *background_layer;

void window_load(Window *window) {
	background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
	bitmap_layer_set_background_color(background_layer, GColorMintGreen);
	layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(background_layer));
	
	text_layer = text_layer_create(GRect(0, 30, 144, 20));
	text_layer_set_text(text_layer, "placeholder");
	text_layer_set_text_color(text_layer, GColorFolly);
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
}

void window_unload(Window *window) {
	text_layer_destroy(text_layer);
	bitmap_layer_destroy(background_layer);
}

int main() {
	window = window_create();
	window_set_window_handlers(window, (WindowHandlers){
		.load = window_load,
		.unload = window_unload
	});
	window_stack_push(window, true);
	app_event_loop();
}
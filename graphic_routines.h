#ifndef GRAPHIC_ROUTINES_H
#define GRAPHIC_ROUTINES_H

#include "graphic_startup.h"

bool Allegro_routines::_flip() {

	al_flip_display();
	al_clear_to_color(al_map_rgb(255, 255, 255));

	return runing;
}

bool Allegro_routines::_timed() {

	al_wait_for_event(event_queue, &evnt);
	al_get_next_event(mouse_event_queue, &mouse_evnt);

	if (evnt.type == ALLEGRO_EVENT_DISPLAY_CLOSE || evnt.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
		runing = false;
	}

	if (evnt.type == ALLEGRO_EVENT_TIMER) {

		return true;
	}
	return false;
}

void Allegro_routines::_add_images(File_list* file_list) {

	image_lenght += file_list->lenght;
	ALLEGRO_BITMAP** verify = (ALLEGRO_BITMAP**)realloc(image, sizeof(ALLEGRO_BITMAP*) * image_lenght);
	if (!verify) alloc_memory_error();

	image = verify;

	char** verify_id = (char**)realloc(image_id, sizeof(char*) * image_lenght);
	if (!verify_id) alloc_memory_error();

	image_id = verify_id;

	for (register unsigned int i = image_lenght - file_list->lenght, e = 0; i < image_lenght; i++, e++) {
		image[i] = al_load_bitmap(file_list->files[e]);
		image_id[i] = file_list->ids[e];
		cout << " file.: " << file_list->files[e] << " - id: " << file_list->ids[e] << endl;
	}
}

void Allegro_routines::_add_fonts(Font_list* file_list) {

	font_lenght += file_list->lenght;
	ALLEGRO_FONT** verify = (ALLEGRO_FONT**)realloc(font, sizeof(ALLEGRO_FONT*) * font_lenght);
	if (!verify) alloc_memory_error();

	font = verify;

	char** verify_id = (char**)realloc(font_id, sizeof(char*) * font_lenght);
	if (!verify_id) alloc_memory_error();

	font_id = verify_id;

	for (register unsigned int i = font_lenght - file_list->lenght, e = 0; i < font_lenght; i++, e++) {
		font[i] = al_load_ttf_font(file_list->files[i], file_list->sizes[i], file_list->flags[i]);
		font_id[i] = file_list->ids[e];
		cout << " file.: " << file_list->files[e] << " - id: " << file_list->ids[e] << endl;
	}
}

#endif // !GRAPHIC_ROUTINES_H


#ifndef GRAPHIC_STARTUP_H
#define GRAPHIC_STARTUP_H

#include <iostream>

#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>

using namespace std;

#include "alloc_functions.h"



class File_list {
public:

	char** files = nullptr;
	char** ids = nullptr;
	unsigned int lenght = 0;

	void add(const char* file, const char* id) {
		alloc_str_vector(&files, lenght, file);
		alloc_str_vector(&this->ids, lenght, id);
		lenght++;
	}

	~File_list() {
		if (files) {
			for (register unsigned int i = 0; i < lenght; i++) free(files[i]);
			free(files);
		}
		/*if (ids) {
			for (register unsigned int i = 0; i < lenght; i++) free(ids[i]);
			free(ids);
		}*/
	}
};

class Font_list : public File_list{
public:
	unsigned int* sizes = nullptr;
	int* flags = nullptr;

	void add_font(const char* font, const char* id, unsigned int size, int flags) {

		alloc_vector<unsigned int>(&this->sizes, lenght, size);
		alloc_vector<int>(&this->flags, lenght, flags);
		add(font, id);
	}

	~Font_list() {
		if (sizes) {
			free(sizes);
		}
		if (flags) {
			free(flags);
		}
	}
};

class Allegro_routines {
public:
	int display_size[2] = { 0, 0 };
	int fps = 0;
	bool runing = true;

	ALLEGRO_DISPLAY* display = nullptr;

	ALLEGRO_EVENT evnt;
	ALLEGRO_EVENT_QUEUE* event_queue = nullptr;
	ALLEGRO_EVENT mouse_evnt;
	ALLEGRO_EVENT_QUEUE* mouse_event_queue = nullptr;

	ALLEGRO_TIMER* timer = nullptr;

	ALLEGRO_BITMAP** image = nullptr;
	char** image_id = nullptr;
	unsigned int image_lenght = 0;

	ALLEGRO_FONT** font = nullptr;
	char** font_id = nullptr;
	unsigned int font_lenght = 0;

	Allegro_routines(int display_x, int display_y, double fps, File_list* image_file_list = nullptr, Font_list* font_file_list = nullptr) {

		display_size[0] = display_x;
		display_size[1] = display_y;

		this->fps = fps;

		if (!al_init()) { 
			al_show_native_message_box(display, "Erro", "", "Falha ao iniciar recurso -> al_init()", "", 2); exit(-1); 
		}
		if(!al_init_font_addon()){ 
			al_show_native_message_box(display, "Erro", "", "Falha ao iniciar recurso -> al_init_font_addon()", "", 2); exit(-1);
		}
		if(!al_init_image_addon()){ 
			al_show_native_message_box(display, "Erro", "", "Falha ao iniciar recurso -> al_init_image_addon()", "", 2); exit(-1); 
		}
		if(!al_init_primitives_addon()){ 
			al_show_native_message_box(display, "Erro", "", "Falha ao iniciar recurso -> al_init_primitives_addon()", "", 2); exit(-1); 
		}
		if(!al_init_ttf_addon()){ 
			al_show_native_message_box(display, "Erro", "", "Falha ao iniciar recurso -> al_init_ttf_addon()", "", 2); exit(-1); 
		}

		if(image_file_list) _add_images(image_file_list);
		if (font_file_list) _add_fonts(font_file_list);

		display = al_create_display(display_x, display_y);

		timer = al_create_timer(1/fps);

		if (!al_install_keyboard()) {
			al_show_native_message_box(display, "Erro", "", "Falha ao iniciar recurso -> al_install_keyboard()", "", 2); exit(-1);
		}
		if (!al_install_mouse()) {
			al_show_native_message_box(display, "Erro", "", "Falha ao iniciar recurso -> al_install_mouse()", "", 2); exit(-1);
		}

		event_queue = al_create_event_queue();
		mouse_event_queue = al_create_event_queue();

		al_register_event_source(event_queue, al_get_keyboard_event_source());
		al_register_event_source(event_queue, al_get_display_event_source(display));
		al_register_event_source(event_queue, al_get_timer_event_source(timer));
		al_register_event_source(mouse_event_queue, al_get_mouse_event_source());

		al_start_timer(timer);
	}

	~Allegro_routines() {
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
		al_destroy_event_queue(mouse_event_queue);
		al_destroy_timer(timer);

		
		for (register unsigned int i = 0; i < image_lenght; i++) {
			cout << " deleting file..: " << image_id[i] << endl;
			al_destroy_bitmap(image[i]);
			free(image_id[i]);
		}
		
		for (register unsigned int i = 0; i < font_lenght; i++) {
			cout << " deleting file..: " << font_id[i] << endl;
			al_destroy_font(font[i]);
			free(font_id[i]);
		}

		free(font_id);
		free(image_id);
	}

	bool _flip();
	bool _timed();
	void _add_images(File_list* file_list);
	void _add_fonts(Font_list* file_list);

	};

#endif // !GRAPHIC_STARTUP_H

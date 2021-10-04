#ifndef GRAPHIC_CONVERGE_H
#define GRAPHIC_CONVERGE_H

#include "graphic_draws.h"

class GraphicFullManager : Allegro_routines, DrawManager{

	File_list* images;
	Font_list* fonts;

public:
	GraphicFullManager(int dx, int dy, double fps, File_list* images = nullptr, Font_list* fonts = nullptr) :
		DrawManager(dx, dy), Allegro_routines(dx, dy, fps, images, fonts) {
		
		this->images = new File_list;
		this->fonts = new Font_list;
	
	};

	void loadImages(const char* file, const char* id) {
		images->add(file, id);
	}

	void loadFonts(const char* font, const char* id, unsigned int size, int flags) {
		fonts->add_font(font, id, size, flags);
	}

	void upData() {

		if (fonts->lenght) { 
			_add_fonts(fonts);
			delete fonts; 
			fonts = new Font_list; 
		}
		if (images->lenght) {
			_add_images(images); 
			delete images; 
			images = new File_list;
		}
	}

	bool flip() {

		drawAllBox(this);

		return _flip();
	}

	bool timed() {
		return _timed();
	}

	void addBox(const char* id, const char* style, float x, float y, float width, float height) {

		_addBox(new Box(id, _getStyleById(style), x, y, width, height));
	}

	void addStyle(const char* id, int borderColor[3], int backgroundColor[3], int fontColor[3],
		const char* fontType, int fontSize, float borderSize[4], float padding[4], float margin[4]) {

		_addStyle(new Style(id, borderColor, backgroundColor, fontColor,
			fontType, fontSize, borderSize, padding, margin));
	}

	~GraphicFullManager(){
		delete fonts;
		delete images;
	}
};

#endif // GRAPHIC_CONVERGE_H
#ifndef GRAPHIC_MANAGER_H
#define GRAPHIC_MANAGER_H

#include "vectorX.h"

class Style {
public:

	Style* next = nullptr;

	char* id = nullptr;

	int *borderColor = nullptr;
	float *borderSize = nullptr;
	float* padding = nullptr;
	float* margin = nullptr;

	int *backgroundColor = nullptr;

	int *fontColor = nullptr;
	char* fontType = nullptr;
	int fontSize = 18;

	Style(const char* id, int borderColor[3], int backgroundColor[3], int fontColor[3],
		const char* fontType, int fontSize, float borderSize[4], float padding[4], float margin[4]) {

		this->id = new char[strlen(id)+1];
		strcpy(this->id, id);

		this->borderColor = borderColor;
		this->backgroundColor = backgroundColor;

		this->fontType = new char[strlen(fontType)+1];
		strcpy(this->fontType, fontType);

		this->fontColor = fontColor;
		this->fontSize = fontSize;

		this->borderSize = borderSize;
		this->padding = padding;
		this->margin = margin;

		cout << " style: " << this->id << endl;

	}

	~Style() {
		cout << " deleting style: " << this->id << endl;
		free(borderColor);
		free(backgroundColor);
		free(fontColor);

		free(padding);
		free(margin);
		free(borderSize);

		delete id;
		delete fontType;
	}
};

class Box {
public:

	Box* next = nullptr;

	Box* master = nullptr;
	Box* inherit = nullptr;

	float x = 0, y = 0, w = 0, h = 0,
		*p = nullptr, *m = nullptr, *b = nullptr;

	char* id = nullptr;
	Style* style = nullptr;

	Box(){}

	Box(const char* id, Style* style, float x, float y, float width, float height) {

		this->x = x;
		this->y = y;
		w = width;
		h = height;
		p = style->padding;
		m = style->margin;
		b = style->borderSize;
		this->style = style;

		this->id = new char[strlen(id) + 1];
		strcpy(this->id, id);

		cout << " box..: " << this->id << endl;
	}

	~Box(){
		cout << " deleting box..: " << this->id << endl;
		delete id;
	}
};


class Body {
public:

	Box* box = nullptr;
	Style* style = nullptr;

	Box* master = nullptr;
	Box* inherit = nullptr;

	Body(Style* style, float width, float height) {

		box = new Box("body", style, 0, 0, width, height);
		this->style = style;
		
	}

	~Body() {
		delete box; // talves isso se torne um erro
	}
};

class DrawManager {
public:
	Body* body = nullptr;
	Style* globalStyle = nullptr;

	Box* boxHeader = nullptr;
	Box* boxAnchor = nullptr;

	Style* styleHeader = nullptr;
	Style* styleAnchor = nullptr;

	DrawManager(float width, float height) {
		
		globalStyle = new Style("*", vector3(0), vector3(25), vector3(255), "ArialBlack", 24, vector4<float>(0), vector4<float>(5), vector4<float>(0));
		body = new Body(globalStyle, width, height);

		styleHeader = globalStyle;
		boxHeader = body->box;

		styleAnchor = globalStyle;
		boxAnchor = body->box;
	}

	~DrawManager() {

		for (Style* ptr = styleHeader, *del = styleHeader; ptr; ptr = ptr->next, delete del, del = ptr);
		for (Box* ptr = boxHeader, *del = boxHeader; ptr; ptr = ptr->next, delete del, del = ptr);
	}

	void _addStyle(Style* self) {

		styleAnchor->next = self;
		styleAnchor = self;
	}

	void _addBox(Box* self) {

		boxAnchor->next = self;
		boxAnchor = self;
	}

	Style* _getStyleById(const char* id) {

		for (Style* ptr = styleHeader; ptr; ptr = ptr->next) 
			if (!strcmp(ptr->id, id)) return ptr;

		return nullptr;
	}

	Box* _getBoxById(const char* id) {

		for (Box* ptr = boxHeader; ptr; ptr = ptr->next)
			if (!strcmp(ptr->id, id)) return ptr;

		return nullptr;
	}
};


#endif // !GRAPHIC_MANAGER_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include "graphic_converge.h"

int main() {

	GraphicFullManager gfc(1080, 720, 40);

	gfc.loadImages("pictures/pc1.jpg", "pc1");
	gfc.loadImages("pictures/pc2.jpg", "pc2");
	gfc.loadImages("pictures/pc3.jpg", "pc3");
	gfc.loadImages("pictures/pc4.jpg", "pc4");
	gfc.loadImages("pictures/pc5.jpg", "pc5");
	gfc.loadImages("pictures/pc6.jpg", "pc6");
	gfc.loadImages("pictures/pc7.jpg", "pc7");
	gfc.loadImages("pictures/pc8.jpg", "pc8");

	gfc.loadFonts("fonts/arial-black.ttf", "ArialBlack", 24, 0);
	gfc.loadFonts("fonts/GeosansLight.ttf", "GeosansLight", 24, 0);
	gfc.loadFonts("fonts/GeosansLight-Oblique.ttf", "GeosansLight-Oblique", 24, 0);

	gfc.upData();

	gfc.addStyle("header-style", vector3(0, 0, 0), vector3(125), vector3(0), "GeosansLight", 24, vector4<float>(0, 0, 2, 0), vector4<float>(0), vector4<float>(0));
	gfc.addStyle("section-right-style", vector3(0, 0, 0), vector3(125), vector3(0), "GeosansLight", 24, vector4<float>(0, 2, 0, 0), vector4<float>(0), vector4<float>(0));
	gfc.addStyle("section-left-style", vector3(0, 0, 0), vector3(186), vector3(0), "GeosansLight", 24, vector4<float>(0, 0, 0, 0), vector4<float>(0), vector4<float>(0));

	gfc.addBox("header", "header-style", 0, 0, 1080, 100);
	gfc.addBox("section-right", "section-right-style", 0, 102, 420, 620);
	gfc.addBox("section-left", "section-left-style", 422, 102, 1080, 620);

	
	File_list imgs;

	imgs.add("pictures/pc1.jpg", "pc1");
	imgs.add("pictures/pc2.jpg", "pc2");
	imgs.add("pictures/pc3.jpg", "pc3");
	imgs.add("pictures/pc4.jpg", "pc4");
	imgs.add("pictures/pc5.jpg", "pc5");
	imgs.add("pictures/pc6.jpg", "pc6");
	imgs.add("pictures/pc7.jpg", "pc7");
	imgs.add("pictures/pc8.jpg", "pc8");
	
	Font_list fts;

	fts.add_font("fonts/arial-black.ttf", "ArialBlack", 24, 0);
	fts.add_font("fonts/GeosansLight.ttf", "GeosansLight", 24, 0);
	fts.add_font("fonts/GeosansLight-Oblique.ttf", "GeosansLight-Oblique", 24, 0);
	/*
	DrawManager dmg(1080, 720);

	dmg.body->style->backgroundColor = vector3(62, 68, 72);

	dmg.addStyle(new Style("header-style", vector3(0, 0, 0), vector3(125), vector3(0), "GeosansLight", 24, vector4<float>(0, 0, 2 ,0), vector4<float>(0), vector4<float>(0)));
	dmg.addStyle(new Style("section-right-style", vector3(0, 0, 0), vector3(125), vector3(0), "GeosansLight", 24, vector4<float>(0, 2, 0 ,0), vector4<float>(0), vector4<float>(0)));
	dmg.addStyle(new Style("section-left-style", vector3(0, 0, 0), vector3(186), vector3(0), "GeosansLight", 24, vector4<float>(0, 0, 0 ,0), vector4<float>(0), vector4<float>(0)));

	dmg.addBox(new Box("header", dmg.getStyleById("header-style"), 0, 0, 1080, 100));

	dmg.addBox(new Box("section-right", dmg.getStyleById("section-right-style"), 0, 102, 420, 620));

	dmg.addBox(new Box("section-left", dmg.getStyleById("section-left-style"), 422, 102, 1080, 620));

	
	Allegro_routines gpc(dmg.body->box->w, dmg.body->box->h, 40, &imgs, &fts);
	*/

	while (gfc.flip()) if (gfc.timed());

	return 0;
}


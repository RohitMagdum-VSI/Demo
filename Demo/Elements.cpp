#include "Elements.h"
#include "DrawChars.h"

DrawChars drawChar;

void drawMedicalIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b};
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.03f, 0.03f, 1.0f };

	vector<string>  textToDraw;
	std::string currentChars = "Medical Science";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawDramaIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.03f, 0.03f, 1.0f };

	vector<string>  textToDraw;
	std::string currentChars = "Natak";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawTeacherIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.03f, 0.03f, 1.0f };
	
	vector<string>  textToDraw;
	std::string currentChars = "Teacher";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawAstroIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.03f, 0.03f, 1.0f };

	vector<string>  textToDraw;
	std::string currentChars = "Astrology";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawAppleIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.025f, 0.025f, 1.0f };
	
	vector<string>  textToDraw;
	std::string currentChars = "Apple Final Cut Pro";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawWin32Icon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.025f, 0.025f, 1.0f };

	vector<string>  textToDraw;
	std::string currentChars = "Win 32, COM";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawUnixIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.025f, 0.025f, 1.0f };

	vector<string>  textToDraw;
	std::string currentChars = "UNIX";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawAndroidIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.03f, 0.03f, 1.0f };

	vector<string>  textToDraw;
	std::string currentChars = "android";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawiOSIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.025f, 0.025f, 1.0f };
	
	vector<string>  textToDraw;
	std::string currentChars = "iOS";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawOpenGlIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.025f, 0.025f, 1.0f };

	vector<string>  textToDraw;
	std::string currentChars = "OpenGL";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawCUDAIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.025f, 0.025f, 1.0f };

	vector<string>  textToDraw;
	std::string currentChars = "CUDA";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawARMIcon(POSITION position, EL_COLOR color)
{
	vector<double> wordSpacVec;
	wordSpacVec.resize(10);
	wordSpacVec[0] = 0.0f;

	vector<double> charSpacVec;
	charSpacVec.resize(10);
	charSpacVec[0] = 0.3f;

	vector<double> charWidth;
	charWidth.resize(10);
	charWidth[0] = 0.5;

	vector<double> traslateXParam;
	traslateXParam.resize(10);
	traslateXParam[0] = position.x;

	vector<double> traslateYParam;
	traslateYParam.resize(10);
	traslateYParam[0] = position.y;

	vector<double> traslateZParam;
	traslateZParam.resize(10);
	traslateZParam[0] = position.z;

	vector<double> rgbVec1{ color.r, color.g, color.b };
	vector<vector<double>>rgbValueVec;
	rgbValueVec.resize(10);
	rgbValueVec[0] = rgbVec1;

	vector<vector<double>>scaleValueVec;
	scaleValueVec.resize(10);
	scaleValueVec[0] = { 0.025f, 0.025f, 1.0f };

	vector<string>  textToDraw;
	std::string currentChars = "ARM";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void DrawElements(void)
{
	EL_COLOR color;
	POSITION pos;

	color = { 1.0f, 1.0f, 1.0f };

	//level 1 ------------------------------
	pos = { -7.6f, -6.0f, -15.0f };
	drawMedicalIcon(pos, color);

	pos = { -2.2f, -6.0f, -15.0f };
	drawDramaIcon(pos, color);

	pos = { 0.4f, -6.0f, -15.0f };
	drawTeacherIcon(pos, color);

	pos = { 3.6f, -6.0f, -15.0f };
	drawAstroIcon(pos, color);

	pos = { 7.0f, -6.0f, -15.0f };
	drawAndroidIcon(pos, color);

	//level 2 ------------------------------
	pos = { -4.8f, -5.0f, -15.0f };
	drawWin32Icon(pos, color);

	pos = { -1.3f, -5.0f, -15.0f };
	drawUnixIcon(pos, color);

	pos = { 1.1f, -5.0f, -15.0f };
	drawAppleIcon(pos, color);
	
	pos = { 6.5f, -5.0f, -15.0f };
	drawiOSIcon(pos, color);

	//level 3 -----------------------------
	pos = { -1.3f, -4.0f, -15.0f };
	drawOpenGlIcon(pos, color);

	pos = { 1.3f, -4.0f, -15.0f };
	drawCUDAIcon(pos, color);

	pos = { 3.5f, -4.0f, -15.0f };
	drawARMIcon(pos, color);
}
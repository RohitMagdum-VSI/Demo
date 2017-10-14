#include "Elements.h"
#include "DrawChars.h"

void drawMedicalIcon(POSITION position, EL_COLOR color)
{
	DrawChars drawChar;

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
	DrawChars drawChar;

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
	DrawChars drawChar;

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
	DrawChars drawChar;

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
	DrawChars drawChar;

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
	DrawChars drawChar;

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
	DrawChars drawChar;

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
	DrawChars drawChar;

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

void drawOpenGlIcon(POSITION position, EL_COLOR color)
{
	DrawChars drawChar;

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
	std::string currentChars = "OpenGL";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void drawiOSIcon(POSITION position, EL_COLOR color)
{
	DrawChars drawChar;

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
	std::string currentChars = "iOS";
	textToDraw.push_back(currentChars);

	drawChar.initDrawChar(wordSpacVec, charSpacVec, charWidth, traslateXParam, traslateYParam,
		traslateZParam, rgbValueVec, scaleValueVec, textToDraw);

	drawChar.setWordToDisplayOnScreen();
}

void DrawElements(void)
{
	EL_COLOR color;
	POSITION pos;

	//level 1 ------------------------------
	pos = { -6.6f, -6.0f, -15.0f };
	color = { 1.0f, 1.0f, 1.0f };
	drawMedicalIcon(pos, color);

	pos = { -1.2f, -6.0f, -15.0f };
	color = { 1.0f, 1.0f, 1.0f };
	drawDramaIcon(pos, color);

	pos = { 1.4f, -6.0f, -15.0f };
	color = { 1.0f, 1.0f, 1.0f };
	drawTeacherIcon(pos, color);

	pos = { 4.6f, -6.0f, -15.0f };
	color = { 1.0f, 1.0f, 1.0f };
	drawAstroIcon(pos, color);

	//level 2 ------------------------------
	pos = { -4.8f, -5.4f, -15.0f };
	color = { 1.0f, 1.0f, 1.0f };
	drawWin32Icon(pos, color);

	pos = { -1.3f, -5.4f, -15.0f };
	color = { 1.0f, 1.0f, 1.0f };
	drawUnixIcon(pos, color);

	pos = { 1.1f, -5.4f, -15.0f };
	color = { 1.0f, 1.0f, 1.0f };
	drawAppleIcon(pos, color);

	pos = { 6.0f, -17.0f, -50.0f };
	color = { 0.0f, 1.0f, 0.2f };
	drawAndroidIcon(pos, color);

	pos = { 10.0f, -20.0f, -50.0f };
	color = { 1.0f, 1.0f, 1.0f };
	drawOpenGlIcon(pos, color);

	pos = { 14.0f, -15.0f, -50.0f };
	color = { 1.0f, 1.0f, 1.0f };
	drawiOSIcon(pos, color);
}
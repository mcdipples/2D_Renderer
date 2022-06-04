#ifndef PARSER_H
#define PARSER_H

#include <QCoreApplication>
#include <QMessageBox>
#include <QFile>
#include <fstream>
#include <iostream>
#include <string>
#include <QTextStream>
#include <stdlib.h>
#include "shapes.h"

using namespace std;
using namespace Qt;

sdog::vector<Shape*> readFile();
inline void seekToColon(istream& stream);
inline void seekToComma(istream& stream);

Shape* ReadLine(ifstream&, int ShapeID);
Shape* ReadPolyLine(ifstream&, int ShapeID);
Shape* ReadPolygon(ifstream&, int ShapeID);
Shape* ReadRectangle(ifstream&, int ShapeID);
Shape* ReadSquare(ifstream&, int ShapeID);
Shape* ReadEllipse(ifstream&, int ShapeID);
Shape* ReadCircle(ifstream&, int ShapeID);
Shape* ReadText(ifstream&, int ShapeID);

QColor getColor(const string);
PenStyle getPenStyle(const string);
PenCapStyle getPenCapStyle(const string);
PenJoinStyle getPenJoinStyle(const string);

BrushStyle getBrushStyle(const string);
QFont::Weight getFontWeight(const string);
int getShapeType(const string shapeType);

int getTextColor(const string textcolor);
int getTextAlignment(const string ta);
int getTextFontStyle(const string tfs);
int getTextFontFamily(const string tff);
int getTextFontWeight(const string tfw);

#endif // PARSER_H

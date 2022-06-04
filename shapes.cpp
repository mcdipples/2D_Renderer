#include "shapes.h"
#include <fstream>
using namespace std;

//uwu
int Shape::numShapes = 1;

//string serializePenStyle(QPen pen)
//{
//    if(pen.style() == NoPen){
//        return "NoPen";
//    }
//    else if(pen.style() == SolidLine){
//        return "SolidLine";
//    }
//    else if(pen.style() == DashLine){
//        return "DashLine";
//    }
//    else if(pen.style() == DotLine){
//        return "DotLine";
//    }
//    else if(pen.style() == DashDotLine){
//        return "DashDotLine";
//    }
//    else if(pen.style() == DashDotDotLine){
//        return "DashDotDotLine";
//    }else {
//        return "NoPen";
//    }
//}

//string serializePenCapStyle(QPen pen)
//{
//    if(pen.capStyle() == FlatCap){
//        return "FlatCap";
//    }
//    else if(pen.capStyle() == SquareCap){
//        return "SquareCap";
//    }
//    else if(pen.capStyle() == RoundCap){
//        return "RoundCap";
//    }else {
//        return "FlatCap";
//    }
//}

//string serializeColor(QColor color)
//{
//    if(color == Qt::white) {
//        return "white";   // enum white = 3
//    }
//    else if(color == Qt::black){
//        return "black";
//    }
//    else if(color == Qt::red){
//        return "red";
//    }
//    else if(color == Qt::green){
//        return "green";
//    }
//    else if(color == Qt::blue){
//        return "blue";   // Line: runs though and returns 9 (blue), maybe it is assigning the color?
//    }
//    else if(color == Qt::cyan){
//        return "cyan";
//    }
//    else if(color == Qt::magenta){
//        return "magenta";
//    }
//    else if(color == Qt::yellow){
//        return "yellow";
//    }
//    else if(color == Qt::gray){
//        return "gray";
//    } else {
//        return "black";
//    }
//}

//string serializePenJoinStyle(QPen pen)
//{
//    if(pen.joinStyle() == MiterJoin){
//        return "MiterJoin";
//    }
//    else if(pen.joinStyle() == BevelJoin){
//        return "BevelJoin";
//    }
//    else if(pen.joinStyle() == RoundJoin){
//        return "RoundJoin";
//    } else {
//        return "MiterJoin";
//    }
//}

////string serializeBrushStyle(serializeBrushStyle(brush)
////{
////    if(brush == SolidPattern){
////        return "SolidPattern";
////    }
////    else if(brush == HorPattern){
////        return "HorPattern";
////    }
////    else if(brush == VerPattern){
////        return "VerPattern";
////    }
////    else if(brush == NoBrush){
////        return "NoBrush";
////    } else {
////        return "SolidPattern";
////    }
////}

//int serializeShapeType(string shapeType)
//{
//    if(shapeType == "Line"){
//        return 1;
//    }
//    else if(shapeType == "Polyline"){
//        return 2;
//    }
//    else if(shapeType == "Polygon"){
//        return 3;
//    }
//    else if(shapeType == "Rectangle"){
//        return 4;
//    }
//    else if(shapeType == "Square"){
//        return 5;
//    }
//    else if(shapeType == "Ellipse"){
//        return 6;
//    }
//    else if(shapeType == "Circle"){
//        return 7;
//    }
//    else if(shapeType == "Text"){
//        return 8;
//    }
//    else {
//        return 0;
//    }
//}

//int serializeTextColor(string textcolor)
//{
//    if(textcolor == "blue"){
//        return 0;
//    }
//    else if(textcolor == "red"){
//        return 1;
//    }
//    else if(textcolor == "green"){
//        return 2;
//    }
//    else if(textcolor == "yellow"){
//        return 3;
//    }
//    else if(textcolor == "black"){
//        return 4;
//    }
//    else if(textcolor == "white"){
//        return 5;
//    }
//    else if(textcolor == "cyan"){
//        return 6;
//    }
//    else if(textcolor == "magenta"){
//        return 7;
//    }
//    else if(textcolor == "gray"){
//        return 8;
//    }
//    else {
//        return 4;
//    }
//}

//int serializeTextAlignment(string ta)
//{
//    if(ta == "AlignLeft"){
//        return 0;
//    }
//    else if(ta == "AlignCenter"){
//        return 1;
//    }
//    else if(ta == "AlignRight"){
//        return 2;
//    }
//    else if(ta == "AlignTop"){
//        return 3;
//    }
//    else if(ta == "AlignBottom"){
//        return 4;
//    }
//    else {
//        return 4;
//    }
//}

//int serializeTextFontStyle(string tfs)
//{
//    if(tfs == "StyleItalic"){
//        return 0;
//    }
//    else if(tfs == "Bold"){
//        return 1;
//    }
//    else{
//        return 0;
//    }
//}

//int serializeTextFontFamily(string tff)
//{
//    if(tff == "Comic Sans MS"){
//        return 0;
//    }
//    else if(tff == "Courier"){
//        return 1;
//    }
//    else if(tff == "Helvetica"){
//        return 2;
//    }
//    else if(tff == "Times"){
//        return 3;
//    }
//    else {
//        return 0;
//    }
//}

//int serializeTextFontWeight(string tfw)
//{
//    if(tfw == "Thin"){
//        return 0;
//    }
//    else if(tfw == "Light"){
//        return 1;
//    }
//    else if(tfw == "Normal"){
//        return 2;
//    }
//    else if(tfw == "Bold"){
//        return 3;
//    }
//    else {
//        return 2;
//    }
//}

void serializeWrite(/*sdog::vector<Shape*> &shapeVector*/) {
    int id;

    string shapeType = "Line";

    QPoint shapeDim;
    int x1 = 20;
    int y1 = 90;
    int x2 = 100;
    int y2 = 20;

    QPen pen;
    string penStyle = "DashDotLine";
    string penCapStyle = "FlatCap";
    string penJoinStyle = "MiterJoin";
    QColor penColor;
    string penStrColor = "blue";
    int penWidth = 2;


    QBrush brush;
    string brushStyle;
    QColor brushColor;
    string brushStrColor;

    Text text;
    QFont font;


    ofstream myfile;
    myfile.open ("C:/Users/isaac_m2olzwl/OneDrive/Documents/project/shapes_copy.txt");

    myfile << "ShapeId: " << id << "\nShapeType: " << shapeType << "\nShapeDimensions: " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << "\nPenColor: " << penStrColor << "\nPenWidth: " <<  penWidth << "\nPenStyle: " << penStyle << "\nPenCapStyle: " << penCapStyle << "\nPenJoinStyle: " << penJoinStyle << "\n";


//    while (!shapeVector.end()) {
//        for (int i = 0; i < shapeVector.size(); i++) {
            //serializes the Shape ID for shape contained within vector
//            id = shapeVector[i]->serializeID();

//            //serializes shapeType to determine what needs to be written
//            shapeType = shapeVector[i]->serializeShape();

//            if(shapeType == "Line") {
//                //serializes points used for shape
////                shapeDim = shapeVector[i]->serializePointBegin();
////                x1 = shapeDim.x();
////                y1 = shapeDim.y();
////                shapeDim = shapeVector[i]->serializePointEnd();
////                x2 = shapeDim.x();
////                y2 = shapeDim.y();

//                //serializes the pen used for the shape within vector
//                pen = shapeVector[i]->serializePen();

//                //Converts pen parameters from QObjects into strings for output
//                penStyle = serializePenStyle(pen);
//                penColor = pen.color();
//                penCapStyle = serializePenCapStyle(pen);
//                penJoinStyle = serializePenJoinStyle(pen);
//                penStrColor = serializeColor(penColor);
//                penWidth = pen.width();

//                myfile << "ShapeId: " << id << "\nShapeType: " << shapeType << "\nShapeDimensions: " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << "\nPenColor: " << penStrColor << "\nPenWidth: " <<  penWidth << "\nPenStyle: " << penStyle << "\nPenCapStyle: " << penCapStyle << "\nPenJoinStyle: " << penJoinStyle << "\n";
//            }
//            else if(shapeType == "Polyline") {
//                //serializes the pen used for the shape within vector
//                pen = shapeVector[i]->serializePen();

//                //Converts pen parameters from QObjects into strings for output
//                penStyle = serializePenStyle(pen);
//                penColor = pen.color();
//                penCapStyle = serializePenCapStyle(pen);
//                penJoinStyle = serializePenJoinStyle(pen);
//                penStrColor = serializeColor(penColor);

//                //TODO: OUTPUT TO FILE
//            }
//            else if(shapeType == "Polygon") {
//                //serializes the pen used for the shape within vector
//                pen = shapeVector[i]->serializePen();

//                //Converts pen parameters from QObjects into strings for output
//                penStyle = serializePenStyle(pen);
//                penColor = pen.color();
//                penCapStyle = serializePenCapStyle(pen);
//                penJoinStyle = serializePenJoinStyle(pen);
//                penStrColor = serializeColor(penColor);

//                //serializes brush used for shape within vector
//                brush = shapeVector[i]->serializeBrush();

//                //Converts brush parameters from QObjects into strings for output
//                brushColor = brush.color();
//                brushStrColor = serializeColor(brushColor);

//                //TODO: OUTPUT TO FILE
//            }
//            else if(shapeType == "Rectangle") {
//                //serializes the pen used for the shape within vector
//                pen = shapeVector[i]->serializePen();

//                //Converts pen parameters from QObjects into strings for output
//                penStyle = serializePenStyle(pen);
//                penColor = pen.color();
//                penCapStyle = serializePenCapStyle(pen);
//                penJoinStyle = serializePenJoinStyle(pen);
//                penStrColor = serializeColor(penColor);

//                //serializes brush used for shape within vector
//                brush = shapeVector[i]->serializeBrush();

//                //Converts brush parameters from QObjects into strings for output
//                brushColor = brush.color();
//                brushStrColor = serializeColor(brushColor);

//                //TODO: OUTPUT TO FILE
//            }

//            else if(shapeType == "Square") {
//                //serializes the pen used for the shape within vector
//                pen = shapeVector[i]->serializePen();

//                //Converts pen parameters from QObjects into strings for output
//                penStyle = serializePenStyle(pen);
//                penColor = pen.color();
//                penCapStyle = serializePenCapStyle(pen);
//                penJoinStyle = serializePenJoinStyle(pen);
//                penStrColor = serializeColor(penColor);

//                //serializes brush used for shape within vector
//                brush = shapeVector[i]->serializeBrush();

//                //Converts brush parameters from QObjects into strings for output
//                brushColor = brush.color();
//                brushStrColor = serializeColor(brushColor);

//                //TODO: OUTPUT TO FILE
//            }

//            else if(shapeType == "Ellipse") {
//                //serializes the pen used for the shape within vector
//                pen = shapeVector[i]->serializePen();

//                //Converts pen parameters from QObjects into strings for output
//                penStyle = serializePenStyle(pen);
//                penColor = pen.color();
//                penCapStyle = serializePenCapStyle(pen);
//                penJoinStyle = serializePenJoinStyle(pen);
//                penStrColor = serializeColor(penColor);

//                //serializes brush used for shape within vector
//                brush = shapeVector[i]->serializeBrush();

//                //Converts brush parameters from QObjects into strings for output
//                brushColor = brush.color();
//                brushStrColor = serializeColor(brushColor);

//                //TODO: OUTPUT TO FILE
//            }

//            else if(shapeType == "Circle") {
//                //serializes the pen used for the shape within vector
//                pen = shapeVector[i]->serializePen();

//                //Converts pen parameters from QObjects into strings for output
//                penStyle = serializePenStyle(pen);
//                penColor = pen.color();
//                penCapStyle = serializePenCapStyle(pen);
//                penJoinStyle = serializePenJoinStyle(pen);
//                penStrColor = serializeColor(penColor);

//                //serializes brush used for shape within vector
//                brush = shapeVector[i]->serializeBrush();

//                //Converts brush parameters from QObjects into strings for output
//                brushColor = brush.color();
//                brushStrColor = serializeColor(brushColor);

//                //TODO: OUTPUT TO FILE
//            }

//            else if (shapeType == "Text") {

//            }
//        }
//    }

    myfile.close();

    return;
}

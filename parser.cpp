#include "parser.h"

inline void seekToColon(istream& stream){
    stream.ignore(numeric_limits<streamsize>::max(), ':');
    if (stream.peek() == ' '){ stream.ignore(); }
}
inline void seekToComma(istream& stream){
    stream.ignore(numeric_limits<streamsize>::max(), ',');
    if (stream.peek() == ' '){ stream.ignore(); }
}

// implementations for getters
QColor getColor(string color)
{
    if(color == "white"){
        return Qt::white;   // enum white = 3
    }
    else if(color == "black"){
        return Qt::black;
    }
    else if(color == "red"){
        return Qt::red;
    }
    else if(color == "green"){
        return Qt::green;
    }
    else if(color == "blue"){
        return Qt::blue;   // Line: runs though and returns 9 (blue), maybe it is assigning the color?
    }
    else if(color == "cyan"){
        return Qt::cyan;
    }
    else if(color == "magenta"){
        return Qt::magenta;
    }
    else if(color == "yellow"){
        return Qt::yellow;
    }
    else if(color == "gray"){
        return Qt::gray;
    } else {
        return Qt::black;
    }
}

PenStyle getPenStyle(string style)
{
    if(style == "NoPen"){
        return NoPen;
    }
    else if(style == "SolidLine"){
        return SolidLine;
    }
    else if(style == "DashLine"){
        return DashLine;
    }
    else if(style == "DotLine"){
        return DotLine;
    }
    else if(style == "DashDotLine"){
        return DashDotLine;
    }
    else if(style == "DashDotDotLine"){
        return DashDotDotLine;
    }else {
        return NoPen;
    }
}

PenCapStyle getPenCapStyle(string cap)
{
    if(cap == "FlatCap"){
        return FlatCap;
    }
    else if(cap == "SquareCap"){
        return SquareCap;
    }
    else if(cap == "RoundCap"){
        return RoundCap;
    }else {
        return FlatCap;
    }
}

PenJoinStyle getPenJoinStyle(string join)
{
    if(join == "MiterJoin"){
        return MiterJoin;
    }
    else if(join == "BevelJoin"){
        return BevelJoin;
    }
    else if(join == "RoundJoin"){
        return RoundJoin;
    } else {
        return MiterJoin;
    }
}

BrushStyle getBrushStyle(string brush)
{
    if(brush == "SolidPattern"){
        return SolidPattern;
    }
    else if(brush == "HorPattern"){
        return HorPattern;
    }
    else if(brush == "VerPattern"){
        return VerPattern;
    }
    else if(brush == "NoBrush"){
        return NoBrush;
    } else {
        return SolidPattern;
    }
}

int getShapeType(string shapeType)
{
    if(shapeType == "Line"){
        return 1;
    }
    else if(shapeType == "Polyline"){
        return 2;
    }
    else if(shapeType == "Polygon"){
        return 3;
    }
    else if(shapeType == "Rectangle"){
        return 4;
    }
    else if(shapeType == "Square"){
        return 5;
    }
    else if(shapeType == "Ellipse"){
        return 6;
    }
    else if(shapeType == "Circle"){
        return 7;
    }
    else if(shapeType == "Text"){
        return 8;
    }
    else {
        return 0;
    }
}

int getTextColor(string textcolor)
{
    if(textcolor == "blue"){
        return 0;
    }
    else if(textcolor == "red"){
        return 1;
    }
    else if(textcolor == "green"){
        return 2;
    }
    else if(textcolor == "yellow"){
        return 3;
    }
    else if(textcolor == "black"){
        return 4;
    }
    else if(textcolor == "white"){
        return 5;
    }
    else if(textcolor == "cyan"){
        return 6;
    }
    else if(textcolor == "magenta"){
        return 7;
    }
    else if(textcolor == "gray"){
        return 8;
    }
    else {
        return 4;
    }
}

int getTextAlignment(string ta)
{
    if(ta == "AlignLeft"){
        return 0;
    }
    else if(ta == "AlignCenter"){
        return 1;
    }
    else if(ta == "AlignRight"){
        return 2;
    }
    else if(ta == "AlignTop"){
        return 3;
    }
    else if(ta == "AlignBottom"){
        return 4;
    }
    else {
        return 4;
    }
}

int getTextFontStyle(string tfs)
{
    if(tfs == "StyleItalic"){
        return 0;
    }
    else if(tfs == "Bold"){
        return 1;
    }
    else{
        return 0;
    }
}

int getTextFontFamily(string tff)
{
    if(tff == "Comic Sans MS"){
        return 0;
    }
    else if(tff == "Courier"){
        return 1;
    }
    else if(tff == "Helvetica"){
        return 2;
    }
    else if(tff == "Times"){
        return 3;
    }
    else {
        return 0;
    }
}

int getTextFontWeight(string tfw)
{
    if(tfw == "Thin"){
        return 0;
    }
    else if(tfw == "Light"){
        return 1;
    }
    else if(tfw == "Normal"){
        return 2;
    }
    else if(tfw == "Bold"){
        return 3;
    }
    else {
        return 2;
    }
}

sdog::vector<Shape*> readFile()
{
   sdog::vector<Shape*> shapeMag;

   ifstream file;
   file.open("D:/source/repos/Qt_Projects/ScrumDogProject/ScrumDogProject/project/shapes.txt");

    // check file status
   //======================================
   if(file.is_open()) {
       qInfo() << "File opened successfully!";
   }

   if(!file.good())
   {
       qInfo() << "HEY: File is in an error state!!\n Here's the error:";
       qCritical() << strerror(errno);
         // checks which kind of error is happening
   }

   if(!file.is_open()) {
       qCritical() << "File failed to open!";
   }
    //======================================

   while(!file.eof()) {

       int ShapeID;
       int type = 0;
       string shapeType;

       seekToColon(file);
       file >> ShapeID; // read in shapeID

       seekToColon(file);
       getline(file, shapeType);    // read in shapeType
       type = getShapeType(shapeType);

    //---------------------
    switch(type){
       //Read Line
       case 1:
           qInfo() << "Reading line!";
           shapeMag.push_back(ReadLine(file, ShapeID));
           break;

       //Read PolyLine
       case 2:
            qInfo() << "Reading polyline!";
           shapeMag.push_back(ReadPolyLine(file, ShapeID));
           break;

       //Read Polygon
       case 3:
           qInfo() << "Reading polygon!";
           shapeMag.push_back(ReadPolygon(file, ShapeID));
           break;

       //Read Rectangle
       case 4:
           qInfo() << "Reading Rectangle!";
           shapeMag.push_back(ReadRectangle(file, ShapeID));
           break;

       //Read Square
       case 5:
        qInfo() << "Reading Square!";
           shapeMag.push_back(ReadSquare(file, ShapeID));
           break;

       //Read Ellipse
       case 6:
        qInfo() << "Reading Ellipse!";
           shapeMag.push_back(ReadEllipse(file, ShapeID));
           break;

       //Read Circle
       case 7:
        qInfo() << "Reading Circle!";
           shapeMag.push_back(ReadCircle(file, ShapeID));
           break;

       //Read Text
       case 8:
        qInfo() << "Reading Text!";
           shapeMag.push_back(ReadText(file, ShapeID));
           break;

       default:
          qInfo() << "No shapes to read!";
           break;
       }
       file.peek();
   }
   file.close();
   return shapeMag;
}

/*!
 * \brief ReadLine
 * \param file
 * \param id
 * \return new line object
 */
Shape* ReadLine(ifstream& file, int ShapeID){  // complete
    //======================================
    int x{0};
    int y{0};
    int x2{0};
    int y2{0};
    string color;
    string style;
    string c_style;
    string join;
    int width{0};

    QColor p_color = Qt::black; // default to black
    PenStyle p_style;
    PenCapStyle p_c_style;
    PenJoinStyle p_penjoin;
    //======================================

    // ShapeDimensions: get coords for qpoint begin and end
    seekToColon(file);
    file >> x;
    seekToComma(file);
    file >> y;
    seekToComma(file);
    file >> x2;
    seekToComma(file);
    file >> y2;

    //---------------------
    // PenColor
    seekToColon(file);
    getline(file, color);
    p_color = getColor(color);  // reading in "blue" as color string, but not translating it to QColor?

    //---------------------
    // PenWidth
    seekToColon(file);
    file >> width;

    //---------------------
    // PenStyle
    seekToColon(file);
    getline(file, style);
    p_style = getPenStyle(style);   // never read -- i think it's fine

    //---------------------
    // PenCapStyle
    seekToColon(file);
    getline(file, c_style);
    p_c_style = getPenCapStyle(c_style);

    //---------------------
    // PenJoinStyle
    seekToColon(file);
    getline(file, join);
    p_penjoin = getPenJoinStyle(join);

    //---------------------
    // need Qpen object and Qpoints
    QPoint pointBegin(x, y);    // set Qpoints
    QPoint pointEnd(x2, y2);

    // create new line object and pass in params
    Line* line = new Line(pointBegin, pointEnd);
    line->setID(ShapeID);
    line->setPen(p_color, width, p_style, p_c_style, p_penjoin);
    line->setShape(Shape::line);

    return line;
}

Shape* ReadPolyLine(ifstream& file, int ShapeID){   // complete(?)
    //======================================
    string color;
    string style;
    string c_style;
    string join;

    int width{0};

    QColor p_color;
    PenStyle p_style;
    PenCapStyle p_c_style;
    PenJoinStyle p_penjoin;

    Polyline* polyline = new Polyline();    // default shape constructor
    //======================================

    // ShapeDimensions
    seekToColon(file);
    do {
        int x;
        int y;
        file >> x;
        seekToComma(file);  // seek to ", "
        file >> y;

        QPoint pt(x, y);
        polyline->setPoints(pt);
        // push each point read in into pointArr

        if (file.peek() ==','){
        seekToComma(file); }

    } while(file.peek() != '\n');

    //---------------------
    // PenColor
    seekToColon(file);
    getline(file, color);
    p_color = getColor(color);

    //---------------------
    // PenWidth
    seekToColon(file);
    file >> width;

    //---------------------
    // PenStyle
    seekToColon(file);
    getline(file, style);
    p_style = getPenStyle(style);   // never read -- i think it's fine

    //---------------------
    // PenCapStyle
    seekToColon(file);
    getline(file, c_style);
    p_c_style = getPenCapStyle(c_style);

    //---------------------
    // PenJoinStyle
    seekToColon(file);
    getline(file, join);
    p_penjoin = getPenJoinStyle(join);

    polyline->setPen(p_color, width, p_style, p_c_style, p_penjoin);
    polyline->setID(ShapeID);

    return polyline;
}

Shape* ReadPolygon(std::ifstream& file, int ShapeID){
    //======================================
    string color;
    string style;
    string c_style;
    string join;
    int width{0};

    QColor p_color;
    PenStyle p_style;
    PenCapStyle p_c_style;
    PenJoinStyle p_penjoin;
    QColor b_color;
    BrushStyle b_style;

    //Needs constructor
    Polygon* polygon = new Polygon();
    //======================================

    // ShapeDimensions
    seekToColon(file);
    do {
        int x;
        int y;
        file >> x;
        seekToComma(file);  // seek to ", "
        file >> y;

        QPoint pt(x, y);
        polygon->setPoints(pt);
        // push each point read in into pointArr

        if (file.peek() ==','){
        seekToComma(file); }

    } while(file.peek() != '\n');

    //---------------------
    // PenColor
    seekToColon(file);
    getline(file, color);
    p_color = getColor(color);

    //---------------------
    // PenWidth
    seekToColon(file);
    file >> width;

    //---------------------
    // PenStyle
    seekToColon(file);
    getline(file, style);
    p_style = getPenStyle(style);   // never read -- i think it's fine

    //---------------------
    // PenCapStyle
    seekToColon(file);
    getline(file, c_style);
    p_c_style = getPenCapStyle(c_style);

    //---------------------
    // PenJoinStyle
    seekToColon(file);
    getline(file, join);
    p_penjoin = getPenJoinStyle(join);

    //---------------------
    // BrushColor
    seekToColon(file);
    getline(file, color);
    b_color = getColor(color);

    //---------------------
    // BrushStyle
    file.ignore(numeric_limits<streamsize>::max(),  ':');
    getline(file, style);
    b_style = getBrushStyle(style);

    polygon->setPen(p_color, width, p_style, p_c_style, p_penjoin);
    polygon->setID(ShapeID);
    polygon->setBrush(b_color, b_style);
    return polygon;
}

Shape* ReadRectangle(ifstream& file, int ShapeID){
    //======================================
    string color;
    string style;
    string c_style;
    string join;
    string bstyle;
    string bcolor;
    int pwidth;
    int width{0};
    int height{0};
    int x{0};
    int y{0};   // origin = point( x, y )

    QColor p_color;
    PenStyle p_style;
    PenCapStyle p_c_style;
    PenJoinStyle p_penjoin;
    QColor b_color;
    BrushStyle b_style;
    //======================================

    // ShapeDimensions
    seekToColon(file);
    file >> x;
    seekToComma(file);
    file >> y;
    seekToComma(file);
    file >> width;
    seekToComma(file);
    file >> height;

    //---------------------
    // PenColor
    seekToColon(file);
    getline(file, color);
    p_color = getColor(color);

    //---------------------
    // PenWidth
    seekToColon(file);
    file >> pwidth;

    //---------------------
    // PenStyle
    seekToColon(file);
    getline(file, style);
    p_style = getPenStyle(style);   // never read -- i think it's fine

    //---------------------
    // PenCapStyle
    seekToColon(file);
    getline(file, c_style);
    p_c_style = getPenCapStyle(c_style);

    //---------------------
    // PenJoinStyle
    seekToColon(file);
    getline(file, join);
    p_penjoin = getPenJoinStyle(join);

    //---------------------
    // BrushColor
    seekToColon(file);
    getline(file, bcolor);
    b_color = getColor(bcolor);

    //---------------------
    // BrushStyle
    seekToColon(file);
    getline(file, bstyle);
    b_style = getBrushStyle(bstyle);

    Rectangle* rectangle = new Rectangle(x, y, width, height);
    rectangle->setBrush(b_color, b_style);
    rectangle->setPen(p_color, pwidth, p_style, p_c_style, p_penjoin);
    rectangle->setID(ShapeID);

    return rectangle;
}

Shape* ReadSquare(std::ifstream& file, int ShapeID){
    //======================================
    string color;
    string style;
    string c_style;
    string join;
    string bstyle;
    string bcolor;
    int width{0};   // square does not have height since width == height
    int pwidth{0};
    int x{0};
    int y{0};   // origin = point( x, y )

    QColor p_color;
    PenStyle p_style;
    PenCapStyle p_c_style;
    PenJoinStyle p_penjoin;
    QColor b_color;
    BrushStyle b_style;

    Square* square = new Square();
    //======================================

    // ShapeDimensions
    seekToColon(file);
    file >> x;
    seekToComma(file);
    file >> y;
    seekToComma(file);
    file >> width;

    //---------------------
    // PenColor
    seekToColon(file);
    getline(file, color);
    p_color = getColor(color);

    //---------------------
    // PenWidth
    seekToColon(file);
    file >> pwidth;

    //---------------------
    // PenStyle
    seekToColon(file);
    getline(file, style);
    p_style = getPenStyle(style);   // never read -- i think it's fine

    //---------------------
    // PenCapStyle
    seekToColon(file);
    getline(file, c_style);
    p_c_style = getPenCapStyle(c_style);

    //---------------------
    // PenJoinStyle
    seekToColon(file);
    getline(file, join);
    p_penjoin = getPenJoinStyle(join);

    //---------------------
    // BrushColor
    seekToColon(file);
    getline(file, bcolor);
    b_color = getColor(bcolor);

    //---------------------
    // BrushStyle
    seekToColon(file);
    getline(file, bstyle);
    b_style = getBrushStyle(bstyle);

    square->setBrush(b_color, b_style);
    square->setPen(p_color, pwidth, p_style, p_c_style, p_penjoin);
    square->setID(ShapeID);
    square->setSquareStart(x, y);
    square->setSideLength(width);

    return square;
}

Shape* ReadEllipse(std::ifstream& file, int ShapeID){
    //======================================
    string color;
    string style;
    string c_style;
    string join;
    string bstyle;
    string bcolor;
    int pwidth;
    int width{0};
    int height{0};
    int x{0};
    int y{0};   // origin = point( x, y )

    QColor p_color;
    PenStyle p_style;
    PenCapStyle p_c_style;
    PenJoinStyle p_penjoin;
    QColor b_color;
    BrushStyle b_style;
    //======================================

    // ShapeDimensions
    seekToColon(file);
    file >> x;
    seekToComma(file);
    file >> y;
    seekToComma(file);
    file >> width;
    seekToComma(file);
    file >> height;

    //---------------------
    // PenColor
    seekToColon(file);
    getline(file, color);
    p_color = getColor(color);

    //---------------------
    // PenWidth
    seekToColon(file);
    file >> pwidth;

    //---------------------
    // PenStyle
    seekToColon(file);
    getline(file, style);
    p_style = getPenStyle(style);   // never read -- i think it's fine

    //---------------------
    // PenCapStyle
    seekToColon(file);
    getline(file, c_style);
    p_c_style = getPenCapStyle(c_style);

    //---------------------
    // PenJoinStyle
    seekToColon(file);
    getline(file, join);
    p_penjoin = getPenJoinStyle(join);

    //---------------------
    // BrushColor
    seekToColon(file);
    getline(file, bcolor);
    b_color = getColor(bcolor);

    //---------------------
    // BrushStyle
    seekToColon(file);
    getline(file, bstyle);
    b_style = getBrushStyle(bstyle);

    //Needs constructor
    Ellipse* ellipse = new Ellipse(x, y, width, height);
    ellipse->setID(ShapeID);
    ellipse->setBrush(b_color, b_style);
    ellipse->setPen(p_color, pwidth, p_style, p_c_style, p_penjoin);

    return ellipse;
}

Shape* ReadCircle(std::ifstream& file, int ShapeID){
    //======================================
    string color;
    string style;
    string c_style;
    string join;
    string bstyle;
    string bcolor;
    int pwidth;
    int width{0};
    int height{0};
    int x{0};
    int y{0};   // origin = point( x, y )

    QColor p_color;
    PenStyle p_style;
    PenCapStyle p_c_style;
    PenJoinStyle p_penjoin;
    QColor b_color;
    BrushStyle b_style;
    //======================================

    // ShapeDimensions
    seekToColon(file);
    file >> x;
    seekToComma(file);
    file >> y;
    seekToComma(file);
    file >> width;
    height = width;

    //---------------------
    // PenColor
    seekToColon(file);
    getline(file, color);
    p_color = getColor(color);

    //---------------------
    // PenWidth
    seekToColon(file);
    file >> pwidth;

    //---------------------
    // PenStyle
    seekToColon(file);
    getline(file, style);
    p_style = getPenStyle(style);

    //---------------------
    // PenCapStyle
    seekToColon(file);
    getline(file, c_style);
    p_c_style = getPenCapStyle(c_style);

    //---------------------
    // PenJoinStyle
    seekToColon(file);
    getline(file, join);
    p_penjoin = getPenJoinStyle(join);

    //---------------------
    // BrushColor
    seekToColon(file);
    getline(file, bcolor);
    b_color = getColor(bcolor);

    //---------------------
    // BrushStyle
    seekToColon(file);
    getline(file, bstyle);
    b_style = getBrushStyle(bstyle);

    //Needs constructor
    Circle* circle = new Circle(x, y, width, height);
    circle->setID(ShapeID);
    circle->setBrush(b_color, b_style);
    circle->setPen(p_color, pwidth, p_style, p_c_style, p_penjoin);

    return circle;
}

Shape* ReadText(std::ifstream& file, int ShapeID){
    //======================================
    string color;   // text color
    string text;    // TextString
    string align;   // text align
    string fontSize;
    string fontFam;
    string fontStyle;
    string fontWeight;

    int x1; //tx
    int x2; //bx
    int y1; //ty
    int y2; //by

    int tc;     // text color
    QString ts; // TextString
    int ta;     // text align
    int tfs;    // text font style
    int tff;    // text font fam
    int tfw;    // text font weight
    int tps;    // text point size


    //======================================
    // ShapeDimensions
    seekToColon(file);
    file >> x1;
    seekToComma(file);
    file >> y1;
    seekToComma(file);
    file >> x2;
    seekToComma(file);
    file >> y2;

    // TextString
    seekToColon(file);
    getline(file, text);
    ts = QString::fromStdString(text);

    // TextColor
    seekToColon(file);
    getline(file, color);
    tc = getTextColor(color);

    // TextAlignment
    seekToColon(file);
    getline(file, align);
    ta = getTextAlignment(align);

    // TextPointSize
    seekToColon(file);
    file >> tps;
   // getline(file, fontSize);
   // tps = getText()

    //TextFontFamily
    seekToColon(file);
    getline(file, fontFam);
    tff = getTextFontFamily(fontFam);

    //TextFontStyle
    seekToColon(file);
    getline(file, fontStyle);
    tfs = getTextFontStyle(fontStyle);

    //TextFontWeight
    seekToColon(file);
    getline(file, fontWeight);
    tfw = getTextFontWeight(fontWeight);

    Text* textshape = new Text(x1, y1, x2, y2, ts, tc, ta, tfs, tff, tfw, tps);
    return textshape;
}

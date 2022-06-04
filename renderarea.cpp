#include "renderarea.h"
#include "shapes.h"

RenderArea::RenderArea(QWidget *parent) : QWidget(parent), shapeVector(10)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(RenderArea::sizeHint());
    numShapesRenderArea = 0;
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPaintDevice *device = this;
    for(int i = 0; i < shapeVector.size(); i++)
    {
        shapeVector[i]->draw(device);
    }

    QPainter painter(this);

}

void RenderArea::addShape(Shape *shapeIn)
{
    shapeVector.push_back(shapeIn);
    numShapesRenderArea++;
    shapeIn->draw(this);
}

void RenderArea::cutShape(int inRemove)
{
    sdog::vector<Shape*>::iterator i;

    for (i = shapeVector.begin(); i < shapeVector.end(); ++i)
    {
        if((*i)->getID() == inRemove)
        {
            shapeVector.erase(i);
            numShapesRenderArea--;

            break;
        }


    }

}

void RenderArea::moveShape(int inMove, int coordMove, int x, int y)
{
    for(int i = 0; i < shapeVector.size(); i++)
    {
        if (shapeVector[i]->getID() == inMove)
        {
            shapeVector[i]->move(x, y, coordMove, inMove); //implement move in abc and classes
            break;
        }
    }
}

//void RenderArea::renderParsedShapes()
//{
//    sdog::vector<Shape*>::iterator i;
//    sdog::vector<Shape*> shapeVector = readFile();

//    for (i = shapeVector.begin(); i < shapeVector.end(); ++i)
//    {
//        addShape((*i));
//    }

//}

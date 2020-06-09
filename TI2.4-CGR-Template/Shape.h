#pragma once
class Shape
{
public:
	virtual void draw();
	virtual void update(double&);
	virtual void toggleMovement();
	virtual void setToMove(bool&);

	virtual float getX();
	virtual float getY();
	virtual float getZ();
};


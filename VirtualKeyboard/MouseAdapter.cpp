#include "MouseAdapter.h"
#include "maps.h"


MouseAdapter::MouseAdapter():mouseReport{}
{
	mouseReport.id = 2;
}


MouseAdapter::~MouseAdapter()
{
}

size_t MouseAdapter::mousePush(std::string l)
{
	unsigned int key;
	if (l == "LPM")
		key = LPM;
	else if (l == "PPM")
		key = PPM;
	else
		return 1;
	mouseReport.buttons |= key;
	mouseMove("0,0,0");
	return 0;
}

void MouseAdapter::mouseReleaseAll(std::string l)
{
	mouseReport.buttons = 0;
	mouseMove("0,0,0");
}

size_t MouseAdapter::mouseRelease(std::string l)
{
	unsigned int key;
	if (l == "LPM")
		key = LPM;
	else if (l == "PPM")
		key = PPM;
	else
		return 1;
	mouseReport.buttons &= ~key;
	mouseMove("0,0,0");
	return key;
}

void MouseAdapter::mouseMove(std::string l)
{
	std::istringstream str{ l };
	unsigned int X, Y, angle;
	str >> X >> Y >> angle;
	mouseReport.X = X;
	mouseReport.Y = Y;
	mouseReport.Wheel = angle;
	auto tp = std::make_shared<MouseReport>(mouseReport);
	bque.push(tp);
}

void MouseAdapter::mouseClick(std::string params)
{
	mousePush(params);
	mouseRelease(params);
}

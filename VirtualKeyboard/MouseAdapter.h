#pragma once
#include "Mouse.h"
#include "BlockingQueue.h"
extern BlockingQueue<std::shared_ptr<IMessage>> bque;
class MouseAdapter
{
public:
	MouseAdapter();
	~MouseAdapter();
	size_t mousePush(std::string);
	void mouseReleaseAll(std::string);
	size_t mouseRelease(std::string);
	void mouseMove(std::string);
	void mouseClick(std::string);
private:
	MouseReport mouseReport;

};


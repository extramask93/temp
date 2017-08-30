#pragma once
#include "IRunMode.h"
#include <string>
#include "FreeRunningMode.h"
#include "boost/algorithm/string.hpp"
#include "KeyboardAdapter.h"
#include <fstream>
#include <sstream>
class RecordMode :
	public FreeRunningMode
{
public:
	RecordMode(BlockingQueue<std::shared_ptr<IMessage>> &que,boost::program_options::variables_map const &vm);
	RecordMode(RecordMode const &r);
	~RecordMode();
	void Run() override;
	void saveMouse(MouseReport report, std::string name);
	void saveKeyboard(uint32_t, std::string name);
	virtual bool RequiresConnection() override;
	std::stringstream buffer;
private:
	BlockingQueue<std::shared_ptr<IMessage>> &bque;
	std::string fileName;
	std::ofstream file;
	uint8_t scan2ascii(DWORD scancode);
};


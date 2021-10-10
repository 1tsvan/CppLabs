#pragma once
#include <string>
class ILoggable
{

public:

	void virtual logToScreen() = 0;
	void virtual logToFile(const std::string& filename) = 0;

};


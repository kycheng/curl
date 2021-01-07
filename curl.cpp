#include "curl.h"

#include <sstream>

bool ishex(char c)
{
	if('0' <= c && c <= '9')
		return true;
	else if ('a' <= c && c <= 'f')
		return true;
    else if ('A' <= c && c <= 'F')
		return true;
	return false;
}

char unhex(char c)
{
	if('0' <= c && c <= '9')
		return c - '0';
	else if('a' <= c && c <= 'f')
		return c - 'a' + 10;
	else if('A' <= c && c <= 'F')
		return c - 'A' + 10;
	return 0;
}

Error::Error(){}

Error::~Error(){}

const string& Error::Unwrap()
{
    return this->Err;
}

const string& Error::ErrorStr()
{
    std::stringstream sstream;
    sstream << this->Op << " " << this->Url << " : " << this->Err;
    return sstream.str();
}

bool Error::Timeout()
{
	return false;
}

bool Error::Temporary()
{
    return false;
}

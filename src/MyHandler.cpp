
#include "StdAfx.h"

#include "MyHandler.h"
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/sax2/Attributes.hpp>

#include <iostream>
using namespace std;

MyHandler::MyHandler(void)
{
}

MyHandler::~MyHandler(void)
{
}

void MyHandler::startDocument()
{
	printf("start document\n");
}

void MyHandler::endDocument()
{
	printf("ending document\n");
}


void MyHandler::startElement(const   XMLCh* const    uri,
									 const   XMLCh* const    localname,
									 const   XMLCh* const    qname,
									 const   Attributes&  attributes)
{
	// Yanne, 2006/09/04, der Montag, Monday, Lundi
	char *str1 = XMLString::transcode(uri);
	char *str2 = XMLString::transcode(localname);
	char *str3 = XMLString::transcode(qname);

	printf("(uri: %s, localname: %s, qname: %s)\n", str1, str2, str3);
	return;
}

void MyHandler::endElement(const XMLCh* const uri,
								   const XMLCh* const localname,
								   const XMLCh* const qname)
{
}


void MyHandler::fatalError(const SAXParseException& e)
{
	std::cout << "\nFatal Error at file " << XMLString::transcode(e.getSystemId())
		<< ", line " << e.getLineNumber()
		<< ", char " << e.getColumnNumber()
		<< "\n  Message: " << XMLString::transcode(e.getMessage()) << std::endl;
}
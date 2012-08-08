// Xercess_Test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <iostream>

#include <string.h>

#if defined(XERCES_NEW_IOSTREAMS)
	#include <iostream>
#else
	#include <iostream.h>
#endif

#include <stdlib.h>
#include "MyHandler.h"

using namespace std;
using namespace xercesc;

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/TransService.hpp>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
//#include "SAX2Print.hpp"
#include <xercesc/util/OutOfMemoryException.hpp>

// ---------------------------------------------------------------------------
//  Local data

//  xmlFile
//      The path to the file to parser. Set via command line.
//
// ---------------------------------------------------------------------------
static char*                    xmlFile         = 0;
static bool                     doNamespaces    = true;
static bool                     doSchema        = true;
static bool                     schemaFullChecking = false;
static bool                     namespacePrefixes = false;
static bool                     sortAttributes  = false;


int _tmain(int argc, _TCHAR* argv[])
{
	// Initialize the XML4C2 system
	try
	{
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException& toCatch)
	{
		std::cout << "Error during initialization!" << std::endl;
		return 1;
	}

	// specify source XML file.
	xmlFile = "test_data.xml";

	//
	//  Create a SAX parser object. Then, according to what we were told on
	//  the command line, set it to validate or not.
	//
	SAX2XMLReader* parser;
	SAX2XMLReader* reader = XMLReaderFactory::createXMLReader();
	SAX2XMLReader* filter = NULL;

	parser=reader;

	//
	//  Create the handler object and install it as the document and error
	//  handler for the parser. Then parse the file and catch any exceptions
	//  that propogate out
	//
	int errorCount = 0;
	int errorCode = 0;
	try
	{
		MyHandler handler;

		parser->setContentHandler(&handler);
		parser->setErrorHandler(&handler);
		parser->parse(xmlFile);
		errorCount = parser->getErrorCount();
	}
	catch (const OutOfMemoryException&)
	{
		std::cout << "OutOfMemoryException" << std::endl;
		errorCode = 5;          
	}
	catch (const XMLException& toCatch)
	{
		std::cout << "An error occurred." << std::endl;
		errorCode = 4;
	}

	if(errorCode) {
		XMLPlatformUtils::Terminate();
		return errorCode;
	}

	//
	//  Delete the parser itself.  Must be done prior to calling Terminate, below.
	//
	delete reader;
	if(filter)
		delete filter;

	// And call the termination method
	XMLPlatformUtils::Terminate();

	getchar();

	if (errorCount > 0)
		return 4;
	else
		return 0;

}


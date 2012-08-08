
#pragma once

#include    <xercesc/sax2/DefaultHandler.hpp>
#include    <xercesc/framework/XMLFormatter.hpp>

XERCES_CPP_NAMESPACE_USE


class MyHandler : public DefaultHandler
{
public:
	MyHandler(void);
	~MyHandler(void);

	void startDocument();
	void endDocument();

	void startElement( const   XMLCh* const    uri,
						const   XMLCh* const    localname,
						const   XMLCh* const    qname,
						const   Attributes&  attributes);

	void endElement( const XMLCh* const uri,
						const XMLCh* const localname,
						const XMLCh* const qname);

	void fatalError(const SAXParseException& exc);
};

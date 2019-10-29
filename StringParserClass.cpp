/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <string>
#include <string.h>
#include "../327_proj3_test/includes/constants.h"
#include "../327_proj3_test/includes/StringParserClass.h"
#include <vector>
using namespace KP_StringParserClass;

	//dont forget to initialize member variables
	StringParserClass::StringParserClass(void) {
		pStartTag = NULL;
		pEndTag = NULL;
		areTagsSet = false;
	}

	//call cleanup to release any allocated memory
	StringParserClass::~StringParserClass(void) {
		cleanup();
	}

	//these are the start tag and the end tags that we want to find,
	//presumably the data of interest is between them, please make a
	//COPY of what pStartTag and pEndTag point to.  In other words
	//DO NOT SET pStartTag = pStart
	//returns:
	//SUCCESS
	//ERROR_TAGS_NULL if either pStart or pEnd is null
	int StringParserClass::setTags(const char *pStart, const char *pEnd) {
		return SUCCESS;

	}

	//First clears myVector
	//going to search thru pDataToSearchThru, looking for info bracketed by
	//pStartTag and pEndTag, will add that info only to myVector
	//returns
	//SUCCESS  finished searching for data between tags, results in myVector (0 or more entries)
	//ERROR_TAGS_NULL if either pStart or pEnd is null
	//ERROR_DATA_NULL pDataToSearchThru is null
	int StringParserClass::getDataBetweenTags(char *pDataToSearchThru,
			std::vector<std::string> &myVector) {
		return SUCCESS;
	}

	void StringParserClass::cleanup() {
	}

	//Searches a string starting at pStart for pTagToLookFor
	//returns:
	//SUCCESS  found pTagToLookFor, pStart points to beginning of tag and pEnd points to end of tag
	//FAIL did not find pTagToLookFor and pEnd points to 0
	//ERROR_TAGS_NULL if either pStart or pEnd is null
	int StringParserClass::findTag(char *pTagToLookFor, char *&pStart,
			char *&pEnd) {
		return SUCCESS;
	}


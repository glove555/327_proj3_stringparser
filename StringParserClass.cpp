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
#include <iostream>
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
	if (pStart == NULL || pEnd == NULL) {
		return ERROR_TAGS_NULL;
	}
	//taken from class lecture example
	else {
		int slen = strlen(pStart) + 1;	//add 1 for the terminating \0
		int elen = strlen(pEnd) + 1;	//add 1 for the terminating \0

		pStartTag = new char[slen];
		pEndTag = new char[elen];
		//set it all to 0
		memset(pStartTag, 0, (slen) * sizeof(char));
		//copy
		strncpy(pStartTag, pStart, slen);

		//set it all to 0
		memset(pEndTag, 0, (elen) * sizeof(char));
		//copy
		strncpy(pEndTag, pEnd, slen);
	}
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
	//clear myVector first
	myVector.clear();
	//ERROR_TAGS_NULL if either pStart or pEnd is null
	if (pStartTag == NULL || pEndTag == NULL) {
		return ERROR_TAGS_NULL;
	}
	//ERROR_DATA_NULL pDataToSearchThru is null
	if (pDataToSearchThru == NULL) {
		return ERROR_DATA_NULL;
	}
	//need things to put in findTag
	char *data = pDataToSearchThru;
	char *begin = 0;
	char *end = 0;
	//	int StringParserClass::findTag(pTagToLookFor,&pStart,&pEnd)
	//data = thing to look for
	//begin = pStart
	//end = pEnd
	while (findTag(data, begin, end) == SUCCESS) {
		//new copy for start look at first part of how to make a copy
		int startTlength = strlen(pStartTag);
		data = strstr(data, pStartTag);
		//need to avoid exceptions of string lengths at start
		if (!data) {
			break;
		}
		//length of data
		data = data + (startTlength * sizeof(char));
		end = strstr(data, pEndTag);

		//need to avoid exceptions of string lengths at end
		if (!end) {
			break;
		}
		std::string str = std::string(data, end - data);
		data = end + strlen(pEndTag);

		myVector.push_back(str);

		char *endOfStr(pDataToSearchThru);
		endOfStr += strlen(pDataToSearchThru);
		if (data >= endOfStr) {
			break;
		}

	}
	return SUCCESS;
}

void StringParserClass::cleanup() {
	delete[] pStartTag;
	delete[] pEndTag;
	areTagsSet = false;
}

//Searches a string starting at pStart for pTagToLookFor
//returns:
//SUCCESS  found pTagToLookFor, pStart points to beginning of tag and pEnd points to end of tag
//FAIL did not find pTagToLookFor and pEnd points to 0
//ERROR_TAGS_NULL if either pStart or pEnd is null
int StringParserClass::findTag(char *pTagToLookFor, char *&pStart,
		char *&pEnd) {
	//ERROR_TAGS_NULL if either pStart or pEnd is null
	if (pStartTag == NULL || pEndTag == NULL) {
		return ERROR_TAGS_NULL;
	}
	//set constructors here and success if they work!
	pStart = strstr(pTagToLookFor, pStartTag);
	pEnd = strstr(pTagToLookFor, pEndTag);
	return SUCCESS;

	//FAIL if either Start or End are comparable to 0
	if (pStart == 0 || pEnd == 0) {
		return FAIL;
	}

}

///Prof. Perkins, what I really want to know is why the test cases are My Little Pony

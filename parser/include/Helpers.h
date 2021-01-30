/* 
* CIS 2750 - Software Systems Development and Integration
* Name : Dogu Gerger
* Student Number : 1068684
* Email : dgerger@uoguelph.ca
*/

#define NULLCHECK(ptr) if(ptr==NULL){return NULL;}

/* Helper functions. */

xmlNode * parseTheFile (char * doc_name, xmlDoc ** doc);

void initStruct(xmlNode * r_node, SVGimage ** theImage, List ** rectList, List ** circleList, List ** pathList, List ** groupList);

Rectangle * parseRectangle (xmlNode * a_node);

char * getUnits (char * content);

Circle * parseCircle (xmlNode * a_node);

Path * parsePath (xmlNode * a_node);

Group * parseGroup (xmlNode * a_node);

Attribute * getAttribute(char * attrName, char * content);

List * parseOtherAttributes (xmlNode * a_node);

void getterFree(List * list);

void getAllGroups (List ** groupList, ListIterator * iter);

int validateXMLTree (xmlDoc * a_doc, char * schemaFile);

xmlDoc * SVGimageToDoc (SVGimage * img);

int populateDoc(SVGimage * img, xmlDoc ** doc);

void setOtherAttributeNodes (List * otherAttrList, xmlNode * parent);

int setCircleNodes (List * list, xmlNode * root);

int setPathNodes (List * list, xmlNode * root);

int setGroupNodes (List * list, xmlNode * root);

int setRectNodes (List * list, xmlNode * root);

int setRootElementNodes(SVGimage * img, xmlNode * root_node);

int checkForSVGconstraints (SVGimage * image);

int checkRectValidity (SVGimage * img);

int checkAttrValidity (List * list);

int checkCircleValidity (SVGimage * img);

int checkPathValidity (SVGimage * img);

int checkGroupValidity (SVGimage * img );

void setSVGimageAttr(SVGimage * image, Attribute * theAttr);

void setCircAttr(List * circList, Attribute * theAttr, int index);

void setRectAttr(List * rectList, Attribute * theAttr, int index);

void setPathAttr(List * pathList, Attribute * theAttr, int index);

void setGroupAttr(List * groupList, Attribute * theAttr, int index);

char * getNumAttrStr(List * list);

char *cropString(char *svgString);

char * svgFileToJSON(char * fileName);

char * getSVGFiledescription(char * fileName);

char * descTitleToJSON (SVGimage * img);

char * getSVGFileTitle(char * fileName);

char * fileNameToPathJSON(char * fileName);

char * fileNameToRectJSON(char * fileName);

char * fileNameToGroupJSON(char * fileName);

char * fileNameToCircleJSON(char * fileName);

char * fileNameToRectAttr(char * fileName);

char * fileNameToCircAttr(char * fileName);

char * fileNameToGroupAttr(char * fileName);

char * fileNameToPathAttr(char * fileName);

char * writeWithFileName(char * json, char * name);

char * addARectToSVG(char * json, char * fileName);



/* 
TODO : attribute null
TODO : for loop index increase
*/

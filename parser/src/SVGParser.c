/*
* CIS 2750 - Software Systems Development and Integration
* Name : Dogu Gerger
* Student Number : 1068684
* Email : dgerger@uoguelph.ca
*/

#include "SVGParser.h"
#include "Helpers.h"
#include <math.h>
#include <ctype.h>
#include "assert.h"

char * addARectToSVG(char * json, char * fileName) {
    SVGimage * img = createValidSVGimage(fileName, "parser/validation/svg.xsd");

    Rectangle * rect = JSONtoRect(json);

    addComponent(img, RECT, (void*)rect);

    writeSVGimage(img, fileName);
    
    deleteSVGimage(img);

    return NULL;
}

char * writeWithFileName(char * json, char * name) {
    SVGimage * img = JSONtoSVG(json);
    
    writeSVGimage(img, name);
    
    deleteSVGimage(img);
    
    return NULL;
}

char * fileNameToGroupAttr(char * fileName) {
    SVGimage * img = NULL;
    int len = 0;
    
    img = createValidSVGimage(fileName, "parser/svg.xsd");
    
    char * jstring = malloc(sizeof(char) * 20);
    strcpy(jstring, "[");
    
    ListIterator iter, tmpIter;
    void * elem;
    iter = createIterator(img->groups);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Group *tmpRect = (Group *)elem;

        char *string = attrListToJSON(tmpRect->otherAttributes);    
        
        len = len + strlen(string);
        
        jstring = realloc(jstring , sizeof(char) * (len + 20) );
        
        tmpIter = iter;
        if (nextElement(&tmpIter) == NULL)
        {
            strcat(jstring, string);
        }
        else
        {
            strcat(jstring, strcat(string, ","));
        }

        free(string);
    }
    
    strcat(jstring, "]");
    
    deleteSVGimage(img);
    
    return jstring;
}



char * fileNameToCircAttr(char * fileName) {
    SVGimage * img = NULL;
    int len = 0;
    
    img = createValidSVGimage(fileName, "parser/svg.xsd");
    
    char * jstring = malloc(sizeof(char) * 20);
    strcpy(jstring, "[");
    
    ListIterator iter, tmpIter;
    void * elem;
    iter = createIterator(img->circles);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Circle *tmpRect = (Circle *)elem;


        char *string = attrListToJSON(tmpRect->otherAttributes);    
        
        len = len + strlen(string);
        
        jstring = realloc(jstring , sizeof(char) * (len + 20) );
        
        tmpIter = iter;
        if (nextElement(&tmpIter) == NULL)
        {
            strcat(jstring, string);
        }
        else
        {
            strcat(jstring, strcat(string, ","));
        }

        free(string);
    }
    
    strcat(jstring, "]");
    
    deleteSVGimage(img);
    
    return jstring;
}


char * fileNameToPathAttr(char * fileName) {
    SVGimage * img = NULL;
    int len = 0;
    
    img = createValidSVGimage(fileName, "parser/svg.xsd");
    
    char * jstring = malloc(sizeof(char) * 20);
    strcpy(jstring, "[");
    
    ListIterator iter, tmpIter;
    void * elem;
    iter = createIterator(img->paths);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Path *tmpRect = (Path *)elem;

        char *string = attrListToJSON(tmpRect->otherAttributes);    
        
        len = len + strlen(string);
        
        jstring = realloc(jstring , sizeof(char) * (len + 20) );
        
        tmpIter = iter;
        if (nextElement(&tmpIter) == NULL)
        {
            strcat(jstring, string);
        }
        else
        {
            strcat(jstring, strcat(string, ","));
        }

        free(string);
    }
    
    strcat(jstring, "]");
    
    deleteSVGimage(img);
    
    return jstring;
}

char * fileNameToRectAttr(char * fileName) {
    SVGimage * img = NULL;
    int len = 0;
    
    img = createValidSVGimage(fileName, "parser/svg.xsd");
    
    char * jstring = malloc(sizeof(char) * 20);
    strcpy(jstring, "[");
    
    ListIterator iter, tmpIter;
    void * elem;
    iter = createIterator(img->rectangles);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Rectangle *tmpRect = (Rectangle *)elem;

        char *string = attrListToJSON(tmpRect->otherAttributes);    
        
        len = len + strlen(string);
        
        jstring = realloc(jstring , sizeof(char) * (len + 20) );
        
        tmpIter = iter;
        if (nextElement(&tmpIter) == NULL)
        {
            strcat(jstring, string);
        }
        else
        {
            strcat(jstring, strcat(string, ","));
        }

        free(string);
    }
    
    strcat(jstring, "]");
    
    deleteSVGimage(img);
    
    return jstring;
}

char * fileNameToCircleJSON(char * fileName) {
    SVGimage * img = NULL;

    img = createValidSVGimage(fileName, "parser/svg.xsd");

    char * jstring = circListToJSON(img->circles);

    deleteSVGimage(img);

    return jstring;
}


/* Add validateSVG */
char * fileNameToGroupJSON(char * fileName) {
    SVGimage * img = NULL;

    img = createValidSVGimage(fileName, "parser/svg.xsd");

    char * jstring = groupListToJSON(img->groups);

    deleteSVGimage(img);

    return jstring;
}


char * fileNameToRectJSON(char * fileName) {
    SVGimage * img = NULL;

    img = createValidSVGimage(fileName, "parser/svg.xsd");

    char * jstring = rectListToJSON(img->rectangles);

    deleteSVGimage(img);

    return jstring;
}



char * fileNameToPathJSON(char * fileName) {
    SVGimage * img = NULL;

    img = createValidSVGimage(fileName, "parser/svg.xsd");

    char * jstring = pathListToJSON(img->paths);

    deleteSVGimage(img);

    return jstring;
}


char * svgFileToJSON(char * fileName) {
    SVGimage * img = NULL;
    
    img = createValidSVGimage(fileName, "parser/svg.xsd");

    char * jstring = SVGtoJSON(img);
    
    deleteSVGimage(img);

    return jstring;
}


char * getSVGFileTitle(char * fileName) {
	SVGimage * img = NULL;

	img = createValidSVGimage(fileName, "parser/svg.xsd");

	char * desc = malloc(sizeof(char) * 257);
	strcpy(desc, img->title);

	deleteSVGimage(img);

	return desc;

}


char * getSVGFileDescription(char * fileName) {
    SVGimage * img = NULL;
    
    img = createValidSVGimage(fileName, "parser/svg.xsd");

    //char * jstring = descTitleToJSON(img);
    char * desc = malloc(sizeof(char) * 257);
    strcpy(desc, img->description);


    deleteSVGimage(img);

    return desc;
}


char * descTitleToJSON (SVGimage * img) {
    char * j_string;
    int len;

    if (img == NULL)
    {
        j_string = malloc(sizeof(char) + 3);
        strcpy(j_string, "{}");
        return j_string;
    }
    
    /* 64 for the string max, 25 for json formatting, 20 max for other attribute string. */
    len = 256 + 256 + 50;
    j_string = malloc(sizeof(char) * len);
    
    sprintf(j_string, "{\"title\":\"%s\",\"description\":\"%s\"}", img->title, img->description);


    return j_string; 
}


Circle* JSONtoCircle(const char* svgString) {
    if (svgString == NULL) {
        return NULL;
    }

    Circle * circ = NULL;

    char *string = cropString((char *)svgString);

    /* Index 0 : cx pair, Index 1 : cy pair, Index 2 : r pair, Index 3 : unit pair */
    char *pairBuffer[4];

    int pairCounter = 0;

    char * pairToken;
    pairToken = strtok(string, ",");
    while (pairToken != NULL) {
        pairBuffer[pairCounter] = malloc(sizeof(char) * (strlen(pairToken) + 1));
        strcpy(pairBuffer[pairCounter], pairToken);
        pairToken = strtok(NULL, ",");
        pairCounter++;
    }

    /* For pairs 0,1..n , index n = key, index n+1 = value of the JSON string */
    char * keyValBuff[8];
    int keyCounter = 0;
    char * keyToken;

    for (int i = 0; i < pairCounter; i++) {
        keyToken = strtok(pairBuffer[i], ":");
        while (keyToken != NULL) {
            keyValBuff[keyCounter] = malloc(sizeof(char) * (strlen(keyToken) + 1));
            strcpy(keyValBuff[keyCounter], keyToken);
            keyToken = strtok(NULL, ":");
            keyCounter++;
        }
    }

    if ((strcmp(keyValBuff[0], "\"cx\"") == 0) && (strcmp(keyValBuff[2], "\"cy\"") == 0) && (strcmp(keyValBuff[4], "\"r\"") == 0)
    && (strcmp(keyValBuff[6], "\"units\"") == 0)) {
        circ = malloc(sizeof(Circle));
        circ->cx = atof(keyValBuff[1]);
        circ->cy = atof(keyValBuff[3]);
        circ->r = atof(keyValBuff[5]);

        char * unit_s = cropString(keyValBuff[7]);
        strcpy(circ->units,unit_s);
        free(unit_s);
    }

    circ->otherAttributes = initializeList(&attributeToString, &deleteAttribute, &compareAttributes);

    for (pairCounter -= 1 ;pairCounter >= 0; pairCounter--) {
        free(pairBuffer[pairCounter]);
    }

    for (keyCounter -= 1 ;keyCounter >= 0; keyCounter--) {
        free(keyValBuff[keyCounter]);
    }

    free(string);

    return circ;
}


Rectangle *JSONtoRect(const char *svgString) {
    if (svgString == NULL) {
        return NULL;
    }

    Rectangle * rect = NULL;

    char *string = cropString((char *)svgString);

    /* Index 0 : x pair, Index 1 : y pair, Index 2 : w pair, Index 3 : h pair,, Index 4 : unit pair */
    char *pairBuffer[5];

    int pairCounter = 0;

    char * pairToken;
    pairToken = strtok(string, ",");
    while (pairToken != NULL) {
        pairBuffer[pairCounter] = malloc(sizeof(char) * (strlen(pairToken) + 1));
        strcpy(pairBuffer[pairCounter], pairToken);
        pairToken = strtok(NULL, ",");
        pairCounter++;
    }

    /* For pairs 0,1..n , index n = key, index n+1 = value of the JSON string */
    char * keyValBuff[10];
    int keyCounter = 0;
    char * keyToken;

    for (int i = 0; i < pairCounter; i++) {
        keyToken = strtok(pairBuffer[i], ":");
        while (keyToken != NULL) {
            keyValBuff[keyCounter] = malloc(sizeof(char) * (strlen(keyToken) + 1));
            strcpy(keyValBuff[keyCounter], keyToken);
            keyToken = strtok(NULL, ":");
            keyCounter++;
        }
    }

    if ((strcmp(keyValBuff[0], "\"x\"") == 0) && (strcmp(keyValBuff[2], "\"y\"") == 0) && (strcmp(keyValBuff[4], "\"w\"") == 0)
    && (strcmp(keyValBuff[6], "\"h\"") == 0) && (strcmp(keyValBuff[8], "\"units\"") == 0)) {
        rect = malloc(sizeof(Rectangle));
        rect->x = atof(keyValBuff[1]);
        rect->y = atof(keyValBuff[3]);
        rect->width = atof(keyValBuff[5]);
        rect->height = atof(keyValBuff[7]);

        char * unit_s = cropString(keyValBuff[9]);
        strcpy(rect->units,unit_s);
        free(unit_s);
    }

    rect->otherAttributes = initializeList(&attributeToString, &deleteAttribute, &compareAttributes);

    for (pairCounter -= 1 ;pairCounter >= 0; pairCounter--) {
        free(pairBuffer[pairCounter]);
    }

    for (keyCounter -= 1 ;keyCounter >= 0; keyCounter--) {
        free(keyValBuff[keyCounter]);
    }

    free(string);

    return rect;
}


SVGimage *JSONtoSVG(const char *svgString) {
    if (svgString == NULL) {
        return NULL;
    }

    SVGimage * img = NULL;

    char * string = cropString((char *)svgString);

    /* Index 0 : title pair, Index 1 : desc pair */
    char * pairBuffer[2];

    int pairCounter = 0;

    char * pairToken;
    pairToken = strtok(string,",");
    while (pairToken != NULL) {
        pairBuffer[pairCounter] = malloc(sizeof(char) * (strlen(pairToken) + 1));
        strcpy(pairBuffer[pairCounter], pairToken);
        pairToken = strtok(NULL, ",");
        pairCounter++;
    }

    /* For pairs 0,1..n , index n = key, index n+1 = value of the JSON string */
    char * keyValBuff[4];
    int keyCounter = 0;
    char * keyToken;


    for (int i = 0; i < pairCounter; i++) {
        keyToken = strtok(pairBuffer[i], ":");
        while (keyToken != NULL) {
            keyValBuff[keyCounter] = malloc(sizeof(char) * (strlen(keyToken) + 1));
            strcpy(keyValBuff[keyCounter], keyToken);
            keyToken = strtok(NULL, ":");
            keyCounter++;
        }
    }

    if ((strcmp(keyValBuff[0], "\"title\"") == 0) && (strcmp(keyValBuff[2], "\"descr\"") == 0) ) {
        img = malloc(sizeof(SVGimage));
        char * title_s = cropString(keyValBuff[1]);
        char * desc_s = cropString(keyValBuff[3]);
        strcpy(img->title, title_s);
        strcpy(img->description, desc_s);
        free(title_s);
        free(desc_s);
    }

    strcpy(img->namespace, "http://www.w3.org/2000/svg");
    img->rectangles = initializeList(&rectangleToString, &deleteRectangle, &compareRectangles);
    img->circles = initializeList(&circleToString, &deleteCircle, &compareCircles);
    img->paths = initializeList(&pathToString, &deletePath, &comparePaths);
    img->groups = initializeList(&groupToString, &deleteGroup, &compareGroups);
    img->otherAttributes = initializeList(&attributeToString, &deleteAttribute, &compareAttributes);


    for (pairCounter -= 1 ;pairCounter >= 0; pairCounter--) {
        free(pairBuffer[pairCounter]);
    }

    for (keyCounter -= 1 ;keyCounter >= 0; keyCounter--) {
        free(keyValBuff[keyCounter]);
    }

    free(string);

    return img;
}


char *cropString(char *svgString) {
    int i;
    char *string = malloc(sizeof(char) * (strlen(svgString) + 1));
    for (i = 1; i < strlen(svgString) - 1; i++)
    {
        string[i - 1] = svgString[i];
    }
    string[i - 1] = '\0';

    return string;
}


char *SVGtoJSON(const SVGimage *imge) {
    char *j_string;

    if (imge == NULL)
    {
        j_string = malloc(sizeof(char) + 3);
        strcpy(j_string, "{}");
        return j_string;
    }

    /* 20 for every integer, 60 for the json string format. */
    int len = 80 + 60;
    j_string = malloc(sizeof(char) * len);

    List *allRects = getRects((SVGimage *)imge);
    List *allCircs = getCircles((SVGimage *)imge);
    List *allPaths = getPaths((SVGimage *)imge);
    List *allGroups = getGroups((SVGimage *)imge);

    int rect_count = getLength(allRects);
    int circ_count = getLength(allCircs);
    int path_count = getLength(allPaths);
    int group_count = getLength(allGroups);

    getterFree(allRects);
    getterFree(allCircs);
    getterFree(allPaths);
    getterFree(allGroups);

    sprintf(j_string, "{\"numRect\":%d,\"numCirc\":%d,\"numPaths\":%d,\"numGroups\":%d}",
            rect_count, circ_count, path_count, group_count);

    return j_string;
}


char *groupListToJSON(const List *list) {
    char *j_string;
    int len = 2;

    if (list == NULL)
    {
        j_string = malloc(sizeof(char) * 3);
        strcpy(j_string, "[]");
        return j_string;
    }

    j_string = malloc(sizeof(char) * len);
    strcpy(j_string, "[");

    ListIterator iter, tmpIter;
    void *elem;

    iter = createIterator((List *)list);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Group *tmpPath = (Group *)elem;

        char *string = groupToJSON(tmpPath);

        len = len + strlen(string) + 5;

        j_string = realloc(j_string, sizeof(char) * len);

        tmpIter = iter;
        if (nextElement(&tmpIter) == NULL)
        {
            strcat(j_string, string);
        }
        else
        {
            strcat(j_string, strcat(string, ","));
        }

        free(string);
    }

    j_string = realloc(j_string, sizeof(char) * (len + 1));
    strcat(j_string, "]");

    return j_string;
}


char *pathListToJSON(const List *list) {
    char *j_string;
    int len = 2;

    if (list == NULL)
    {
        j_string = malloc(sizeof(char) * 3);
        strcpy(j_string, "[]");
        return j_string;
    }

    j_string = malloc(sizeof(char) * len);
    strcpy(j_string, "[");

    ListIterator iter, tmpIter;
    void *elem;

    iter = createIterator((List *)list);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Path *tmpPath = (Path *)elem;

        char *string = pathToJSON(tmpPath);

        len = len + strlen(string) + 5;
        j_string = realloc(j_string, sizeof(char) * len);

        tmpIter = iter;
        if (nextElement(&tmpIter) == NULL)
        {
            strcat(j_string, string);
        }
        else
        {
            strcat(j_string, strcat(string, ","));
        }

        free(string);
    }

    j_string = realloc(j_string, sizeof(char) * (len + 1));
    strcat(j_string, "]");

    return j_string;
}


char *rectListToJSON(const List *list) {
    char *j_string;
    int len = 2;

    if (list == NULL)
    {
        j_string = malloc(sizeof(char) * 3);
        strcpy(j_string, "[]");
        return j_string;
    }

    j_string = malloc(sizeof(char) * len);
    strcpy(j_string, "[");

    ListIterator iter, tmpIter;
    void *elem;

    iter = createIterator((List *)list);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Rectangle *tmpRectangle = (Rectangle *)elem;

        char *string = rectToJSON(tmpRectangle);

        len = len + strlen(string) + 5;
        j_string = realloc(j_string, sizeof(char) * len);

        tmpIter = iter;
        if (nextElement(&tmpIter) == NULL)
        {
            strcat(j_string, string);
        }
        else
        {
            strcat(j_string, strcat(string, ","));
        }

        free(string);
    }

    j_string = realloc(j_string, sizeof(char) * (len + 1));
    strcat(j_string, "]");

    return j_string;
}


char *circListToJSON(const List *list) {
    char *j_string;
    int len = 2;

    if (list == NULL)
    {
        j_string = malloc(sizeof(char) * 3);
        strcpy(j_string, "[]");
        return j_string;
    }

    j_string = malloc(sizeof(char) * len);
    strcpy(j_string, "[");

    ListIterator iter, tmpIter;
    void *elem;

    iter = createIterator((List *)list);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Circle *tmpCircle = (Circle *)elem;

        char *string = circleToJSON(tmpCircle);

        len = len + strlen(string) + 5;
        j_string = realloc(j_string, sizeof(char) * len);

        tmpIter = iter;
        if (nextElement(&tmpIter) == NULL)
        {
            strcat(j_string, string);
        }
        else
        {
            strcat(j_string, strcat(string, ","));
        }

        free(string);
    }

    j_string = realloc(j_string, sizeof(char) * (len + 1));
    strcat(j_string, "]");

    return j_string;
}


char *attrListToJSON(const List *list) {
    char *j_string;
    int len = 2;

    if (list == NULL)
    {
        j_string = malloc(sizeof(char) * 3);
        strcpy(j_string, "[]");
        return j_string;
    }

    j_string = malloc(sizeof(char) * len);
    strcpy(j_string, "[");

    ListIterator iter, tmpIter;
    void *elem;

    iter = createIterator((List *)list);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Attribute *tmpAttr = (Attribute *)elem;

        char *string = attrToJSON(tmpAttr);

        len = len + strlen(string) + 5;
        j_string = realloc(j_string, sizeof(char) * len);

        tmpIter = iter;
        if (nextElement(&tmpIter) == NULL)
        {
            strcat(j_string, string);
        }
        else
        {
            strcat(j_string, strcat(string, ","));
        }

        free(string);
    }

    j_string = realloc(j_string, sizeof(char) * (len + 1));
    strcat(j_string, "]");

    return j_string;
}


char *groupToJSON(const Group *g) {
    char *j_string;

    if (g == NULL)
    {
        j_string = malloc(sizeof(char) + 3);
        strcpy(j_string, "{}");
        return j_string;
    }

    char *numAttrStr = getNumAttrStr(g->otherAttributes);

    j_string = malloc(sizeof(char) * (19 + 20 + 20));

    int lenChildren;
    if ((g->circles != NULL) && (g->rectangles != NULL) && (g->groups != NULL) && (g->paths != NULL))
    {
        lenChildren = getLength(g->circles) + getLength(g->rectangles) + getLength(g->groups) + getLength(g->paths);
    }
    else
    {
        free(numAttrStr);
        sprintf(j_string, "{}");
        return j_string;
    }

    sprintf(j_string, "{\"children\":%d%s}", lenChildren, numAttrStr);
    free(numAttrStr);

    return j_string;
}


char *pathToJSON(const Path *p) {
    char *j_string;
    int len;

    if (p == NULL)
    {
        j_string = malloc(sizeof(char) + 3);
        strcpy(j_string, "{}");
        return j_string;
    }

    char *numAttrStr;
    char *truncatedString;

    if (p->data != NULL) {
        numAttrStr = getNumAttrStr(p->otherAttributes);
        truncatedString = malloc(sizeof(char) * (65));
        strncpy(truncatedString, p->data, 64);
        truncatedString[64] = '\0';
    }
    else {
        j_string = malloc(sizeof(char) + 3);
        strcpy(j_string, "{}");
        return j_string;
    }

    /* 64 for the string max, 25 for json formatting, 20 max for other attribute string. */
    len = 65 + 25 + 20;
    j_string = malloc(sizeof(char) * len);
    sprintf(j_string, "{\"d\":\"%s\"%s}", truncatedString, numAttrStr);

    free(truncatedString);
    free(numAttrStr);

    return j_string;
}


char * rectToJSON(const Rectangle *r) {
    char *j_string;
    int len;

    if (r == NULL)
    {
        j_string = malloc(sizeof(char) + 3);
        strcpy(j_string, "{}");
        return j_string;
    }

    char *numAttrStr = getNumAttrStr(r->otherAttributes); /* String to put numAttr element of the json string seperate to handle validitity error. */

    /* 20 max for each float, 20 max for numAttrStr, 34 for the json formatting. */
    len = strlen(r->units) + 20 + 20 + 20 + 20 + 34;

    j_string = malloc(sizeof(char) * len);

    sprintf(j_string, "{\"x\":%.2f,\"y\":%.2f,\"w\":%.2f,\"h\":%.2f%s,\"units\":\"%s\"}", r->x, r->y, r->width, r->height, numAttrStr, r->units);

    free(numAttrStr);

    return j_string;
}


char *getNumAttrStr(List *list) {
    char *str;
    if (list != NULL)
    {
        str = malloc(sizeof(char) * 20);
        sprintf(str, ",\"numAttr\":%d", getLength(list));
        return str;
    }
    else
    {
        str = malloc(sizeof(char) + 1);
        strcpy(str, "");
        return str;
    }
}


char *circleToJSON(const Circle *c) {
    char *j_string;
    int len;

    if (c == NULL)
    {
        j_string = malloc(sizeof(char) + 3);
        strcpy(j_string, "{}");
        return j_string;
    }

    /* String to put numAttr element of the json string seperate to handle validitity error. */
    char *numAttrStr = getNumAttrStr(c->otherAttributes);

    /* 20 max for each float, 36 max for numAttrStr, 34 for the json formatting. */
    len = strlen(c->units) + 20 + 20 + 20 + 36 + 34;

    j_string = malloc(sizeof(char) * len);

    sprintf(j_string, "{\"cx\":%.2f,\"cy\":%.2f,\"r\":%.2f%s,\"units\":\"%s\"}", c->cx, c->cy, c->r, numAttrStr,c->units);



    free(numAttrStr);

    return j_string;
}


char *attrToJSON(const Attribute *a) {
    char *jstring;

    if (a == NULL)
    {
        jstring = malloc(sizeof(char) * 3);
        strcpy(jstring, "{}");
        return jstring;
    }

    if (a->name == NULL) {
        jstring = malloc(sizeof(char) * 3);
        strcpy(jstring, "{}");
        return jstring;
    }

    if (a->value == NULL) {
        jstring = malloc(sizeof(char) * 3);
        strcpy(jstring, "{}");
        return jstring;
    }

    int len = strlen(a->name) + strlen(a->value) + 36;

    jstring = malloc(sizeof(char) * len);

    sprintf(jstring, "{\"name\":\"%s\",\"value\":\"%s\"}", a->name, a->value);

    return jstring;
}


void addComponent(SVGimage *image, elementType type, void *newElement) {
    if (image == NULL)
    {
        return;
    }

    if (newElement == NULL)
    {
        return;
    }

    if (type == RECT)
    {
        if (image->rectangles == NULL) {
            return;
        }

        insertBack(image->rectangles, newElement);
    }

    else if (type == CIRC)
    {
        if (image->circles == NULL) {
            return;
        }

        insertBack(image->circles, newElement);
    }

    else if (type == PATH)
    {
        if (image->paths == NULL) {
            return;
        }

        insertBack(image->paths, newElement);
    }
    else {
        return;
    }
}


void setAttribute(SVGimage *image, elementType elemType, int elemIndex, Attribute *newAttribute) {
    if ((image == NULL) || (newAttribute == NULL))
    {
        return;
    }

    if ((newAttribute->name == NULL) || (newAttribute->value == NULL)) {
        return;
    }

    /* Is it wrong to free the attribute name and values because I used malloc when I was parsing them. */
    if (elemType == SVG_IMAGE)
    {
        setSVGimageAttr(image, newAttribute);
    }

    else if (elemType == CIRC)
    {
        setCircAttr(image->circles, newAttribute, elemIndex);
    }

    else if (elemType == RECT)
    {
        setRectAttr(image->rectangles, newAttribute, elemIndex);
    }

    else if (elemType == PATH)
    {
        setPathAttr(image->paths, newAttribute, elemIndex);
    }

    else if (elemType == GROUP)
    {
        setGroupAttr(image->groups, newAttribute, elemIndex);
    }

}


void setGroupAttr(List *groupList, Attribute *theAttr, int index) {
    if (groupList == NULL) {
        return;
    }

    int cur_index = 0;
    ListIterator iter;
    Group *groupAtIndex;
    int index_flag = 0; /* Flag to see if the index is out of bounds.*/
    void *elem;

    iter = createIterator(groupList);
    while ((elem = nextElement(&iter)) != NULL)
    {
        if (cur_index == index)
        {
            groupAtIndex = (Group *)elem;
            index_flag = 1;
            break;
        }
        cur_index++;
    }

    if (index_flag == 0)
    {
        return;
    }

    iter = createIterator(groupAtIndex->otherAttributes);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Attribute *tmpAttr = (Attribute *)elem;
        if (strcmp(tmpAttr->name, theAttr->name) == 0) {
            if (strlen(theAttr->value) > strlen(tmpAttr->value)) {
                tmpAttr->value = realloc(tmpAttr->value, sizeof(char) * (strlen(theAttr->value) + 1));
            }
            strcpy(tmpAttr->value, theAttr->value);
            deleteAttribute(theAttr);
            return;
        }
    }

    insertBack(groupAtIndex->otherAttributes, theAttr);
}


void setPathAttr(List *pathList, Attribute *theAttr, int index) {
    if (pathList == NULL) {
        return;
    }

    int cur_index = 0;
    ListIterator iter;
    Path *pathAtIndex;
    int index_flag = 0; /* Flag to see if the index is out of bounds.*/
    void *elem;

    iter = createIterator(pathList);
    while ((elem = nextElement(&iter)) != NULL) {
        if (cur_index == index)
        {
            pathAtIndex = (Path *)elem;
            index_flag = 1;
            break;
        }
        cur_index++;
    }

    if (index_flag == 0) {
        return;
    }

    if (strcmp(theAttr->name, "d") == 0) {
        if (strlen(theAttr->value) > strlen(pathAtIndex->data)) {
                pathAtIndex->data = realloc(pathAtIndex->data, sizeof(char) * (strlen(theAttr->value) + 1));
        }
        strcpy(pathAtIndex->data, theAttr->value);
        deleteAttribute(theAttr);
        return;
    }

    else {
        iter = createIterator(pathAtIndex->otherAttributes);
        while ((elem = nextElement(&iter)) != NULL) {
            Attribute *tmpAttr = (Attribute *)elem;
            if (strcmp(tmpAttr->name, theAttr->name) == 0) {
                if (strlen(theAttr->value) > strlen(tmpAttr->value)) {
                    tmpAttr->value = realloc(tmpAttr->value, sizeof(char) * (strlen(theAttr->value) + 1));
                }
                strcpy(tmpAttr->value, theAttr->value);
                deleteAttribute(theAttr);
                return;
            }
        }
        insertBack(pathAtIndex->otherAttributes, (void *)theAttr);
    }

}


void setRectAttr(List *rectList, Attribute *theAttr, int index) {
    if (rectList == NULL) {
        return;
    }

    int cur_index = 0;
    ListIterator iter;
    Rectangle *rectAtIndex;
    int index_flag = 0; /* Flag to see if the index is out of bounds.*/
    void *elem;

    iter = createIterator(rectList);
    while ((elem = nextElement(&iter)) != NULL)
    {
        if (cur_index == index)
        {
            rectAtIndex = (Rectangle *)elem;
            index_flag = 1;
            break;
        }
        cur_index++;
    }

    if (index_flag == 0)
    {
        return;
    }

    if (strcmp(theAttr->name, "x") == 0)
    {
        rectAtIndex->x = atof(theAttr->value);
        deleteAttribute(theAttr);
        return;
    }

    else if (strcmp(theAttr->name, "y") == 0)
    {
        rectAtIndex->y = atof(theAttr->value);
        deleteAttribute(theAttr);
        return;
    }

    else if (strcmp(theAttr->name, "width") == 0)
    {
        rectAtIndex->width = atof(theAttr->value);
        deleteAttribute(theAttr);
        return;
    }

    else if (strcmp(theAttr->name, "height") == 0) {
        rectAtIndex->height = atof(theAttr->value);
        deleteAttribute(theAttr);
        return;
    }
    else
    {
        iter = createIterator(rectAtIndex->otherAttributes);
        while ((elem = nextElement(&iter)) != NULL) {
            Attribute *tmpAttr = (Attribute *)elem;
            if (strcmp(tmpAttr->name, theAttr->name) == 0) {
                if (strlen(theAttr->value) > strlen(tmpAttr->value)) {
                   tmpAttr->value = realloc(tmpAttr->value, sizeof(char) * (strlen(theAttr->value) + 1));
                }
                strcpy(tmpAttr->value, theAttr->value);
                deleteAttribute(theAttr);
                return;
            }
        }

        insertBack(rectAtIndex->otherAttributes, (void *)theAttr);
    }
}


void setCircAttr(List *circList, Attribute *theAttr, int index) {
    if (circList == NULL) {
        return;
    }

    int cur_index = 0;
    ListIterator iter;
    Circle *circAtIndex;
    int index_flag = 0; /* Flag to see if the index is out of bounds.*/
    void *elem;


    iter = createIterator(circList);
    while ((elem = nextElement(&iter)) != NULL)
    {
        if (cur_index == index)
        {
            circAtIndex = (Circle *)elem;
            index_flag = 1;
            break;
        }
        cur_index++;
    }

    if (index_flag == 0)
    {
        return;
    }

    if (strcmp(theAttr->name, "cx") == 0)
    {
        circAtIndex->cx = atof(theAttr->value);
        deleteAttribute(theAttr);
        return;
    }

    else if (strcmp(theAttr->name, "cy") == 0)
    {
        circAtIndex->cy = atof(theAttr->value);
        deleteAttribute(theAttr);
        return;
    }

    else if (strcmp(theAttr->name, "r") == 0)
    {
        circAtIndex->r = atof(theAttr->value);
        deleteAttribute(theAttr);
        return;
    }
    else
    {
        iter = createIterator(circAtIndex->otherAttributes);
        while ((elem = nextElement(&iter)) != NULL)
        {
            Attribute *tmpAttr = (Attribute *)elem;
            if (strcmp(tmpAttr->name, theAttr->name) == 0)
            {
                if (strlen(theAttr->value) > strlen(tmpAttr->value)) {
                    tmpAttr->value = realloc(tmpAttr->value, sizeof(char) * (strlen(theAttr->value) + 1));
                }
                strcpy(tmpAttr->value, theAttr->value);
                deleteAttribute(theAttr);
                return;
            }
        }
        insertBack(circAtIndex->otherAttributes, (void *)theAttr);
    }

}


void setSVGimageAttr(SVGimage *image, Attribute *theAttr) {
    List *attrList = image->otherAttributes;
    ListIterator iter;
    void *elem;

    if (attrList == NULL) {
        return;
    }

    iter = createIterator(attrList);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Attribute *tmpAttr = (Attribute *)elem;

        if (strcmp(tmpAttr->name, theAttr->name) == 0)
        {
            if (strlen(theAttr->value) > strlen(tmpAttr->value)) {
                tmpAttr->value = realloc(tmpAttr->value, sizeof(char) * (strlen(theAttr->value) + 1));
            }
            strcpy(tmpAttr->value, theAttr->value);
            deleteAttribute(theAttr);
            return;
        }
    }
    insertBack(image->otherAttributes, (void *)theAttr);

}


bool writeSVGimage(SVGimage *image, char *fileName) {

    if (image == NULL)
    {
        return false;
    }

    if (fileName == NULL)
    {
        return false;
    }

    xmlDoc *svgDoc = SVGimageToDoc(image);

    if (svgDoc == NULL)
    {
        return false;
    }

    int ret_val = xmlSaveFormatFileEnc(fileName, svgDoc, "UTF-8", 1);

    if (ret_val == -1)
    {
        xmlFreeDoc(svgDoc);
        xmlCleanupParser();
        return false;
    }

    else
    {
        xmlFreeDoc(svgDoc);
        xmlCleanupParser();
        return true;
    }
}


bool validateSVGimage(SVGimage *image, char *schemaFile) {
    int flag_1 = 0; /* Flag for schema validation. */
    int flag_2 = 0; /* Flag for internal constraint validation. */

    if (image == NULL)
    {
        return false;
    }

    flag_2 = checkForSVGconstraints(image);
    if (flag_2 == 0) {
        return false;
    }

    xmlDoc *isItValid = SVGimageToDoc(image);

    if (isItValid == NULL)
    {
        return false;
    }

    int ret = validateXMLTree(isItValid, schemaFile);

    if (ret == 0)
    {
        flag_1 = 1;
    }

    flag_2 = checkForSVGconstraints(image);

    if ((flag_1 == 1) && (flag_2 == 1))
    {
        return true;
    }

    return false;
}


int checkForSVGconstraints(SVGimage *image) {
    int flag = 1;
    /*
    * Constraits:
    * Namespace can't be empty.   (DONE)
    * In svg image list's cannot be null. May be empty. (DONE)
    * In rectangle, width and height cannot be negative. (DONE)
    * Attribute list of eny element can't be null. (DONE)
    * In Circle, radius cannot be negative. (DONE)
    * In Path data cannot be null. (DONE)
    * In groups no list can be null including groups of groups list.  (DONE)
    * In any extra attribute name and value cannot be null.  (DONE)
    * Returns 1 if all the constraints pass, 0 if any fails.
    */

    if (image->namespace[0] == '\0')
    {
        flag = 0;
        return flag;
    }

    if ((image->rectangles == NULL) || (image->circles == NULL) || (image->paths == NULL) || (image->groups == NULL) || (image->otherAttributes == NULL))
    {
        flag = 0;
        return flag;
    }

    if ((flag = checkAttrValidity(image->otherAttributes)) == 0)
    {
        return flag;
    }

    if ((flag = checkRectValidity(image)) == 0)
    {
        return flag;
    }

    if ((flag = checkCircleValidity(image)) == 0)
    {
        return flag;
    }

    if ((flag = checkPathValidity(image)) == 0)
    {
        return flag;
    }

    if ((flag = checkGroupValidity(image)) == 0)
    {
        return flag;
    }

    return flag;
}


int checkGroupValidity(SVGimage *img) {
    int flag = 1;
    ListIterator iter;
    void *elem;

    List *groupList = getGroups(img);

    iter = createIterator(groupList);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Group *tmpGroup = (Group *)elem;

        if ((tmpGroup->rectangles == NULL) || (tmpGroup->circles == NULL) || (tmpGroup->paths == NULL))
        {
            flag = 0;
        }

        if (checkAttrValidity(tmpGroup->otherAttributes) == 0)
        {
            flag = 0;
        }
    }

    getterFree(groupList);

    return flag;
}


int checkPathValidity(SVGimage *img) {
    List *pathList = getPaths(img);

    ListIterator iter;
    int flag = 1;
    void *elem;

    iter = createIterator(pathList);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Path *tmpPath = (Path *)elem;

        if (tmpPath->data == NULL)
        {
            flag = 0;
        }

        if (checkAttrValidity(tmpPath->otherAttributes) == 0)
        {
            flag = 0;
        }
    }

    getterFree(pathList);

    return flag;
}


int checkUnitValdity(char *units) {
    char allUnits[23][6] = {"cm", "", "mm", "in", "mm", "px", "pt", "pc", "em", "ex", "ch", "rem", "vw", "vh", "rad", "grad", "deg","turn","s","ms","min","h"};
    for (int i = 0; i < 21; i++)
    {
        if (strcmp(allUnits[i], units) == 0)
        {
            return 1;
        }
    }
    return 0;
}


int checkCircleValidity(SVGimage *img) {
    List *circleList = getCircles(img);
    ListIterator iter;
    int flag = 1;
    void *elem;

    iter = createIterator(circleList);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Circle *tmpCircle = (Circle *)elem;
        if (tmpCircle->r < 0)
        {
            flag = 0;
        }
        if (checkUnitValdity(tmpCircle->units) == 0)
        {
            flag = 0;
        }

        if (checkAttrValidity(tmpCircle->otherAttributes) == 0)
        {
            flag = 0;
        }
    }

    getterFree(circleList);

    return flag;
}


int checkAttrValidity(List *list) {
    ListIterator iter;
    int flag = 1;
    void *elem;


    if (list == NULL)
    {
        flag = 0;
        return flag;
    }

    iter = createIterator(list);
    
    while ((elem = nextElement(&iter)) != NULL){
        Attribute *tmpAttr = (Attribute *)elem;

        if (tmpAttr->name == NULL)
        {
            flag = 0;
        }
        if (tmpAttr->value == NULL)
        {
            flag = 0;
        }
    }

    return flag;
}


int checkRectValidity(SVGimage *img) {
    List *rectList = getRects(img);
    ListIterator iter;
    int flag = 1;
    void *elem;

    iter = createIterator(rectList);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Rectangle *tmpRect = (Rectangle *)elem;

        if (tmpRect->width < 0)
        {
            flag = 0;
        }

        if (tmpRect->height < 0)
        {
            flag = 0;
        }

        if (checkUnitValdity(tmpRect->units) == 0)
        {
            flag = 0;
        }

        if (checkAttrValidity(tmpRect->otherAttributes) == 0) {
            flag = 0;
        }

    }

    getterFree(rectList);

    return flag;
}


xmlDoc *SVGimageToDoc(SVGimage *img) {
    xmlDoc *new_doc = NULL;
    xmlNode *root = NULL;

    if (img == NULL)
    {
        return NULL;
    }

    //LIBXML_TEST_VERSION;
    /* Allocates a new xmlDoc structure. */
    new_doc = xmlNewDoc((xmlChar *)"1.0");
    if (new_doc == NULL)
    {
        return NULL;
    }

    /* Creates the root node. */
    root = xmlNewNode(NULL, (xmlChar *)"svg");

    /* Sets the root node of our new doc to the allocated root node. */
    xmlDocSetRootElement(new_doc, root);

    /* Creates an internal subset for our document. */
    xmlCreateIntSubset(new_doc, (xmlChar *)"svg", NULL, (xmlChar *)"tree2.dtd");

    if (populateDoc(img, &new_doc) == -1)
    {
        xmlFreeDoc(new_doc);
        return NULL;
    }

    return new_doc;
}


int setGroupNodes(List *list, xmlNode *root) {
    if (list == NULL) {
        return -1;
    }
    if (root == NULL) {
        return -1;
    }

    ListIterator iter;
    xmlNode *group_node = NULL;

    void *elem;

    iter = createIterator(list);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Group *tmpGroup = (Group *)elem;
        group_node = xmlNewChild(root, NULL, (xmlChar *)"g", NULL);

        if (tmpGroup->otherAttributes != NULL)
            if (getLength(tmpGroup->otherAttributes) > 0)
            {
                setOtherAttributeNodes(tmpGroup->otherAttributes, group_node);
            }

        setRectNodes(tmpGroup->rectangles, group_node);
        setCircleNodes(tmpGroup->circles, group_node);
        setPathNodes(tmpGroup->paths, group_node);
        setGroupNodes(tmpGroup->groups, group_node);
    }

    return 0;
}


int setPathNodes(List *list, xmlNode *root) {
    if (list == NULL) {
        return -1;
    }

    if (root == NULL) {
        return -1;
    }

    ListIterator iter;
    xmlNode *path_node = NULL;

    void *elem;

    iter = createIterator(list);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Path *tmpPath = (Path *)elem;
        path_node = xmlNewChild(root, NULL, (xmlChar *)"path", NULL);

        xmlNewProp(path_node, (xmlChar *)"d", (xmlChar *)tmpPath->data);

        if (tmpPath->otherAttributes != NULL)
            if (getLength(tmpPath->otherAttributes) > 0)
            {
                setOtherAttributeNodes(tmpPath->otherAttributes, path_node);
            }
    }

    return 0;
}


int setRectNodes(List *list, xmlNode *root) {
    if (list == NULL) {
        return -1;
    }
    if (root == NULL) {
        return -1;
    }

    ListIterator iter;
    xmlNode *rect_node = NULL;
    char buffer[506];

    void *elem;

    iter = createIterator(list);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Rectangle *tmpRect = (Rectangle *)elem;
        rect_node = xmlNewChild(root, NULL, (xmlChar *)"rect", NULL);

        sprintf(buffer, "%f", tmpRect->x);
        strcat(buffer,tmpRect->units);
        xmlNewProp(rect_node, (xmlChar *)"x", (xmlChar *)buffer);
        buffer[0] = '\0';

        sprintf(buffer, "%f", tmpRect->y);
        strcat(buffer,tmpRect->units);
        xmlNewProp(rect_node, (xmlChar *)"y", (xmlChar *)buffer);
        buffer[0] = '\0';

        sprintf(buffer, "%f", tmpRect->width);
        strcat(buffer,tmpRect->units);
        xmlNewProp(rect_node, (xmlChar *)"width", (xmlChar *)buffer);
        buffer[0] = '\0';

        sprintf(buffer, "%f", tmpRect->height);
        strcat(buffer,tmpRect->units);
        xmlNewProp(rect_node, (xmlChar *)"height", (xmlChar *)buffer);
        buffer[0] = '\0';
        if (tmpRect->otherAttributes != NULL)
            if (getLength(tmpRect->otherAttributes) > 0)
            {
                setOtherAttributeNodes(tmpRect->otherAttributes, rect_node);
            }
    }

    return 0;
}


int setCircleNodes(List *list, xmlNode *root) {
    if (list == NULL) {
        return -1;
    }
    if (root == NULL) {
        return -1;
    }

    ListIterator iter;
    xmlNode *circle_node = NULL;
    char buffer[506];

    void *elem;

    iter = createIterator(list);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Circle *tmpCircle = (Circle *)elem;
        circle_node = xmlNewChild(root, NULL, (xmlChar *)"circle", NULL);

        sprintf(buffer, "%f", tmpCircle->cx);
        strcat(buffer, tmpCircle->units);
        xmlNewProp(circle_node, (xmlChar *)"cx", (xmlChar *)buffer);
        buffer[0] = '\0';

        sprintf(buffer, "%f", tmpCircle->cy);
        strcat(buffer, tmpCircle->units);
        xmlNewProp(circle_node, (xmlChar *)"cy", (xmlChar *)buffer);
        buffer[0] = '\0';

        sprintf(buffer, "%f", tmpCircle->r);
        strcat(buffer, tmpCircle->units);
        xmlNewProp(circle_node, (xmlChar *)"r", (xmlChar *)buffer);
        buffer[0] = '\0';

        if (tmpCircle->otherAttributes != NULL)
            if (getLength(tmpCircle->otherAttributes) > 0)
            {
                setOtherAttributeNodes(tmpCircle->otherAttributes, circle_node);
            }
    }

    return 0;
}


void setOtherAttributeNodes(List *otherAttrList, xmlNode *parent) {
    ListIterator iter;
    iter = createIterator(otherAttrList);
    void *elem;

    while ((elem = nextElement(&iter)) != NULL)
    {
        Attribute *tmpAttr = (Attribute *)elem;
        xmlNewProp(parent, (xmlChar *)(tmpAttr->name), (xmlChar *)(tmpAttr->value));
    }
}


int populateDoc(SVGimage *img, xmlDoc **doc) {
    xmlNode *root_node = xmlDocGetRootElement(*doc);
    if (root_node == NULL)
    {
        return -1;
    }

    if (setRootElementNodes(img, root_node) == -1){
        return -1;
    }

    if (setRectNodes(img->rectangles, root_node) == -1) {
        return -1;
    }

    if (setCircleNodes(img->circles, root_node) == -1) {
        return -1;
    }

    if (setPathNodes(img->paths, root_node) == -1) {
        return -1;
    }

    if (setGroupNodes(img->groups, root_node) == -1) {
        return -1;
    }

    return 0;
}


int setRootElementNodes(SVGimage *img, xmlNode *root_node) {
    if (img == NULL) {
        return -1;
    }

    xmlNs *new_namespace = NULL;

    new_namespace = xmlNewNs(root_node, (xmlChar *)img->namespace, NULL);

    if (new_namespace == NULL) {
        return -1;
    }

    xmlSetNs(root_node, new_namespace);

    if (img->otherAttributes != NULL) {
        if (getLength(img->otherAttributes) > 0) {
            setOtherAttributeNodes(img->otherAttributes, root_node);
        }
    }

    if (img->title[0] != '\0')
    {
        xmlNewChild(root_node, NULL, (xmlChar *)"title", (xmlChar *)img->title);
    }

    if (img->description[0] != '\0')
    {
        xmlNewChild(root_node, NULL, (xmlChar *)"desc", (xmlChar *)img->description);
    }

    return 0;
}


SVGimage *createValidSVGimage(char *fileName, char *schemaFile) {
    int ret;
    xmlDoc *doc = NULL;

    if (fileName == NULL) {
        return NULL;
    }

    if (schemaFile == NULL) {
        return NULL;
    }

    doc = xmlReadFile(fileName, NULL, 0);
    if (doc == NULL)
    {
        xmlCleanupParser();
        return NULL;
    }

    ret = validateXMLTree(doc, schemaFile);

    if (ret == 0)
    {
        SVGimage * valid_svg = createSVGimage(fileName);
        NULLCHECK(valid_svg)
        return valid_svg;
    }
    else
    {
        return NULL;
    }

    return NULL;
}


int validateXMLTree(xmlDoc *a_doc, char *schemaFile) {
    xmlDoc *doc = a_doc;
    xmlSchema *schema = NULL;
    xmlSchemaParserCtxt *schema_ctxt;

    if (doc == NULL)
    {
        return -1;
    }

    xmlLineNumbersDefault(1);

    /* Creates an xml schema parse context. */
    schema_ctxt = xmlSchemaNewParserCtxt(schemaFile);
    if (schema_ctxt == NULL)
    {
        xmlFreeDoc(doc);
        xmlCleanupParser();
        return -1;
    }

    /* Set the functions for error handling for validation context. */
    xmlSchemaSetParserErrors(schema_ctxt, (xmlSchemaValidityErrorFunc)fprintf, (xmlSchemaValidityWarningFunc)fprintf, stderr);

    /* Parse the schema and point the internal set the internal schema struct. */
    schema = xmlSchemaParse(schema_ctxt);
    if (schema == NULL)
    {
        xmlSchemaFreeParserCtxt(schema_ctxt);
        xmlFreeDoc(doc);
        xmlCleanupParser();
        return -1;
    }

    /* Free the schema parser context. */
    xmlSchemaFreeParserCtxt(schema_ctxt);

    /* Create a valid context. */
    xmlSchemaValidCtxt *valid_ctxt;
    int ret;
    valid_ctxt = xmlSchemaNewValidCtxt(schema);
    if (valid_ctxt == NULL)
    {
        xmlSchemaFree(schema);
        xmlFreeDoc(doc);
        xmlCleanupParser();
        return -1;
    }

    xmlSchemaSetValidErrors(valid_ctxt, (xmlSchemaValidityErrorFunc)fprintf, (xmlSchemaValidityWarningFunc)fprintf, stderr);

    /* Validates the doc againts the schema structure. */
    ret = xmlSchemaValidateDoc(valid_ctxt, doc);

    xmlSchemaFreeValidCtxt(valid_ctxt);
    xmlSchemaFree(schema);
    xmlFreeDoc(doc);
    xmlCleanupParser();
    xmlMemoryDump();

    return ret;
}


char *SVGimageToString(SVGimage *img) {
    NULLCHECK(img);

    ListIterator iter;
    char *elem;

    long len = 46;
    char *description = malloc(sizeof(char) * len);

    strcpy(description, "String description for the svg image : \n\n");

    len = len + 9;
    len += strlen(img->namespace);
    if ((img->description)[0] != '\0')
        len += strlen(img->description);
    if ((img->title)[0] != '\0')
        len += strlen(img->title);

    len = len + 26 + 18 + 31 + 9;

    /* Allocates enough memory to concat namespace, title and description and concats them in. */
    description = realloc(description, sizeof(char) * len);
    strcat(description, "Namespace : ");
    strcat(description, img->namespace);
    strcat(description, "\n\n");
    strcat(description, "Title : ");
    if ((img->title)[0] != '\0')
        strcat(description, img->title);
    strcat(description, "\n\n");
    strcat(description, "Description of the svg : ");
    if ((img->description)[0] != '\0')
        strcat(description, img->description);
    strcat(description, "\n\n");

    iter = createIterator(img->rectangles);
    if (iter.current)
    {
        while ((elem = nextElement(&iter)) != NULL)
        {
            Rectangle *tmpRect = (Rectangle *)elem;
            char *str = img->rectangles->printData(tmpRect);
            len = len + strlen(str) + 30;
            description = realloc(description, sizeof(char) * len);
            strcat(description, strcat(str, "\n"));
            free(str);
        }
    }

    iter = createIterator(img->circles);
    if (iter.current)
    {
        while ((elem = nextElement(&iter)) != NULL)
        {
            Circle *tmpCircle = (Circle *)elem;
            char *str = img->circles->printData(tmpCircle);
            len = len + strlen(str) + 30;
            description = realloc(description, sizeof(char) * len);
            strcat(description, strcat(str, "\n"));
            free(str);
        }
    }

    iter = createIterator(img->paths);
    if (iter.current)
    {
        while ((elem = nextElement(&iter)) != NULL)
        {
            Path *tmpPath = (Path *)elem;
            char *str = img->paths->printData(tmpPath);
            len = len + strlen(str) + 30;
            description = realloc(description, sizeof(char) * len);
            strcat(description, strcat(str, "\n"));
            free(str);
        }
    }

    iter = createIterator(img->otherAttributes);
    if (iter.current)
    {
        while ((elem = nextElement(&iter)) != NULL)
        {
            Attribute *tmpAttribute = (Attribute *)elem;
            char *str = img->otherAttributes->printData(tmpAttribute);
            len = len + strlen(str) + 55;
            description = realloc(description, sizeof(char) * len);
            strcat(description, "Other svg attribute : \n");
            strcat(description, strcat(str, "\n"));
            free(str);
        }
    }

    iter = createIterator(img->groups);
    if (iter.current)
    {
        while ((elem = nextElement(&iter)) != NULL)
        {
            Group *tmpGroup = (Group *)elem;
            char *str = img->groups->printData(tmpGroup);
            len = len + strlen(str) + 55;
            description = realloc(description, sizeof(char) * len);
            strcat(description, strcat(str, "\n"));
            free(str);
        }
    }

    return description;
}


SVGimage *createSVGimage(char *fileName) {
    SVGimage *theImage = NULL;

    xmlNode *root = NULL;
    xmlDoc *doc = NULL;

    if ((root = parseTheFile(fileName, &doc)) == NULL)
    {
        if (doc != NULL)
        {
            xmlFreeDoc(doc);
        }
        return NULL;
    }

    theImage = (SVGimage *)malloc(sizeof(SVGimage));

    List *rectList = initializeList(&rectangleToString, &deleteRectangle, &compareRectangles);
    List *circleList = initializeList(&circleToString, &deleteCircle, &compareCircles);
    List *pathList = initializeList(&pathToString, &deletePath, &comparePaths);
    List *groupList = initializeList(&groupToString, &deleteGroup, &compareGroups);

    (theImage->description)[0] = '\0';
    (theImage->title)[0] = '\0';

    initStruct(root, &theImage, &rectList, &circleList, &pathList, &groupList);

    xmlFreeDoc(doc);
    //xmlCleanupParser();

    return theImage;
}


void deleteSVGimage(SVGimage *img) {
    if (img == NULL)
    {
        return;
    }

    if (img->rectangles != NULL)
    {
        freeList(img->rectangles);
    }

    if (img->circles != NULL)
    {
        freeList(img->circles);
    }

    if (img->paths != NULL)
    {
        freeList(img->paths);
    }

    if (img->groups != NULL)
    {
        freeList(img->groups);
    }

    if (img->otherAttributes != NULL)
    {
        freeList(img->otherAttributes);
    }

    free(img);
}


void initStruct(xmlNode *r_node, SVGimage **theImage, List **rectList, List **circleList, List **pathList, List **groupList) {
    xmlNode *cur_node = NULL;

    for (cur_node = r_node; cur_node != NULL; cur_node = cur_node->next)
    {
        /* Getting the namespace from the xml object. */
        if (cur_node->ns != NULL)
        {
            xmlNs *theNameSpace;
            if ((theNameSpace = cur_node->ns) != NULL) {
                strncpy((*theImage)->namespace, (char *)theNameSpace->href, 255);
                (*theImage)->namespace[255] = '\0';
            }
        }

        if (strcmp((char *)cur_node->name, "svg") == 0)
        {
            List *attrList = parseOtherAttributes(cur_node);
            (*theImage)->otherAttributes = attrList;
        }

        if (strcmp((char *)cur_node->name, "title") == 0)
        {
            xmlChar *titleContent = xmlNodeGetContent(cur_node);
            strncpy((*theImage)->title, (char *)titleContent, 255);
            (*theImage)->title[255] = '\0';
            xmlFree(titleContent);
            titleContent = NULL;
        }


        if (strcmp((char *)cur_node->name, "desc") == 0)
        {
            char *descContent = (char *)xmlNodeGetContent(cur_node);
            strncpy((*theImage)->description, descContent, 255);
            (*theImage)->description[255] = '\0';
            xmlFree(descContent);
        }


        if (strcmp((char *)cur_node->name, "rect") == 0)
        {
            if (strcmp((char *)cur_node->parent->name, "g") != 0)
            {
                Rectangle *rect = parseRectangle(cur_node);
                if (rect != NULL) {
                    insertBack((*rectList), (void *)rect);
                }
            }
        }

        if (strcmp((char *)cur_node->name, "circle") == 0)
        {
            if (strcmp((char *)cur_node->parent->name, "g") != 0)
            {
                Circle *circle = parseCircle(cur_node);
                if (circle != NULL)
                {
                    insertBack((*circleList), (void *)circle);
                }
            }
        }

        if (strcmp((char *)cur_node->name, "path") == 0)
        {
            if (strcmp((char *)cur_node->parent->name, "g") != 0)
            {
                Path *path = parsePath(cur_node);
                if (path != NULL)
                {
                    insertBack((*pathList), (void *)path);
                }
            }
        }

        if (strcmp((char *)cur_node->name, "g") == 0)
        {
            if (strcmp((char *)cur_node->parent->name, "g") != 0)
            {
                xmlNode *tmp = cur_node->children;
                Group *group = parseGroup(tmp);
                if (group != NULL)
                {
                    insertBack((*groupList), (void *)group);
                }
            }
        }

        (*theImage)->paths = (*pathList);
        (*theImage)->rectangles = (*rectList);
        (*theImage)->circles = (*circleList);
        (*theImage)->groups = (*groupList);

        initStruct(cur_node->children, theImage, rectList, circleList, pathList, groupList);
    }
}


List *parseOtherAttributes(xmlNode *a_node) {
    xmlNode *the_node = a_node;
    xmlAttr *attr;

    List *attrList = initializeList(&attributeToString, &deleteAttribute, &compareAttributes);

    for (attr = the_node->properties; attr != NULL; attr = attr->next)
    {
        char *attrName = (char *)attr->name;
        xmlNode *value = attr->children;
        char *cont = (char *)(value->content);

        Attribute *attribute = getAttribute(attrName, cont);

        insertBack(attrList, (void *)attribute);
    }

    return attrList;
}


Attribute *getAttribute(char *attrName, char *content) {
    Attribute *newAttribute = malloc(sizeof(Attribute));

    newAttribute->name = malloc(sizeof(char) * (strlen(attrName) + 1));
    newAttribute->value = malloc(sizeof(char) * (strlen(content) + 1));

    strcpy(newAttribute->name, attrName);
    strcpy(newAttribute->value, content);

    return newAttribute;
}


Group *parseGroup(xmlNode *a_node) {
    NULLCHECK(a_node)
    xmlNode *tmpNode = NULL;

    Group *theGroup = malloc(sizeof(Group));
    NULLCHECK(theGroup)

    List *rectList = initializeList(&rectangleToString, &deleteRectangle, &compareRectangles);
    List *circleList = initializeList(&circleToString, &deleteCircle, &compareCircles);
    List *pathList = initializeList(&pathToString, &deletePath, &comparePaths);
    List *groupList = initializeList(&groupToString, &deleteGroup, &compareGroups);

    List *groupAttrList = parseOtherAttributes(a_node->parent);

    for (tmpNode = a_node; tmpNode != NULL; tmpNode = tmpNode->next)
    {
        if (strcmp((char *)tmpNode->name, "rect") == 0)
        {
            xmlNode *tmp2 = tmpNode;
            Rectangle *rect = parseRectangle(tmp2);
            insertBack(rectList, (void *)rect);
        }

        if (strcmp((char *)tmpNode->name, "circle") == 0)
        {
            Circle *circle = parseCircle(tmpNode);
            insertBack(circleList, (void *)circle);
        }

        if (strcmp((char *)tmpNode->name, "path") == 0)
        {
            Path *path = parsePath(tmpNode);
            insertBack(pathList, (void *)path);
        }

        if (strcmp((char *)tmpNode->name, "g") == 0)
        {
            Group *group = parseGroup(tmpNode->children);
            insertBack(groupList, (void *)group);
        }
    }

    theGroup->paths = pathList;
    theGroup->rectangles = rectList;
    theGroup->circles = circleList;
    theGroup->groups = groupList;
    theGroup->otherAttributes = groupAttrList;

    return theGroup;
}


Path *parsePath(xmlNode *a_node) {
    NULLCHECK(a_node)
    xmlNode *the_node = a_node;

    Path *newPath = (Path *)malloc(sizeof(Path));
    NULLCHECK(newPath)

    List *pathAttrList = initializeList(&attributeToString, &deleteAttribute, &compareAttributes);

    xmlAttr *attr;

    for (attr = the_node->properties; attr != NULL; attr = attr->next)
    {
        char *attrName = (char *)attr->name;
        xmlNode *value = attr->children;
        char *cont = (char *)(value->content);

        if (strcmp(attrName, "d") == 0)
        {
            newPath->data = malloc(sizeof(char) * (strlen(cont) + 1));
            strcpy(newPath->data, cont);
        }
        else
        {
            Attribute *attribute = getAttribute(attrName, cont);
            insertBack(pathAttrList, (void *)attribute);
        }
    }

    newPath->otherAttributes = pathAttrList;

    return newPath;
}


Circle *parseCircle(xmlNode *a_node) {
    NULLCHECK(a_node)
    xmlNode *the_node = a_node;

    Circle *newCircle = (Circle *)malloc(sizeof(Circle));
    NULLCHECK(newCircle)

    List *circleAttrList = initializeList(&attributeToString, &deleteAttribute, &compareAttributes);

    xmlAttr *attr;

    for (attr = the_node->properties; attr != NULL; attr = attr->next)
    {
        char *attrName = (char *)attr->name;
        xmlNode *value = attr->children;
        char *cont = (char *)(value->content);

        if (strcmp(attrName, "cx") == 0)
        {
            newCircle->cx = atof(cont);

            char *theUnits;
            if ((theUnits = getUnits(cont)) != NULL)
            {
                strcpy(newCircle->units, theUnits);
                free(theUnits);
            }
        }

        else if (strcmp(attrName, "cy") == 0)
        {
            newCircle->cy = atof(cont);
        }

        else if (strcmp(attrName, "r") == 0)
        {
            newCircle->r = atof(cont);
        }
        else
        {
            Attribute *attribute = getAttribute(attrName, cont);
            insertBack(circleAttrList, (void *)attribute);
        }
    }

    newCircle->otherAttributes = circleAttrList;

    return newCircle;
}


Rectangle *parseRectangle(xmlNode *a_node) {
    NULLCHECK(a_node)
    xmlNode *the_node = a_node;

    Rectangle *newRect = (Rectangle *)malloc(sizeof(Rectangle));
    NULLCHECK(newRect)

    List *rectAttrList = initializeList(&attributeToString, &deleteAttribute, &compareAttributes);

    xmlAttr *attr;

    newRect->x = 0;
    newRect->y = 0;
    newRect->height = 0;
    newRect->width = 0;

    for (attr = the_node->properties; attr != NULL; attr = attr->next)
    {
        /* Parse the rectangle attributes into the rectangle struct.*/
        char *attrName = (char *)attr->name;
        xmlNode *value = attr->children;
        char *cont = (char *)(value->content);

        if (strcmp(attrName, "x") == 0)
        {
            newRect->x = atof(cont);

            /* Parses the units if they exist and copies them into the rectangle struct. */
            char *theUnits;
            if ((theUnits = getUnits(cont)) != NULL)
            {
                strcpy(newRect->units, theUnits);
                free(theUnits);
            }
        }

        else if (strcmp(attrName, "y") == 0)
        {
            newRect->y = atof(cont);
        }
        else if (strcmp(attrName, "width") == 0)
        {
            newRect->width = atof(cont);
        }
        else if (strcmp(attrName, "height") == 0)
        {
            newRect->height = atof(cont);
        }
        else
        {
            Attribute *attribute = getAttribute(attrName, cont);
            insertBack(rectAttrList, (void *)attribute);
        }
    }

    newRect->otherAttributes = rectAttrList;

    return newRect;
}


xmlNode *parseTheFile(char *doc_name, xmlDoc **doc) {
    xmlNode *node_root = NULL;

    LIBXML_TEST_VERSION

    *doc = xmlReadFile(doc_name, NULL, 0);

    NULLCHECK(*doc)

    node_root = xmlDocGetRootElement(*doc);

    //print_the_elements(node_root);

    /* Comment out for now. (executed inside the createSVGimage function) */
    // xmlFreeDoc(doc);
    xmlCleanupParser();

    return node_root;
}


char *getUnits(char *content) {
    int i, j;
    char characters[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char *theUnit = malloc(sizeof(char));
    int counter = 0;
    int flag = 0;
    for (i = 0; i < strlen(content); i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (content[i] == characters[j])
            {
                theUnit = realloc(theUnit, (sizeof(char) * (counter + 2)));
                theUnit[counter] = content[i];
                counter++;
                flag = 1;
            }
        }
    }

    if (flag == 0)
    {
        theUnit = realloc(theUnit, sizeof(char) * 3);
        strcpy(theUnit, "");
    }
    else
    {
        theUnit[counter] = '\0';
    }

    return theUnit;
}


void deleteRectangle(void *data) {
    Rectangle *tmp;

    if (data == NULL)
    {
        return;
    }

    tmp = (Rectangle *)data;

    freeList(tmp->otherAttributes);
    free(tmp);
}


void deleteCircle(void *data) {
    if (data == NULL)
    {
        return;
    }

    Circle *temp_circle;

    temp_circle = (Circle *)data;

    freeList(temp_circle->otherAttributes);
    free(temp_circle);
}


void deletePath(void *data) {
    Path *temp_path;

    if (data == NULL)
    {
        return;
    }

    temp_path = (Path *)data;

    free(temp_path->data);
    freeList(temp_path->otherAttributes);
    free(temp_path);
}


void deleteGroup(void *data) {
    Group *temp_group;

    if (data == NULL)
    {
        return;
    }

    temp_group = (Group *)data;
    freeList(temp_group->rectangles);
    freeList(temp_group->circles);
    freeList(temp_group->paths);
    freeList(temp_group->otherAttributes);

    if (getLength(temp_group->groups) > 0)
    {
        freeList(temp_group->groups);
    }
    else
    {
        freeList(temp_group->groups);
    }

    free(temp_group);
}


void deleteAttribute(void *data) {
    Attribute *tmp;

    if (data == NULL)
    {
        return;
    }

    tmp = (Attribute *)data;

    free(tmp->name);
    free(tmp->value);
    free(tmp);
}


char *circleToString(void *data) {
    NULLCHECK(data);

    Circle *tempCircle;
    char *description;
    long len;

    tempCircle = (Circle *)data;

    /* 20 each for every float plus units + 3 and 1 for '\0' */
    len = 20 + 20 + 20 + strlen(tempCircle->units) + 4;
    len = len + 120; /* For the string description.*/

    description = (char *)malloc(sizeof(char) * len);

    sprintf(description, "%s\nValue for cx :  %f\nValue for cy : %f\nValue for r : %f\nThe units for the circle: %s\n", "Circle :", tempCircle->cx, tempCircle->cy, tempCircle->r, tempCircle->units);

    strcat(description, "Other Attributes for the circle : \n");

    ListIterator iter = createIterator(tempCircle->otherAttributes);
    void *elem;
    while ((elem = nextElement(&iter)) != NULL)
    {
        Attribute *tmpName = (Attribute *)elem;

        char *str = tempCircle->otherAttributes->printData(tmpName);
        len = len + strlen(str) + 30;

        description = realloc(description, sizeof(char) * len);

        strcat(description, str);
        free(str);
    }

    return description;
}


char *groupToString(void *data) {
    Group *temp_group;
    void *elem;
    int len = 14;

    if (data == NULL)
    {
        return NULL;
    }

    char *description = malloc(sizeof(char) * len);

    strcpy(description, "Group : \n");

    temp_group = (Group *)data;

    ListIterator iter = createIterator(temp_group->circles);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Circle *tmpName = (Circle *)elem;

        char *str = temp_group->circles->printData(tmpName);
        len = len + strlen(str) + 30;
        description = realloc(description, sizeof(char) * len);
        strcat(description, strcat(str, "\n"));
        free(str);
    }

    iter = createIterator(temp_group->rectangles);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Rectangle *tmpName = (Rectangle *)elem;

        char *str = temp_group->rectangles->printData(tmpName);
        len = len + strlen(str) + 30;

        description = realloc(description, sizeof(char) * len);
        strcat(description, strcat(str, "\n"));
        free(str);
    }

    iter = createIterator(temp_group->paths);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Path *tmpName = (Path *)elem;

        char *str = temp_group->paths->printData(tmpName);
        len = len + strlen(str) + 30;

        description = realloc(description, sizeof(char) * len);
        strcat(description, strcat(str, "\n"));
        free(str);
    }

    iter = createIterator(temp_group->otherAttributes);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Attribute *tmpName = (Attribute *)elem;
        char *str = temp_group->otherAttributes->printData(tmpName);
        len = len + strlen(str) + 50;

        description = realloc(description, sizeof(char) * len);

        strcat(description, "Other group attributes : \n");
        strcat(description, strcat(str, "\n"));

        free(str);
    }

    iter = createIterator(temp_group->groups);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Group *tmpName = (Group *)elem;
        char *str = temp_group->groups->printData(tmpName);
        len = len + strlen(str) + 30;

        description = realloc(description, sizeof(char) * len);
        strcat(description, strcat(str, "\n"));

        free(str);
    }

    return description;
}


char *attributeToString(void *data) {
    char *description;
    int len = 0;

    Attribute *tempAttribute;
    tempAttribute = (Attribute *)data;

    len = strlen(tempAttribute->name) + strlen(tempAttribute->value) + 94;

    description = malloc(sizeof(char) * len);

    sprintf(description, "Name of the attribute : %s\nValue of the attribute : %s\n", tempAttribute->name, tempAttribute->value);

    return description;
}


char *pathToString(void *data) {
    Path *tempPath;
    char *description;
    long len = 0;

    NULLCHECK(data);

    tempPath = (Path *)data;

    /* 20 each for every float plus units + 3 and 1 for '\0' */
    len = strlen(tempPath->data) + 70;

    description = (char *)malloc(sizeof(char) * len);

    sprintf(description, "%s\nValue for data :  %s\n", "Path :", tempPath->data);

    strcat(description, "Other Attributes for the path : \n");

    ListIterator iter = createIterator(tempPath->otherAttributes);
    void *elem;
    while ((elem = nextElement(&iter)) != NULL)
    {
        Attribute *tmpName = (Attribute *)elem;

        char *str = tempPath->otherAttributes->printData(tmpName);
        len = len + strlen(str) + 30;

        description = realloc(description, sizeof(char) * len);

        strcat(description, str);
        free(str);
    }

    return description;
}


char *rectangleToString(void *data) {
    Rectangle *tempRect;
    char *description;
    long len;

    NULLCHECK(data);

    tempRect = (Rectangle *)data;

    /* 20 each for every float plus units + 3 and 1 for '\0' */
    len = 20 + 20 + 20 + 20 + strlen(tempRect->units) + 4;
    len = len + 38 + 24 + 25 + 46; /* For the string description.*/

    description = (char *)malloc(sizeof(char) * len);

    sprintf(description, "%s\nValue for x :  %f\nValue for y :  %f\nValue for width :  %f\nValue for height :  %f\nThe units for the rectangle: %s\n",
            "Rectangle :", tempRect->x, tempRect->y, tempRect->width, tempRect->height, tempRect->units);

    strcat(description, "Other Attributes for the rectangle : \n");
    ListIterator iter = createIterator(tempRect->otherAttributes);
    void *elem;
    while ((elem = nextElement(&iter)) != NULL)
    {
        Attribute *tmpName = (Attribute *)elem;

        char *str = tempRect->otherAttributes->printData(tmpName);
        len = len + strlen(str) + 30;

        description = realloc(description, sizeof(char) * len);

        strcat(description, str);
        free(str);
    }

    return description;
}


int compareRectangles(const void *first, const void *second) {
    return 0;
}


int compareCircles(const void *first, const void *second) {
    return 0;
}


int comparePaths(const void *first, const void *second) {
    return 0;
}


int compareGroups(const void *first, const void *second) {
    return 0;
}


int compareAttributes(const void *first, const void *second) {
    return 0;
}


void getterFree(List *list) {
    if (list == NULL)
    {
        return;
    }

    if (list->head == NULL && list->tail == NULL)
    {
        free(list);
        return;
    }

    Node *tmp;
    Node *tmp2;

    while (list->head != NULL)
    {
        tmp = list->head;
        tmp2 = tmp;
        list->head = list->head->next;
        free(tmp2);
    }

    free(list);
}


List *getRects(SVGimage *img) {
    List *rectangleList = initializeList(&rectangleToString, &deleteRectangle, &compareRectangles);
    if (img == NULL)
    {
        return rectangleList;
    }

    ListIterator iter;
    void *elem;

    iter = createIterator(img->rectangles);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Rectangle *tmpRect = (Rectangle *)elem;
        insertBack(rectangleList, (void *)tmpRect);
    }

    List *listOfGroups = getGroups(img);
    if (getLength(listOfGroups) > 0)
    {
        iter = createIterator(listOfGroups);
        while ((elem = nextElement(&iter)) != NULL)
        {
            Group *tmpGroup = (Group *)elem;
            if (getLength(tmpGroup->rectangles) > 0)
            {
                ListIterator iter2 = createIterator(tmpGroup->rectangles);
                void *r_elem;
                while ((r_elem = nextElement(&iter2)) != NULL)
                {
                    Rectangle *tmpRect = (Rectangle *)r_elem;
                    insertBack(rectangleList, (void *)tmpRect);
                }
            }
        }
    }

    getterFree(listOfGroups);

    return rectangleList;
}


List *getPaths(SVGimage *img) {
    List *pathList = initializeList(&pathToString, &deletePath, &comparePaths);

    if (img == NULL)
    {
        return pathList;
    }

    ListIterator iter;
    void *elem;

    iter = createIterator(img->paths);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Path *tmpPath = (Path *)elem;
        insertBack(pathList, (void *)tmpPath);
    }

    List *listOfGroups = getGroups(img);
    if (getLength(listOfGroups) > 0)
    {
        iter = createIterator(listOfGroups);
        while ((elem = nextElement(&iter)) != NULL)
        {
            Group *tmpGroup = (Group *)elem;
            if (getLength(tmpGroup->paths) > 0)
            {
                ListIterator iter2 = createIterator(tmpGroup->paths);
                void *r_elem;
                while ((r_elem = nextElement(&iter2)) != NULL)
                {
                    Path *tmpPath = (Path *)r_elem;
                    insertBack(pathList, (void *)tmpPath);
                }
            }
        }
    }
    getterFree(listOfGroups);

    return pathList;
}


List *getCircles(SVGimage *img) {
    List *circleList = initializeList(&circleToString, &deleteCircle, &compareCircles);
    if (img == NULL)
    {
        return circleList;
    }

    ListIterator iter;
    void *elem;

    iter = createIterator(img->circles);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Circle *tmpCircle = (Circle *)elem;
        insertBack(circleList, (void *)tmpCircle);
    }

    List *listOfGroups = getGroups(img);

    if (getLength(listOfGroups) > 0)
    {
        iter = createIterator(listOfGroups);
        while ((elem = nextElement(&iter)) != NULL)
        {
            Group *tmpGroup = (Group *)elem;
            if (getLength(tmpGroup->circles) > 0)
            {
                ListIterator iter2 = createIterator(tmpGroup->circles);
                void *r_elem;
                while ((r_elem = nextElement(&iter2)) != NULL)
                {
                    Circle *tmpCircle = (Circle *)r_elem;
                    insertBack(circleList, (void *)tmpCircle);
                }
            }
        }
    }

    getterFree(listOfGroups);

    return circleList;
}


List *getGroups(SVGimage *img) {
    List *groupList = initializeList(&groupToString, &deleteGroup, &compareGroups);

    if (img == NULL)
    {
        return groupList;
    }

    ListIterator iter;

    iter = createIterator(img->groups);
    getAllGroups(&groupList, &iter);

    return groupList;
}


void getAllGroups(List **groupList, ListIterator *iter) {
    void *elem;
    while ((elem = nextElement(iter)) != NULL)
    {
        Group *tmpGroup = (Group *)elem;
        insertBack((*groupList), (void *)tmpGroup);

        if (getLength(tmpGroup->groups) > 0)
        {
            ListIterator iter2 = createIterator(tmpGroup->groups);
            getAllGroups(groupList, &iter2);
        }
    }
}


int numAttr(SVGimage *img) {
    if (img == NULL)
    {
        return 0;
    }
    int num = 0;

    num = num + getLength(img->otherAttributes);

    ListIterator iter;
    void *elem;

    List *allRects = getRects(img);
    iter = createIterator(allRects);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Rectangle *tmpRect = (Rectangle *)elem;
        num = num + getLength(tmpRect->otherAttributes);
    }
    getterFree(allRects);

    List *allCircles = getCircles(img);
    iter = createIterator(allCircles);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Circle *tmpCircle = (Circle *)elem;
        num = num + getLength(tmpCircle->otherAttributes);
    }
    getterFree(allCircles);

    List *allPaths = getPaths(img);
    iter = createIterator(allPaths);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Path *tmpPath = (Path *)elem;
        num = num + getLength(tmpPath->otherAttributes);
    }
    getterFree(allPaths);

    List *allGroups = getGroups(img);
    iter = createIterator(allGroups);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Group *tmpGroup = (Group *)elem;
        num = num + getLength(tmpGroup->otherAttributes);
    }
    getterFree(allGroups);

    return num;
}


int numGroupsWithLen(SVGimage *img, int len) {
    if (img == NULL)
    {
        return 0;
    }

    if (len < 0)
    {
        return 0;
    }

    int count = 0;

    ListIterator iter;
    void *elem;

    iter = createIterator(img->groups);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Group *tmpGroup = (Group *)elem;
        if ((getLength(tmpGroup->rectangles) + getLength(tmpGroup->circles) + getLength(tmpGroup->paths) + getLength(tmpGroup->groups)) == len)
        {
            count++;
        }
    }

    return count;
}


int numPathsWithdata(SVGimage *img, char *data) {
    if (img == NULL)
    {
        return 0;
    }

    if (data == 0)
    {
        return 0;
    }

    int count = 0;

    List *allPaths = getPaths(img);

    ListIterator iter;
    void *elem;

    iter = createIterator(allPaths);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Path *tmpPath = (Path *)elem;
        if (strcmp(tmpPath->data, data) == 0)
        {
            count++;
        }
    }

    getterFree(allPaths);

    return count;
}


int numCirclesWithArea(SVGimage *img, float area) {
    if (img == NULL)
    {
        return 0;
    }

    if (area < 0)
    {
        return 0;
    }

    int count = 0;

    List *allCircles = getCircles(img);

    ListIterator iter;
    void *elem;

    iter = createIterator(allCircles);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Circle *tmpCircle = (Circle *)elem;
        float cir_area = (3.14159265) * (tmpCircle->r) * (tmpCircle->r);
        if (ceil((float)cir_area) == ceil(area))
        {
            count++;
        }
    }

    getterFree(allCircles);

    return count;
}


int numRectsWithArea(SVGimage *img, float area) {
    if (img == NULL)
    {
        return 0;
    }

    if (area < 0)
    {
        return 0;
    }
    int count = 0;

    List *allRects = getRects(img);

    ListIterator iter;
    void *elem;

    iter = createIterator(allRects);
    while ((elem = nextElement(&iter)) != NULL)
    {
        Rectangle *tmpRect = (Rectangle *)elem;
        if (ceil((tmpRect->height) * (tmpRect->width)) == ceil(area))
        {
            count++;
        }
    }

    getterFree(allRects);

    return count;
}




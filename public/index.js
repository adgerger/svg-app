// Put all onload AJAX calls here, and event listeners
$(document).ready(function() {
    
    // On page-load AJAX Example
    $.ajax({
        type: 'get',            //Request type
        dataType: 'json',       //Data type - we will use JSON for almost everything 
        url: '/someendpoint',   //The server endpoint we are connecting to
        data: {
            name1: "Value 1",
            name2: "Value 2"
        },
        success: function (data) {
            /*  Do something with returned object
                Note that what we get is an object, not a string, 
                so we do not need to parse it on the server.
                JavaScript really does handle JSONs seamlessly
            */
            
            $('#blah').html("On page load, received string '"+data.foo+"' from server");
            //We write the object to the console to show that the request was successful
            console.log(data); 

        },
        fail: function(error) {
            // Non-200 return, do something with error
            $('#blah').html("On page load, received error from server");
            console.log(error); 
        }
    });
    
    $.ajax({
        type: 'get',
        dataType: 'json',
        url: '/uploadedFiles',
        data: { 
            fileName: "rects.svg",
            fileSize: "0KB",
            numRect: "0",
            numCirc: "0",
            numPath: "0",
            numGroups: "0"
        },
        success: function (data) {
           
           for(let i = 0; i < data.length; i++){
               console.log("The file name received is :");
               console.log(data[i].fileName); 
               let imgLoc = "./uploads/" + data[i].fileName;
               
               var fileLog = document.getElementById("fileLogTable");
               let row = fileLog.insertRow(fileLog.rows.length);
               
               /* Adds the cells */
               let imgCell = row.insertCell(0);
               let hrefCell = row.insertCell(1);
               let fsCell = row.insertCell(2);
               let numRCell = row.insertCell(3);
               let numCCell = row.insertCell(4);
               let numPCell = row.insertCell(5);
               let numGCell = row.insertCell(6);

               /* Creates and adds an image */
               var img = document.createElement('img');
               img.src = imgLoc;
               img.height = 100;
               img.width = 100;
               imgCell.appendChild(img);
               
               /* Adds the file name href */
               let link = document.createElement('a');
               let linkText = document.createTextNode(data[i].fileName);
               link.appendChild(linkText);
               link.href = data[i].fileName;
               hrefCell.appendChild(link);

               /* Adds the file size -- currently hard coded -- */
               let fsElement = document.createElement('p');
               let fsText = document.createTextNode(data[i].fileSize);
               fsElement.appendChild(fsText);
               fsCell.appendChild(fsElement);

               /* Adds the number of rectangles */
               let numRElement = document.createElement('p');
               let numRText = document.createTextNode(data[i].numRect);
               numRElement.appendChild(numRText);
               numRCell.appendChild(numRElement);

               /* Adds the number of circles */
               let numCElement = document.createElement('p');
               let numCText = document.createTextNode(data[i].numCirc);
               numCElement.appendChild(numCText);
               numCCell.appendChild(numCElement);
                
               /* Adds the number of paths */
               let numPElement = document.createElement('p');
               let numPText = document.createTextNode(data[i].numPath);
               numPElement.appendChild(numPText);
               numPCell.appendChild(numPElement);

               /* Adds the number of paths */
               let numGElement = document.createElement('p');
               let numGText = document.createTextNode(data[i].numGroups);
               numGElement.appendChild(numGText);
               numGCell.appendChild(numGElement);

            } 

        },
        fail: function(error) {
            console.log("Error with uploading file names. ");
            console.log(error);
        }
    });
    
    // $.ajax({
    //     type: 'post',
    //     dataType: 'application/json',
    //     url: '/text',
    //     data: { 
    //         q: "test1212",
    //         q2: "test3443",
    //     },
    //     success: function (data) {
    //         console.log(data);
    //     },
    //     fail: function(error) {
    //         console.log("Error with uploading file names. ");
    //         console.log(error);
    //     }
    // });

    $.ajax({
        type: 'get',
        dataType: 'json',
        url: '/getSVGfiles',
        data: { 
            fileName: "rects.svg",
            desc: "desc-query",
            title: "title-query",
            paths: "paths-query",
            rects: "rects-query",
            groups: "groups-query",
            circles: "circles-query",
            rectsAttr: "rects-query",
            circsAttr: "circs-query",
            pathsAttr: "paths-query",
            groupsAttr: "groups-query",
        },
        success: function (data) {
            let fileNames = [];
            
            data.forEach(element => {
                fileNames.push(element.fileName);
            });
            
            addDropdownContent(fileNames);
            let test = listenDropDown(data);
            //listenShowAttributeDropDown();

        },
        fail: function(error) {
            console.log("Error with uploading file names. ");
            console.log(error);
        }
    });
    
    customizeButton();
    
    clsBtn = document.getElementById("cls-btn");
    openBtn = document.getElementById("open-button");
    

    openBtn.addEventListener("click", openForm);
    clsBtn .addEventListener("click", closeForm);

    function openForm() {
        document.getElementById("myForm").style.display = "block";
      }
      
    function closeForm() {
        document.getElementById("myForm").style.display = "none";
    }
    
    let submitBtn = document.getElementById("submit-btn");
    submitBtn.addEventListener("click", handleSubmit);

    function handleSubmit() {
        console.log("Submitted");
        let svgNameInput = document.getElementById("svgNameInput");
        let descriptionInput = document.getElementById("descriptionInput");
        let titleInput = document.getElementById("titleInput");
        $.ajax({
            type: 'post',
            dataType: 'application/json',
            url: '/text',
            data: { 
                name: String(svgNameInput.value),
                title: String(titleInput.value),
                description: String(descriptionInput.value),
            },
            success: function (data) {
                console.log(data);
            },
            fail: function(error) {
                console.log("Error with uploading file names. ");
                console.log(error);
            }
        });
        closeForm();
        window.location.reload();
    }
    function openForm2() {
        document.getElementById("myForm2").style.display = "block";
    }
    
    let openBtn2 = document.getElementById("open-button-2");
    openBtn2.addEventListener("click", openForm2);
    
    let submitBtn2 = document.getElementById("submit-btn-2");
    submitBtn2.addEventListener("click", handleSubmit2);

    function handleSubmit2() {
        console.log("Submitted");
        let xInput = document.getElementById("xInput");
        let yInput = document.getElementById("yInput");
        let hInput = document.getElementById("hInput");
        let wInput = document.getElementById("wInput");
        let uInput = document.getElementById("uInput");
        $.ajax({
            type: 'post',
            dataType: 'application/json',
            url: '/rectAdd',
            data: { 
                x: String(xInput.value),
                y: String(yInput.value),
                w: String(wInput.value),
                h: String(hInput.value),
                units: String(uInput.value),
                fname: String(global1),
            },
            success: function (data) {
                console.log(data);
            },
            fail: function(error) {
                console.log("Error with uploading file names. ");
                console.log(error);
            }
        });
        closeForm();
        window.location.reload();
    }

    // Event listener form example , we can use this instead explicitly listening for events
    // No redirects if possible
    $('#someform').submit(function(e){
        $('#blah').html("Form has data: "+$('#entryBox').val());
        e.preventDefault();
        //Pass data to the Ajax call, so it gets passed to the server
        $.ajax({
            //Create an object for connecting to another waypoint
        });
    });
    
    let f;
    document.getElementById('real-file-button').onchange = function () {
        f = this.value;
        f = f.replace(/.*[\/\\]/, '');
        console.log("Selected File " + f);
    };

});

function listenShowAttributeDropDown(data) {

    let anakinSkywalker;    
    document.getElementById("main-attribute-dropdown").addEventListener("click",function(e) {
        if(e.target && e.target.nodeName == "A") {
            let target = String(e.target.text);
            if (target[0] == 'R') {
                console.log("Inside R with file " + data.fileName);
                handleShowAttributes(target, data.rectsAttr);    
            }
            else if (target[0] == 'C') {
                console.log("Inside C with file " + data.fileName);
                handleShowAttributes(target, data.circsAttr);    
            }
            else if (target[0] == 'P') {
                console.log("Inside P with file " + data.fileName);
                handleShowAttributes(target, data.pathsAttr);    
            }
            else if (target[0] == 'G') {
                console.log("Inside G with file " + data.fileName);
                handleShowAttributes(target, data.groupsAttr);    
            }
        }
    });
}

function handleShowAttributes(targeted, data) {

    if (data.length == 0) {
        return;
    }
    let index = parseInt(targeted.charAt(targeted.length-1)) - 1;
    
    console.log();
    console.log("-----------------");
    console.log("INDEX :");
    console.log(index);
    console.log("DATA:");
    console.log(data);
    console.log("DATA INDEX :");
    console.log(data[index]);
    console.log("-----------------");
    console.log();
    
    let closeButton = document.querySelector(".close-button");
    //let modalDiv = document.querySelector(".myModal");
    let attrViewTable = document.getElementById("main-table");
    
    let newTable = document.createElement("table");
    newTable.id = "attribute-view-table";
    newTable.className = "attrViewTable";
    
    let newTableHead = document.createElement("thead");
    
    let newTr = document.createElement("tr");
    let newTh = document.createElement("th");
    let thText = document.createTextNode("Attributes");
    
    newTh.appendChild(thText);
    newTr.appendChild(newTh);
    newTableHead.appendChild(newTr);
    newTable.appendChild(newTableHead);


    for (let i = 0; i < data[index].length; i++) {
        let row = newTable.insertRow();
        let cell = row.insertCell(0);
        
        let attrDesc = document.createElement('p');
        let br = document.createElement('br');
        let attrDescTxt = document.createTextNode("Attribute Name: " + data[index][i].name);
        let attrDescTxt2 = document.createTextNode("Attribute Value: " + data[index][i].value);
        attrDesc.appendChild(attrDescTxt);
        attrDesc.appendChild(br);
        attrDesc.appendChild(attrDescTxt2);
        cell.appendChild(attrDesc);
    
    }
    
    attrViewTable.replaceChild(newTable, attrViewTable.childNodes[0]);

    toggleModal();
    closeButton.addEventListener("click", toggleModal);


}

function toggleModal() {
    let modalDiv = document.querySelector(".myModal");
    modalDiv.classList.toggle("show-modal");
}

function addDropdownContent(fileNames) {
    var myParent = document.getElementById("dropdownList");

    //Create and append select list
    var selectList = document.getElementById("mySelect");

    //Create and append the options
    for (var i = 0; i < fileNames.length; i++) {
        var option = document.createElement("option");
        //option.value = fileNames[i];
        option.text = fileNames[i];
        option.id = "option-" + fileNames[i];
        selectList.appendChild(option);
    }
}

var global1;

function listenDropDown(data) {
    document.getElementById('mySelect').addEventListener('change', warn, true);
    let anakinSkywalker;
    function warn(dropDown) {
        dropDown.preventDefault();
        dropDown.stopPropagation();
        
        anakinSkywalker = dropDown.currentTarget.value;
        for (let i = 0; i < data.length; i++) {
            if( data[i].fileName == anakinSkywalker) {
                console.log("The chosen one is " + data[i].fileName); 
                global1 = anakinSkywalker;
                populateSVGtable(data[i]);
                document.getElementById("main-attribute-dropdown").addEventListener("click",function(e) {
                    if(e.target && e.target.nodeName == "A") {
                        let target = String(e.target.text);
                        if ((target[0] == 'R') && (data[i].fileName === anakinSkywalker)) {
                            console.log("Inside R with file " + data[i].fileName);
                            handleShowAttributes(target, data[i].rectsAttr);    
                        }
                        else if ((target[0] == 'C') && (data[i].fileName === anakinSkywalker)) {
                            console.log("Inside C with file " + data[i].fileName);
                            handleShowAttributes(target, data[i].circsAttr);    
                        }
                        else if ((target[0] == 'P') && (data[i].fileName === anakinSkywalker)) {
                            console.log("Inside P with file " + data[i].fileName);
                            handleShowAttributes(target, data[i].pathsAttr);    
                        }
                        else if ((target[0] == 'G') && (data[i].fileName === anakinSkywalker)) {
                            console.log("Inside G with file " + data[i].fileName);
                            handleShowAttributes(target, data[i].groupsAttr);    
                        }
                    }
                })
            }
        }
    }
}


function populateSVGtable(data) {
    let imgLoc = "./uploads/" + data.fileName;
    
    /* Get the main table. */
    var mainTable = document.getElementById("mainSVGtable");

    /* Creates a new dynamic table */
    let table = document.createElement('table');
    table.id = 'svgViewerTable';
    table.className = 'svgViewer';
    
    let tableHead = table.createTHead();
    
    /* Creates the rows for the table headers. */
    let tr1 = document.createElement('tr');
    let tr2 = document.createElement('tr');
    let tr3 = document.createElement('tr');

    /* Creates the headers for the table */
    let thImageTitle = document.createElement('th');
    
    let thTitle = document.createElement('th');
    let thDescription = document.createElement('th');
    
    let thComponent = document.createElement('th');
    let thSummary = document.createElement('th');
    let thOthrAttr = document.createElement('th');

    /* Creates the text for table heads */
    let imageHead = document.createTextNode('Image View');
    
    let titleHead = document.createTextNode('Title');
    let descriptionHead = document.createTextNode('Description');

    let componentHead = document.createTextNode('Component');
    let summaryHead = document.createTextNode('Summary');
    let othrAttrHead = document.createTextNode('Other Attributes');
    
    
    /* Adds the header texts to headers. */
    thImageTitle.appendChild(imageHead);
    
    thTitle.appendChild(titleHead);
    thDescription.appendChild(descriptionHead);
    
    thComponent.appendChild(componentHead);
    thSummary.appendChild(summaryHead);
    thOthrAttr.appendChild(othrAttrHead);


    /* Adds the headers to header rows */
    tr1.appendChild(thImageTitle);
    
    tr2.appendChild(thTitle);
    tr2.appendChild(thDescription);
    
    tr3.appendChild(thComponent);
    tr3.appendChild(thSummary);
    tr3.appendChild(thOthrAttr);
    
    /* Adds the head rows to table head */
    tableHead.appendChild(tr1);
    tableHead.appendChild(tr2);
    tableHead.appendChild(tr3);
    
    /* Adds the table head to the table */
    table.appendChild(tableHead);
    
    /* Hides the default table */
    let defaultTable = document.getElementById("defaultTable")
    //defaultTable.style.visibility = "hidden"
    if (defaultTable != null) {
        defaultTable.remove();    
    }
    
    /* Replaces the child of the main table with the new dynamic table created. Adds it if none exist. */
    mainTable.replaceChild(table, mainTable.childNodes[0]);
    
    /* Populates the table added with the json data provided */     


    let row1 = table.insertRow(table.rows.length-2);
    let row2 = table.insertRow(table.rows.length-1);
    

    let imgCell = row1.insertCell(0);
    
    let titleCell = row2.insertCell(0);
    let descCell = row2.insertCell(1);

    var img = document.createElement('img');
    img.src = imgLoc;
    img.height = 200;
    img.width = 200;
    imgCell.appendChild(img);


    let titleElement = document.createElement('p');
    let titleText = document.createTextNode(data.title);
    titleElement.appendChild(titleText);
    titleCell.appendChild(titleElement);

    let descElement = document.createElement('p');
    let descText = document.createTextNode(data.desc);
    descElement.appendChild(descText);
    descCell.appendChild(descElement);

    
    let mainAttrDropDown = document.getElementById("main-attribute-dropdown")
    let curAttrDropDown = document.createElement("ul");
    
    addPaths(table, data , curAttrDropDown);
    addRects(table, data , curAttrDropDown);
    addGroups(table, data , curAttrDropDown);
    addCircles(table, data ,curAttrDropDown);
    
    mainAttrDropDown.innerHTML = curAttrDropDown.innerHTML;


}


function addCircles(table, data, curAttrDropDown) {
    
    for (let i = 0; i < data.circles.length; i++) {
        let row = table.insertRow(table.rows.length);
        
        let componentCell = row.insertCell(0);
        let summaryCell =  row.insertCell(1);
        let othrAttrCell = row.insertCell(2);

        
        let compElement = document.createElement('p');
        let compText = document.createTextNode("Circle " + (i+1));
        addToAttributeDropdown("Circle " + (i+1), curAttrDropDown);
        compElement.appendChild(compText);
        componentCell.appendChild(compElement);

        
        let summaryElement = document.createElement('p');
        let summaryText = document.createTextNode("x= " + data.circles[i].cx + data.circles[i].units + "  y = " + data.circles[i].cy + data.circles[i].units + "  Radius: "+ data.circles[i].r + data.circles[i].units );
        summaryElement.appendChild(summaryText);
        summaryCell.appendChild(summaryElement);

        
        let othrAttrElement = document.createElement('p');
        let othrAttrText = document.createTextNode(data.circles[i].numAttr);
        othrAttrElement.appendChild(othrAttrText);
        othrAttrCell.appendChild(othrAttrElement);
    }
    
}


function addRects(table, data, curAttrDropDown) {
    
    for (let i = 0; i < data.rects.length; i++) {
        let row = table.insertRow(table.rows.length);
        
        let componentCell = row.insertCell(0);
        let summaryCell =  row.insertCell(1);
        let othrAttrCell = row.insertCell(2);

        
        let compElement = document.createElement('p');
        let compText = document.createTextNode("Rectangle " + (i+1));
        addToAttributeDropdown("Rectangle " + (i+1), curAttrDropDown);
        compElement.appendChild(compText);
        componentCell.appendChild(compElement);

        
        let summaryElement = document.createElement('p');
        let summaryText = document.createTextNode("x= " + data.rects[i].x + data.rects[i].units+ 
        "  y= " + data.rects[i].y + data.rects[i].units + "   width: " + data.rects[i].w + "  height: " + data.rects[i].h);
        summaryElement.appendChild(summaryText);
        summaryCell.appendChild(summaryElement);

        
        let othrAttrElement = document.createElement('p');
        let othrAttrText = document.createTextNode(data.rects[i].numAttr);
        othrAttrElement.appendChild(othrAttrText);
        othrAttrCell.appendChild(othrAttrElement);

        
    }
    
}


function addGroups(table, data, curAttrDropDown) {
    
    for (let i = 0; i < data.groups.length; i++) {
        let row = table.insertRow(table.rows.length);
        
        let componentCell = row.insertCell(0);
        let summaryCell =  row.insertCell(1);
        let othrAttrCell = row.insertCell(2);

        
        let compElement = document.createElement('p');
        let compText = document.createTextNode("Group " + (i+1));
        addToAttributeDropdown("Group " + (i+1), curAttrDropDown);
        compElement.appendChild(compText);
        componentCell.appendChild(compElement);

        
        let summaryElement = document.createElement('p');
        let summaryText = document.createTextNode("Children : " + data.groups[i].children);
        summaryElement.appendChild(summaryText);
        summaryCell.appendChild(summaryElement);

        
        let othrAttrElement = document.createElement('p');
        let othrAttrText = document.createTextNode(data.groups[i].numAttr);
        othrAttrElement.appendChild(othrAttrText);
        othrAttrCell.appendChild(othrAttrElement);
    }
    
}


function addPaths(table, data, curAttrDropDown) {
    
    for (let i = 0; i < data.paths.length; i++) {
        let row = table.insertRow(table.rows.length);
        
        let componentCell = row.insertCell(0);
        let summaryCell =  row.insertCell(1);
        let othrAttrCell = row.insertCell(2);

        
        let compElement = document.createElement('p');
        let compText = document.createTextNode("Path " + (i+1));
        addToAttributeDropdown("Path " + (i+1), curAttrDropDown);
        compElement.appendChild(compText);
        componentCell.appendChild(compElement);

        
        let summaryElement = document.createElement('p');
        let summaryText = document.createTextNode("Data : " + data.paths[i].d);
        summaryElement.appendChild(summaryText);
        summaryCell.appendChild(summaryElement);

        
        let othrAttrElement = document.createElement('p');
        let othrAttrText = document.createTextNode(data.paths[i].numAttr);
        othrAttrElement.appendChild(othrAttrText);
        othrAttrCell.appendChild(othrAttrElement);
    }
    
}


function customizeButton(){
    const realUploadBtn = document.getElementById("real-upload-button");
    const customUploadBtn = document.getElementById("upload-button");

    customUploadBtn.addEventListener("click", function() {
        realUploadBtn.click();
    });
    
    const realFileBtn = document.getElementById("real-file-button");
    const customFileBtn = document.getElementById("file-button");

    customFileBtn.addEventListener("click", function() {
        realFileBtn.click();
    });

}

function addToAttributeDropdown(text, curAttrDropDown) {
    
    let attributeName = document.createElement("li");
    attributeName.setAttribute("role","presentation");

    let attributeNameA = document.createElement("a");
    attributeNameA.setAttribute("role","menuitem");
    attributeNameA.setAttribute("tabindex","-1");
    //attributeNameA.setAttribute("href","#");

    let attributeNameText = document.createTextNode(text);

    attributeNameA.appendChild(attributeNameText);
    attributeName.appendChild(attributeNameA);
    curAttrDropDown.appendChild(attributeName);

}

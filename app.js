'use strict'

// C library API
const ffi = require('ffi-napi');

// Express App (Routes)
const express = require("express");
const app     = express();
const path    = require("path");
const fileUpload = require('express-fileupload');

app.use(express.json())
app.use(fileUpload());
app.use(express.static(path.join(__dirname+'/uploads')));


// Minimization
const fs = require('fs');
const JavaScriptObfuscator = require('javascript-obfuscator');

// Important, pass in port as in `npm run dev 1234`, do not change
const portNum = process.argv[2];

// Send HTML at root, do not change
app.get('/',function(req,res){
  res.sendFile(path.join(__dirname+'/public/index.html'));
});

// Send Style, do not change
app.get('/style.css',function(req,res){
  //Feel free to change the contents of style.css to prettify your Web app
  res.sendFile(path.join(__dirname+'/public/style.css'));
});


/* 
TODO : Remove this when you figure out the error. 
*/
//app.get('/index.js',function(req,res){
//  res.sendFile(path.join(__dirname+'/public/index.js'));
//});

// Send obfuscated JS, do not change
app.get('/index.js',function(req,res){
  fs.readFile(path.join(__dirname+'/public/index.js'), 'utf8', function(err, contents) {
    const minimizedContents = JavaScriptObfuscator.obfuscate(contents, {compact: true, controlFlowFlattening: true});
    res.contentType('application/javascript');
    res.send(minimizedContents._obfuscatedCode);
  });
});


//Respond to POST requests that upload files to uploads/ directory
app.post('/upload', function(req, res) {
  if(!req.files) {
    return res.status(400).send('No files were uploaded.');
  }
 
  let uploadFile = req.files.uploadFile;
 
  // Use the mv() method to place the file somewhere on your server
  uploadFile.mv('uploads/' + uploadFile.name, function(err) {
    if(err) {
      return res.status(500).send(err);
    }

    res.redirect('/');
  });
});




//Respond to GET requests for files in the uploads/ directory
app.get('/uploads/:name', function(req , res){

  fs.stat('uploads/' + req.params.name, function(err, stat) {
    if(err == null) {
      res.sendFile(path.join(__dirname+'/uploads/' + req.params.name));
    } else {
      console.log('Error in file downloading route: '+err);
      res.send('');
    }
  });
});

//******************** Your code goes here ******************** 



/* Returns the file size of a given file in kilobytes. */
function getFileSize(fileName) {
  
  var fileStats = fs.statSync(fileName);
  
  var fileSizeInBytes = fileStats["size"];

  fileSizeInBytes = fileSizeInBytes / 1024;
  
  return Math.round(fileSizeInBytes);
}


let sharedLibrary = ffi.Library('./libsvgparse', {
    'svgFileToJSON': [ 'string', [ 'string' ] ],
    'getSVGFileDescription': [ 'string', [ 'string' ] ],
    'getSVGFileTitle': [ 'string', [ 'string' ] ],
    'fileNameToPathJSON' : [ 'string', [ 'string' ] ],
    'fileNameToRectJSON' : [ 'string', [ 'string' ] ],
    'fileNameToGroupJSON' : [ 'string', [ 'string' ] ],
    'fileNameToCircleJSON' : [ 'string', [ 'string' ] ],
    'fileNameToRectAttr' : [ 'string', [ 'string' ] ],
    'fileNameToCircAttr' : [ 'string', [ 'string' ] ],
    'fileNameToPathAttr' : [ 'string', [ 'string' ] ],
    'fileNameToGroupAttr' : [ 'string', [ 'string' ] ],
    'writeWithFileName' : [ 'string', [ 'string', 'string' ] ],
    'addARectToSVG' : [ 'string', [ 'string', 'string' ] ],
});


app.post('/rectAdd', function(req, res) {
  var output = {};
  
  req.on('data', function(data) {
    data = data.toString();
    data = data.split('&');
    for (var i = 0; i < data.length; i++) {
        var tokenizedData = data[i].split("=");
        output[tokenizedData[0]] = tokenizedData[1];
    }
    
    console.log(output.fname);
    
    let toCreate = {
      x: output.x,
      y: output.y,
      w: output.w,
      h: output.h,
      units: output.units,
    }
    
    toCreate = JSON.stringify(toCreate);
    
    console.log(toCreate);
    
    let fileName = "./uploads/" + output.fname;
    
    sharedLibrary.addARectToSVG(toCreate, fileName);

  })
  
  
  res.redirect('/');

});


app.post('/text', function(req, res) {
  var output = {};
  
  req.on('data', function(data) {
    data = data.toString();
    data = data.split('&');
    for (var i = 0; i < data.length; i++) {
        var tokenizedData = data[i].split("=");
        output[tokenizedData[0]] = tokenizedData[1];
    }
    
    let titleString = "";
    let tokenizedTitle = output.title.split("+");
    tokenizedTitle.forEach(element => {
      titleString = titleString + element + " ";
    });

    let descString = "";
    let tokenizedDesc = output.description.split("+");
    tokenizedDesc.forEach(element => {
      descString = descString + element + " ";
    });
    

    
    let toCreate = {
      title: titleString,
      descr: descString,
    }
    
    toCreate = JSON.stringify(toCreate);
    let fileName = "./uploads/" + output.name + ".svg";
    sharedLibrary.writeWithFileName(toCreate, fileName);

  })
  
  
  res.redirect('/');

});


app.get('/getSVGfiles', function(req, res){
  var jsonArr = [];

  let filePath;
  fs.readdirSync("./uploads/").forEach(file => {
    filePath = "./uploads/" + file;  

    let svgJSON = sharedLibrary.svgFileToJSON(filePath);
    
    let desc = sharedLibrary.getSVGFileDescription(filePath);
    let title = sharedLibrary.getSVGFileTitle(filePath);
    let paths = sharedLibrary.fileNameToPathJSON(filePath);
    let rects = sharedLibrary.fileNameToRectJSON(filePath);
    let groups = sharedLibrary.fileNameToGroupJSON(filePath);
    let circles = sharedLibrary.fileNameToCircleJSON(filePath);
    
    let rectAttributes = sharedLibrary.fileNameToRectAttr(filePath);
    let circAttributes = sharedLibrary.fileNameToCircAttr(filePath);
    let pathAttributes = sharedLibrary.fileNameToPathAttr(filePath);
    let groupAttributes = sharedLibrary.fileNameToGroupAttr(filePath);

    
    paths = JSON.parse(paths);
    rects = JSON.parse(rects);
    groups = JSON.parse(groups);
    circles = JSON.parse(circles);
    
    rectAttributes = JSON.parse(rectAttributes);
    circAttributes = JSON.parse(circAttributes);
    pathAttributes = JSON.parse(pathAttributes);
    groupAttributes = JSON.parse(groupAttributes);
    
    

    let fullJSON = {
      fileName: file,
      desc: desc.toString(),
      title: title.toString(),
      paths: paths,
      rects: rects,
      groups: groups,
      circles: circles,
      rectsAttr: rectAttributes,
      circsAttr: circAttributes,
      pathsAttr: pathAttributes,
      groupsAttr: groupAttributes
    };
  
    jsonArr.push(fullJSON);
  
  });
  
  // console.log("The data being sent is : ");
  // console.log(jsonArr);
  res.send(jsonArr);
  
});


app.get('/uploadedFiles', function(req, res){
  var jsonArr = [];

  let filePath;
  fs.readdirSync("./uploads/").forEach(file => {
    filePath = "./uploads/" + file;  

    let fileSize = getFileSize(filePath).toString(8) + "KB";

    let svgJSON = sharedLibrary.svgFileToJSON(filePath);
    
    let desc = sharedLibrary.getSVGFileDescription(filePath);
    
    //console.log(desc);
    

    svgJSON = JSON.parse(svgJSON);
    
    let fullJSON = {
      fileName: file,
      fileSize: fileSize,
      numRect: svgJSON.numRect,
      numCirc: svgJSON.numCirc,
      numPath: svgJSON.numPaths,
      numGroups: svgJSON.numGroups
    };
    
    jsonArr.push(fullJSON);
  
  });
  
  // console.log("The data being sent is : ");
  // console.log(jsonArr);

  res.send(jsonArr);
});



//Sample endpoint
app.get('/someendpoint', function(req , res){
  let retStr = req.query.name1 + " " + req.query.name2;
  
  res.send({
    foo: retStr
  });
});

app.listen(portNum);
console.log('Running app at localhost: ' + portNum);

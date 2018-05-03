/*
 * File........: hjp4lib.js
 * Created.....: 2000/04/11, Guido Krueger
 * Changed.....: 2007/10/28, Guido Krueger
 * Copyright...: (c) 2001,2007 Guido Krueger. All Rights Reserved.
 *
 * Permission to use, copy, modify, and distribute this
 * software and its documentation for NON-COMMERCIAL purposes
 * and without fee is hereby granted provided that this
 * copyright notice appears in all copies.
 *
 * THE AUTHOR MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE
 * SUITABILITY OF THE SOFTWARE, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
 * NON-INFRINGEMENT. THE AUTHOR SHALL NOT BE LIABLE FOR ANY
 * DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING, MODIFYING
 * OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 */
//-----------------------------------------------------------------------
//Global variables
//-----------------------------------------------------------------------
var isNS = (navigator.appName.toUpperCase().indexOf("NETSCAPE") != -1);
var isIE = (navigator.appName.toUpperCase().indexOf("MICROSOFT") != -1);
var jdkdocs = "file:///C|/jdk1.7/docs/";
var apidocs = "file:///C|/jdk1.7/docs/api/";
//---
//Nachfolgend ein Beispiel für UNIX-Systeme
//var jdkdocs = "file:///usr/local/jdk1.6/docs/";
//var apidocs = "file:///usr/local/jdk1.6/docs/api/";
//---
//Nachfolgend der direkte Link ins Internet
//var jdkdocs = "http://java.sun.com/javase/6/docs/";
//var apidocs = "http://java.sun.com/javase/6/docs/api/";
var keycodes = null;
var keylinks = null;

//-----------------------------------------------------------------------
//Function definitions
//-----------------------------------------------------------------------
/**
 * Jumps to the API doc of the given qualified class name.
 */
function getApiDoc(classname)
{
  return apidocs + classname.replace(/\./g, "/") + ".html";
}

/**
 * Jumps to the JDK doc index.
 */
function getDocIndex()
{
  return jdkdocs + "index.html";
}

/**
 * Jumps to the API doc index.
 */
function getApiIndex()
{
  return apidocs + "index.html";
}

/**
 * Creates the keycodes and keylinks arrays from the given definition
 * String and installs the onKbdEvent keyboard handler. keydef must have
 * the following format: "code1,dest1;code2,dest2;code3,dest3;...".
 */
function installKbdHandler(keydef)
{
  //define keycodes and keylinks
  keycodes = new Array();
  keylinks = new Array();
  var index = 0;
  var items = keydef.split(";");
  for (var i = 0; i < items.length; ++i) {
    var item = items[i].split(",");
    keycodes[index] = parseInt(item[0]);
    keylinks[index] = item[1];
    ++index;
  }
  //install handler
  if (isNS) {
    document.captureEvents(Event.KEYPRESS);
  }
  document.onkeypress = onKbdEvent;
}

/**
 * Keyboard handler that uses the keycodes and keylinks information
 * to jump to a certain destination based on the last key typed.
 */
function onKbdEvent(e)
{
  //get keycode
  var key = -1;
  if (isNS) {
    if (e.which != 0 && (typeof e.modifiers == "undefined" || e.modifiers == 0 || e.modifiers == 4)) {
      key = e.which;
    }
  }
  if (isIE) {
    e = window.event;
    if (!e.ctrlKey && !e.altKey && !e.shiftKey) {
      key = e.keyCode;
    }
    e.cancelBubble = true;
  }
  if (keycodes != null && keylinks != null) {
    for (var i = 0; i < keycodes.length; ++i) {
      if (key == keycodes[i]) {
        if (keylinks[i] == "APIDOCS") {
          window.location = getApiIndex();
        } else if (keylinks[i] == "JDKDOCS") {
          window.location = getDocIndex();
        } else {
          window.location = keylinks[i];
        }
        break;
      }
    }
  }
}

//-----------------------------------------------------------------------
//Body code
//-----------------------------------------------------------------------

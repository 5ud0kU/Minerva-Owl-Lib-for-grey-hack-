// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.1.9
//   ,|.

// Official Documentation : https://minervaowllib.com

//Prototype Header.
//This header should be placed in /lib , in fact this header is the core of the lib.
//This is where object are return when you want to create a new type of class.
//
//import_code("/lib/Prototype.h");
//
//myClass = new Prototype("sometype");
//print(typeof(myClass));

//Make a prototype of a map and create a class
//Out of it.
Prototype = function(x,y)
  _Prototype = {};
  _Prototype.prototype = y;
  _Prototype.prototype.classID = x;
  _Prototype.classID = x;
  return _Prototype;
end function

//Class create a class
Class = function(name,map)
    return @(new Prototype(name,map)).__isa;
end function

//Create an object from the given template
//using Prototype.
//Npc = Class("npc",{"name":"default"});

//npc = Class("npc",Npc.prototype);
//npc.name = "robocop";
//npc.health = 100;

//Here we can see that we can create multiple reuseble template to those
//prototype.All the derived from Classe.prototype will change dynamically
//over the script.Its like the cube you place in unity by rustic example.
//npc2 = new Npc.prototype;
//npc2.__isa.name = "overwrite Npc template with this";

//Pla = Class("npc",{"name":"default"});
//pla = Class("npc",Pla.prototype);
//pla.name = "notrobocop";

//print(Npc);
//print(npc);
//print(Pla);
//print(pla);

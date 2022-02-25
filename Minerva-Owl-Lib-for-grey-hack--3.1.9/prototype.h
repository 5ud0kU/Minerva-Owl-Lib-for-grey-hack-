// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.1.9
//   ,|.

// Official Documentation : https://minervaowllib.com

Prototype = function(x,y)
  _Prototype = {};
  _Prototype.prototype = y;
  _Prototype.prototype.classID = x;
  _Prototype.classID = x;
  return _Prototype;
end function

Class = function(name,map)
    return @(new Prototype(name,map)).__isa;
end function

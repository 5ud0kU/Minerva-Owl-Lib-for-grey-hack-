// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.1.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_String = Class("template",{});
_String.prototype.reserved_reverse_string = "";

_String.prototype.reverseString = function(x)
	if typeof(x) != "string" then return "error : reverse string -> x expected string.";
	string = [];
	for i in range(0,x.len -1)
		string.push(x[i]);
	end for
	string.reverse;
	String.reserved_reverse_string = string.join("");
	return String.reserved_reverse_string;
end function

_String.prototype.stringToDecimal = function(x)
	if typeof(x) != "string" then return "error : string to decimal -> x expected string.";
	decString = "";
	for i in range(0,x.len -1)
		decString = decString + code(x[i]);
		if i < x.len -1 then decString = decString + ":";
	end for
	return decString;
end function

_String.prototype.stringToHex = function(x)
	if typeof(x) != "string" then return "error : string to hex -> x expected string.";
	hexString = "";
	for i in range(0,x.len -1)
		hexString = hexString + Math.decimalToHex(code(x[i]),"");
		if i < x.len -1 then hexString = hexString + ":";
	end for
	return hexString;
end function

_String.prototype.stringToList = function(x)
	if typeof(x) != "string" then return "error : string to list -> x expected string.";
	list = [];
	for i in range(0,x.len -1)
		list.push(x[i]);
	end for
	return list;
end function

_String.prototype.cut = function(x,y)
	if typeof(x) != "string" then return "error : string cut -> x expected string.";
	if typeof(y) != "list" then return "error : string cut -> x expected vector2.";

	string = String.stringToList(x);
	part1 = [];
	part2 = [];
	for i in range(0,string.len -1)
		if i < y[0] then part1.push(string[i]);
		if i > y[1] then part2.push(string[i]);
	end for
	cutString = [part1.join(""),part2.join("")];

	return cutString;
end function

_String.prototype.replace = function(x,y,z)
	if typeof(x) != "string" then return "error : string replace -> x expected string.";
	if typeof(y) != "list" then return "error : string replace -> y expected string.";
	if typeof(z) != "string" then return "error : string replace -> z expected string.";

	string = String.stringToList(x);
	part1 = [];
	part2 = [];

	for i in range(0,string.len -1)
		if i < y[0] then part1.push(string[i]);
		if i > y[1] then part2.push(string[i]);
	end for
	newString = part1.join("") + z + part2.join("");

	return newString;
end function

String = new Class("String",_String.prototype).prototype;

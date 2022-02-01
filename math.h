// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.1.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Math = Class("template",{});
_Math.prototype.reserved_hex_string = "";
_Math.prototype.reserved_binary_string = "";

_Math.prototype.vector2 = function(x,y)
	if typeof(x) != "number" then return "error : vector2 -> x not a number.";
	if typeof(y) != "number" then return "error : vector2 -> y not a number.";
	return [x,y];
end function

_Math.prototype.vector3 = function(x,y,z)
	if typeof(x) != "number" then return "error : vector3 -> x not a number.";
	if typeof(y) != "number" then return "error : vector3 -> y not a number.";
	if typeof(z) != "number" then return "error : vector3 -> z not a number.";
	return [x,y,z];
end function

_Math.prototype.vector4 = function(x,y,z,w)
	if typeof(x) != "number" then return "error : vector4 -> x not a number.";
	if typeof(y) != "number" then return "error : vector4 -> y not a number.";
	if typeof(z) != "number" then return "error : vector4 -> z not a number.";
	if typeof(w) != "number" then return "error : vector4 -> w not a number.";
	return [x,y,z,w];
end function

_Math.prototype.decimalToHex = function(x,z)
	if typeof(x) != "number" then return "error : decimal to hex -> x not number.";

	remainder = x% 16;
	sum = x / 16;
	hex = z;

	if remainder == 10 then remainder = "A";
	if remainder == 11 then remainder = "B";
	if remainder == 12 then remainder = "C";
	if remainder == 13 then remainder = "D";
	if remainder == 14 then remainder = "E";
	if remainder == 15 then remainder = "F";

	hex = hex + str(remainder);
	if str(sum).indexOf(char(46)) != null then
		sum = str(sum).split(char(46))[0].to_int;
	end if

	if sum > 0 then
		Math.decimalToHex(sum,hex);
	else
		Math.reserved_hex_string = String.reverseString(hex);
	end if
	return Math.reserved_hex_string;
end function

_Math.prototype.percent = function(x,y)
	if typeof(x) != "number" then return "error : pourcent -> x expected int.";
	if typeof(x) != "number" then return "error : pourcent -> y expected int.";
	percent = (x/y) * 100;
	return percent;
end function

_Math.prototype.median = function(x)
	if typeof(x) != "list" then return "error : median -> x expected list.";
	n = x.len;
	median = x[(n + 1)/2];
	return median;
end function

_Math.prototype.average = function(x)
	if typeof(x) != "list" then return "error : average -> x list expected.";
	sum = 0;
	elements = 0;
	for i in range(0,x.len -1)
		if typeof(x[i]) != "number" then return "error :  average -> x[i] expected integer.";
		sum = sum + x[i];
		elements = elements + 1;
	end for

	average = sum/elements;
	return average;
end function

_Math.prototype.decimalToBinary = function(x,y)
	if typeof(x) != "number" then return "error : decimal to binary -> x int expected.";

	remainder = x% 2;
	sum = x / 2;
	binary = y;

	binary = binary + str(remainder);
	if str(sum).indexOf(char(46)) != null then
		sum = str(sum).split(char(46))[0].to_int;
	end if

	if sum == 1 or sum == 0 then
		if sum == 0 then binary = binary + "0";
		if sum == 1 then binary = binary + "1";
		Math.reserved_binary_string = String.reverseString(binary).to_int;
		return Math.reserved_binary_string;
	else
		return Math.decimalToBinary(sum,binary);
	end if
end function

_Math.prototype.binaryToDecimal = function(x)
	bin = str(x);
	sum = 0;
	for i in range(0,bin.len -1)
		sum = (sum * 2) + bin[i].to_int;
	end for
	return sum;
end function

Math = new Class("Math",_Math.prototype).prototype;

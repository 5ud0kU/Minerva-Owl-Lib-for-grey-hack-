// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.1.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Algo = Class("template",{});

_Algo.prototype.swap = function(x)
	if typeof(x) != "list" then return "error : swap -> x list expected.";
	if x.len != 2 then return "error : swap -> x len 2 expected.";
	a = x[0];
	b = x[1];
	x[0] = b;
	x[1] = a;
	return x;
end function

_Algo.prototype.compare = function(x,y)
	if x > y then return ">"; //62
	if x < y then return "<"; //60
	if x == y then return "=="; //61
end function

_Algo.prototype.max = function(x)
	if typeof(x) != "list" then return "error : max -> x list expected."
	if x.len != 2 then return "error : max -> x len 2 expected."
	if typeof(x[0]) == "number" and typeof(x[1]) == "number" then
		max = Algo.compare(x[0],x[1]);
		if max == ">" or max == "==" then return x[0];
		if max == "<" then return x[1];
	else if typeof(x[0]) == "string" and typeof(x[1]) == "number" then
		max = Algo.compare(code(x[0]),x[1]);
		if max == ">" or max == "==" then return x[0];
		if max == "<" then return x[1];
	else if typeof(x[0]) == "number" and typeof(x[1]) == "string" then
		max = Algo.compare(x[0],code(x[1]));
		if max == ">" or max == "==" then return x[0];
		if max == "<" then return x[1];
	else if typeof(x[0]) == "string" and typeof(x[1]) == "string" then
		max = Algo.compare(code(x[0]),code(x[1]));
		if max == ">" or max == "==" then return x[0];
		if max == "<" then return x[1];
	end if
	return;
end function

_Algo.prototype.min = function(x)
	if typeof(x) != "list" then return "error : min -> x list expected.";
	if x.len != 2 then return "error : min -> x len 2 expected.";
	if typeof(x[0]) == "number" and typeof(x[1]) == "number" then
		min = Algo.compare(x[0],x[1]);
		if min == ">" or min == "==" then return x[1];
		if min == "<" then return x[0];
	else if typeof(x[0]) == "string" and typeof(x[1]) == "number" then
		min = Algo.compare(code(x[0]),x[1]);
		if min == ">" or min == "==" then return x[1];
		if min == "<" then return x[0];
	else if typeof(x[0]) == "number" and typeof(x[1]) == "string" then
		min = Algo.compare(x[0],code(x[1]));
		if min == ">" or min == "==" then return x[1];
		if min == "<" then return x[0];
	else if typeof(x[0]) == "string" and typeof(x[1]) == "string" then
		min = Algo.compare(code(x[0]),code(x[1]));
		if min == ">" or min == "==" then return x[1];
		if min == "<" then return x[0];
	end if
	return;
end function

_Algo.prototype.permute = function(x,y);
	if typeof(x) != "string" then return "error : permute -> x string expected.";
	if typeof(y) != "list" then return "error : permute -> y list expected.";

	s0 = String.stringToList(x);
	s1 = s0[0];
	s2 = s0[1:s0.len].join("");

	swap = Algo.swap([s1,s2]).join("");
	revs = String.reverseString(swap);

	y.push(swap);
	y.push(revs);

	if y.indexOf(y[0],1) != null then return y[1:y.len -1];
	if y.indexOf(y[0],1) == null then return Algo.permute(swap,y);
end function

Algo = new Class("Algo",_Algo.prototype).prototype;

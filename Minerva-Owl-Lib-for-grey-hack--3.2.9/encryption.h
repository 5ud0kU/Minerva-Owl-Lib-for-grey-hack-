// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.2.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Encryption = Class("template",{});

_Encryption.prototype.rot13 = function(x)
	if typeof(x) != "string" then return "error : rot13 -> x expected a string.";
	if x.len < 0 then return "error : rot13 -> x string is empty.";
	chars = String.stringToList(x);
	for i in range(0,chars.len -1)
		if code(chars[i]) >= 65 and code(chars[i]) <= 90 then
			chars[i] = char(65 + (code(chars[i]) - 65+13)%26);
		else if code(chars[i]) >= 97 and code(chars[i]) <= 122 then
			chars[i] = char(97 + (code(chars[i]) - 97+13)%26);
		end if
	end for
	return chars.join("");
end function

_Encryption.prototype.caesar = function(x,y)
	if typeof(x) != "string" then return "error : caesar -> x expected a string.";
	if typeof(y) != "number" then return "error : caesar -> y expected a number.";
	if x.len < 0 then return "error : caesar -> x string is empty.";
	chars = String.stringToList(x);
	for i in range(0,chars.len -1)
		if code(chars[i]) >= 65 and code(chars[i]) <= 90 then
			chars[i] = char(65 + (code(chars[i]) - 65+y)%26);
		else if code(chars[i]) >= 97 and code(chars[i]) <= 122 then
			chars[i] = char(97 + (code(chars[i]) - 97+y)%26);
		end if
	end for
	return chars.join("");
end function

_Encryption.prototype.byteSwap = function(x)
	if typeof(x) != "string" then return "error : byteSwap -> x expected a string.";
	if x.len < 0 then return "error : byteSwap -> x string is empty.";
	byteString = String.stringToDecimal(x);
	bytes = [];

	byte = "";
	for i in  range(0,byteString.len -1)
		if byteString[i] == ":" then
			bin = Math.decimalToBinary(byte.to_int,"");
			bytes.push(bin);
			byte = "";
		else
			byte = byte + byteString[i];
			if i == byteString.len -1 then
				bin = Math.decimalToBinary(byte.to_int,"");
				bytes.push(bin);
				byte = "";
			end if
		end if
	end for

	for i in range(0,bytes.len -1)
		byte = str(bytes[i]);
		if byte.len < 7 then
			bytes[i] = "00" + str(byte);
		else if byte.len == 7 then
			bytes[i] = "0" + str(byte);
		end if
	end for

	for i in range(0,bytes.len -1)
		bin = [];
		set = "";
		for e in range(0,str(bytes[i]).len -1)
			set = set + str(bytes[i])[e];
			if set.len == 2 then
				newByte = Algo.swap([set[0],set[1]]);
				newByte = newByte[0] + newByte[1];
				bin.push(newByte);
				set = "";
			end if

			if e == str(bytes[i]).len -1 then
				bytes[i] = bin.join("");
			end if
		end for
	end for

	decString = [];
	for i in range(0,bytes.len -1)
		decString.push(Math.binaryToDecimal(bytes[i]));
	end for

	string = ""
	for i in range(0,decString.len -1)
		string = string + char(decString[i]);
	end for

	return string;
end function

Encryption = new Class("Encryption",_Encryption.prototype).prototype;

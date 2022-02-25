// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.1.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Meta = Class("template",{});

_Meta.prototype.dump = function(x,y)
	m = @Libs.metaxploit
	if typeof(y) != "number" then return "error : dump -> y expected number.";
	target = m.net_use(x,y);
	if typeof(target) != "NetSession" then return "error : dump -> net session failed.";
	if typeof(Libs.metaxploit) != "MetaxploitLib" then return "error : dump metaxploit not found in /lib";
	target_lib = target.dump_lib;
	target_scan = m.scan(target_lib);
	target_exploits = [];
	for i in range(0,target_scan.len -1)
		target_exploits.push({"mem":target_scan[i],"cve":m.scan_address(target_lib,target_scan[i])});
	end for
	return target_exploits;
end function

_Meta.prototype.decrypt = function(x)
	c = @Libs.crypto;
	password = c.decipher(x.split(char(58))[1]);
	return password;
end function

Meta = new Class("Meta",_Meta.prototype).prototype;

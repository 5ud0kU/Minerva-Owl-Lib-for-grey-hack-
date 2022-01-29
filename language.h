// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.1.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Language = Class("template",{});

_Language.prototype.localization = function(locapath)
	config = get_shell.host_computer.File(locapath);
	if typeof(config) != "file" then return "Could not read '" + locapath + "' eval(file)";
	if config.get_content.len < 0 then return false;

	//Getting the localizators - example of a peace of file format.
	//spanish;french;english;myowninvented
	//juego;jeu;game;engio
	//krita;kri;krite;fwer

	data = config.get_content.split(char(10));
	localizators = data[0].split(";");
	if localizators.len < 1 then return false;

	dict = [];

	for i in range(1,data.len -1)
		//get the variant string - 'juego;jeu;game;engio'
		variant_string = data[i].split(";");
		if data[i].len < 1 then return false;

		//if the variant string contain only the tag
		//then add undefined value for each localizators
		if data[i].len == 1 then
			for e in range(0,localizators.len -1)
				variant_string.push("undefined");
			end for
		end if

		//assemble the dictionnary
		map = {"word":variant_string[0],"dict":[]};

		for e in range(0,variant_string.len -1)
				if e > localizators.len then return "Cannot parse -> '" + dictpath + "' eval(file)";
				map.dict.push({localizators[e]:variant_string[e]});
		end for

		dict.push(map);
	end for

	return dict;
end function

_Language.prototype.trad = function(wor,lan,dic)
	for i in range(0,dic.len -1)
		if dic[i].word == wor then
			for e in range(0,dic[i].dict.len -1)
				map = dic[i].dict[e];
				if map.hasIndex(lan) == true then
					return map[lan];
				end if
			end for
		end if
	end for
	return "undefined.";
end function

Language = new Class("Language",_Language.prototype).prototype;

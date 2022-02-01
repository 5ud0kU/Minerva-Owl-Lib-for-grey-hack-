// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.1.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_FileSystem = Class("template",{});
_FileSystem.prototype.reserved_stream = {"read":false,"write":false,"file":""};

_FileSystem.prototype.stream = function(x,y)
	if FileSystem.reserved_stream.read == false and FileSystem.reserved_stream.write == false then
		if x == "out" then FileSystem.reserved_stream.write = true;
		if x == "in" then FileSystem.reserved_stream.read = true;
		if FileSystem.reserved_stream.read == false and FileSystem.reserved_stream.write == false then return "error : stream unknown type , available in or out.";
		FileSystem.reserved_stream.file = get_shell.host_computer.File(y);
		if typeof(FileSystem.reserved_stream.file) != "file" then
			if y.indexOf(char(47)) == null then
				get_shell.host_computer.touch(current_path,y);
			else
				directory = "/" + y.split(char(47))[1:y.split(char(47)).len - 1].join(char(47));
				filename = y.split(char(47))[y.split(char(47)).len - 1];
				get_shell.host_computer.touch(directory,filename);
			end if
			if typeof(get_shell.host_computer.File(y)) != "file" then return "error : stream file -> y was unable to create the file.";
			if typeof(get_shell.host_computer.File(y)) == "file" then FileSystem.reserved_stream.file = get_shell.host_computer.File(y);
		end if
		return;
	else
		return "Buffer in use.";
	end if
end function

_FileSystem.prototype.write = function(x)
	if FileSystem.reserved_stream.write == true then
		if typeof(FileSystem.reserved_stream.file) != "file" then return "error : write -> file not exist";
		FileSystem.reserved_stream.file.set_content(x);
		return;
	else
		return "Buffer currently closed.";
	end if
end function

_FileSystem.prototype.read = function()
	if FileSystem.reserved_stream.read == true then
		if typeof(FileSystem.reserved_stream.file) != "file" then return "error : write -> file not exist";
		return FileSystem.reserved_stream.file.get_content;
	else
		return "Buffer currently closed.";
	end if
end function

_FileSystem.prototype.flush = function()
	FileSystem.reserved_stream.read = false;
	FileSystem.reserved_stream.write = false;
	FileSystem.reserved_stream.file = "";
end function

FileSystem = new Class("FileSystem",_FileSystem.prototype).prototype;

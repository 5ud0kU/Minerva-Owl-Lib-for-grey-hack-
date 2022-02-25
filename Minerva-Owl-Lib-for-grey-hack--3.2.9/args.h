// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.2.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Args = Class("template",{});

_Args.prototype.dictionnary = function(dictpath)
  config = get_shell.host_computer.File(dictpath);
  if typeof(config) != "file" then return "Could not read -> '" + dictpath + "' eval(file)";
  if config.get_content.len < 1 then return false;

  //arg1-2 -> e.g "mycommand -args1 1 2"
  data = config.get_content.split(";");
  elements = [];

  for i in range(0,data.len -1)
    argstring = data[i].split("-");
    if argstring.len != 2 then return str("Could not parse -> " + argstring.join("") + " in eval(list)");
    if typeof(argstring[1].to_int) != "number" then str("Could not parse -> " + argstring[1].join("") + " : eval(number)");
    arg = "-" + argstring[0];
    argchilds = argstring[1];
    elements.push({"arg":arg,"childs":argchilds.to_int});
  end for

  return elements;
end function

_Args.prototype.eval = function(cmap,dictpath)
  if typeof(cmap) != "map" then return "error : eval -> cmap expected a map.";
  if typeof(dictpath) != "string" then return "error eval -> dictpath expected a string.";
  if cmap.len < 1 then return "error : eval -> cmap is empty.";
  if dictpath.len < 1 then return "error : eval -> dictpath is empty."
  isValid = false;
  errors = [];
  for i in range(0,cmap.len -1)
    for e in range(0,Args.dictionnary(dictpath).len -1)
      template = Args.dictionnary(dictpath)[e];
      command = cmap[i];

      if template.arg == command.arg then
        if template.childs == command.childs.len then
          isValid = true;
          break;
        end if
      end if

    end for

    if isValid == true then
      isValid = false;
    else
      errors.push(str("args.eval(invalid parameter : + " + cmap[i].arg + ")"));
    end if
  end for
  if errors.len > 0 then return errors;
  if errors.len == 0 then return true;
end function

_Args.prototype.parse = function(command,dictpath)
  if typeof(command) != "string" then return "error : parse -> command expected string.";
  if typeof(dictpath) != "string" then return "error : parse -> dictpath expected string.";
  if command.len < 1 then return "error : parse -> command is empty.";
  if dictpath.len < 1 then return "error : parse -> dictpath is empty.";
  cmap = [];

  //building the received line into a index map.
  command = command.split(" ");
  for i in range(0,command.len -1)
    if command[i][0] == "-" then
      map = {"arg":command[i],"childs":[]};
      for e in range(i,command.len -1)
        if e != i then
          if command[e][0] == "-" then break;
          map.childs.push(command[e]);
        end if
      end for
      cmap.push(map);
    end if
  end for

  //looking if theres error in the command line received by using
  //a dictionnary of templates.
  evaluation = Args.eval(cmap,dictpath);
	if cmap.len == 0 then return "unrecognize input.";
  if evaluation == true then return cmap;
  return evaluation;
end function

Args = new Class("Args",_Args.prototype).prototype;

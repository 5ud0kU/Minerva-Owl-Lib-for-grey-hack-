// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.2.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Libs = Class("template",{});
_Libs.prototype.metaxploit = "";
_Libs.prototype.crypto = "";
_Libs.prototype.aptclient = "";
_Libs.prototype.load_dependencies = function()
  libFolder = get_shell.host_computer.File("/lib");
  if typeof(libFolder) == "file" then
    files = libFolder.get_files;
    if files.len > 0 then
      for i in range(0,files.len -1)
        if files[i].name == "metaxploit.so" then
          Libs.metaxploit = include_lib(files[i].path);
        else if files[i].name == "crypto.so" then
          Libs.crypto = include_lib(files[i].path);
        else if files[i].name == "aptclient.so" then
          Libs.aptclient = include_lib(files[i].path);
        end if
      end for
    end if
  end if
end function

Libs = new Class("Libs",_Libs.prototype).prototype;

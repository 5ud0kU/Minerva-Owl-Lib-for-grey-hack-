// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.2.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Key = Class("template",{});

_Key.prototype.Backspace = {"KeyCode":8,"name":"Backspace"};
_Key.prototype.Tab = {"KeyCode":9,"name":"Tab"};
_Key.prototype.Enter = {"KeyCode":13,"name":"Enter"};
_Key.prototype.Shift = {"KeyCode":16,"name":"Shift"};
_Key.prototype.Ctrl = {"KeyCode":17,"name":"Ctrl"};
_Key.prototype.Alt = {"KeyCode":18,"name":"Alt"};
_Key.prototype.CapsLock = {"KeyCode":20,"name":"CapsLock"};
_Key.prototype.Escape = {"KeyCode":27,"name":"Escape"};
_Key.prototype.PageUp = {"KeyCode":33,"name":"PageUp"};
_Key.prototype.PageDown = {"KeyCode":34,"name":"PageDown"};
_Key.prototype.End = {"KeyCode":35,"name":"End"};
_Key.prototype.Home = {"KeyCode":36,"name":"Home"};
_Key.prototype.LeftArrow = {"KeyCode":37,"name":"LeftArrow"};
_Key.prototype.UpArrow = {"KeyCode":38,"name":"UpArrow"};
_Key.prototype.RightArrow = {"KeyCode":39,"name":"RightArrow"};
_Key.prototype.DownArrow = {"KeyCode":40,"name":"DownArrow"};
_Key.prototype.Insert = {"KeyCode":45,"name":"Insert"};
_Key.prototype.Delete = {"KeyCode":46,"name":"Delete"};
_Key.prototype._0 = {"KeyCode":48,"name":"0"};
_Key.prototype._1 = {"KeyCode":49,"name":"1"};
_Key.prototype._2 = {"KeyCode":50,"name":"2"};
_Key.prototype._3 = {"KeyCode":51,"name":"3"};
_Key.prototype._4 = {"KeyCode":52,"name":"4"};
_Key.prototype._5 = {"KeyCode":53,"name":"5"};
_Key.prototype._6 = {"KeyCode":54,"name":"6"};
_Key.prototype._7 = {"KeyCode":55,"name":"7"};
_Key.prototype._8 = {"KeyCode":56,"name":"8"};
_Key.prototype._9 = {"KeyCode":57,"name":"9"};
_Key.prototype.A = {"KeyCode":65,"name":"a"};
_Key.prototype.B = {"KeyCode":66,"name":"b"};
_Key.prototype.C = {"KeyCode":67,"name":"c"};
_Key.prototype.D = {"KeyCode":68,"name":"d"};
_Key.prototype.E = {"KeyCode":69,"name":"e"};
_Key.prototype.F = {"KeyCode":70,"name":"f"};
_Key.prototype.G = {"KeyCode":71,"name":"g"};
_Key.prototype.H = {"KeyCode":72,"name":"h"};
_Key.prototype.I = {"KeyCode":73,"name":"i"};
_Key.prototype.J = {"KeyCode":74,"name":"j"};
_Key.prototype.K = {"KeyCode":75,"name":"k"};
_Key.prototype.L = {"KeyCode":76,"name":"l"};
_Key.prototype.M = {"KeyCode":77,"name":"m"};
_Key.prototype.N = {"KeyCode":78,"name":"n"};
_Key.prototype.O = {"KeyCode":79,"name":"o"};
_Key.prototype.P = {"KeyCode":80,"name":"p"};
_Key.prototype.Q = {"KeyCode":81,"name":"q"};
_Key.prototype.R = {"KeyCode":82,"name":"r"};
_Key.prototype.S = {"KeyCode":83,"name":"s"};
_Key.prototype.T = {"KeyCode":84,"name":"t"};
_Key.prototype.U = {"KeyCode":85,"name":"u"};
_Key.prototype.V = {"KeyCode":86,"name":"v"};
_Key.prototype.W = {"KeyCode":87,"name":"w"};
_Key.prototype.X = {"KeyCode":88,"name":"x"};
_Key.prototype.Y = {"KeyCode":89,"name":"y"};
_Key.prototype.Z = {"KeyCode":90,"name":"z"};
_Key.prototype.Num0 = {"KeyCode":96,"name":"0"};
_Key.prototype.Num1 = {"KeyCode":97,"name":"1"};
_Key.prototype.Num2 = {"KeyCode":98,"name":"2"};
_Key.prototype.Num3 = {"KeyCode":99,"name":"3"};
_Key.prototype.Num4 = {"KeyCode":100,"name":"4"};
_Key.prototype.Num5 = {"KeyCode":101,"name":"5"};
_Key.prototype.Num6 = {"KeyCode":102,"name":"6"};
_Key.prototype.Num7 = {"KeyCode":103,"name":"7"};
_Key.prototype.Num8 = {"KeyCode":104,"name":"8"};
_Key.prototype.Num9 = {"KeyCode":105,"name":"9"};
_Key.prototype.Multiply = {"KeyCode":106,"name":"*"};
_Key.prototype.Addition = {"KeyCode":107,"name":"+"};
_Key.prototype.Substract = {"KeyCode":109,"name":"-"};
_Key.prototype.DecimalPoint = {"KeyCode":110,"name":"."};
_Key.prototype.Divide = {"KeyCode":111,"name":"/"};
_Key.prototype.f1 = {"KeyCode":112,"name":"f1"};
_Key.prototype.f2 = {"KeyCode":113,"name":"f2"};
_Key.prototype.f3 = {"KeyCode":114,"name":"f3"};
_Key.prototype.f4 = {"KeyCode":115,"name":"f4"};
_Key.prototype.f5 = {"KeyCode":116,"name":"f5"};
_Key.prototype.f6 = {"KeyCode":117,"name":"f6"};
_Key.prototype.f7 = {"KeyCode":118,"name":"f7"};
_Key.prototype.f8 = {"KeyCode":119,"name":"f8"};
_Key.prototype.f9 = {"KeyCode":120,"name":"f9"};
_Key.prototype.f10 = {"KeyCode":121,"name":"f10"};
_Key.prototype.f11 = {"KeyCode":122,"name":"f11"};
_Key.prototype.f12 = {"KeyCode":123,"name":"f12"};
_Key.prototype.NumLock = {"KeyCode":145,"name":"NumLock"};
_Key.prototype.SemiColon = {"KeyCode":186,"name":"SemiColon"};
_Key.prototype.EqualSign = {"KeyCode":187,"name":"EqualSign"};
_Key.prototype.Comma = {"KeyCode":188,"name":"Comma"};
_Key.prototype.Dash = {"KeyCode":189,"name":"Period"};
_Key.prototype.Period = {"KeyCode":190,"name":"Period"};
_Key.prototype.ForwardSlash = {"KeyCode":191,"name":"ForwardSlash"};
_Key.prototype.GraveAccent = {"KeyCode":192,"name":"GraveAccent"};
_Key.prototype.OpenBracket = {"KeyCode":219,"name":"OpenBracket"};
_Key.prototype.BackSlash = {"KeyCode":220,"name":"BackSlash"};
_Key.prototype.CloseBracket = {"KeyCode":221,"name":"CloseBracket"};
_Key.prototype.SingleQuote = {"KeyCode":222,"name":"SingleQuote"};

_Key.prototype.awaitKey = function(curt)
	if typeof(curt) != "string" then return "error : curt expected a string.";
	x = user_input(curt,false,true);
	return x;
end function

_Key.prototype.compare = function(key, x)
	if typeof(x) != "string" then return "error : compare -> x expected a string.";
	if x.len < 0 then return "error : compare -> x string is empty.";
	if typeof(key) != "string" then return "error : compare -> key expected a string.";
	if key.len < 0 then return "error : compare -> key string is empty.";

	if Key[key].name == x then return true;
	if Key[key].name != x then return false;
end function

Key = new Class("Key",_Key.prototype).prototype;

// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.1.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Graph = Class("Graph",{});
_Graph.prototype.reserved_hex_tag = "";
_Graph.prototype.reserved_video_buffer = {"queud":[],"lastFrame":""};
_Graph.prototype.reserved_video_display = {"grid":[8,8],"content":[],"bg":"<mark=#000000>x</mark>","rate":0.6}; //default 8x8
_Graph.prototype.reserved_video_switch = true;

_Graph.prototype.rgb = function(x)
	if typeof(x) != "list" then return "error : rgb -> x expected list.";
	if x.len != 3 then return "error : rgb -> x expected 3 len."
	hexTag = "";
	for i in range(0,x.len -1)
		if typeof(x[i]) != "number" then return "error : rgb -> x[i] not a number"
		hexTag = hexTag + Math.decimalToHex(x[i],"");
	end for

	if hexTag.len < 6 then
		hexTag = "#0" + hexTag;
	else
		hexTag = "#" + hexTag;
	end if

	Graph.reserved_hex_tag = hexTag;
	return Graph.reserved_hex_tag;
end function

_Graph.prototype.color = function(x,y)
	color = "<color=" + y + ">" + x + "</color>";
	return color;
end function

_Graph.prototype.Size = function(x,y)
	if typeof(y) != "number" then return "error : size y not a number.";
	return "<size=" + y + ">" + x + "</size>";
end function

_Graph.prototype.italic = function(x)
	italic = "<i>" + x + "</i>";
	return italic;
end function

_Graph.prototype.bold = function(x)
	bold = "<b>" + x + "</b>";
	return bold;
end function

_Graph.prototype.underline = function(x)
	return "<u>" + x + "</u>";
end function

_Graph.prototype.drawLine = function(x,y)
	if typeof(x) != "string" then return "error : draw line -> x expected string.";
	if typeof(y) != "number" then return "error : draw line -> y expected int.";
	for i in range(1,y)
		x = x + char(95);
	end for
	return Graph.underline(x) ;
end function

_Graph.prototype.align = function(x,y)
	if y != "center" and y != "right" and y != "left" then return "error : align -> y expected left,right or center.";
	return "<align=" + y + ">" + x + "</align>";
end function

_Graph.prototype.spacing = function(x,y)
	return "<cspace=" + y + ">" + x + "</cspace>";
end function

_Graph.prototype.font = function(x,y)
	return "<font=" + y + ">" + x + "</font>";
end function

_Graph.prototype.indent = function(x,y)
	return "<indent=" + y + ">" + x + "</indent>";
end function

_Graph.prototype.margin = function(x,y)
	return "<margin=" + y + ">" + x + "</margin>";
end function

_Graph.prototype.mark = function(x,y)
	return "<mark=" + y + ">" + x + "</mark>";
end function

_Graph.prototype.sprite = function(x)
	return "<sprite=" + x + ">";
end function

_Graph.prototype.strike = function(x)
	return "<s>" + x + "</s>";
end function

_Graph.prototype.videoEngine = function(buf,dis)
	clear_screen;
	while (Graph.reserved_video_buffer.queud.len != 0)
		if Graph.reserved_video_display.content.len == 0 then
			yaxis = [];
			for i in range(1,Graph.reserved_video_display.grid[0])
				xaxis = [];
				for e in range(1,Graph.reserved_video_display.grid[1])
					xaxis.push((Graph.reserved_video_display.bg));
				end for
				yaxis.push(xaxis);
			end for
			Graph.reserved_video_display.content = yaxis;
		end if

		Graph.reserved_video_display.content[Graph.reserved_video_buffer.queud[0].position[0] -1][Graph.reserved_video_buffer.queud[0].position[1] -1] = Graph.reserved_video_buffer.queud[0].value;
		frame = "";
		for i in range(0,Graph.reserved_video_display.content.len -1)
			for e in range(0,Graph.reserved_video_display.content[i].len -1)
				if Graph.reserved_video_display.content[i][e] == "" then Graph.reserved_video_display.content[i][e] = Graph.reserved_video_display.bg;
			end for
			frame = frame + char(10) + Graph.reserved_video_display.content[i].join("");
		end for
		if Graph.reserved_video_buffer.queud.len == 1 then
			Graph.reserved_video_buffer.lastFrame = frame;
			print(frame);
			wait(Graph.reserved_video_display.rate);
		end if
		Graph.reserved_video_buffer.queud.remove(0);
	end while
	return;
end function

_Graph.prototype.animator = function(x)
	for i in range(0,x.len -1)
		Graph.reserved_video_buffer.queud.push(x[i]);
	end for
	return Graph.videoEngine(Graph.reserved_video_buffer,Graph.reserved_video_display);
end function

_Graph.prototype.animationPart = function(x,y)
	if typeof(x) != "string" then return "error : animation part -> x expected string.";
	if typeof(y) != "list" then return "error : animation part -> y expected number.";
	animationString = {};
	animationString.value = x;
	animationString.position = y;
	return animationString;
end function

_Graph.prototype.displayFlush = function()
	Graph.reserved_video_display.content = [];
	return;
end function

_Graph.prototype.bgColor = function(x)
	Graph.reserved_video_display.bg = "<mark=" + x + ">x</mark>";
	return;
end function

_Graph.prototype.displayResolution = function(x,y)
	if typeof(x) != "number" then return "error : display resolution -> x expected number.";
	if typeof(y) != "number" then return "error : display resolution -> y expected number.";
	Graph.reserved_video_display.grid[0] = x;
	Graph.reserved_video_display.grid[1] = y;
	return;
end function

_Graph.prototype.lastFrame = function()
	return Graph.reserved_video_buffer.lastFrame;
end function

_Graph.prototype.displayRate = function(x)
	if typeof(x) != "number" then return "error : display rate -> x expected number.";
	return Graph.reserved_video_display.rate(x);
end function

Graph = new Class("Graph",_Graph.prototype).prototype;

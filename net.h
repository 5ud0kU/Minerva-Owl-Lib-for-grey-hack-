// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.1.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Net = Class("template",{});

_Net.prototype.reserved_backsession = [];

_Net.prototype.scan_wifi = function(x)
	networks = get_shell.host_computer.wifi_networks(x);
	return networks;
end function

_Net.prototype.ack = function(x)
	c = @Libs.crypto;
	bid = x.split(char(44))[0];
	eid = x.split(char(44))[1];
	ack = x.split(char(44))[2].to_int;
	return c.aireplay(bid,eid,ack);
end function

_Net.prototype.interface = function(x,y)
	c = @Libs.crypto;
	return c.airmon(x,y);
end function

_Net.prototype.netconfig = function()
	config = [get_router.essid_name,get_router.bssid_name,get_shell.host_computer.network_gateway,get_shell.host_computer.local_ip,get_shell.host_computer.public_ip,whois(get_shell.host_computer.public_ip)];
	return config;
end function

_Net.prototype.toNetStr = function(x,y)
	data = x.split(char(32));
	if data.len != 3 then return "error : net to string -> x the string format is not recognized.";
	bid = data[0];
	eid = data[2];
	ack = y;
	netString = bid + "," + eid + "," + ack;
	return netString;
end function

_Net.prototype.addSession = function(x)
	if typeof(x) != "shell" then return "error : background session -> x shell expected.";
	session = new {};
	session.ip = x.host_computer.public_ip;
	session.lan = x.host_computer.local_ip;
	session.gateway = get_router(x.host_computer.public_ip).local_ip;
	session.shell = x;
	session.id = Net.reserved_backsession.len ;
	Net.reserved_backsession.push(session);
	return;
end function

_Net.prototype.closeSession = function(x)
	if typeof(x) != "number" then return "error : close session -> x int expected.";
	Net.reserved_backsession.remove(x);
	return;
end function

_Net.prototype.backsessions = function()
	return Net.reserved_backsession;
end function

_Net.prototype.connect = function(x,y,z,w)
	if typeof(y) != "number" then return "error : connect -> y int expected";
	Net.addSession(get_shell.connect_service(x,y,z,w));
	return;
end function

Net = new Class("Net",_Net.prototype).prototype;

// Minerva Owl Lib Open Source Package for Grey Hack 0.7.3x, coded by Chrome https://steamcommunity.com/id/01043477120/.
// The package is a bundle of many functions.You can use this script for learning , personal usage.If you add
// or remove code in view to integrated it to your own public project, in this case please mention wich part belong
// to my personal work and intellectual integrity.

//  /¤v¤\
//  |/ \|
//  |/ \|  Minerva Owl Lib 3.2.9
//   ,|.

// Official Documentation : https://minervaowllib.com

_Thread = Class("template",{});

_Thread.prototype.state = false;
_Thread.prototype.threads = [];

// mythread - list
_Thread.prototype.add = function(x,y)
  if typeof(x) != "string" then return "error : thread -> x expected a string.";
  if typeof(y) != "list" then return "error : thread -> y expected a list.";
  if x.len < 0 then return "error : thread -> x the string is empty.";
  if y.len < 0 then return "error : thread -> y the list is empty.";

  thread = {"name":x, "process":y};
  Thread.threads.push(thread);

  return 1;
end function

_Thread.prototype.kill = function(x)
  if typeof(x) != "string" then return "error : thread -> x expected a string.";
  if x.len < 0 then return "error : thread -> x the string is empty.";
  if Thread.threads.len < 1 then return "error : thread -> theres not element processing.";

  for i in range(0,Thread.threads.len -1)
    if Thread.threads[i].name == x then
      Thread.threads.remove(i);
      return 1;
    end if
  end for
  return 0;
end function

_Thread.prototype.stop = function()
  Thread.state = false;
  return 1;
end function

//This is a imitation of a coroutine.
_Thread.prototype.exec = function()
  if Thread.threads.len < 1 then return "error : thread -> theres no element to process.";
  Thread.state = true;
  while(Thread.state == true and Thread.threads.len > 0)
    for i in range(0, Thread.threads.len -1)
      routine = Thread.threads[i].process;

      if routine.len > 0 then
        routine[0];
        Thread.threads[i].process.remove(0);
      else
        Thread.threads.remove(0);
      end if
    end for
  end while;
  return 1;
end function

Thread = new Class("Thread",_Thread.prototype).prototype;

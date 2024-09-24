#ifndef MANUAL_H
#define MANUAL_H

#include <ESP8266WebServer.h>
#include <Ticker.h>

extern Ticker timer;
extern ESP8266WebServer server;
extern const int led, air, fan;

void handleManual()
{
	String output = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>Document</title><style> * { box-sizing: border-box; padding: 0; margin: 0; } body { padding: 30px 100px; display: flex; flex-direction: column; align-items: center; justify-content: flex-start; gap: 40px; } h1 { width: 230px; height: 70px; display: flex; justify-content: center; align-items: center; background-color: #77c9ff; border-radius: 15px; box-shadow: 7px 6px 28px 1px rgba(0, 0, 0, 0.24); } .wrapper { display: flex; flex-direction: column; height: 200px; width: 230px; padding: 15px; align-items: center; justify-content: space-between; color: #2c3e50; background-color: #77c9ff; border-radius: 15px; box-shadow: 7px 6px 28px 1px rgba(0, 0, 0, 0.24); } .control { width: 100%; display: flex; justify-content: space-between; align-items: center; } .title { font-size: 25px; } .btn { background-color: #fff; box-shadow: 7px 6px 28px 1px rgba(0, 0, 0, 0.24); border: none; border-radius: 30px; width: 60px; height: 30px; cursor: pointer; padding: 5px; transition: 0.3s all; } .btn:before { content: ''; display: block; background-color: #000; width: 20px; height: 20px; border-radius: 50%; margin-left: 0; transition: 0.3s ease-in; } .btn-active { background-color: green; } .btn-active:before { margin-left: 30px; background-color: #fff; } .back { width: 230px; height: 40px; font-size: 20px; font-weight: 600; text-decoration: none; color: #2c3e50; background-color: #77c9ff; border-radius: 15px; box-shadow: 7px 6px 28px 1px rgba(0, 0, 0, 0.24); display: flex; justify-content: center; align-items: center; transition: 0.3s all; } .back:hover { background-color: #fff; } </style></head><body><h1>Manual control</h1><div class='wrapper'><div class='control'><h2 class='title'>Light</h2><div class='btn btn-active'></div></div><div class='control'><h2 class='title'>Aeration</h2><div class='btn btn-active'></div></div><div class='control'><h2 class='title'>Fan</h2><div class='btn btn-active'></div></div></div><a href='/' class='back'>Go Back</a><script> const controls = document.querySelectorAll('.btn'); const info = document.querySelector('.work'); controls.forEach((a, i) => { a.addEventListener('click', (event) => { control(event.target, i); event.target.classList.toggle('btn-active'); }); }); function control(a, i) { switch (i) { case 0: if (a.classList.contains('btn-active')) fetch('/LED_ON'); else fetch('/LED_OFF'); break; case 1: if (a.classList.contains('btn-active')) fetch('/AIR_ON'); else fetch('/AIR_OFF'); break; case 2: if (a.classList.contains('btn-active')) fetch('/FAN_ON'); else fetch('/FAN_OFF'); break; } } </script></body></html>";
	timer.detach();
	server.send(200, "text/html", output);
}

void ledOn()
{
	digitalWrite(led, HIGH);
	String output = "{\"state\":" + String(digitalRead(0)) + "}";
	server.send(200, "application/json", output);
}

void ledOff()
{
	digitalWrite(led, LOW);

	String output = "{\"state\":" + String(digitalRead(0)) + "}";
	server.send(200, "application/json", output);
}

void airOn()
{
	digitalWrite(air, HIGH);

	String output = "{\"state\":" + String(digitalRead(0)) + "}";
	server.send(200, "application/json", output);
}

void airOff()
{
	digitalWrite(air, LOW);

	String output = "{\"state\":" + String(digitalRead(0)) + "}";
	server.send(200, "application/json", output);
}

void fanOn()
{
	digitalWrite(fan, HIGH);

	String output = "{\"state\":" + String(digitalRead(0)) + "}";
	server.send(200, "application/json", output);
}

void fanOff()
{
	digitalWrite(fan, LOW);

	String output = "{\"state\":" + String(digitalRead(0)) + "}";
	server.send(200, "application/json", output);
}

#endif
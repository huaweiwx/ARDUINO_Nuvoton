#include "lua.h"

uint8_t LuaRunning = 0;
void Lua_Stop() {
  if (LuaRunning)
    Serial.flush();
}

int Lua_millis(lua_State *L) {
  lua_pushnumber(L, millis());
  return 1;
}

int Lua_delay(lua_State *L) {
  int nValue = lua_gettop(L);
  unsigned long DelayTime;
  if (nValue != 1)  {
    lua_pushstring(L, "Error! Example: delay(1000) -> delay 1000ms");
    lua_error(L);
  }
  if (!lua_isinteger(L, 1))  {
    lua_pushstring(L, "Error! Use Integer to delay");
    lua_error(L);
  }
  DelayTime = lua_tonumber(L, 1);
  delay(DelayTime);
  return 0;
}

int Lua_pinMode(lua_State *L) {
  int nValue = lua_gettop(L);
  if (nValue != 2) {
    lua_pushstring(L, "Error! Example: pinMode(pin,\"OUTPUT\")");
    lua_error(L);
  }

  if (!lua_isinteger(L, 1))lua_pushstring(L, "Error pin !"), lua_error(L);
  if (!lua_isstring(L, 2))lua_pushstring(L, "Error Mode !"), lua_error(L);

  int pin = lua_tonumber(L, 1);
  if (pin >= NUM_DIGITAL_PINS) {
    lua_pushstring(L, "Error pin must be < NUM_DIGITAL_PINS!");
    lua_error(L);
  }

  String Mode = String(lua_tostring(L, 2));
  Mode.toUpperCase();
  if (Mode == "OUTPUT")pinMode(pin, OUTPUT);
  else if (Mode == "INPUT")pinMode(pin, INPUT);
  else if (Mode == "INPUT_PULLUP")pinMode(pin, INPUT_PULLUP);
  else if (Mode == "INPUT_PULLDOWN")pinMode(pin, INPUT_PULLDOWN);
  else if (Mode == "INPUT_ANALOG")pinMode(pin, INPUT);
  else if (Mode == "PWM")pinMode(pin, OUTPUT);
  else
  {
    lua_pushstring(L, "Error Pin Mode! \r\nMode: OUTPUT, INPUT, INPUT_PULLUP, INPUT_PULLDOWN, INPUT_ANALOG, PWM");
    lua_error(L);
  }
  return 0;
}

int Lua_digitalWrite(lua_State *L) {
  int nValue = lua_gettop(L);
  if (nValue != 2) {
    lua_pushstring(L, "Error! Example: digitalWrite(pin,state)");
    lua_error(L);
  }

  for (int i = 1; i <= 2; i++) {
    if (!lua_isinteger(L, i))    {
      lua_pushstring(L, "Error number of Value!");
      lua_error(L);
    }
  }

  int pin = lua_tonumber(L, 1);
  int State = lua_tonumber(L, 2);

  if (pin >= NUM_DIGITAL_PINS) {
    lua_pushstring(L, "Error pin must be < NUM_DIGITAL_PINS!");
    lua_error(L);
  }

  digitalWrite(pin, State);
  return 0;
}

int Lua_digitalToggle(lua_State *L) {
  int nValue = lua_gettop(L);
  if (nValue != 1)  {
    lua_pushstring(L, "Error! Example: digitalToggle(pin)");
    lua_error(L);
  }

  if (!lua_isinteger(L, 1))  {
    lua_pushstring(L, "Error number of Value!");
    lua_error(L);
  }

  int pin = lua_tonumber(L, 1);

  if (pin >= NUM_DIGITAL_PINS) {
    lua_pushstring(L, "Error pin must be < NUM_DIGITAL_PINS!");
    lua_error(L);
  }

  digitalToggle(pin);
  return 0;
}

int Lua_digitalRead(lua_State *L) {
  int nValue = lua_gettop(L);
  if (nValue != 1)  {
    lua_pushstring(L, "Error! Example: digitalRead(pin)");
    lua_error(L);
  }

  if (!lua_isinteger(L, 1))  {
    lua_pushstring(L, "Error number of Value!");
    lua_error(L);
  }

  int pin = lua_tonumber(L, 1);

  if (pin >= NUM_DIGITAL_PINS) {
    lua_pushstring(L, "Error pin must be < NUM_DIGITAL_PINS!");
    lua_error(L);
  }

  lua_pushnumber(L, digitalRead(pin));
  return 1;
}

int Lua_analogWrite(lua_State *L)
{
  int nValue = lua_gettop(L);
  if (nValue != 2)  {
    lua_pushstring(L, "Error! Example: analogWrite(pin,val) ");
    lua_error(L);
  }

  for (int i = 1; i <= 2; i++)  {
    if (!lua_isinteger(L, i))    {
      lua_pushstring(L, "Error number of Value!");
      lua_error(L);
    }
  }

  int pin = lua_tonumber(L, 1);
  int val = lua_tonumber(L, 2);

  if (pin >= NUM_DIGITAL_PINS)  {
    lua_pushstring(L, "Error pin must be < NUM_DIGITAL_PINS!");
    lua_error(L);
  }

  analogWrite(pin, val);
  return 0;
}

int Lua_analogRead(lua_State *L) {
  int nValue = lua_gettop(L);
  if (nValue != 1)  {
    lua_pushstring(L, "Error! Example: analogRead(pin)");
    lua_error(L);
  }

  if (!lua_isinteger(L, 1))  {
    lua_pushstring(L, "Error number of Value!");
    lua_error(L);
  }

  int pin = lua_tonumber(L, 1);

  if (pin >= NUM_DIGITAL_PINS)  {
    lua_pushstring(L, "Error pin must be < NUM_DIGITAL_PINS!");
    lua_error(L);
  }
  lua_pushnumber(L, analogRead(pin));
  return 1;
}

int Cmd_lua(int argc, char *argv[]) {
  Serial.println("\r\nArduino lua initializing...");
  Serial.setTimeout(10);
  //  Serial.attachInterrupt(Lua_Stop);

  int error = 0;
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  lua_register(L, "millis", Lua_millis);
  lua_register(L, "delay", Lua_delay);
  lua_register(L, "pinMode", Lua_pinMode);
  lua_register(L, "digitalWrite", Lua_digitalWrite);
  lua_register(L, "digitalRead", Lua_digitalRead);
  lua_register(L, "analogWrite", Lua_analogWrite);
  lua_register(L, "analogRead", Lua_analogRead);
  lua_register(L, "digitalToggle", Lua_digitalToggle);

  luaL_dostring(L, "print(\"> Version:\",_VERSION)");

  while (1) {
    if (Serial.available()) {
      String rx = Serial.readString();
      char *rx_buffer = new char[rx.length() + 10];

      Serial.println("\r\nCode:\r\n");
      Serial.println(rx);
      Serial.printf("\r\n(Size: %d )\r\n", rx.length());
      rx.toCharArray(rx_buffer, rx.length() + 10);

      Serial.print("\r\n> ");
      LuaRunning = 1;
      error = luaL_loadbuffer(L, rx_buffer, strlen(rx_buffer), "line") || lua_pcall(L, 0, 0, 0);
      delete []rx_buffer;
      LuaRunning = 0;
    }
    if (error)  {
      Serial.println(lua_tostring(L, -1));
      error = 0;
      LuaRunning = 0;
      //lua_pop(L, 1);
    }
  }
  //lua_close(L);
}


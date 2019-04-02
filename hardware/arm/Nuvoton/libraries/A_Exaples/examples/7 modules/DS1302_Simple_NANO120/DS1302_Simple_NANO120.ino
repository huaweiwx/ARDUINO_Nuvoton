
#include <ThreeWire.h>
#include <RtcDS1302.h>

// STM32 NUCLEO F401 CONNECTIONS:
//#define  DS1302_VCC  3.3v - 5v
//#define  DS1302_GND  GND
#define  DS1302_CLK  PE_2
#define  DS1302_DAT  PE_3
#define  DS1302_RST  PE_4

ThreeWire myWire(DS1302_DAT, DS1302_CLK, DS1302_RST); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void setup ()
{
#if defined(DS1302_GND)
  pinMode(DS1302_GND, OUTPUT);
  digitalWrite(DS1302_GND, LOW);
#endif

#if defined(DS1302_VCC)
  pinMode(DS1302_VCC, OUTPUT);
  digitalWrite(DS1302_VCC, HIGH);
#endif

  Serial.begin(115200);

  Serial.print("compiled: ");
  Serial.print(__DATE__);
  Serial.println(__TIME__);

  Rtc.Init();

  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  printDateTime(compiled);
  Serial.println();

  if (Rtc.GetIsWriteProtected())
  {
    Serial.println("RTC was write protected, enabling writing now");
    Rtc.SetIsWriteProtected(false);
  }

  if (!Rtc.GetIsRunning())
  {
    Serial.println("RTC was not actively running, starting now");
    Rtc.SetIsRunning(true);
  }

  RtcDateTime now = Rtc.GetDateTime();
  if (now < compiled) {
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    Rtc.SetDateTime(compiled);
  } else if (now > compiled) {
    Serial.println("RTC is newer than compile time. (this is expected)");
  } else if (now == compiled){
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }
}

void loop ()
{
  RtcDateTime now = Rtc.GetDateTime();

  printDateTime(now);
  Serial.println();

  delay(1000); // ten seconds
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt)
{
  char datestring[20];
  snprintf_P(datestring,
             countof(datestring),
             PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
             dt.Month(),
             dt.Day(),
             dt.Year(),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );
  Serial.print(datestring);
}

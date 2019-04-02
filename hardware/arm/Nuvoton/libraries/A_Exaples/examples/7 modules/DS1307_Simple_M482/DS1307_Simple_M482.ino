/* DS1307_AT24C32 module */
// connections:
// DS1307 SCL --> SCL
// DS1307 SDA --> SDA
// DS1307 VCC --> VCC
// DS1307 GND --> GND

/*NUVOTON M482 */
#define USE_WARESOFT  1  /* set to 1 use software i2c */
#define AT24CXX_SCL    PB_2
#define AT24CXX_SDA    PB_3
#define VCC_PIN        PB_4
#define GND_PIN        PB_5


#if USE_WARESOFT > 0
/* for software wire use below */
  #include <WireSoft.h>  // must be included here so that Arduino library object file references work
  #include <RtcDS1307.h>
  TwoWireSoft myWire(AT24CXX_SDA, AT24CXX_SCL);
  RtcDS1307<TwoWireSoft> Rtc(myWire);
/*for software wire use above */
#else
/* for normal hardware wire use below */
  #include <Wire.h> // must be included here so that Arduino library object file references work
  TwoWire  myWire(AT24CXX_SDA, AT24CXX_SCL);
  #include <RtcDS1307.h>
  RtcDS1307<TwoWire> Rtc(Wire);
/* for normal hardware wire use above */
#endif

void setup ()
{
#ifdef    GND_PIN
  pinMode(GND_PIN, OUTPUT);
  digitalWrite(GND_PIN, LOW);
#endif
#ifdef    VCC_PIN
  pinMode(VCC_PIN, OUTPUT);
  digitalWrite(VCC_PIN, HIGH);
#endif

  Serial.begin(115200);
  Serial.print("compiled: ");
  Serial.print(__DATE__);
  Serial.println(__TIME__);

  //--------RTC SETUP ------------
  // if you are using ESP-01 then uncomment the line below to reset the pins to
  // the available pins for SDA, SCL
  // Wire.begin(0, 2); // due to limited pins, use pin 0 and 2 for SDA, SCL

  Rtc.Init();

  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  printDateTime(compiled);
  Serial.println();

  if (!Rtc.IsDateTimeValid())
  {
    // Common Cuases:
    //    1) first time you ran and the device wasn't running yet
    //    2) the battery on the device is low or even missing

    Serial.println("RTC lost confidence in the DateTime!");

    // following line sets the RTC to the date & time this sketch was compiled
    // it will also reset the valid flag internally unless the Rtc device is
    // having an issue

    Rtc.SetDateTime(compiled);
  }

  if (!Rtc.GetIsRunning()){
    Serial.println("RTC was not actively running, starting now");
    Rtc.SetIsRunning(true);
  }

  RtcDateTime now = Rtc.GetDateTime();
  if (now < compiled){
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    Rtc.SetDateTime(compiled);
  } else if (now > compiled) {
    Serial.println("RTC is newer than compile time. (this is expected)");
  } else if (now == compiled) {
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }

  // never assume the Rtc was last configured by you, so
  // just clear them to your needed state
  Rtc.SetSquareWavePin(DS1307SquareWaveOut_Low);
}

void loop ()
{
  if (!Rtc.IsDateTimeValid()) {
    // Common Cuases:
    //    1) the battery on the device is low or even missing and the power line was disconnected
    Serial.println("RTC lost confidence in the DateTime!");
  }

  RtcDateTime now = Rtc.GetDateTime();

  printDateTime(now);
  Serial.println();

  delay(10000); // ten seconds
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

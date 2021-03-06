
void clockSet(byte hr, byte min)
{
    rtc.adjust(DateTime(2020, 3, 31, hr, min, 0));
}

void clockAlarmSet(byte hr, byte min)
{
    rtc.clearAlarm(1);
    rtc.setAlarm1(DateTime(2020, 3, 31, hr, min, 0), DS3231_A1_Hour);
}

void clockClearAlarm()
{
    rtc.clearAlarm(1);
}

void clockEnableAlarm()
{
    rtc.enableAlarm(1);
}

void clockDisableAlarm()
{
    rtc.disableAlarm(1);
}

bool clockIsAlarmEnabled()
{
    return rtc.isAlarmEnabled(1);
}

void clockSetup()
{
    rtc.begin();
    if (rtc.lostPower())
    {
        clockSet(0, 0); // 00:00
    }
    rtc.clearAlarm(1);
}

byte clockGetTemp()
{
    return (byte) round(rtc.getTemperature());
}

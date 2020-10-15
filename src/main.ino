#define TRIGGER_PIN PB10
#define ECHO_PIN PB11

#define LED_PIN PC13

#define SerialMon Serial

void getUltraSonicData(void);

char buffer[100];

void setup()
{
    SerialMon.begin(115200);
    delay(100);
    while (!SerialMon)
    {
        ;
    }
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    getUltraSonicData();
    delay(3500);
}

void getUltraSonicData(void)
{
    long duration, cm;
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(5);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);
    cm = (duration ) / 58.2;
    snprintf(buffer, sizeof(buffer), "Distance: %lu", cm);
    SerialMon.println(buffer);
    if (cm < 20)
    {
        digitalWrite(LED_PIN, !(digitalRead(LED_PIN)));
    }
    
}
char command;

char state = 's'; // 'stop'

// Digital PWM-enabled pin numbers

int M1A = 3; // R motor REV
int M1B = 5; // R motor FWD
int M2A = 6; // L motor REV
int M2B = 9; // L motor FWD

// Initial motor PWM levels

int M1 = 255;
int M2 = 230;

void setup()
{
    Serial.begin(115200);

    pinMode(M1A, OUTPUT);
    pinMode(M1B, OUTPUT);
    pinMode(M2A, OUTPUT);
    pinMode(M2B, OUTPUT);
}
void loop()
{
    command = Serial.read();

    if (command == 'v') // 'velocity'
    {
        Serial.println("Toggle between full and half speed");

        if (M1 == 255)
        {
            M1 = 127;
            M2 = 115;
        }
        else
        {
            M1 = 255;
            M2 = 230;
        }
    }
    if (command == 'l' || state == 'l')
    {
        if (command == 'l')
        {
            Serial.println("Turn left backward");
        }
        state = 'l';

        analogWrite(M1A, M1);
        analogWrite(M1B,  0);
        analogWrite(M2A,  0);
        analogWrite(M2B,  0);
    }
    if (command == 'B' || state == 'B')
    {
        if (command == 'B')
        {
            Serial.println("Move backward");
        }
        state = 'B';

        analogWrite(M1A, M1);
        analogWrite(M1B,  0);
        analogWrite(M2A, M2);
        analogWrite(M2B,  0);
    }
    if (command == 'r' || state == 'r')
    {
        if (command == 'r')
        {
            Serial.println("Turn right backward");
        }
        state = 'r';

        analogWrite(M1A,  0);
        analogWrite(M1B,  0);
        analogWrite(M2A, M2);
        analogWrite(M2B,  0);
    }
    if (command == 'a' || state == 'a')
    {
        if (command == 'a')
        {
            Serial.println("Pivot left");
        }
        state = 'a';

        analogWrite(M1A,  0);
        analogWrite(M1B, M1);
        analogWrite(M2A, M2);
        analogWrite(M2B,  0);
    }
    if (command == 's' || state == 's')
    {
        if (command == 's')
        {
            Serial.println("Stop");
        }
        state = 's';

        analogWrite(M1A,  0);
        analogWrite(M1B,  0);
        analogWrite(M2A,  0);
        analogWrite(M2B,  0);
    }
    if (command == 'b' || state == 'b')
    {
        if (command == 'b')
        {
            Serial.println("pivot right");
        }
        state = 'b';

        analogWrite(M1A, M1);
        analogWrite(M1B,  0);
        analogWrite(M2A,  0);
        analogWrite(M2B, M2);
    }
    if (command == 'L' || state == 'L')
    {
        if (command == 'L')
        {
            Serial.println("Turn left forward");
        }
        state = 'L';

        analogWrite(M1A,  0);
        analogWrite(M1B, M1);
        analogWrite(M2A,  0);
        analogWrite(M2B,  0);
    }
    if (command == 'F' || state == 'F')
    {
        if (command == 'F')
        {
            Serial.println("Move forward");
        }
        state = 'F';

        analogWrite(M1A,  0);
        analogWrite(M1B, M1);
        analogWrite(M2A,  0);
        analogWrite(M2B, M2);
    }
    if (command == 'R' || state == 'R')
    {
        if (command == 'R')
        {
            Serial.println("Turn right forward");
        }
        state = 'R';

        analogWrite(M1A,  0);
        analogWrite(M1B,  0);
        analogWrite(M2A,  0);
        analogWrite(M2B, M2);
    }
}

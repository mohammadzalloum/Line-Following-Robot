#include <DRV8835MotorShield.h>

// ===== إعداد الدرايفر (Pololu DRV8835) =====
// DIR1 → D7, PWM1 → D8, PWM2 → D9, DIR2 → D10
DRV8835MotorShield motors(7, 8, 9, 10);

// ===== إعداد QTR-8RC Reflectance Sensor Array =====
// التوصيلات كما طلبت:
//   Sensor 1 → D13
//   Sensor 2 → D12
//   Sensor 3 → D11
//   Sensor 4 → D6
//   Sensor 5 → D5
//   Sensor 6 → D4
//   Sensor 7 → D3
//   Sensor 8 → D2
const uint8_t sensorPins[8] = { 13, 12, 11, 6, 5, 4, 3, 2 };
uint16_t sensorValues[8];

// أوزان الحساسات (يسار → يمين)
const int weights[8] = { -7, -5, -3, -1, 1, 3, 5, 7 };

// إعدادات السرعة
const int baseSpeed      = 160;   // سرعة أساسية للمستقيم
const int maxSpeed       = 400;   // أقصى سرعة للمحركات
const int correctionGain = 90;    // قوة الالتفاف

void setup() {
  Serial.begin(9600);

  // تهيئة أرجل الحساسات لشحن مكثفات QTR-8RC
  for (uint8_t i = 0; i < 8; i++) {
    pinMode(sensorPins[i], OUTPUT);
    digitalWrite(sensorPins[i], LOW);
  }

  // إذا كان اتجاه أحد المحركات عكسيًا، يمكنك قلبه هنا:
  // motors.flipM1(true);
  // motors.flipM2(true);

  motors.setSpeeds(0, 0);
  delay(500);
  Serial.println(">> بدء تتبع الخط <<");
}

void loop() {
  readQTR8RC();
  int error      = computeError();
  int correction = error * correctionGain;

  int leftSpeed  = constrain(baseSpeed + correction, -maxSpeed, maxSpeed);
  int rightSpeed = constrain(baseSpeed - correction, -maxSpeed, maxSpeed);

  motors.setSpeeds(leftSpeed, rightSpeed);

  // طباعة لمراقبة الأداء وضبط المعاملات
  Serial.print("Err=");    Serial.print(error);
  Serial.print("  L=");    Serial.print(leftSpeed);
  Serial.print("  R=");    Serial.println(rightSpeed);

  delay(20);
}

// ==== دالة قراءة QTR-8RC (RC style) ====
void readQTR8RC() {
  // شحن المكثفات
  for (uint8_t i = 0; i < 8; i++) {
    pinMode(sensorPins[i], OUTPUT);
    digitalWrite(sensorPins[i], HIGH);
  }
  delayMicroseconds(10);

  // قياس زمن التفريغ
  const uint16_t MAX_COUNT = 3000;
  for (uint8_t i = 0; i < 8; i++) {
    pinMode(sensorPins[i], INPUT);
    uint16_t count = 0;
    while (digitalRead(sensorPins[i]) == HIGH && count < MAX_COUNT) {
      count++;
    }
    sensorValues[i] = count;
  }
}

// ==== دالة حساب الخطأ بناءً على الأوزان ====
int computeError() {
  long num = 0, den = 0;
  for (uint8_t i = 0; i < 8; i++) {
    num += (long)sensorValues[i] * weights[i];
    den += sensorValues[i];
  }
  if (den == 0) return 0;  // لم يُرصد الخط
  return num / den;
}
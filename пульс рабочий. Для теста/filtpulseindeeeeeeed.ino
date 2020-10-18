int ans[3], temp[3], aaans[3], ttemp[3], a[3], t[3];
int _max = 0, _min = 10000, toothmax = 0, counter = 0;
double timer[2];
short rateValue, preVal = 0;
short A = 0, B = 0;
double maxTime[2];
short iter = 0;
bool crest = false;
double period, freq;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int rateValue = analogRead(A1), val;

  //filter
  for (int i = 0; i < 3; i++) {
    temp[i] = ans[i];
    ttemp[i] = aaans[i];
    t[i] = a[i];
  }
  a[2] = (aaans[0] + aaans[1] + aaans[2]) / 3;
  a[1] = t[2];
  a[0] = t[1];
  aaans[2] = (ans[0] + ans[1] + ans[2]) / 3;
  aaans[1] = ttemp[2];
  aaans[0] = ttemp[1];
  ans[2] = rateValue;
  ans[1] = temp[2];
  ans[0] = temp[1];
  val = (a[2] + a[1] + a[0]) / 3;

  //pulse
  if (!A && !crest) {
    A = rateValue;
    crest = true;
    timer[0] = millis();
  }
  else if (!B && !crest) {
    B = rateValue;
    crest = true;
    timer[1] = millis();
  }
  if (rateValue > preVal) {
    crest = false;
  }
  if (A && B) {
    if (max(A, B) == A) {
      maxTime[iter] = timer[0];
    }
    else {
      maxTime[iter] = timer[1];
    }
    ++iter;
    A = B = 0;
    if (iter == 2) {
      period = (maxTime[1] - maxTime[0]) / 1000;
      iter = 0;
      freq = 60 / period;
      Serial.print("period: ");
      Serial.print(period);
      Serial.print(" freq: ");
      Serial.print(freq);
      Serial.print("\n");
    }
  }
  preVal = rateValue;
  Serial.println(val);
}

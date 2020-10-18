int ans[3], temp[3], aaans[3], ttemp[3], a[3], t[3];
int _max = 0, _min = 10000, toothmax = 0, counter = 0;
  bool crest = true, too = false;
void setup() {
  Serial.begin(9600);

}

void loop() {
  static int time_ = 0;
  int rateValue = analogRead(A1), val;
  
  time_ = millis();
  if (time_ >= 60000) {
    time_ = 0;
  }
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
  _max = max(_max, val);
  _min = min(_min, val);
  if (_max > val && !too && crest) {
    _max = 0;
    counter++;
  }
  if (_min < val && !too && crest) {
    crest = false;
    too = true;
  }
  if (!crest && _min < val) {
    crest = true;
  }
  if (too) {
    toothmax = max(toothmax, val);
    if (toothmax > val) {
      too = false;
      toothmax = 0;
    }
  }
  Serial.println(val);
}

int ans[3], temp[3], aaans[3], ttemp[3], a[3], t[3];
void setup() {
  Serial.begin(9600);

}

void loop() {
  int rateValue = analogRead(A1);
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
  Serial.println((a[0] + a[1] + a[2]) / 3);
  delay(50);
}

int pin[4][3]={{2,3,4},{5,6,7},{8,9,10},{11,12,13}}; // merah,kuning,hijau per sisi

void setup(){
  for(int i=0;i<12;i++)pinMode(pin[i/3][i%3],OUTPUT);
}

void semuaMerah(){
  for(int i=0;i<4;i++){
    digitalWrite(pin[i][0],HIGH);
    digitalWrite(pin[i][1],LOW);
    digitalWrite(pin[i][2],LOW);
  }
}

void kedip(int p){
  for(int i=0;i<3;i++){
    digitalWrite(p,HIGH);delay(300);
    digitalWrite(p,LOW);delay(300);
  }
}

void hijau(int s){
  semuaMerah();
  
  // TRANSISI: Merah → Kuning nyala 1 detik → Hijau
  digitalWrite(pin[s][0],LOW);
  digitalWrite(pin[s][1],HIGH);
  delay(1000);
  
  digitalWrite(pin[s][1],LOW);
  digitalWrite(pin[s][2],HIGH);
  delay(5000);
  
  digitalWrite(pin[s][2],LOW);
  kedip(pin[s][1]);  // Kuning kedip 3x
  digitalWrite(pin[s][0],HIGH);
}

void loop(){
  for(int s=0;s<4;s++){
    hijau(s);
    delay(2000);
  }
}
#define motor_pin 6
#define speed_pin 5
double time1 = 0.00 ;
double time2 = 0.00;
int startpoint  = 200; 
double integration;
double derivitive;
double motor;
double output2 = 0.00;
double dt;
double output1;
float const alpha = 0.04;
float error1;
float error2 = 0.00;
float const Kp = 1.00;
float const Kd = 2.00;
float const Ki = 4.00; 
void setup() {
  // put your setup code here, to run once:
  pinMode(motor_pin, OUTPUT);
  pinMode(speed_pin, INPUT);
}
class pid
{
  public:
  void proportional()
  {
  float error1  = startpoint - motor; // Proportional
  }
  void integrate()
  {
    integration += error1*dt;
  }
  void diffrentiate()
  {
    derivitive  = (error1-error2)/dt;
    error2 = error1;
  }
};
void loop() {
  // put your main code here, to run repeatedly:
  motor = analogRead(speed_pin);
  time1 = millis();
  dt = ((time1-time2)/1000);
  time2 = time1;
  pid proportional(); // Proportional
  pid integrate(); //Integration
  pid diffrentiate(); // Diffrentiation
  pid output();
  output1 = (error1*Kp)+(integration*Ki)+(derivitive*Kd);
  //Filter
  double output3 = (alpha*output1) + (1-alpha)*output2;  
  output2 = output3; 
  analogWrite(motor_pin, output3);
}

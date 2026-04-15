// ===== SENSOR 1 =====
void calibrationd(){
sensor.setBlackMin(3, 10, 3);
sensor.setBlackMax(100*1.5, 100*1.35, 80*1.15);
sensor.setGreenMin(18,  40, 18);
sensor.setGreenMax(30, 55, 30);
sensor.setRedMin(100, 0, 0);
sensor.setRedMax(255, 50, 50);
sensor.setWhiteMin(140*0.9, 140*0.9, 100*0.9);
sensor.setWhiteMax(320, 285, 230);
sensor.setSilverMin(180, 180, 180);
sensor.setSilverMax(230, 230, 230);


// ===== SENSOR 2 =====
sensor2.setBlackMin(30, 45, 25);
sensor2.setBlackMax(190*1.2, 170*1.2, 95*1.2);
sensor2.setGreenMin(0, 100, 0);
sensor2.setGreenMax(50, 255, 50);
sensor2.setRedMin(100, 0, 0);
sensor2.setRedMax(255, 50, 50);
sensor2.setWhiteMin(160*0.9, 200*0.9, 120*0.9);
sensor2.setWhiteMax(440, 465, 345);
sensor2.setSilverMin(180, 180, 180);
sensor2.setSilverMax(230, 230, 230);


// ===== SENSOR 3 =====
sensor3.setBlackMin(15, 15, 10);
sensor3.setBlackMax(110*1.6, 100*1.15, 100*1.2);
sensor3.setGreenMin(0, 100, 0);
sensor3.setGreenMax(50, 255, 50);
sensor3.setRedMin(100, 0, 0);
sensor3.setRedMax(255, 50, 50);
sensor3.setWhiteMin(105*0.9, 110*0.9, 60*0.9);
sensor3.setWhiteMax(300, 250, 215);
sensor3.setSilverMin(180, 180, 180);
sensor3.setSilverMax(230, 230, 230);


// ===== SENSOR 4 =====
sensor4.setBlackMin(60, 90, 30);
sensor4.setBlackMax(300*1.6, 420*1.2, 220*1.2);
sensor4.setGreenMin(0, 100, 0);
sensor4.setGreenMax(50, 255, 50);
sensor4.setRedMin(100, 0, 0);
sensor4.setRedMax(255, 50, 50);
sensor4.setWhiteMin(390*0.9, 420*0.9, 150*0.9);
sensor4.setWhiteMax(710, 780, 450);
sensor4.setSilverMin(180, 180, 180);
sensor4.setSilverMax(230, 230, 230);
}

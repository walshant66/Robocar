int getDistance()
{
	unsigned long pulseTime;
	int distance;
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);
	pulseTime = pulseIn(echo, HIGH, timeOut);
	distance = (float)pulseTime * 340/2/10000;
	return distance;
}

int checkDirection()
{
	int distance [2] = {0,0};
	int turnDir = 1;
	servoLook.write(180);
	delay(500);
	distance[0] = getDistance();
	servoLook.write(0);
	delay(1000);
	distances[1] = getDistance();
	if(distance[0]>=200 && distance[1]>=200)
		turnDir = 0;
	else if (distances[0]<=stopDist && distance[1]<=stopDist)
		turnDir = 1;
	else if(distance[0]>=distances[1])
		turnDir = 0;
	else if(distances[0]<distances[1])
		turnDir = 2;
	return turnDir;
}
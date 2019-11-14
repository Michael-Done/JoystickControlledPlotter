//newEncoderX = x-axis motor encoder value
//newEncoderY = y-axis motor encoder value
//oldEncoderx = oldEncoderX value (initialized as 0 in task main() )
//oldEncoderY = oldEncoderY value (initialized as 0 in task main() )

bool inactivityTest(int newEncoderX, int newEncoderY, int & oldEncoderX, int & oldEncoderY) //True implies exit
{
if (time1[T1]>IDLETIME)
    return true;

if(newEncoderX != oldEncoderX && newEncoderY !=oldEncoderY)  //an axis has moved
{
time1[T1]=0;
oldEncoderX=newEncoderX;        //Reset Timer, Update Current Encoder Value
oldEncoderY=newEncoderY;
cout<<"hello";
}

return false;

}


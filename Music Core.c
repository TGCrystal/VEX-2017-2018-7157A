float bpm = 120;

float mGetFrequency(int note, int octave)
{
	float base;
	float multiplier;
	switch(note) {
		case 1:
			base = 16.35;
			break;
		case 2:
			base = 17.32;
			break;
		case 3:
			base = 18.35;
			break;
		case 4:
			base = 19.45;
			break;
		case 5:
			base = 20.6;
			break;
		case 6:
			base = 21.83;
			break;
		case 7:
			base = 23.12;
			break;
		case 8:
			base = 24.5;
			break;
		case 9:
			base = 25.96;
			break;
		case 10:
			base = 27.5;
			break;
		case 11:
			base = 29.14;
			break;
		case 12:
			base = 30.87;
			break;
	}
	switch(multiplier) {
		case 0:
			multiplier = 1.0;
			break;
		case 1:
			multiplier = 2.0;
			break;
		case 2:
			multiplier = 4.0;
			break;
		case 3:
			multiplier = 8.0;
			break;
		case 4:
			multiplier = 16.0;
			break;
		case 5:
			multiplier = 32.0;
			break;
		case 6:
			multiplier = 64.0;
			break;
		case 7:
			multiplier = 128.0;
			break;
		case 8:
			multiplier = 256.0;
			break;
	}
	return (note*multiplier);
}

float mGetDuration(float division)
{
	return (bpm/(division*100));
}

void mC(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(1, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mDF(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(2, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mD(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(3, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mEF(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(4, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mE(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(5, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mF(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(6, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mGF(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(7, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mG(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(8, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mAF(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(9, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mA(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(10, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mBF(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(11, octave), finalDuration);
	wait10Msec(finalDuration);
}
void mB(int octave, float division)
{
	float finalDuration = mGetDuration(division);
	PlayTone(mGetFrequency(12, octave), finalDuration);
	wait10Msec(finalDuration);
}